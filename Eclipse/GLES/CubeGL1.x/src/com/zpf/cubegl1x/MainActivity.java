package com.zpf.cubegl1x;


import com.zpf.cubegl1.x.R;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class MainActivity extends Activity {
	private MySurfaceView mGLView;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		mGLView = (MySurfaceView) findViewById(R.id.mySurfaceView1);	
		
	}
	@Override
	protected void onPause(){
		super.onPause();
		mGLView = (MySurfaceView) findViewById(R.id.mySurfaceView1);
		mGLView.onPause();
	}
	@Override
	protected void onResume(){
		super.onResume();
		mGLView = (MySurfaceView) findViewById(R.id.mySurfaceView1);
		mGLView.onResume();
	}
}
