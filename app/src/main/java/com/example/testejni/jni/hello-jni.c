
#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <unistd.h>

#define  LOG_TAG    "JNIFuncionando"

#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

JNIEXPORT jstring JNICALL
Java_com_example_testejni_FirstFragment_stringFromJNI( JNIEnv* env, jobject thiz )
{
    pid_t pid = getpid();
     LOGD( "process id %d\n", pid);
    char path[64] = { 0 };

    sprintf(path, "/proc/%d/cmdline", pid);
    FILE *cmdline = fopen(path, "r");
    if (cmdline) {
        char application_id[64] = { 0 };
        fread(application_id, sizeof(application_id), 1, cmdline);
        LOGD(  "application id %s\n", application_id);
        fclose(cmdline);
    }

    LOGD("Tampering detected! Terminating...");
    return (*env)->NewStringUTF(env, "Hello from JNI ! Gilciney  Compiled with ABI ");
}