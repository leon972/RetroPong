#include <genesis.h>
#include "resources.h"
#include "include/level.h"
#include "include/text.h"

extern u16 g_screen_width_tiles; //40 (320 px)
extern u16 g_screen_height_tiles; //28 (224 px)

void Level_loadLevelAssets(Level* level)
{
    VDP_loadTileSet(tiles.tileset,TILES_BASE_IDX,DMA);    
}

void Level_setLevelPalettes(Level* level)
{
    VDP_setPalette(PAL1,tiles.palette->data);
    VDP_setPalette(PAL2,paddle1.palette->data);
}

void Level_drawFloor()
{      
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,TILE_FLOOR),0,0,g_screen_width_tiles,g_screen_height_tiles);
}

void drawWall(Wall *wall)
{
   // char a[128];
   // sprintf(a,"%d %d %d %d",wall->x,wall->y,wall->w,wall->h);
   // VDP_drawText(a,4,4);
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,TILE_WALL),wall->x,wall->y,wall->w,wall->h);    
}

void Level_drawLevel(Level *level)
{   
    SYS_disableInts();  
    VDP_clearTextArea(0,0,g_screen_width_tiles,g_screen_height_tiles);
    char t[32];   
    sprintf(t,"LEVEL %d",level->num);
    drawTextCenter(t,2);   
   // VDP_clearPlane(BG_B,TRUE);
   // VDP_clearPlane(BG_A,TRUE);
    Level_loadLevelAssets(level);
    Level_setLevelPalettes(level);
    Level_drawFloor();
    

   // VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,TILE_WALL),0,0,g_screen_width_tiles,2);
    
    for (u16 i=0;i<MAX_WALLS;++i)
    {
        if (level->walls[i].enabled)
        {                   
            drawWall(&level->walls[i]);
        }
    }  

    SYS_enableInts();  
}
