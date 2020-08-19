//
// Created by leo on 18.08.20.
//

#ifndef ULTRALIGHT_JAVA_BRIDGED_GPU_DRIVER_HPP
#define ULTRALIGHT_JAVA_BRIDGED_GPU_DRIVER_HPP

#endif // ULTRALIGHT_JAVA_BRIDGED_GPU_DRIVER_HPP

#pragma once

#include <Ultralight/Ultralight.h>

#include "ultralight_java/util/jni_reference_wrapper.hpp"

namespace ultralight_java {

    class BridgedGPUDriver : public ultralight::GPUDriver, JNIReferenceWrapper {
    public:
        explicit BridgedGPUDriver(JNIEnv *env, jobject gpu_driver);

        void BeginSynchronize() final;

        void EndSynchronize() final;

        uint32_t NextTextureId() final;

        void CreateTexture(uint32_t texture_id,
                           ultralight::Ref<ultralight::Bitmap> bitmap) final;

        void UpdateTexture(uint32_t texture_id,
                           ultralight::Ref<ultralight::Bitmap> bitmap) final;

        void BindTexture(uint8_t texture_unit,
                         uint32_t texture_id);

        void DestroyTexture(uint32_t texture_id) final;

        uint32_t NextRenderBufferId() final;

        void CreateRenderBuffer(uint32_t render_buffer_id,
                                const ultralight::RenderBuffer& buffer) final;

        void BindRenderBuffer(uint32_t render_buffer_id);

        void UpdateGeometry(uint32_t geometry_id,
                            const ultralight::VertexBuffer& vertices,
                            const ultralight::IndexBuffer& indices) final;

        void DrawGeometry(uint32_t geometry_id,
                          uint32_t indices_count,
                          uint32_t indices_offset,
                          const ultralight::GPUState& state);

        void DestroyGeometry(uint32_t geometry_id) final;

        void UpdateCommandList(const ultralight::CommandList& list) final;

        bool HasCommandsPending();

        void DrawCommandList();
    };

}
