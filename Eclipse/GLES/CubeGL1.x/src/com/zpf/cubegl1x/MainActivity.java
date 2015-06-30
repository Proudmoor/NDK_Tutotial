package com.zpf.cubegl1x;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class MainActivity extends Activity {
	private GLSurfaceView mGLView;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		mGLView = new MySurfaceView(this);
		
		setContentView(mGLView);
	}
}
