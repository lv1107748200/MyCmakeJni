#include <jni.h>
#include <string>
#include <opencv2/core/core.hpp>
#include "../jni/native-lib.h"

using namespace std;
using namespace cv;

JNIEXPORT jstring JNICALL
Java_com_hr_mycmakejni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jintArray JNICALL
Java_com_hr_mycmakejni_MainActivity_grayProc(
        JNIEnv *env,
        jobject instance,
        jintArray buf,
        jint w,
        jint h) {

    LOGE("开始");

    jint *cbuf;
    jboolean ptfalse = false;
    cbuf = env->GetIntArrayElements(buf, &ptfalse);
    if(cbuf == NULL){
        return 0;
    }

    Mat imgData(h, w, CV_8UC4, (unsigned char*)cbuf);

    uchar* ptr = imgData.ptr(0);
    for(int i = 0; i < w*h; i ++){
        uchar grayScale = (uchar)(ptr[4*i+2]*0.299 + ptr[4*i+1]*0.587 + ptr[4*i+0]*0.114);
        ptr[4*i+1] = grayScale;
        ptr[4*i+2] = grayScale;
        ptr[4*i+0] = grayScale;
    }

    int size=w * h;
    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, cbuf);
    env->ReleaseIntArrayElements(buf, cbuf, 0);

    LOGE("结束");
    return result;
}

