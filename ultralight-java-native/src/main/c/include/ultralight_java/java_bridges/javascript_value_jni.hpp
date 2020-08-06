#pragma once

#include <jni.h>

namespace ultralight_java {
    /**
     * Class for interfacing with JSValueRef from java
     */
    class JavascriptValueJNI {
    public:
        /**
         * Protects the value and returns a JavascriptProtectedValue object.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return The protected value
         */
        static jobject protect(JNIEnv *env, jobject java_instance);

        /**
         * Releases the reference.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         */
        static void context_unlocking(JNIEnv *env, jobject java_instance);

        /**
         * Retrieves the type of the reference.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return The type of this reference as a java object
         */
        static jobject get_type(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is an undefined value.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return true if this reference is an undefined value, false otherwise
         */
        static bool is_undefined(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is a null value.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return true if this reference is a null value, false otherwise
         */
        static bool is_null(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is a boolean value.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return true if this reference is a boolean value, false otherwise
         */
        static bool is_boolean(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is a number value.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return true if this reference is a number value, false otherwise
         */
        static bool is_number(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is a string value.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return true if this reference is a string value, false otherwise
         */
        static bool is_string(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is a symbol value.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return true if this reference is a symbol value, false otherwise
         */
        static bool is_symbol(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is an object value.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return true if this reference is an object value, false otherwise
         */
        static bool is_object(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is an array value.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return true if this reference is an array value, false otherwise
         */
        static bool is_array(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is a date value.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return true if this reference is a date value, false otherwise
         */
        static bool is_date(JNIEnv *env, jobject java_instance);

        /**
         * Retrieves the JSTypedArrayType of this reference.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return The typed array type of this reference
         */
        static jobject get_typed_array_type(JNIEnv *env, jobject java_instance);

        /**
         * Tests whether this reference is equal to another.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @param java_other The other instance of a JSValueRef
         * @return true if the reference are equal, false otherwise
         */
        static bool is_equal(JNIEnv *env, jobject java_instance, jobject java_other);

        /**
         * Tests whether this reference is strictly equal to another.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @param java_other The other instance of a JSValueRef
         * @return true if the reference are strictly equal, false otherwise
         */
        static bool is_strict_equal(JNIEnv *env, jobject java_instance, jobject java_other);

        /**
         * Converts this reference to a json string.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @param indentation The amount of spaces to use for indentation
         * @return This reference as a json string
         */
        static jstring to_json(JNIEnv *env, jobject java_instance, jshort indentation);

        /**
         * Converts this reference to a boolean.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return This reference as a boolean
         */
        static jboolean to_boolean(JNIEnv *env, jobject java_instance);

        /**
         * Converts this reference to a number.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return This reference as a double
         */
        static jdouble to_number(JNIEnv *env, jobject java_instance);

        /**
         * Converts this reference to a string.
         *
         * @param env The JNI environment to use for accessing java
         * @param java_instance The java instance of this JSValueRef
         * @return This reference as a string
         */
        static jstring to_string_copy(JNIEnv *env, jobject java_instance);
    };
} // namespace ultralight_java