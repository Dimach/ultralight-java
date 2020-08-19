//
// Created by leo on 18.08.20.
//
#include <ultralight_java/java_bridges/bridged_gpu_driver.hpp>

#include "ultralight_java/java_bridges/proxied_java_exception.hpp"
#include "ultralight_java/ultralight_java_instance.hpp"
#include "ultralight_java/util/temporary_jni.hpp"
#include "ultralight_java/util/util.hpp"

namespace ultralight_java {

    BridgedGPUDriver::BridgedGPUDriver(JNIEnv *env, jobject gpu_driver) : JNIReferenceWrapper(env, gpu_driver) {
    }

    void BridgedGPUDriver::BeginSynchronize() {
        TemporaryJNI env;

        env->CallVoidMethod(reference, runtime.ultralight_gpu_driver.begin_synchronize_method);
        ProxiedJavaException::throw_if_any(env);
    }

    void BridgedGPUDriver::EndSynchronize() {
        TemporaryJNI env;

        env->CallVoidMethod(reference, runtime.ultralight_gpu_driver.end_synchronize_method);
        ProxiedJavaException::throw_if_any(env);
    }

    uint32_t BridgedGPUDriver::NextTextureId() {
        TemporaryJNI env;

        jlong java_result = env->CallLongMethod(reference, runtime.ultralight_gpu_driver.next_texture_id_method);
        ProxiedJavaException::throw_if_any(env);

        return static_cast<uint32_t>(java_result);
    }

    void BridgedGPUDriver::CreateTexture(uint32_t texture_id, ultralight::Ref<ultralight::Bitmap> bitmap) {
        TemporaryJNI env;


    }

}
