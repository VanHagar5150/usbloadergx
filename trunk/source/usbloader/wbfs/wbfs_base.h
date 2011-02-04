#ifndef _H
#define _H

#include "libs/libwbfs/libwbfs.h"
#include "usbloader/utils.h"
#include "usbloader/frag.h"

#define CACHE_SIZE      32
#define CACHED_SECTORS  64

class Wbfs
{
    public:
        Wbfs(u32, u32, u32);
        ~Wbfs() { Close(); };
        static s32 Init(u32);
        s32 CheckGame(u8 *);
        s32 GameSize(u8 *, f32 *);
        bool IsMounted() { return hdd == 0; };
        virtual int GetFragList(u8 *id) { return 0; };
        virtual bool ShowFreeSpace(void);

        virtual s32 Open() = 0;
        virtual void Close() {};
        virtual wbfs_disc_t* OpenDisc(u8 *discid) = 0;
        virtual void CloseDisc(wbfs_disc_t *disc) = 0;
        virtual s32 Format();
        virtual s32 GetCount(u32 *) = 0;
        virtual s32 GetHeaders(struct discHdr *, u32, u32) = 0;
        virtual s32 AddGame(void) = 0;
        virtual s32 RemoveGame(u8 *) = 0;
        virtual s32 DiskSpace(f32 *, f32 *) = 0;
        virtual s32 RenameGame(u8 *, const void *) = 0;
        virtual s32 ReIDGame(u8 *discid, const void *newID) = 0;
        virtual u64 EstimateGameSize(void) = 0;
        virtual const u8 GetFSType(void) const = 0;
        const wbfs_t *GetHDDHandle(void) const { return hdd; }
    protected:
        wbfs_t *hdd;
        u32 device, lba, size;
        u8 wbfs_part_fs;
};

#endif //_H
