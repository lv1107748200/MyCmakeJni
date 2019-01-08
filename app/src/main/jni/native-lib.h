//
// Created by 吕 on 2017/12/1.
//

#ifndef MYCMAKEJNI_NATIVE_LIB_H
#define MYCMAKEJNI_NATIVE_LIB_H

#include <jni.h>
#include <android/log.h>

#define  LOG_TAG    "sout"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

extern "C" {
JNIEXPORT jstring JNICALL
Java_com_hr_mycmakejni_MainActivity_stringFromJNI
        (JNIEnv *, jobject);

/*
 * Class:     com_hr_mycmakejni_MainActivity
 * Method:    grayProc
 * Signature: ([III)[I
 */
JNIEXPORT jintArray JNICALL
Java_com_hr_mycmakejni_MainActivity_grayProc
        (JNIEnv *, jobject, jintArray, jint, jint);

}
#endif //MYCMAKEJNI_NATIVE_LIB_H
