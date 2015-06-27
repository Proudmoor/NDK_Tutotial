package com.zpf.hellondk;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import jni.getNDKStr;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		TextView tv = new TextView(this);
		tv.setTextSize(30);
		tv.setText(getNDKStr.GetString());
		setContentView(tv);
	}
	
	
	static{
		System.loadLibrary("HelloNDK");
	}

	
}
