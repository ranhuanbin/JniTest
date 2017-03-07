#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "LogUtils.h"

JNIEXPORT jstring JNICALL
Java_rhb_jnitest_MainActivity_getStringFromJNI(JNIEnv *env, jobject instance) {
    return (*env)->NewStringUTF(env, "Hello World");
}

JNIEXPORT void JNICALL
Java_rhb_jnitest_iotest_IOUtils_WriteFile(JNIEnv *env, jobject instance, jstring path_,jbyteArray bytes_) {
    const char *path = (*env)->GetStringUTFChars(env, path_, JNI_FALSE);
    jbyte *bytes = (*env)->GetByteArrayElements(env, bytes_, JNI_FALSE);
    FILE *file = fopen(path,"wb");
    if (file!=NULL){
        int length = strlen(bytes);
        LOGI("%s,length = %d",__FUNCTION__,length);
    }
    (*env)->ReleaseStringUTFChars(env, path_, path);
    (*env)->ReleaseByteArrayElements(env, bytes_, bytes, 0);
}