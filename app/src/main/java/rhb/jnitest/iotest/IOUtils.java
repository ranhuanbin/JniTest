package rhb.jnitest.iotest;

public class IOUtils {
    static {
        System.loadLibrary("sample");
    }

    public native void WriteFile(String path, String msg);

//    public void writeFile(String path, byte[] bytes) {
//        WriteFile(path, bytes);
//    }
}
