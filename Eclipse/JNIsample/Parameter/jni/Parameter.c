#include <jni.h>
#include <android/log.h>
#include <stdlib.h>

JNIEXPORT jboolean JNICALL Java_com_zpf_parameter_MainActivity_passBoolean(
		JNIEnv *pEnv, jobject pObj, jboolean pBoolean){
	__android_log_print(ANDROID_LOG_INFO, "native", "%d in %d bytes", pBoolean, sizeof(jboolean));
	return (!pBoolean);
}

JNIEXPORT jint JNICALL Java_com_zpf_parameter_MainActivity_passInt(
		JNIEnv *pEnv, jobject pObj, jint pInt){
	__android_log_print(ANDROID_LOG_INFO, "native", "%d in %d bytes", pInt, sizeof(jint));
	return pInt + 1;
}

JNIEXPORT jdouble JNICALL Java_com_zpf_parameter_MainActivity_passDouble(
		JNIEnv *pEnv, jobject pObj, jdouble pDouble){
	__android_log_print(ANDROID_LOG_INFO, "native", "%f in %d bytes", pDouble, sizeof(jdouble));
	return pDouble +0.5;
}

JNIEXPORT jlong JNICALL Java_com_zpf_parameter_MainActivity_passLong(
		JNIEnv *pEnv, jobject pObj, jlong pLong){
	__android_log_print(ANDROID_LOG_INFO, "native", "%llu in %d bytes", pLong, sizeof(jlong));
	return pLong + 1;
}

JNIEXPORT jfloat JNICALL Java_com_zpf_parameter_MainActivity_passFloat(
		JNIEnv *pEnv, jobject pObj, jfloat pFloat){
	__android_log_print(ANDROID_LOG_INFO, "native", "%f in %d bytes", pFloat, sizeof(jfloat));
	return pFloat +0.5;
}

JNIEXPORT jbyte JNICALL Java_com_zpf_parameter_MainActivity_passByte(
		JNIEnv *pEnv, jobject pObj, jbyte pByte){
	 __android_log_print(ANDROID_LOG_INFO, "native", "%d in %d bytes", pByte, sizeof(jbyte));
	return pByte + 1;
}

JNIEXPORT jchar JNICALL Java_com_zpf_parameter_MainActivity_passChar(
		JNIEnv *pEnv, jobject pObj, jchar pChar){
	__android_log_print(ANDROID_LOG_INFO, "native", "%c in %d bytes", pChar, sizeof(jchar));
		pChar = '*';
	return pChar;
}

JNIEXPORT jshort JNICALL Java_com_zpf_parameter_MainActivity_passShort(
		JNIEnv *pEnv, jobject pObj, jshort pShort){
	__android_log_print(ANDROID_LOG_INFO, "native", "%d in %d bytes", pShort, sizeof(jshort));
	return pShort - 1;
}

JNIEXPORT jstring JNICALL Java_com_zpf_parameter_MainActivity_passStringAndReturn(
		JNIEnv *pEnv, jobject pObj, jstring pStringP){
		//__android_log_print(ANDROID_LOG_INFO, "native", "print jstring: %s", pStringP);

		const jbyte *str;
		jboolean *isCopy;
		str = (*pEnv)->GetStringUTFChars(pEnv, pStringP, isCopy);
		if (str == NULL) {
			__android_log_print(ANDROID_LOG_INFO, "native", "cannot convert jstring to utf-8 string");
		}
		__android_log_print(ANDROID_LOG_INFO, "native", "print UTF-8 string: %s, %d", str, isCopy);

		jsize length = (*pEnv)->GetStringUTFLength(pEnv, pStringP);
		__android_log_print(ANDROID_LOG_INFO, "native", "UTF-8 string length (number of bytes): %d == %d", length, strlen(str));

		__android_log_print(ANDROID_LOG_INFO, "native", "UTF-8 string ends with: %d %d", str[length], str[length+1]);

		(*pEnv)->ReleaseStringUTFChars(pEnv, pStringP, str);

		char nativeStr[100];

		(*pEnv)->GetStringUTFRegion(pEnv, pStringP, 0, length, nativeStr);
		__android_log_print(ANDROID_LOG_INFO, "native", "jstring converted to UTF-8 string and copied to native buffer: %s", nativeStr);

		const char* newStr = "hello new";
		jstring ret = (*pEnv)->NewStringUTF(pEnv, newStr);
		jsize newStrLen = (*pEnv)->GetStringUTFLength(pEnv, ret);
		__android_log_print(ANDROID_LOG_INFO, "native", "UTF-8 string with Chinese characters: %s, string length (number of bytes) %d=%d", newStr, newStrLen, strlen(newStr));
		return ret;
}


