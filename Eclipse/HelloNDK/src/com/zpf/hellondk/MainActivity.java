package com.zpf.hellondk;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import jni.InterWithNDK;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		TextView tv = new TextView(this);
		tv.setTextSize(30);
		tv.setText(InterWithNDK.GetNDKString());
		setContentView(tv);
	}
	
	static{
		System.loadLibrary("HelloNDK");
	}

	
}
