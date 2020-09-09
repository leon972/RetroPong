#include "include/game.h"
#include "include/level.h"
#include "include/spriteobj.h"
#include "resources.h"

// first level
#define START_LEVEL 1
// tile index start for sprites
#define SPRITE_INDEX 30


#define PADDLE_SIZE 32 //pixels
#define PLAYER_IDLE_Y (g_screen_height - PADDLE_SIZE)/2
#define PLAYER_BORDER 40 //pixels
#define PLAYER1_X g_screen_width-PLAYER_BORDER
#define PLAYER2_X PLAYER_BORDER 
#define BALL_IDLE_X g_screen_width/2
#define BALL_IDLE_Y g_screen_height/2

extern u16 g_screen_width_tiles; //40 (320 px)
extern u16 g_screen_height_tiles; //28 (224 px)
extern u16 g_screen_width;
extern u16 g_screen_height;

static Level levels[MAX_LEVELS];

static bool gameInitialized=FALSE;

static SpriteObj ballSpr;
static SpriteObj paddle1Spr;
static SpriteObj paddle2Spr;

 //CPU

static const u16 spritePalette[]={RGB24_TO_VDPCOLOR(0x000000), RGB24_TO_VDPCOLOR(0xa63b03), 
RGB24_TO_VDPCOLOR(0xe5773d), RGB24_TO_VDPCOLOR(0xe6e4ff), 
RGB24_TO_VDPCOLOR(0xb7b4ea), RGB24_TO_VDPCOLOR(0x29318b),
 RGB24_TO_VDPCOLOR(0x6e78f2),RGB24_TO_VDPCOLOR(0x29318B),
 RGB24_TO_VDPCOLOR(0x6E78F2),RGB24_TO_VDPCOLOR(0x74DBF7),
 RGB24_TO_VDPCOLOR(0xFF5252),RGB24_TO_VDPCOLOR(0xFFB500),
 RGB24_TO_VDPCOLOR(0xFFFE6E),RGB24_TO_VDPCOLOR(0x84941B),
 RGB24_TO_VDPCOLOR(0x80711E),RGB24_TO_VDPCOLOR(0x0C723B)};

void initLevels()
{
    memset(levels,0,sizeof(Level));
    levels[0].num=1;
    levels[0].walls[0].enabled=TRUE;
    levels[0].walls[0].w=g_screen_width_tiles;
    levels[0].walls[0].h=1;
    levels[0].walls[0].x=0;
    levels[0].walls[0].y=0;
    levels[0].walls[1].enabled=TRUE;
    levels[0].walls[1].w=g_screen_width_tiles;
    levels[0].walls[1].h=1;
    levels[0].walls[1].x=0;
    levels[0].walls[1].y=g_screen_height_tiles-1;
}


void loadSprites()
{
   PAL_setColors(16*PAL3,spritePalette,16);  
   Sprite_init(&ballSpr,&ball,PAL3,1,FIX16(308.0),FIX16(308.0),FIX16(0.0),FIX16(0.0));    
   Sprite_init(&paddle1Spr,&paddle1,PAL3,1,FIX16(380.0),FIX16(380.0),FIX16(0.0),FIX16(0.0));    
   Sprite_init(&paddle2Spr,&paddle2,PAL3,1,FIX16(380.0),FIX16(380),FIX16(0.0),FIX16(0.0));     
}

void resetBallPosition()
{
    Sprite_setVelocity(&ballSpr,FIX16(0.0),FIX16(0.0));
    Sprite_setPosition(&ballSpr,intToFix16(BALL_IDLE_X),intToFix16(BALL_IDLE_Y));
}

void Player_setName(Player *player,const char* name)
{
    if (player && name && strlen(name)<PLAYER_NAME_SIZE-1)
    {
        memset(player->name,0,PLAYER_NAME_SIZE);
        memcpy(player->name,name,strlen(name));     
    }
}

/**
 * After 
 * */
void initGameSet(Game* game,Player *opponent)
{
    resetBallPosition();
    Sprite_setPosition(game->player1.sprite,intToFix16(PLAYER1_X),intToFix16(PLAYER_IDLE_Y));
    Sprite_setPosition(game->player2.sprite,intToFix16(PLAYER2_X),intToFix16(PLAYER_IDLE_Y));
    fix16 vx,vy;
    if ((opponent->sprite->x-ballSpr.x)>0)
    {
        vx=FIX16(4.0);vy=FIX16(-2.0);        
    }
    else 
    {
        vx=FIX16(-4.0);vy=FIX16(2.0);
    }
    Sprite_setVelocity(&ballSpr,vx,vy);
}

/**
 * Game begin reset score and positions
 * */
void initGame(Game *game)
{
    game->currentLevel=START_LEVEL;
    game->player1.score=game->player2.score=0;  
    initGameSet(game,&game->player1);
}

void Game_initData(Game *game)
{
    if (!gameInitialized) {
        initLevels();             
        Player_setName(&game->player1,"PLAYER1");
        Player_setName(&game->player2,"CPU");  
        // sprite engine init
        SPR_init(0,0,0);
        loadSprites();     
        game->player1.sprite=&paddle1Spr;
        game->player2.sprite=&paddle2Spr;    
        gameInitialized=TRUE;     
        //initGame(game);                
    }
}

bool Game_changeState(Game *game,u16 nextState)
{
    const u16 curState=game->state;

    switch (curState)
    {
        case GAME_SPASH_CREEN:
            if (nextState==GAME_PLAYING)
            {
                game->state=nextState;
                return TRUE;
            }
        break;
        case GAME_PLAYING:
        if (nextState==GAME_GAME_OVER || nextState==GAME_PAUSED)
        {
            game->state=nextState;
            return TRUE;
        }
        break;
        case GAME_GAME_OVER:
        if (nextState==GAME_SPASH_CREEN)
        {
            game->state=nextState;
            return TRUE;
        }
        break;
        case GAME_PAUSED:
        {
            if (nextState==GAME_PLAYING)
            {
                game->state=nextState;
                return TRUE;
            }
        }

        break;
    }

    return FALSE;

}

void Game_processInput(Game *game,u16 button)
{
    switch (button)
    {
        case BUTTON_START:        

        if (game->state==GAME_SPASH_CREEN)
        {
           if (Game_changeState(game,GAME_PLAYING))
           {   
               SYS_disableInts();   
               initGame(game);                 
               Level_drawLevel(&levels[game->currentLevel-1]);  
               SYS_enableInts();    
                                   
           }           
        }

        break;
        case BUTTON_UP:

        break;
        case BUTTON_DOWN:

        break;
    }

}