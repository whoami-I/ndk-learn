//
// Created by user on 20-2-11.
//
#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring
Java_cn_hzw_ndk_1learn_MainActivity_getNdkText(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

