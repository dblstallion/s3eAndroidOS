/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eAndroidOS.h"


#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
// For MIPs (and WP8) platform we do not have asm code for stack switching
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL_LOCK
#endif
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef const char*(*s3eAndroidOSGetManufacturer_t)();
typedef const char*(*s3eAndroidOSGetModel_t)();

/**
 * struct that gets filled in by s3eAndroidOSRegister
 */
typedef struct s3eAndroidOSFuncs
{
    s3eAndroidOSGetManufacturer_t m_s3eAndroidOSGetManufacturer;
    s3eAndroidOSGetModel_t m_s3eAndroidOSGetModel;
} s3eAndroidOSFuncs;

static s3eAndroidOSFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x4ac91e13, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3eAndroidOS");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x4ac91e13, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eAndroidOSAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

const char* s3eAndroidOSGetManufacturer()
{
    IwTrace(ANDROIDOS_VERBOSE, ("calling s3eAndroidOS[0] func: s3eAndroidOSGetManufacturer"));

    if (!_extLoad())
        return NULL;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    const char* ret = g_Ext.m_s3eAndroidOSGetManufacturer();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

const char* s3eAndroidOSGetModel()
{
    IwTrace(ANDROIDOS_VERBOSE, ("calling s3eAndroidOS[1] func: s3eAndroidOSGetModel"));

    if (!_extLoad())
        return NULL;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    const char* ret = g_Ext.m_s3eAndroidOSGetModel();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}
