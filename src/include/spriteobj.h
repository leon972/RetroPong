/**
 * Sprite wrapper
 * 
 * */

#ifndef __SPRTEOBJ_INCLUDE__
#define __SPRTEOBJ_INCLUDE__
 
 #include <genesis.h>

 typedef struct 
 {
     Sprite *sprite;
     fix16 x; //pixels
     fix16 y; //pixels
     // object velocity
     fix16 vel_x; //pixels/cycle
     fix16 vel_y; //pixels/cycle
     int frame;

 } SpriteObj;

 /**
  * Init a sprite object
  **/
 void Sprite_init(SpriteObj *spr,const SpriteDefinition *sprite,int palette,unsigned priority,fix16 x,fix16 y,fix16 vel_x,fix16 vel_y);

 /**
  * Update the sprite position
  */ 
 void Sprite_updatePos(SpriteObj *spr);

 /**
  * Set the sprite velocity
  */
 void Sprite_setVelocity(SpriteObj *spr,fix16 vx,fix16 vy);

 /**
  * Set the sprite position
  */
 void  Sprite_setPosition(SpriteObj *spr,fix16 x,fix16 y);

#endif

