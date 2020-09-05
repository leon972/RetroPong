#ifndef __GAME_INCLUDE__
#define __GAME_INCLUDE__

#include <genesis.h>

//game states
#define GAME_SPASH_CREEN 0
#define GAME_PLAYING 1
#define GAME_GAME_OVER 2
#define GAME_PAUSED 3

#define PLAYER_NAME_SIZE 16
#define PADDLE_SIZE 4

typedef struct 
{
    u16 score;
    char name[PLAYER_NAME_SIZE];
    u16 paddle_y; //y pos in px

} Player;

typedef struct 
{
    Player player1;
    Player player2;
    u16 state;

} Game;

void Game_initData(Game *game);
bool Game_changeState(Game *game,u16 nextState);
void Game_processInput(Game *game,u16 button);
void Player_setName(Player *player,const char* name);

#endif