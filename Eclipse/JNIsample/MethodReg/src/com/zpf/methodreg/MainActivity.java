package com.zpf.methodreg;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {
	private TextView tv;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
        tv = (TextView) findViewById(R.id.display_res);
        callNativeMethods();
	}
	
	private void callNativeMethods(){
		int a= 10, b = 100;
		int c = NativeAdd(a,b);
		tv.setText(a + "+" + b + "=" +c);
		c = NativeMulti(a, b);
		tv.append("\n" +a + "x" +b + "=" +c);
	}
	private native int NativeAdd(int a, int b);
	private native int NativeMulti(int a, int b);
	
	static{
		System.loadLibrary("MethodReg");
	}
}
