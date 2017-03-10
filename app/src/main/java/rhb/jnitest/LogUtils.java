package rhb.jnitest;

import android.util.Log;

public class LogUtils {
    public static void log(Class clazz, String msg) {
        Log.v("JniProject", clazz.getSimpleName() + "->" + msg);
    }
}
