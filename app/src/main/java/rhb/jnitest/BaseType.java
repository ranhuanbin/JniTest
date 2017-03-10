package rhb.jnitest;


public class BaseType {
    static {
        System.loadLibrary("sample");
    }

    public native void writeInt(int num);

    public native void writeByte(byte bys);

    public native void writeString(String msg);

    public native String getString();

    public native byte[] writeByteArray(byte[] bys);
}
