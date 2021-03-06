#include <jni.h>
#include <android/log.h>
#include <GLES/gl.h>
#include <math.h>
#include "Square.h"

#include "Triangle.h"

void naInitGL1x(JNIEnv *env, jclass clazz);
void naDrawGraphics(JNIEnv *env, jclass clazz);
void naSurfaceChanged(JNIEnv *env, jclass clazz, int width, int height);

jint JNI_OnLoad(JavaVM *pVM, void *reserved){
	JNIEnv *env;
	if(pVM->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK){
		return -1;
	}

	JNINativeMethod nm[3];
	nm[0].name = "naInitGL1x";       nm[0].signature = "()V";
	nm[0].fnPtr = (void*)naInitGL1x;
	nm[1].name = "naDrawGraphics";   nm[1].signature = "()V";
	nm[1].fnPtr = (void*)naDrawGraphics;
	nm[2].name = "naSurfaceChanged"; nm[2].signature = "(II)V";
	nm[2].fnPtr = (void*)naSurfaceChanged;

	jclass cls = env->FindClass("com/zpf/opengl1x/MyRenderer");

	env->RegisterNatives(cls, nm, 3);
	return JNI_VERSION_1_6;
}

void naInitGL1x(JNIEnv *env, jclass clazz){
	glDisable(GL_DITHER);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glShadeModel(GL_SMOOTH);
}

void naSurfaceChanged(JNIEnv *env, jclass clazz, int width, int height){
	glViewport(0, 0, width, height);
	float ratio = (float) width /(float) height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrthof(-ratio, ratio, -1, 1, 0, 1);
}

GLfloat trangleVertices[9] = {
	0.0f,  1.0f, 0.0f, // 0. top
	-1.0f, -1.0f, 0.0f, // 1. left-bottom
	1.0f, -1.0f, 0.0f  // 2. right-bottom
};
Triangle mTriangle(trangleVertices);

GLfloat vertices[12] = {
	-1.0f, -1.0f,  0.0f,  // 0. left-bottom
	1.0f, -1.0f,  0.0f,  // 1. right-bottom
	-1.0f,  1.0f,  0.0f,  // 2. left-top
	1.0f,  1.0f,  0.0f   // 3. right-top
};
GLfloat colors[16] = {
	1.0f, 0.0f, 0.0f, 1.0f, // Red
	0.0f, 1.0f, 0.0f, 1.0f, // Green
	0.0f, 0.0f, 1.0f, 1.0f, // Blue
	1.0f, 1.0f, 1.0f, 1.0f	// white
};
GLbyte indices[6] = {
	0, 1, 2,
	1, 2, 3
};
Square mSquare(vertices, colors, indices);

GLfloat matrix[16];
void naDrawGraphics(JNIEnv *env, jclass clazz){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.3f, 0.0f, 0.0f);
	glScalef(0.2f, 0.2f, 0.2f);
	mTriangle.draw();

	glLoadIdentity();
	glTranslatef(-0.3f, 0.0f, 0.0f);
	glScalef(0.2f, 0.2f, 0.2f);
	glRotatef(30.0, 0.0, 0.0, 1.0);//��ת30��
	mSquare.draw();
}
