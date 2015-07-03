package com.zpf.cubegl1x;



import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;
import android.view.MotionEvent;

public class MySurfaceView extends GLSurfaceView {
	private MyRenderer mRenderer;
	
	private float mPreviousX;
	private float mPreviousY;
	private final float TOUCH_SCALE = 180.0f / 320; 
    public MySurfaceView(Context context, AttributeSet attri) {
	        super(context, attri);
	        mRenderer = new MyRenderer();
			this.setRenderer(mRenderer);
			this.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
	    }
	
	public boolean onTouchEvent(final MotionEvent event){
		float x = event.getX();
		float y = event.getY();
		
		switch(event.getAction()){
		case MotionEvent.ACTION_MOVE:
			float dx = x - mPreviousX;
			float dy = y - mPreviousY;
			
			mRenderer.mAngleX += dx * TOUCH_SCALE;
			mRenderer.mAngleY += dy * TOUCH_SCALE;
			requestRender();
		}
		mPreviousX = x;
		mPreviousY = y;
		return true;
	}
	public void setAngle(final float x, final float y){
		mRenderer.mAngleX = x;
		mRenderer.mAngleY = y;
	}
	public void setTrans(final float x, final float y,final float z){
		mRenderer.mDistanceX = x;
		mRenderer.mDistanceY = y;
		mRenderer.mDistanceZ = z;
	}
	public void setProj(boolean pro){
		mRenderer.mProjection = pro;
	}
}
