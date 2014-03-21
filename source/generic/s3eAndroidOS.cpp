/*
Generic implementation of the s3eAndroidOS extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eAndroidOS_internal.h"
s3eResult s3eAndroidOSInit()
{
    //Add any generic initialisation code here
    return s3eAndroidOSInit_platform();
}

void s3eAndroidOSTerminate()
{
    //Add any generic termination code here
    s3eAndroidOSTerminate_platform();
}

const char* s3eAndroidOSGetManufacturer()
{
	return s3eAndroidOSGetManufacturer_platform();
}
