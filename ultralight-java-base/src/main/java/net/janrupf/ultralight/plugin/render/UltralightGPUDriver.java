package net.janrupf.ultralight.plugin.render;

import net.janrupf.ultralight.annotation.NativeType;
import net.janrupf.ultralight.bitmap.UltralightBitmap;

public interface UltralightGPUDriver {

    void beginSynchronize();

    void endSynchronize();

    @NativeType("uint32_t") long nextTextureId();

    void createTexture(@NativeType("uint32_t") long textureId, UltralightBitmap bitmap);

    void updateTexture(@NativeType("uint32_t") long textureId, UltralightBitmap bitmap);

    void destroyTexture(@NativeType("uint32_t") long textureId);

    @NativeType("uint32_t") long nextRenderBufferId();

    void createRenderBuffer(@NativeType("uint32_t") long renderBufferId, UltralightRenderBuffer buffer);

    void destroyRenderBuffer(@NativeType("uint32_t") long renderBufferId);

    @NativeType("uint32_t") long nextGeometryId();

    void createGeometry(@NativeType("uint32_t") long geometryId,
                        final UltralightVertexBuffer vertices,
                        final UltralightIndexBuffer indices);

    void updateGeometry(@NativeType("uint32_t") long geometryId,
                        final UltralightVertexBuffer vertices,
                        final UltralightIndexBuffer indices);

    void destroyGeometry(@NativeType("uint32_t") long geometryId);

    void updateCommandList(final UltralightCommandList list);

}
