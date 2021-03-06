package com.zpf.opengl1x;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;


import android.opengl.GLSurfaceView.Renderer;

public class MyRenderer implements Renderer {
	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config){
		naInitGL1x();
	}
	@Override
	public void onDrawFrame(GL10 gl){
		naDrawGraphics();
	}
	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height){
		naSurfaceChanged(width,  height);
	}
	private static native void naInitGL1x();
	private static native void naDrawGraphics();
	private static native void naSurfaceChanged(int width, int height);
	
	static{
		System.loadLibrary("OpenGL1x");
	}
}
