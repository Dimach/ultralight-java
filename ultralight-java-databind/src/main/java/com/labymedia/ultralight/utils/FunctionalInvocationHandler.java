/*
 * Ultralight Java - Java wrapper for the Ultralight web engine
 * Copyright (C) 2020 LabyMedia and contributors
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

package com.labymedia.ultralight.utils;

import com.labymedia.ultralight.Databind;
import com.labymedia.ultralight.context.ContextProvider;
import com.labymedia.ultralight.ffi.gc.DeletableObject;
import com.labymedia.ultralight.javascript.*;
import com.labymedia.ultralight.javascript.*;

import java.lang.invoke.MethodHandles;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicReference;

/**
 * Invocation handler for Javascript functions bound to functional interfaces.
 */
class FunctionalInvocationHandler implements InvocationHandler {
    private static final MethodHandles.Lookup LOOKUP = MethodHandles.lookup();

    /**
     * Invokes a default method on an interface without knowing the implementation.
     *
     * @param clazz  The interface class to invoke the method on
     * @param method The method to invoke
     * @param proxy  The proxy instance used as {@code this}
     * @param args   The arguments to pass to the invocation
     * @return The return value of the invoked method
     * @throws Throwable If an error occurs while invoking the method
     */
    private static Object invokeDefaultMethod(Class<?> clazz, Method method, Object proxy, Object[] args)
            throws Throwable {
        return LOOKUP.in(clazz).unreflectSpecial(method, clazz).bindTo(proxy).invokeWithArguments(args);
    }

    private final Object lock;
    private final Class<?> target;
    private final ContextProvider contextProvider;
    private final Databind databind;

    private final DeletableObject<ValueWrapper> protectedValue;

    /**
     * Creates a new {@link FunctionalInvocationHandler}.
     *
     * @param function        The bound function
     * @param target          The bound interface
     * @param contextProvider A context provider for calling into Javascript
     * @param databind        The databind instance used for translation between Java and Javascript
     */
    public FunctionalInvocationHandler(
            JavascriptObject function, Class<?> target, ContextProvider contextProvider, Databind databind) {
        this.target = target;
        this.contextProvider = contextProvider;
        this.databind = databind;
        lock = new Object();
        protectedValue = new DeletableObject<>(
                new ValueWrapper(contextProvider, function.protect()), FunctionalInvocationHandler::delete);
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        if (method.isDefault()) {
            // Invoke the default method on the interface
            return invokeDefaultMethod(target, method, proxy, args);
        }

        Class<?> methodSource = method.getDeclaringClass();
        if (methodSource.isInstance(this)) {
            // Invoke the method on this object
            return method.invoke(this, args);
        }

        Class<?>[] methodParameterTypes = method.getParameterTypes();

        CountDownLatch awaiter = new CountDownLatch(1);
        AtomicReference<Object> out = new AtomicReference<>();

        contextProvider.syncWithJavascript((contextLock) -> {
            synchronized (lock) {
                JavascriptContext context = contextLock.getContext();

                // Revive the Javascript value, this will effectively invalidate the protected value
                JavascriptObject object = protectedValue.get().value.revive(contextLock).toObject();

                // Convert all Java arguments to Javascript values
                JavascriptValue[] arguments = new JavascriptValue[args.length];
                for (int i = 0; i < arguments.length; i++) {
                    arguments[i] = databind.getConversionUtils()
                            .toJavascript(context, args[i], methodParameterTypes[i]);
                }

                // Protect the value again
                protectedValue.get().value = object.protect();

                JavascriptValue returnValue = object.callAsFunction(null, arguments);
                Object ret = databind.getConversionUtils().fromJavascript(returnValue, method.getReturnType());
                out.set(ret);
                awaiter.countDown();
            }
        });

        awaiter.await();

        return out.get();
    }

    /**
     * Tuple of a context provider and a protected Javascript value.
     */
    private static class ValueWrapper {
        private final ContextProvider contextProvider;
        private JavascriptProtectedValue value;

        /**
         * Constructs a new {@link ValueWrapper} for a value and its corresponding context provider.
         *
         * @param contextProvider The context provider to use for the value
         * @param value           The protected value
         */
        private ValueWrapper(ContextProvider contextProvider, JavascriptProtectedValue value) {
            this.contextProvider = contextProvider;
            this.value = value;
        }
    }

    /**
     * Deletes a value wrapper when it is not required anymore.
     *
     * @param valueWrapper The wrapper to delete
     */
    private static void delete(ValueWrapper valueWrapper) {
        valueWrapper.contextProvider.syncWithJavascript((contextLock) -> {
            valueWrapper.value.revive(contextLock);
        });
    }
}
