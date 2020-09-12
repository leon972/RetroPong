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
 void Sprite_updatePosByVelocity(SpriteObj *spr);

 /**
  * Set the sprite velocity
  */
 void Sprite_setVelocity(SpriteObj *spr,fix16 vx,fix16 vy);

 /**
  * Set the x component of velocity
  **/
 void Sprite_setVelocityX(SpriteObj *spr,fix16 vx);

  /**
  * Set the x component of velocity
  **/
 void Sprite_setVelocityY(SpriteObj *spr,fix16 vy);

 /**
  * Set the sprite position
  */
 void Sprite_setPosition(SpriteObj *spr,fix16 x,fix16 y);

 void Sprite_incXPos(SpriteObj *spr,fix16 deltaX);

 void Sprite_incYPos(SpriteObj *spr,fix16 deltaY);

 void Sprite_setXPos(SpriteObj *spr,fix16 x);

 void Sprite_setYPos(SpriteObj *spr,fix16 y);

 /**
  * Update the position of the wrapped Sprite
  * Call this function after Sprite_updatePosByVelocity or changing sprite position directly
  * */
 void Sprite_update(SpriteObj *spr);

#endif

