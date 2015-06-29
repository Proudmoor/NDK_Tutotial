package com.zpf.cubegl1.x;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;

public class MyRenderer implements Renderer {
	public float mAngleX;
	public float mAngleY;
	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		// TODO Auto-generated method stub
		naInitGL1x();
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		// TODO Auto-generated method stub
		naSurfaceChanged(width, height);
	}

	@Override
	public void onDrawFrame(GL10 gl) {
		// TODO Auto-generated method stub
		naDrawGraphics(mAngleX, mAngleY);
	}
	
	private static native void naInitGL1x();
	private static native void naSurfaceChanged(int width, int height);
	private static native void naDrawGraphics(float AngleX, float AngleY);
	
}
