#include "include/utils.h"

//screen width in tiles
u16 g_screen_width_tiles; //40
//screen height in tiles
u16 g_screen_height_tiles; //28
//screen width in pixel
u16 g_screen_width;  //320
//screen height in pixel
u16 g_screen_height; //224

void Utils_init()
{
    g_screen_width=VDP_getScreenWidth();
    g_screen_width_tiles=g_screen_width/8;
    g_screen_height=VDP_getScreenHeight();
    g_screen_height_tiles=g_screen_height/8;
}

u16 Utils_centerHorizTiles(u16 len)
{
    return (g_screen_width_tiles-len)/2;
}


