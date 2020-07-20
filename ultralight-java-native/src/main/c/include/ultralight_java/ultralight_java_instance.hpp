#pragma once

#include <Ultralight/Ultralight.h>
#include <Ultralight/platform/Logger.h>
#include <array>
#include <jni.h>

#include "ultralight_java/java_bridges/ultralight_bitmap_jni.hpp"
#include "ultralight_java/java_bridges/ultralight_bitmap_surface_jni.hpp"
#include "ultralight_java/java_bridges/ultralight_key_event_jni.hpp"
#include "ultralight_java/java_bridges/ultralight_platform_jni.hpp"
#include "ultralight_java/java_bridges/ultralight_ref_ptr_jni.hpp"
#include "ultralight_java/java_bridges/ultralight_renderer_jni.hpp"
#include "ultralight_java/java_bridges/ultralight_surface_jni.hpp"
#include "ultralight_java/java_bridges/ultralight_view_jni.hpp"
#include "ultralight_java/util/java_enum.hpp"

namespace ultralight_java {
    class BridgedLogger;

    struct UltralightJavaRuntime {
        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * Method returning the native pointer of the underlying C(++) object
             */
            jmethodID get_handle_method = nullptr;
        } object_with_handle;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * Constructor taking a long as a handle
             */
            jmethodID constructor = nullptr;

