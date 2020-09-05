#ifndef __LEVEL_INCLUDE__
#define  __LEVEL_INCLUDE__

#include <genesis.h>

#define TILE_FLOOR TILE_USERINDEX
#define TILE_WALL  TILE_USERINDEX+1
#define TILES_BASE_IDX TILE_FLOOR
#define MAX_WALLS 8
#define MAX_LEVELS 3

// wall block, units in tiles
typedef struct 
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    bool enabled;

} Wall;

typedef struct
{
    u16 num;
    Wall walls[MAX_WALLS];
    
} Level;


void Level_loadLevelAssets(Level* level);
void Level_setLevelPalettes(Level* level);
void Level_drawFloor();
void Level_drawLevel(Level* level);

#endif