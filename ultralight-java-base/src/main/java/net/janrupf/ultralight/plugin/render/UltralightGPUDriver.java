package net.janrupf.ultralight.plugin.render;

import net.janrupf.ultralight.annotation.NativeType;

public interface UltralightGPUDriver {

    String getName();

    void beginDrawing();

    void endDrawing();

    void bindTexture(@NativeType("uint8_t") long textureUnit, @NativeType("uint32_t") long textureId);

    void bindRenderBuffer(@NativeType("uint32_t") long renderBufferId);

    void clearRenderBuffer(@NativeType("uint32_t") long renderBufferId);

    void drawGeometry(long geometryId, long indicesCount, long indicesOffset);

}
