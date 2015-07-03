#include <jni.h>
#include <android/log.h>
#include <GLES/gl.h>

#include <math.h>

#include "Cube.h"

void naInitGL1x(JNIEnv* env, jclass clazz);
void naDrawGraphics(JNIEnv* env, jclass clazz, float pAngleX, float pAngleY, float pDistance,float, float,bool Proj);
void naSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height, bool Proj);

jint JNI_OnLoad(JavaVM* pVm, void* reserved)
{
	JNIEnv* env;
	if (pVm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
		 return -1;
	}
	JNINativeMethod nm[3];
	nm[0].name = "naInitGL1x";
	nm[0].signature = "()V";
	nm[0].fnPtr = (void*)naInitGL1x;
	nm[1].name = "naDrawGraphics";
	nm[1].signature = "(FFFFFZ)V";
	nm[1].fnPtr = (void*)naDrawGraphics;
	nm[2].name = "naSurfaceChanged";
	nm[2].signature = "(IIZ)V";
	nm[2].fnPtr = (void*)naSurfaceChanged;
	jclass cls = env->FindClass("com/zpf/cubegl1x/MyRenderer");
	// Register methods with env->RegisterNatives.
	env->RegisterNatives(cls, nm, 3);
	return JNI_VERSION_1_6;
}

GLfloat vertices[24] = {
	-1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f,  1.0f, -1.0f,
	-1.0f, 1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	1.0f, -1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f
};

GLfloat colors[32] = {
	0.0f,  1.0f,  0.0f,  1.0f,//0
	0.0f,  1.0f,  0.0f,  1.0f,//1
	1.0f,  0.5f,  0.0f,  1.0f,//2
	1.0f,  0.5f,  0.0f,  1.0f,//3
	1.0f,  0.0f,  0.0f,  1.0f,//4
	1.0f,  0.0f,  0.0f,  1.0f,//5
	0.0f,  0.0f,  1.0f,  1.0f,//6
	1.0f,  0.0f,  1.0f,  1.0f//7
};

GLbyte indices[36] = {
	0, 4, 5, 0, 5, 1,
	1, 5, 6, 1, 6, 2,
	2, 6, 7, 2, 7, 3,
	3, 7, 4, 3, 4, 0,
	4, 7, 6, 4, 6, 5,
	3, 0, 1, 3, 1, 2
};

Cube mCube(vertices, colors, indices);

void naInitGL1x(JNIEnv* env, jclass clazz) {
	glDisable(GL_DITHER);	//disable dither to improve performance with reduced quality
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);	//set clear value for color buffer as black
	glEnable(GL_CULL_FACE);		//enabled for better performance
	glClearDepthf(14.0f);	//set clear value [0, 1] for depth buffer as farthest
	//glEnable(GL_DEPTH_TEST);	//do depth comparison and update depth buffer
	glDepthFunc(GL_LEQUAL);		//type of depth test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading of color

	glLightModelx(GL_LIGHT_MODEL_TWO_SIDE, 0);
	float globalAmbientLight[4] = {0.5, 0.5, 0.5, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);
	//GLfloat lightOneAmbientLight[4] = {1.0, 0.0, 0.0, 1.0};
	GLfloat lightOneDiffuseLight[4] = {0.0, 1.0, 0.0, 1.0};
	GLfloat lightOneSpecularLight[4] = {0.0, 0.0, 1.0, 1.0};
	//glLightfv(GL_LIGHT0, GL_AMBIENT, lightOneAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightOneDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightOneSpecularLight);
	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void naSurfaceChanged(JNIEnv* env, jclass clazz, int width, int height, bool Perspective) {
	glViewport(0, 0, width, height);
	float ratio = (float) width / height;


    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(Perspective){
		glFrustumf(-ratio, ratio, -1.0, 1.0, 1.0, 10);
	}else{
		glOrthof(-ratio, ratio, -1.0, 1.0, -10, 10);
	}
}

void naDrawGraphics(JNIEnv* env, jclass clazz, float pAngleX, float pAngleY,
		float pXAxis,float pYAxis,float pZAxis, bool Perspective) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    	//rotate around x-axis
	//glScalef(1.0f, 1.0f, 1.0f);
	if(Perspective){
		glMatrixMode(GL_MODELVIEW);
		    glLoadIdentity();
		    glTranslatef(pXAxis, 0.0f, 0.0f);
		    glTranslatef(0.0f, pYAxis, 0.0f);
		    glTranslatef(0.0f, 0.0f, pZAxis);
		    glTranslatef(0.0f, 0.0f, -3.0f);
		    glRotatef(pAngleX, 0, 1, 0);	//rotate around y-axis
		    glRotatef(pAngleY, 1, 0, 0);
	}else{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(pXAxis, 0.0f, 0.0f);
	    glTranslatef(0.0f, pYAxis, 0.0f);
	    glTranslatef(0.0f, 0.0f, pZAxis);
	    glTranslatef(0.0f, 0.0f, -3.0f);
		glRotatef(pAngleX, 0, 1, 0);	//rotate around y-axis
		glRotatef(pAngleY, 1, 0, 0);
		glScalef(0.4f, 0.4f,0.4f);
	}
	float lightOnePosition[4] = {0.0, 0.0, 1.0, 0.0};	//final zero means light is directional, (x,y,z) indicates ray direction
		glLightfv(GL_LIGHT0, GL_POSITION, lightOnePosition);
	mCube.draw();
    mCube.lighting();

	//	w=0 to create a directional light (x,y,z is the light direction) like the sun
	//	the effect of an infinite location is that the rays of light can be considered parallel by the time they reach an object.
	//	w=1 to create a positional light like a fireball.
}



