#include <jni.h>
#include <android/log.h>
#include <stdio.h>

jint NativeAdd(JNIEnv *env, jobject pObj, jint pa, jint pb){
	return pa + pb;
}

jint NativeMulti(JNIEnv *pEnv, jobject pObj, jint pa, jint pb){
	return pa * pb;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* pVM, void *reserved){
	JNIEnv *env;
	if((*pVM)->GetEnv(pVM, (void **)&env, JNI_VERSION_1_6)){
		return -1;
	}

	JNINativeMethod nm[2];
	nm[0].name = "NativeAdd"; nm[0].signature = "(II)I";
	nm[0].fnPtr= NativeAdd;
	nm[1].name = "NativeMulti"; nm[1].signature = "(II)I";
	nm[1].fnPtr= NativeMulti;
	jclass cls = (*env) -> FindClass(env, "com/zpf/methodreg/MainActivity");

	(*env) -> RegisterNatives(env, cls, nm, 2);
	return JNI_VERSION_1_6;

}
