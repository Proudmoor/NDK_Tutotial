LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := MethodReg
LOCAL_SRC_FILES := MethodReg.c

include $(BUILD_SHARED_LIBRARY)
