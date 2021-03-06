package com.zpf.parameter;

import java.nio.charset.Charset;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		StringBuilder strBuilder = new StringBuilder();
		strBuilder.append("boolean: ").append(passBoolean(false)).append(System.getProperty("line.separator"))
    	.append("byte: ").append(passByte((byte)10)).append(System.getProperty("line.separator"))
    	.append("char: ").append(passChar('#')).append(System.getProperty("line.separator"))
    	.append("short: ").append(passShort((short)100)).append(System.getProperty("line.separator"))
    	.append("int: ").append(passInt(1000)).append(System.getProperty("line.separator"))
    	.append("long: ").append(passLong(4294967396L)).append(System.getProperty("line.separator"))
    	.append("float: ").append(passFloat(1.11f)).append(System.getProperty("line.separator"))
    	.append("double: ").append(passDouble(11.11)).append(System.getProperty("line.separator"));
		
		TextView tv = (TextView) findViewById(R.id.display);
		tv.setText(strBuilder.toString());
		
		StringBuilder strNative = new StringBuilder();
		strNative.append("Android default character encoding: ").append(Charset.defaultCharset().name())
    		.append(System.getProperty("line.separator"))	
    		.append(passStringAndReturn("hello native code"));
		TextView tvNative = (TextView) findViewById(R.id.disp_string);
		tvNative.setText(strNative.toString());
	}
	
	private native boolean passBoolean(boolean p);
	private native byte    passByte(byte p);
	private native char    passChar(char p);
	private native short   passShort(short p);
	private native int     passInt(int p);
	private native long    passLong(long p);
	private native float   passFloat(float p);
	private native double  passDouble(double p);
	
	private native String  passStringAndReturn(String p);
	
	static{
		System.loadLibrary("Parameter");
	}
	
}
