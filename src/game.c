#include "include/game.h"
#include "include/level.h"

extern u16 g_screen_width_tiles; //40 (320 px)
extern u16 g_screen_height_tiles; //28 (224 px)

void Player_setName(Player *player,const char* name)
{
    if (player && name && strlen(name)<PLAYER_NAME_SIZE-1)
    {
        memset(player->name,0,PLAYER_NAME_SIZE);
        memcpy(player->name,name,strlen(name));     
    }
}

void Game_initData(Game *game)
{
    game->currentLevel=1;
    game->player1.score=game->player2.score=0;
    game->state=GAME_SPASH_CREEN;  
    Player_setName(&game->player1,"PLAYER1");
    Player_setName(&game->player2,"CPU");  
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
               Level_drawLevel(game->currentLevel);                              
           }           
        }

        break;
        case BUTTON_UP:

        break;
        case BUTTON_DOWN:

        break;
    }

}