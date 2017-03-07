package rhb.jnitest;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.ActionBarActivity;
import android.widget.TextView;

import rhb.jnitest.iotest.IOUtils;

public class MainActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(getStringFromJNI());
        IOUtils ioUtils = new IOUtils();
        ioUtils.writeFile("" + Environment.getExternalStorageDirectory(), new byte[2]);
    }

    static {
        System.loadLibrary("sample");
    }

    public native String getStringFromJNI();
}
