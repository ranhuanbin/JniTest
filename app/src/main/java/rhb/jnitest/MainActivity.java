package rhb.jnitest;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;

public class MainActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        BaseType baseType = new BaseType();
        baseType.writeInt(10);
        baseType.writeByte((byte) 5);
        baseType.writeString("This String comes from java");
        String msg = baseType.getString();
        LogUtils.log(getClass(), "msg:" + msg);
        byte[] bys = {1, 2, 3};
        byte[] bytes = baseType.writeByteArray(bys);
        for (int i = 0; i < bytes.length; i++) {
            LogUtils.log(getClass(), "bytes[" + i + "]=" + bytes[i]);
        }
    }
}
