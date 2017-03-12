#include <jni.h>
#include "LogUtils.h"
#include "FilePerform.h"
#include <stdio.h>
#include <stdlib.h>

#define FALSE JNI_FALSE

JNIEXPORT void JNICALL
Java_rhb_jnitest_BaseType_writeInt(JNIEnv *env, jobject instance, jint num) {
    int n = num;
    LOGI("%s,n=%d", __FUNCTION__, n);
}

JNIEXPORT void JNICALL
Java_rhb_jnitest_BaseType_writeByte(JNIEnv *env, jobject instance, jbyte bys) {
    char chs = bys;
    LOGI("%s,chs = %d", __FUNCTION__, chs);
}

JNIEXPORT void JNICALL
Java_rhb_jnitest_BaseType_writeString(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = (*env)->GetStringUTFChars(env, msg_, FALSE);
    LOGI("%s,msg = %s", __FUNCTION__, msg);
    (*env)->ReleaseStringUTFChars(env, msg_, msg);
}

JNIEXPORT jstring JNICALL
Java_rhb_jnitest_BaseType_getString(JNIEnv *env, jobject instance) {
    return (*env)->NewStringUTF(env, "this String comes from C");
}

JNIEXPORT jbyteArray JNICALL
Java_rhb_jnitest_BaseType_writeByteArray(JNIEnv *env, jobject instance, jbyteArray bys_) {
    LOGI("[%s] ", __FUNCTION__);
    jbyte *bys = (*env)->GetByteArrayElements(env, bys_, FALSE);
    jsize length = (*env)->GetArrayLength(env, bys_);
    for (int i = 0; i < length; ++i) {
        LOGI("[%s] bys[%d]=%d\n", __FUNCTION__, i, bys[i]);
    }
    char chs[length];
    memset(chs, 0, sizeof(chs));
    memcpy(chs, bys, sizeof(chs));
//    for (int i = 0; i < length; ++i) {
//        chs[length - i - 1] = bys[i];
//        LOGI("chs[%d]=%d\n", i, chs[i]);
//    }
    jbyteArray bytes = (*env)->NewByteArray(env, length);
    (*env)->SetByteArrayRegion(env, bytes, 0, length, (const jbyte *) chs);
    (*env)->ReleaseByteArrayElements(env, bys_, bys, 0);
    return bytes;
}

JNIEXPORT int JNICALL
Java_rhb_jnitest_iotest_IOUtils_WriteFile(JNIEnv *env, jobject instance, jstring path_,
                                          jstring msg_) {
    const char *path = (*env)->GetStringUTFChars(env, path_, 0);
    const char *msg = (*env)->GetStringUTFChars(env, msg_, 0);
    int result = writeFile(path, msg);
    (*env)->ReleaseStringUTFChars(env, path_, path);
    (*env)->ReleaseStringUTFChars(env, msg_, msg);
    return result;
}

JNIEXPORT jstring JNICALL
Java_rhb_jnitest_iotest_IOUtils_ReadFile(JNIEnv *env, jobject instance, jstring path_) {
    const char *path = (*env)->GetStringUTFChars(env, path_, 0);
    char *ch = readFile(path);
    (*env)->ReleaseStringUTFChars(env, path_, path);
    return (*env)->NewStringUTF(env, ch);
}