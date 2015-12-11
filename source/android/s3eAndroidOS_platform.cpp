/*
 * android-specific implementation of the s3eAndroidOS extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eAndroidOS_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jclass g_s3eAndroidOSClass;
static jobject g_Obj;
static jmethodID g_s3eAndroidOSGetManufacturerHelper;
static jmethodID g_s3eAndroidOSGetModelHelper;
static jmethodID g_s3eAndroidOSGetUIModeType;

s3eResult s3eAndroidOSInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    g_s3eAndroidOSClass = s3eEdkAndroidFindClass("s3eAndroidOS");
    if (!g_s3eAndroidOSClass)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(g_s3eAndroidOSClass, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(g_s3eAndroidOSClass, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_s3eAndroidOSGetManufacturerHelper = env->GetStaticMethodID(g_s3eAndroidOSClass, "s3eAndroidOSGetManufacturer", "()Ljava/lang/String;");
    if (!g_s3eAndroidOSGetManufacturerHelper)
        goto fail;

    g_s3eAndroidOSGetModelHelper = env->GetStaticMethodID(g_s3eAndroidOSClass, "s3eAndroidOSGetModel", "()Ljava/lang/String;");
    if (!g_s3eAndroidOSGetModelHelper)
        goto fail;
	
	g_s3eAndroidOSGetUIModeType = env->GetStaticMethodID(g_s3eAndroidOSClass, "s3eAndroidGetUIModeType", "()I;");
    if (!g_s3eAndroidOSGetUIModeType)
        goto fail;


    IwTrace(ANDROIDOS, ("ANDROIDOS init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(g_s3eAndroidOSClass);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eAndroidOS, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void s3eAndroidOSTerminate_platform()
{
    // Add any platform-specific termination code here
}

static char manufacturer[128];
const char* s3eAndroidOSGetManufacturer_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring manufacturerJString = (jstring)env->CallStaticObjectMethod(g_s3eAndroidOSClass, g_s3eAndroidOSGetManufacturerHelper);
    const char* manufacturerCString = env->GetStringUTFChars(manufacturerJString, 0);
    
    strncpy(manufacturer, manufacturerCString, sizeof(manufacturer));
    
    env->ReleaseStringUTFChars(manufacturerJString, manufacturerCString);
    env->DeleteLocalRef(manufacturerJString);
    
    return manufacturer;
}

static char model[128];
const char* s3eAndroidOSGetModel_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring modelJString = (jstring)env->CallStaticObjectMethod(g_s3eAndroidOSClass, g_s3eAndroidOSGetModelHelper);
    const char* modelCString = env->GetStringUTFChars(modelJString, 0);
    
    strncpy(model, modelCString, sizeof(model));
    
    env->ReleaseStringUTFChars(modelJString, modelCString);
    env->DeleteLocalRef(modelJString);
    
    return model;
}

int s3eAndroidOSGetUIModeType_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallStaticIntMethod(g_s3eAndroidOSClass, g_s3eAndroidOSGetUIModeType);
}
