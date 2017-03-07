package rhb.jnitest.iotest;

public class IOUtils {
    public native void WriteFile(String path, byte[] bytes);

    public void writeFile(String path, byte[] bytes) {
        WriteFile(path, bytes);
    }
}
