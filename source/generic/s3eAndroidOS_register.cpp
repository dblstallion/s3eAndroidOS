/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "s3eAndroidOS_autodefs.h"
#include "s3eEdk.h"
#include "s3eAndroidOS.h"
//Declarations of Init and Term functions
extern s3eResult s3eAndroidOSInit();
extern void s3eAndroidOSTerminate();


void s3eAndroidOSRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[1];
    funcPtrs[0] = (void*)s3eAndroidOSGetManufacturer;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[1] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("s3eAndroidOS", funcPtrs, sizeof(funcPtrs), flags, s3eAndroidOSInit, s3eAndroidOSTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int s3eAndroidOSStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&s3eAndroidOSRegisterExt;
    return 0;
}

int g_s3eAndroidOSVal = s3eAndroidOSStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    s3eAndroidOSRegisterExt();
}
#endif

#endif
