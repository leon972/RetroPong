#include "include/utils.h"

//screen width in tiles
u16 g_screen_width_tiles;
//screen height in tiles
u16 g_screen_height_tiles;

void Utils_init()
{
    g_screen_width_tiles=VDP_getScreenWidth()/8;
    g_screen_height_tiles=VDP_getScreenHeight()/8;
}

u16 Utils_centerHorizTiles(u16 len)
{
    return (g_screen_width_tiles-len)/2;
}


