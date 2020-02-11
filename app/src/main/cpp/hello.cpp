//
// Created by user on 20-2-11.
//
#include <jni.h>
#include <string>
#include <android/log.h>

#define TAG "projectname" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型


extern "C" JNIEXPORT jstring JNICALL
Java_cn_hzw_ndk_1learn_MainActivity_getNdkText(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_cn_hzw_ndk_1learn_MainActivity_ndkPrint(JNIEnv *env, jobject thiz) {
    jclass jclazz = env->GetObjectClass(thiz);
    jmethodID methodId = env->GetMethodID(jclazz, "print", "()V");
    env->CallVoidMethod(thiz, methodId);

    jmethodID methodId2 = env->GetStaticMethodID(jclazz, "add", "(ID)V");
    env->CallStaticVoidMethod(jclazz, methodId2, 1, 2.3);

    jfieldID jfieldId = env->GetFieldID(jclazz, "aa", "I");
    jint aa = env->GetIntField(thiz, jfieldId);
    LOGD("aa=%d\n", aa);

    jclass clz = env->FindClass("cn/hzw/ndk_learn/MainActivity");
    if (clz == jclazz) {
        LOGD("find class\n");
    }
    methodId2 = env->GetStaticMethodID(clz, "add", "(ID)V");
    env->CallStaticVoidMethod(jclazz, methodId2, 1, 2.3);

}extern "C"
JNIEXPORT void JNICALL
Java_cn_hzw_ndk_1learn_MainActivity_setString(JNIEnv *env, jobject thiz, jstring s) {
    jboolean b = true;
    const char *ss = env->GetStringUTFChars(s, &b);
    LOGD("%s\n", ss);
}