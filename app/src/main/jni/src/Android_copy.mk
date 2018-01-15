LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

LOCAL_C_INCLUDES := \Android.mk
    $(LOCAL_PATH)/../SDL2/include \
    $(LOCAL_PATH)/../SDL2_image \
    $(LOCAL_PATH)/../SDL2_mixer \
    $(LOCAL_PATH)/../SDL2_ttf \
    $(LOCAL_PATH)/../mt19937/include \
    $(LOCAL_PATH)/../zerog/include


LOCAL_SRC_FILES := \
    entitas/events/ComponentReplaced.c \
    entitas/events/EntityChanged.c \
    entitas/events/EntityReleased.c \
    entitas/events/GroupChanged.c \
    entitas/events/GroupsChanged.c \
    entitas/events/GroupUpdated.c \
    entitas/events/WorldChanged.c \
    entitas/entitas.c \
    entitas/Group.c \
    entitas/Matcher.c \
    entitas/World.c \
    goop/Class.c \
    goop/Guid.c \
    sdx/audio/audio.c \
    sdx/audio/Sound.c \
    sdx/files/FileHandle.c \
    sdx/files/files.c \
    sdx/graphics/BitmapFont.c \
    sdx/graphics/Camera.c \
    sdx/graphics/graphics.c \
    sdx/graphics/NinePatch.c \
    sdx/graphics/Sprite.c \
    sdx/graphics/Surface.c \
    sdx/graphics/TextureAtlas.c \
    sdx/graphics/TextureEnums.c \
    sdx/graphics/TextureRegion.c \
    sdx/math/Interpolation.c \
    sdx/math/Timeline.c \
    sdx/math/Tween.c \
    sdx/math/TweenAccessor.c \
    sdx/math/Tweenbase.c \
    sdx/math/TweenManager.c \
    sdx/math/Vector2.c \
    sdx/ui/Button.c \
    sdx/ui/Component.c \
    sdx/ui/Label.c \
    sdx/utils/Cache.c \
    sdx/utils/File.c \
    sdx/utils/Json.c \
    sdx/utils/StringTokenizer.c \
    sdx/utils/utils.c \
    sdx/AbstractGame.c \
    sdx/ApplicationListener.c \
    sdx/Color.c \
    sdx/exceptions.c \
    sdx/Files.c \
    sdx/Font.c \
    sdx/InputMultiplexer.c \
    sdx/InputProcessor.c \
    sdx/Screen.c \
    sdx/sdx.c \
    mt19937ar.c \
    systems/AnimationSystem.c \
    systems/CollisionSystem.c \
    systems/DisplaySystem.c \
    systems/ExpireSystem.c \
    systems/InputSystem.c \
    systems/PhysicsSystem.c \
    systems/RemoveSystem.c \
    systems/ScoreSystem.c \
    systems/SoundSystem.c \
    systems/SpawnSystem.c \
    components.c \
    Config.c \
    entity.c \
    Factory.c \
    Game.c \
    main.c \
    shmupwarz.c

LOCAL_SHARED_LIBRARIES := \
    SDL2 \
    SDL2_image \
    SDL2_mixer \
    SDL2_ttf

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
