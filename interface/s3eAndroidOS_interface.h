/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef const char*(*s3eAndroidOSGetManufacturer_t)();
typedef const char*(*s3eAndroidOSGetModel_t)();
typedef        int(*s3eAndroidOSGetUIModeType_t)();

/**
 * struct that gets filled in by s3eAndroidOSRegister
 */
typedef struct s3eAndroidOSFuncs
{
    s3eAndroidOSGetManufacturer_t m_s3eAndroidOSGetManufacturer;
    s3eAndroidOSGetModel_t m_s3eAndroidOSGetModel;
    s3eAndroidOSGetUIModeType_t m_s3eAndroidOSGetUIModeType;
} s3eAndroidOSFuncs;
