#ifndef _IOSLOADER_H_
#define _IOSLOADER_H_

#include <gccore.h>
#include <ogc/machine/processor.h>

#define CheckAHBPROT()	(read32(0x0D800064) == 0xFFFFFFFF)

enum MiosInfo
{
	DEFAULT_MIOS,
	DIOS_MIOS,
	DIOS_MIOS_LITE,
	QUADFORCE,
};

typedef struct _iosinfo_t
{
	u32 magicword;			  //0x1ee7c105
	u32 magicversion;		   // 1
	u32 version;				// Example: 5
	u32 baseios;				// Example: 56
	char name[0x10];			// Example: d2x
	char versionstring[0x10];   // Example: beta2
} __attribute__((packed)) iosinfo_t;

class IosLoader
{
	public:
		static s32 LoadAppCios();
		static s32 LoadGameCios(s32 ios);
		static s32 ReloadIosSafe(s32 ios);
		static s32 ReloadIosKeepingRights(s32 ios);
		static bool IsHermesIOS(s32 ios = IOS_GetVersion());
		static bool IsWaninkokoIOS(s32 ios = IOS_GetVersion());
		static bool IsD2X(s32 ios = IOS_GetVersion());
		static iosinfo_t *GetIOSInfo(s32 ios);
		static u8 GetMIOSInfo();
	private:
		static void LoadIOSModules(s32 ios, s32 ios_rev);
};

#endif
