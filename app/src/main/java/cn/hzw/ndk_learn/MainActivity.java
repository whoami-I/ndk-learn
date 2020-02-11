package cn.hzw.ndk_learn;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    private int aa = 100;
    private String s = "sss";

    public String add(int a, double b, String c) {
        return "sss";
    }

    static {
        System.loadLibrary("hello");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = findViewById(R.id.tv);
        tv.setText(getNdkText());
        ndkPrint();
        setString("llllllllll");
    }

    public native String getNdkText();

    public native void ndkPrint();

    public native void setString(String s);

    public void print() {
        Log.d(TAG, "hello world");
    }

    public static void add(int a, double b) {
        Log.d(TAG, "" + (a + b));
    }
}
