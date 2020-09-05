#ifndef __LEVEL_INCLUDE__
#define  __LEVEL_INCLUDE__

#include <genesis.h>

#define TILE_FLOOR TILE_USERINDEX
#define TILE_WALL  TILE_USERINDEX+1
#define TILES_BASE_IDX TILE_FLOOR

// wall block, units in tiles
typedef struct 
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;

} Wall;

void Level_loadLevelAssets(u16 level);
void Level_setLevelPalettes(u16 level);
void Level_drawFloor();
void Level_drawLevel(u16 level);

#endif