package com.zpf.cubegl1x;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

public class MySurfaceView extends GLSurfaceView {
	private MyRenderer mRenderer;
	
	private float mPreviousX;
	private float mPreviousY;
	private final float TOUCH_SCALE = 180.0f / 32000; 
	public MySurfaceView(Context context){
		super(context);
		mRenderer = new MyRenderer();
		this.setRenderer(mRenderer);
		this.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
	}
	
	public boolean onTouchEvent(final MotionEvent event){
		float x = event.getX();
		float y = event.getY();
		
		switch(event.getAction()){
		case MotionEvent.ACTION_MOVE:
			float dx = x - mPreviousX;
			float dy = y - mPreviousY;
			
			mRenderer.mAngleX += (dx<20?0:dx) * TOUCH_SCALE;
			mRenderer.mAngleY += (dy<20?0:dy) * TOUCH_SCALE;
			requestRender();
		}
		return true;
	}
}
