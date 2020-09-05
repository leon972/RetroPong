#include <genesis.h>
#include "resources.h"
#include "include/level.h"

extern u16 g_screen_width_tiles; //40 (320 px)
extern u16 g_screen_height_tiles; //28 (224 px)

void Level_loadLevelAssets(u16 level)
{
    VDP_loadTileSet(tiles.tileset,TILES_BASE_IDX,DMA);    
}

void Level_setLevelPalettes(u16 level)
{
    VDP_setPalette(PAL1,tiles.palette->data);
    VDP_setPalette(PAL2,paddle1.palette->data);
}

void Level_drawFloor()
{      
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,TILE_FLOOR),0,0,g_screen_width_tiles,g_screen_height_tiles);
}

void Level_drawLevel(u16 level)
{   
    SYS_disableInts();  
    VDP_clearTextArea(0,0,g_screen_width_tiles,g_screen_height_tiles);
    char t[32];
    sprintf(t,"LEVEL %d",level);
    VDP_drawTextBG(BG_A,t,0,0); 
   // VDP_clearPlane(BG_B,TRUE);
   // VDP_clearPlane(BG_A,TRUE);
    Level_loadLevelAssets(level);
    Level_setLevelPalettes(level);
    Level_drawFloor();
    SYS_enableInts();   

    switch (level)
    {
        case 1:

        break;
    }
}
