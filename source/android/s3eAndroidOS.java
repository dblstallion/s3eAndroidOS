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

import android.app.UiModeManager;

import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;

class s3eAndroidOS
{
    public static String s3eAndroidOSGetManufacturer()
    {
        return Build.MANUFACTURER;
    }
    
    public static String s3eAndroidOSGetModel()
    {
        return Build.MODEL;
    }
	
	public static int s3eAndroidOSGetUIModeType()
	{
		UiModeManager uiModeManager = (UiModeManager) LoaderAPI.getActivity().getSystemService(LoaderAPI.getActivity().UI_MODE_SERVICE);
		return uiModeManager.getCurrentModeType();
	}
}
