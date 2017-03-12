package rhb.jnitest.iotest;

public class IOUtils {
    static {
        System.loadLibrary("sample");
    }

    public boolean writeFile(String path, String msg) {
        int result = WriteFile(path, msg);
        return result == 1;
    }

    public String readFile(String path) {
        return ReadFile(path);
    }

    public native int WriteFile(String path, String msg);

    public native String ReadFile(String path);
}
