package com.zpf.cubegl1x;


import com.zpf.cubegl1.x.R;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioGroup;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
	private MySurfaceView mGLView;
	private Button        mRestButton;
	private Button 		  mFlipButton;
	private RadioGroup    mProjRadio;
	private SeekBar 	  mSeekBarX;
	private SeekBar       mSeekBarY;
	private SeekBar       mSeekBarZ;
	
	private TextView      mZAxisView;
	private TextView      mYAxisView;
	private TextView      mXAxisView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		mGLView = (MySurfaceView) findViewById(R.id.mySurfaceView1);
		
		mRestButton = (Button) findViewById(R.id.button1);
		mRestButton.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				mGLView.setAngle(0.0f, 0.0f);
				mGLView.setTrans(0.0f,0.0f, 0.0f);
				mGLView.requestRender();
				mSeekBarX.setProgress(50);
				mSeekBarY.setProgress(50);
				mSeekBarZ.setProgress(30);
				mXAxisView.setText("0");
				mYAxisView.setText("0");
				mZAxisView.setText("-3");
			}
		});
		mFlipButton = (Button) findViewById(R.id.button2);
		mFlipButton.setOnClickListener(new View.OnClickListener() {
			float x = 0.0f;
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				
				x+=180.0f;
				if(x>359.9) x = 0.0f;
				mGLView.setAngle(x, 0.0f);
				mGLView.requestRender();
	
			}
		});
		
		mProjRadio = (RadioGroup) findViewById(R.id.radioGroup1);
		mProjRadio.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
			
			@Override
			public void onCheckedChanged(RadioGroup group, int checkedId) {
				// TODO Auto-generated method stub
				if(checkedId == R.id.radio0){
					mGLView.setProj(true);
					mGLView.onPause();
					mGLView.onResume();
				}else if(checkedId == R.id.radio1){
					mGLView.setProj(false);
					mGLView.onPause();
					mGLView.onResume();
				}	
			}
		});
		
		mXAxisView = (TextView) findViewById(R.id.textViewXTrans);
		mXAxisView.setText("0");
		
		mYAxisView = (TextView) findViewById(R.id.textViewYTrans);
		mYAxisView.setText("0");
		
		mZAxisView =(TextView) findViewById(R.id.textViewZTrans);
		mZAxisView.setText("-3");
		
		mSeekBarX = (SeekBar) findViewById(R.id.seekBarXAxis);
		mSeekBarX.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
			float progressChanged=0.0f;
			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				// TODO Auto-generated method stub
				progressChanged = (progress-50)/50.0f;
				mGLView.setTrans(progressChanged, 0.0f, 0.0f);
				mXAxisView.setText(""+progressChanged);
			}
		});
		
		mSeekBarY = (SeekBar) findViewById(R.id.seekBarYAxis);
		mSeekBarY.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
			float progressChanged = 0.0f;
			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				// TODO Auto-generated method stub
				progressChanged = (progress-50)/50.0f;
				mGLView.setTrans(0.0f, progressChanged, 0.0f);
				mYAxisView.setText(""+progressChanged);
			}
		});
		mSeekBarZ = (SeekBar) findViewById(R.id.seekBarZAxis);
		mSeekBarZ.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
			float progressChanged = 0.0f;
			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				float num = -progressChanged;
				Toast.makeText(MainActivity.this, "glTranslatef(0.0f, 0.0f, "+ num + ".f);", Toast.LENGTH_SHORT).show();
				//mActionView.setText("AxisZ:");
			}
			
			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				// TODO Auto-generated method stub
				progressChanged  = progress/10.0f;
				mGLView.setTrans(0.0f, 0.0f, 3.0f-progressChanged);
				float num = -progressChanged;
				mZAxisView.setText(""+num);
				//mActionView.setText("Changing");
			}
		});
		
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
