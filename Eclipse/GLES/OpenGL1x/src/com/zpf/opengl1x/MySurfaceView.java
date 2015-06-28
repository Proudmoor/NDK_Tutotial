package com.zpf.opengl1x;

import android.content.Context;
import android.opengl.GLSurfaceView;

public class MySurfaceView extends GLSurfaceView {
	private MyRenderer mRenderer;
	
	public MySurfaceView(Context context){
		super(context);
		mRenderer = new MyRenderer();
		this.setRenderer(mRenderer);
		this.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
	}
}
