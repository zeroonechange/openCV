#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_org_opencv_samples_facedetect_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "md 个巴子 ";
    std::int8_t id = 23;
    return env->NewStringUTF(hello.c_str());
}