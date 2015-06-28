LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Parameter
LOCAL_SRC_FILES := Parameter.c

LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)