            /**
             * Native methods that should be bound
             */
            std::array<JNINativeMethod, 6> native_methods =
                {JNINativeMethod{
                     const_cast<char *>("runOnSafeThread"),
                     const_cast<char *>("(Ljava/lang/Runnable;)V"),
                     reinterpret_cast<void *>(&UltralightPlatformJNI::run_on_safe_thread)},
                 JNINativeMethod{
                     const_cast<char *>("instance"),
                     const_cast<char *>("()Lnet/janrupf/ultralight/UltralightPlatform;"),
                     reinterpret_cast<void *>(&UltralightPlatformJNI::instance)},
                 JNINativeMethod{
                     const_cast<char *>("setConfig"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/config/UltralightConfig;)V"),
                     reinterpret_cast<void *>(&UltralightPlatformJNI::set_config)},
                 JNINativeMethod{
                     const_cast<char *>("usePlatformFontLoader"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightPlatformJNI::use_platform_font_loader)},
                 JNINativeMethod{
                     const_cast<char *>("usePlatformFileSystem"),
                     const_cast<char *>("(Ljava/lang/String;)V"),
                     reinterpret_cast<void *>(&UltralightPlatformJNI::use_platform_file_system)},
                 JNINativeMethod{
                     const_cast<char *>("setLogger"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/plugin/logging/UltralightLogger;)V"),
                     reinterpret_cast<void *>(&UltralightPlatformJNI::set_logger)}};
        } ultralight_platform;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /* String */ jfieldID resource_path_field = nullptr;
            /* String */ jfieldID cache_path_field = nullptr;
            /* boolean */ jfieldID use_gpu_renderer_field = nullptr;
            /* double */ jfieldID device_scale_field = nullptr;
            /* FaceWinding */ jfieldID face_winding_field = nullptr;
            /* boolean */ jfieldID enable_images_field = nullptr;
            /* boolean */ jfieldID enable_javascript_field = nullptr;
            /* FontHinting */ jfieldID font_hinting_field = nullptr;
            /* double */ jfieldID font_gamma_field = nullptr;
            /* String */ jfieldID font_family_standard_field = nullptr;
            /* String */ jfieldID font_family_fixed_field = nullptr;
            /* String */ jfieldID font_family_serif_field = nullptr;
            /* String */ jfieldID font_family_sans_serif_field = nullptr;
            /* String */ jfieldID user_agent_field = nullptr;
            /* String */ jfieldID user_stylesheet_field = nullptr;
            /* boolean */ jfieldID force_repaint_field = nullptr;
            /* double */ jfieldID animation_timer_delay_field = nullptr;
            /* double */ jfieldID scroll_timer_delay_field = nullptr;
            /* double */ jfieldID recycle_delay_field = nullptr;
            /* long */ jfieldID memory_cache_size_field = nullptr;
            /* long */ jfieldID page_cache_size_field = nullptr;
            /* long */ jfieldID override_ram_size_field = nullptr;
            /* long */ jfieldID min_large_heap_size_field = nullptr;
            /* long */ jfieldID min_small_heap_size_field = nullptr;
        } ultralight_config;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The enum constants
             */
            JavaEnum<ultralight::FaceWinding> constants = JavaEnum<ultralight::FaceWinding>(
                ultralight::kFaceWinding_Clockwise,
                "CLOCKWISE",
                ultralight::kFaceWinding_CounterClockwise,
                "COUNTER_CLOCKWISE");
        } face_winding;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The java enum constants
             */
            JavaEnum<ultralight::FontHinting> constants = JavaEnum<ultralight::FontHinting>(
                ultralight::kFontHinting_Smooth,
                "SMOOTH",
                ultralight::kFontHinting_Normal,
                "NORMAL",
                ultralight::kFontHinting_Monochrome,
                "MONOCHROME");
        } font_hinting;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /*
             * Method taking a log level and message to log
             */
            jmethodID log_message_method = nullptr;
        } logger;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The java enum constants
             */
            JavaEnum<ultralight::LogLevel> constants = JavaEnum<ultralight::LogLevel>(
                ultralight::kLogLevel_Error,
                "ERROR",
                ultralight::kLogLevel_Warning,
                "WARNING",
                ultralight::kLogLevel_Info,
                "INFO");
        } log_level;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * Constructor taking a long as a handle
             */
            jmethodID constructor = nullptr;

            /**
             * Native methods that should be bound
             */
            std::array<JNINativeMethod, 1> native_methods = {JNINativeMethod{
                const_cast<char *>("delete"),
                const_cast<char *>("(J)V"),
                reinterpret_cast<void *>(&UltralightRefPtrJNI::_delete)}};
        } ref_ptr;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * Constructor taking a java RefPtr as handle
             */
            jmethodID constructor = nullptr;

            /**
             * Native methods that should be bound
             */
            std::array<JNINativeMethod, 6> native_methods =
                {JNINativeMethod{
                     const_cast<char *>("create"),
                     const_cast<char *>("()Lnet/janrupf/ultralight/UltralightRenderer;"),
                     reinterpret_cast<void *>(&UltralightRendererJNI::create)},
                 JNINativeMethod{
                     const_cast<char *>("createView"),
                     const_cast<char *>("(JJZ)Lnet/janrupf/ultralight/UltralightView;"),
                     reinterpret_cast<void *>(&UltralightRendererJNI::createView)},
                 JNINativeMethod{
                     const_cast<char *>("update"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightRendererJNI::update)},
                 JNINativeMethod{
                     const_cast<char *>("render"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightRendererJNI::render)},
                 JNINativeMethod{
                     const_cast<char *>("purgeMemory"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightRendererJNI::purgeMemory)},
                 JNINativeMethod{
                     const_cast<char *>("logMemoryUsage"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightRendererJNI::logMemoryUsage)}};
        } ultralight_renderer;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * Constructor taking a java RefPtr as handle
             */
            jmethodID constructor = nullptr;

            /**
             * Native methods that should be bound
             */
            std::array<JNINativeMethod, 29> native_methods =
                {JNINativeMethod{
                     const_cast<char *>("url"),
                     const_cast<char *>("()Ljava/lang/String;"),
                     reinterpret_cast<void *>(&UltralightViewJNI::url)},
                 JNINativeMethod{
                     const_cast<char *>("title"),
                     const_cast<char *>("()Ljava/lang/String;"),
                     reinterpret_cast<void *>(&UltralightViewJNI::title)},
                 JNINativeMethod{
                     const_cast<char *>("width"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightViewJNI::width)},
                 JNINativeMethod{
                     const_cast<char *>("height"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightViewJNI::height)},
                 JNINativeMethod{
                     const_cast<char *>("isLoading"),
                     const_cast<char *>("()Z"),
                     reinterpret_cast<void *>(&UltralightViewJNI::is_loading)},
                 JNINativeMethod{
                     const_cast<char *>("surface"),
                     const_cast<char *>("()Lnet/janrupf/ultralight/UltralightSurface;"),
                     reinterpret_cast<void *>(&UltralightViewJNI::surface)},
                 JNINativeMethod{
                     const_cast<char *>("loadHTML"),
                     const_cast<char *>("(Ljava/lang/String;Ljava/lang/String;Z)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::load_html)},
                 JNINativeMethod{
                     const_cast<char *>("loadURL"),
                     const_cast<char *>("(Ljava/lang/String;)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::load_url)},
                 JNINativeMethod{
                     const_cast<char *>("resize"),
                     const_cast<char *>("(JJ)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::resize)},
                 JNINativeMethod{
                     const_cast<char *>("evaluateScript"),
                     const_cast<char *>("(Ljava/lang/String;)Ljava/lang/String;"),
                     reinterpret_cast<void *>(&UltralightViewJNI::evaluate_script)},
                 JNINativeMethod{
                     const_cast<char *>("canGoBack"),
                     const_cast<char *>("()Z"),
                     reinterpret_cast<void *>(&UltralightViewJNI::can_go_back)},
                 JNINativeMethod{
                     const_cast<char *>("canGoForward"),
                     const_cast<char *>("()Z"),
                     reinterpret_cast<void *>(&UltralightViewJNI::can_go_forward)},
                 JNINativeMethod{
                     const_cast<char *>("goBack"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::go_back)},
                 JNINativeMethod{
                     const_cast<char *>("goForward"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::go_forward)},
                 JNINativeMethod{
                     const_cast<char *>("goToHistoryOffset"),
                     const_cast<char *>("(I)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::go_to_history_offset)},
                 JNINativeMethod{
                     const_cast<char *>("reload"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::reload)},
                 JNINativeMethod{
                     const_cast<char *>("stop"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::stop)},
                 JNINativeMethod{
                     const_cast<char *>("focus"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::focus)},
                 JNINativeMethod{
                     const_cast<char *>("unfocus"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::unfocus)},
                 JNINativeMethod{
                     const_cast<char *>("hasFocus"),
                     const_cast<char *>("()Z"),
                     reinterpret_cast<void *>(&UltralightViewJNI::has_focus)},
                 JNINativeMethod{
                     const_cast<char *>("hasInputFocus"),
                     const_cast<char *>("()Z"),
                     reinterpret_cast<void *>(&UltralightViewJNI::has_input_focus)},
                 JNINativeMethod{
                     const_cast<char *>("fireKeyEvent"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/input/UltralightKeyEvent;)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::fire_key_event)},
                 JNINativeMethod{
                     const_cast<char *>("fireMouseEvent"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/input/UltralightMouseEvent;)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::fire_mouse_event)},
                 JNINativeMethod{
                     const_cast<char *>("fireScrollEvent"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/input/UltralightScrollEvent;)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::fire_scroll_event)},
                 JNINativeMethod{
                     const_cast<char *>("setViewListener"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/plugin/view/UltralightViewListener;)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::set_view_listener)},
                 JNINativeMethod{
                     const_cast<char *>("setLoadListener"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/plugin/loading/UltralightLoadListener;)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::set_load_listener)},
                 JNINativeMethod{
                     const_cast<char *>("setNeedsPaint"),
                     const_cast<char *>("(Z)V"),
                     reinterpret_cast<void *>(&UltralightViewJNI::set_needs_paint)},
                 JNINativeMethod{
                     const_cast<char *>("needsPaint"),
                     const_cast<char *>("()Z"),
                     reinterpret_cast<void *>(&UltralightViewJNI::needs_paint)},
                 JNINativeMethod{
                     const_cast<char *>("inspector"),
                     const_cast<char *>("()Lnet/janrupf/ultralight/UltralightView;"),
                     reinterpret_cast<void *>(&UltralightViewJNI::inspector)}};
        } ultralight_view;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * Constructor taking 4 ints as the bounds in coordinates
             */
            jmethodID bounds_constructor = nullptr;

            /* int */ jfieldID left_field = nullptr;
            /* int */ jfieldID top_field = nullptr;
            /* int */ jfieldID right_field = nullptr;
            /* int */ jfieldID bottom_field = nullptr;
        } int_rect;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * Constructor taking a UltralightView and a long as a handle
             */
            jmethodID constructor = nullptr;

            /**
             * Native methods that should be bound
             */
            std::array<JNINativeMethod, 10> native_methods =
                {JNINativeMethod{
                     const_cast<char *>("width"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::width)},
                 JNINativeMethod{
                     const_cast<char *>("height"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::height)},
                 JNINativeMethod{
                     const_cast<char *>("rowBytes"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::rowBytes)},
                 JNINativeMethod{
                     const_cast<char *>("size"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::size)},
                 JNINativeMethod{
                     const_cast<char *>("lockPixels"),
                     const_cast<char *>("()Ljava/nio/ByteBuffer;"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::lockPixels)},
                 JNINativeMethod{
                     const_cast<char *>("unlockPixels"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::unlockPixels)},
                 JNINativeMethod{
                     const_cast<char *>("resize"),
                     const_cast<char *>("(JJ)V"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::resize)},
                 JNINativeMethod{
                     const_cast<char *>("setDirtyBounds"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/math/IntRect;)V"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::setDirtyBounds)},
                 JNINativeMethod{
                     const_cast<char *>("dirtyBounds"),
                     const_cast<char *>("()Lnet/janrupf/ultralight/math/IntRect;"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::dirtyBounds)},
                 JNINativeMethod{
                     const_cast<char *>("clearDirtyBounds"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightSurfaceJNI::clearDirtyBounds)}};
        } ultralight_surface;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * Constructor taking a UltralightView and a long as a handle
             */
            jmethodID constructor = nullptr;

            /**
             * Native methods that should be bound
             */
            std::array<JNINativeMethod, 1> native_methods = {JNINativeMethod{
                const_cast<char *>("bitmap"),
                const_cast<char *>("()Lnet/janrupf/ultralight/bitmap/UltralightBitmap;"),
                reinterpret_cast<void *>(&UltralightBitmapSurfaceJNI::bitmap)}};
        } ultralight_bitmap_surface;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The java enum constants
             */
            JavaEnum<ultralight::BitmapFormat> constants = JavaEnum<ultralight::BitmapFormat>(
                ultralight::kBitmapFormat_A8_UNORM,
                "A8_UNORM",
                ultralight::kBitmapFormat_BGRA8_UNORM_SRGB,
                "BGRA8_UNORM_SRGB");
        } ultralight_bitmap_format;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * Constructor taking a RefPtr as handle
             */
            jmethodID constructor = nullptr;

            /**
             * Native methods that should be bound
             */
            std::array<JNINativeMethod, 22> native_methods =
                {JNINativeMethod{
                     const_cast<char *>("create"),
                     const_cast<char *>("()Lnet/janrupf/ultralight/bitmap/UltralightBitmap;"),
                     reinterpret_cast<void *>(static_cast<jobject (*)(JNIEnv *, jclass)>(UltralightBitmapJNI::create))},
                 JNINativeMethod{
                     const_cast<char *>("create"),
                     const_cast<char *>("("
                                        "J"
                                        "J"
                                        "Lnet/janrupf/ultralight/bitmap/UltralightBitmapFormat;"
                                        ")Lnet/janrupf/ultralight/bitmap/UltralightBitmap;"),
                     reinterpret_cast<void *>(static_cast<jobject (*)(JNIEnv *, jclass, jlong, jlong, jobject)>(
                         &UltralightBitmapJNI::create))},
                 JNINativeMethod{
                     const_cast<char *>("create"),
                     const_cast<char *>("("
                                        "J"
                                        "J"
                                        "Lnet/janrupf/ultralight/bitmap/UltralightBitmapFormat;"
                                        "J"
                                        "Ljava/nio/ByteBuffer;"
                                        "Z"
                                        ")Lnet/janrupf/ultralight/bitmap/UltralightBitmap;"),
                     reinterpret_cast<void *>(
                         static_cast<jobject (*)(JNIEnv *, jclass, jlong, jlong, jobject, jlong, jobject, jboolean)>(
                             &UltralightBitmapJNI::create))},
                 JNINativeMethod{
                     const_cast<char *>("create"),
                     const_cast<char *>("("
                                        "Lnet/janrupf/ultralight/bitmap/UltralightBitmap;"
                                        ")Lnet/janrupf/ultralight/bitmap/UltralightBitmap;"),
                     reinterpret_cast<void *>(
                         static_cast<jobject (*)(JNIEnv *, jclass, jobject)>(&UltralightBitmapJNI::create))},
                 JNINativeMethod{
                     const_cast<char *>("width"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::width)},
                 JNINativeMethod{
                     const_cast<char *>("height"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::height)},
                 JNINativeMethod{
                     const_cast<char *>("bounds"),
                     const_cast<char *>("()Lnet/janrupf/ultralight/math/IntRect;"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::bounds)},
                 JNINativeMethod{
                     const_cast<char *>("format"),
                     const_cast<char *>("()Lnet/janrupf/ultralight/bitmap/UltralightBitmapFormat;"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::format)},
                 JNINativeMethod{
                     const_cast<char *>("bpp"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::bpp)},
                 JNINativeMethod{
                     const_cast<char *>("rowBytes"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::row_bytes)},
                 JNINativeMethod{
                     const_cast<char *>("size"),
                     const_cast<char *>("()J"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::size)},
                 JNINativeMethod{
                     const_cast<char *>("ownsPixels"),
                     const_cast<char *>("()Z"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::owns_pixels)},
                 JNINativeMethod{
                     const_cast<char *>("lockPixels"),
                     const_cast<char *>("()Ljava/nio/ByteBuffer;"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::lock_pixels)},
                 JNINativeMethod{
                     const_cast<char *>("unlockPixels"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::unlock_pixels)},
                 JNINativeMethod{
                     const_cast<char *>("rawPixels"),
                     const_cast<char *>("()Ljava/nio/ByteBuffer;"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::raw_pixels)},
                 JNINativeMethod{
                     const_cast<char *>("isEmpty"),
                     const_cast<char *>("()Z"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::is_emtpy)},
                 JNINativeMethod{
                     const_cast<char *>("erase"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::erase)},
                 JNINativeMethod{
                     const_cast<char *>("set"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/bitmap/UltralightBitmap;)V"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::set)},
                 JNINativeMethod{
                     const_cast<char *>("drawBitmap"),
                     const_cast<char *>("("
                                        "Lnet/janrupf/ultralight/math/IntRect;"
                                        "Lnet/janrupf/ultralight/math/IntRect;"
                                        "Lnet/janrupf/ultralight/bitmap/UltralightBitmap;"
                                        "Z"
                                        ")Z"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::width)},
                 JNINativeMethod{
                     const_cast<char *>("writePNG"),
                     const_cast<char *>("(Ljava/lang/String;)Z"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::write_png)},
                 JNINativeMethod{
                     const_cast<char *>("resample"),
                     const_cast<char *>("(Lnet/janrupf/ultralight/bitmap/UltralightBitmap;Z)Z"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::resample)},
                 JNINativeMethod{
                     const_cast<char *>("swapRedBlueChannels"),
                     const_cast<char *>("()V"),
                     reinterpret_cast<void *>(&UltralightBitmapJNI::swap_red_blue_channels)}};
        } ultralight_bitmap;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            jmethodID on_begin_loading_method = nullptr;
            jmethodID on_finish_loading_method = nullptr;
            jmethodID on_fail_loading_method = nullptr;
            jmethodID on_update_history_method = nullptr;
            jmethodID on_window_object_ready_method = nullptr;
            jmethodID on_dom_ready_method = nullptr;
        } ultralight_load_listener;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /* int */ jfieldID id_field = nullptr;
        } ultralight_key;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /* UltralightKeyEventType */ jfieldID type_field = nullptr;
            /* int */ jfieldID modifiers_field = nullptr;
            /* UltralightKey */ jfieldID virtual_key_code_field = nullptr;
            /* int */ jfieldID native_key_code_field = nullptr;
            /* String */ jfieldID key_identifier_field = nullptr;
            /* String */ jfieldID text_field = nullptr;
            /* String */ jfieldID unmodified_text_field = nullptr;
            /* boolean */ jfieldID is_keypad_field = nullptr;
            /* boolean */ jfieldID is_auto_repeat_field = nullptr;
            /* boolean */ jfieldID is_system_key_field = nullptr;

            /**
             * Native methods that should be bound
             */
            std::array<JNINativeMethod, 1> native_methods = {JNINativeMethod{
                const_cast<char *>("getKeyIdentifierFromVirtualKeyCode"),
                const_cast<char *>("(Lnet/janrupf/ultralight/input/UltralightKey;)Ljava/lang/String;"),
                reinterpret_cast<void *>(&UltralightKeyEventJNI::get_key_identifier_from_virtual_key_code)}};
        } ultralight_key_event;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The java enum constants
             */
            JavaEnum<ultralight::KeyEvent::Type> constants = JavaEnum<ultralight::KeyEvent::Type>(
                ultralight::KeyEvent::kType_KeyDown,
                "DOWN",
                ultralight::KeyEvent::kType_KeyUp,
                "UP",
                ultralight::KeyEvent::kType_RawKeyDown,
                "RAW_DOWN",
                ultralight::KeyEvent::kType_Char,
                "CHAR");
        } ultralight_key_event_type;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /* UltralightMouseEventType */ jfieldID type_field = nullptr;
            /* int */ jfieldID x_field = nullptr;
            /* int */ jfieldID y_field = nullptr;
            /* UltralightMouseButton */ jfieldID button_field = nullptr;
        } ultralight_mouse_event;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The java enum constants
             */
            JavaEnum<ultralight::MouseEvent::Button> constants = JavaEnum<ultralight::MouseEvent::Button>(
                ultralight::MouseEvent::kButton_Left,
                "LEFT",
                ultralight::MouseEvent::kButton_Middle,
                "MIDDLE",
                ultralight::MouseEvent::kButton_Right,
                "RIGHT");
        } ultralight_mouse_event_button;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The java enum constants
             */
            JavaEnum<ultralight::MouseEvent::Type> constants = JavaEnum<ultralight::MouseEvent::Type>(
                ultralight::MouseEvent::kType_MouseMoved,
                "MOVED",
                ultralight::MouseEvent::kType_MouseDown,
                "DOWN",
                ultralight::MouseEvent::kType_MouseUp,
                "UP");
        } ultralight_mouse_event_type;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /* UltralightScrollEventType */ jfieldID type_field = nullptr;
            /* int */ jfieldID delta_x_field = nullptr;
            /* int */ jfieldID delta_y_field = nullptr;
        } ultralight_scroll_event;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The java enum constants
             */
            JavaEnum<ultralight::ScrollEvent::Type> constants = JavaEnum<ultralight::ScrollEvent::Type>(
                ultralight::ScrollEvent::kType_ScrollByPixel,
                "BY_PIXEL",
                ultralight::ScrollEvent::kType_ScrollByPage,
                "BY_PAGE");
        } ultralight_scroll_event_type;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * THe java enum constants
             */
            JavaEnum<ultralight::Cursor> constants = JavaEnum<ultralight::Cursor>(
                ultralight::kCursor_Pointer,
                "POINTER",
                ultralight::kCursor_Cross,
                "CROSS",
                ultralight::kCursor_Hand,
                "HAND",
                ultralight::kCursor_IBeam,
                "I_BEAM",
                ultralight::kCursor_Wait,
                "WAIT",
                ultralight::kCursor_Help,
                "HELP",
                ultralight::kCursor_EastResize,
                "EAST_RESIZE",
                ultralight::kCursor_NorthResize,
                "NORTH_RESIZE",
                ultralight::kCursor_NorthEastResize,
                "NORTH_EAST_RESIZE",
                ultralight::kCursor_NorthWestResize,
                "NORTH_WEST_RESIZE",
                ultralight::kCursor_SouthResize,
                "SOUTH_RESIZE",
                ultralight::kCursor_SouthEastResize,
                "SOUTH_EAST_RESIZE",
                ultralight::kCursor_SouthWestResize,
                "SOUTH_WEST_RESIZE",
                ultralight::kCursor_WestResize,
                "WEST_RESIZE",
                ultralight::kCursor_NorthSouthResize,
                "NORTH_SOUTH_RESIZE",
                ultralight::kCursor_EastWestResize,
                "EAST_WEST_RESIZE",
                ultralight::kCursor_NorthEastSouthWestResize,
                "NORTH_EAST_SOUTH_WEST_RESIZE",
                ultralight::kCursor_NorthWestSouthEastResize,
                "NORTH_WEST_SOUTH_EAST_RESIZE",
                ultralight::kCursor_ColumnResize,
                "COLUMN_RESIZE",
                ultralight::kCursor_RowResize,
                "ROW_RESIZE",
                ultralight::kCursor_MiddlePanning,
                "MIDDLE_PANNING",
                ultralight::kCursor_EastPanning,
                "EAST_PANNING",
                ultralight::kCursor_NorthPanning,
                "NORTH_PANNING",
                ultralight::kCursor_NorthEastPanning,
                "NORTH_EAST_PANNING",
                ultralight::kCursor_NorthWestPanning,
                "NORTH_WEST_PANNING",
                ultralight::kCursor_SouthPanning,
                "SOUTH_PANNING",
                ultralight::kCursor_SouthEastPanning,
                "SOUTH_EAST_PANNING",
                ultralight::kCursor_SouthWestPanning,
                "SOUTH_WEST_PANNING",
                ultralight::kCursor_WestPanning,
                "WEST_PANNING",
                ultralight::kCursor_Move,
                "MOVE",
                ultralight::kCursor_VerticalText,
                "VERTICAL_TEXT",
                ultralight::kCursor_Cell,
                "CELL",
                ultralight::kCursor_ContextMenu,
                "CONTEXT_MENU",
                ultralight::kCursor_Alias,
                "ALIAS",
                ultralight::kCursor_Progress,
                "PROGRESS",
                ultralight::kCursor_NoDrop,
                "NO_DROP",
                ultralight::kCursor_Copy,
                "COPY",
                ultralight::kCursor_None,
                "NONE",
                ultralight::kCursor_NotAllowed,
                "NOT_ALLOWED",
                ultralight::kCursor_ZoomIn,
                "ZOOM_IN",
                ultralight::kCursor_ZoomOut,
                "ZOOM_OUT",
                ultralight::kCursor_Grab,
                "GRAB",
                ultralight::kCursor_Grabbing,
                "GRABBING",
                ultralight::kCursor_Custom,
                "CUSTOM");
        } ultralight_cursor;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The java enum constants
             */
            JavaEnum<ultralight::MessageLevel> constants = JavaEnum<ultralight::MessageLevel>(
                ultralight::kMessageLevel_Log,
                "LOG",
                ultralight::kMessageLevel_Warning,
                "WARNING",
                ultralight::kMessageLevel_Error,
                "ERROR",
                ultralight::kMessageLevel_Debug,
                "DEBUG",
                ultralight::kMessageLevel_Info,
                "INFO");
        } message_level;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            /**
             * The java enum constants
             */
            JavaEnum<ultralight::MessageSource> constants = JavaEnum<ultralight::MessageSource>(
                ultralight::kMessageSource_XML,
                "XML",
                ultralight::kMessageSource_JS,
                "JS",
                ultralight::kMessageSource_Network,
                "NETWORK",
                ultralight::kMessageSource_ConsoleAPI,
                "CONSOLE_API",
                ultralight::kMessageSource_Storage,
                "STORAGE",
                ultralight::kMessageSource_AppCache,
                "APP_CACHE",
                ultralight::kMessageSource_Rendering,
                "RENDERING",
                ultralight::kMessageSource_CSS,
                "CSS",
                ultralight::kMessageSource_Security,
                "SECURITY",
                ultralight::kMessageSource_ContentBlocker,
                "CONTENT_BLOCKER",
                ultralight::kMessageSource_Other,
                "OTHER");
        } message_source;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            jmethodID on_change_title_method = nullptr;
            jmethodID on_change_url_method = nullptr;
            jmethodID on_change_tooltip_method = nullptr;
            jmethodID on_change_cursor_method = nullptr;
            jmethodID on_add_console_message_method = nullptr;
            jmethodID on_create_child_view_method = nullptr;
        } ultralight_view_listener;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;

            jmethodID run_method = nullptr;
        } runnable;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;
        } javascript_exception;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;
        } null_pointer_exception;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;
        } illegal_state_exception;

        struct {
            /**
             * The java class itself
             */
            jclass clazz = nullptr;
        } illegal_argument_exception;

        /**
         * The JavaVM instance executing the virtual machine.
         */
        JavaVM *vm = nullptr;

        /**
         * Current global logger instance, or nullptr, if none
         */
        BridgedLogger *bridged_logger = nullptr;
    };

    /**
     * Global runtime struct for easy access of constants.
     */
    extern UltralightJavaRuntime runtime;

    /**
     * Initializes the library using the JavaVM instance.
     *
     * @param vm The currently executing JavaVM
     * @return
     */
    int setup(JavaVM *vm);

    /**
     * Frees global references.
     *
     * @param vm The currently executing JavaVM
     */
    void destruct(JavaVM *vm);
} // namespace ultralight_java