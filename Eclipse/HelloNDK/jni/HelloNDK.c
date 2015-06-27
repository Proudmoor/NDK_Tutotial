#include <jni.h>
#include <string.h>
/* Header for class jni_getNDKStr */


jstring Java_jni_getNDKStr_GetString
  (JNIEnv* env,jobject pObbj){
	return  (*env)->NewStringUTF(env, "Hello from JNI ! ");
}

