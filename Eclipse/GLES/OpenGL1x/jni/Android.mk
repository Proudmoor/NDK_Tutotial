LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := OpenGL1x
LOCAL_SRC_FILES := OpenGL1x.cpp Triangle.cpp Square.cpp

LOCAL_LDLIBS :=-lGLESv1_CM -llog
include $(BUILD_SHARED_LIBRARY)
