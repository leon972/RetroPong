
#include "include/spriteobj.h"
#include <genesis.h>

 /**
  * Init a sprite object
  **/
 void Sprite_init(SpriteObj *spr,const SpriteDefinition *sprite,int palette,unsigned priority,fix16 x,fix16 y,fix16 vel_x,fix16 vel_y)
 {
     spr->frame=0;
     spr->sprite=SPR_addSprite(sprite,fix16ToInt(x),fix16ToInt(y),TILE_ATTR(palette,priority,FALSE,FALSE));
     spr->x=x;
     spr->y=y;
     spr->vel_x=vel_x;
     spr->vel_y=vel_y;   
 }

 /**
  * Update the sprite position
  */ 
 void Sprite_updatePos(SpriteObj *spr)
 {
     spr->x=fix16Add(spr->x,spr->vel_x);
     spr->y=fix16Add(spr->y,spr->vel_y);
     SPR_setPosition(spr->sprite,fix16ToRoundedInt(spr->x),fix16ToRoundedInt(spr->y));
 
 }

 /**
  * Set the sprite velocity
  */
 void Sprite_setVelocity(SpriteObj *spr,fix16 vx,fix16 vy)
 {
     spr->vel_x=vx;
     spr->vel_y=vy;
     
 }

 void  Sprite_setPosition(SpriteObj *spr,fix16 x,fix16 y)
 {
     spr->x=x;
     spr->y=y;
     SPR_setPosition(spr->sprite,fix16ToRoundedInt(x),fix16ToRoundedInt(y));
 }