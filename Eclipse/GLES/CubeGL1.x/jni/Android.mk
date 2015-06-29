LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := CubeGL1.x
LOCAL_SRC_FILES := CubeGL1.x.cpp Cube.cpp

LOCAL_LDLIBS := -lGLESv1_CM  -llog


include $(BUILD_SHARED_LIBRARY)
