/*
java implementation of the s3eAndroidOS extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;

import android.os.Build;

class s3eAndroidOS
{
    public static String s3eAndroidOSGetManufacturer()
    {
        return Build.MANUFACTURER;
    }
}
