
#include "include/spriteobj.h"
#include <genesis.h>

void Sprite_update(SpriteObj *spr)
{
     SPR_setPosition(spr->sprite,fix16ToRoundedInt(spr->x),fix16ToRoundedInt(spr->y));
}

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

 void Sprite_updatePosByVelocity(SpriteObj *spr)
 {
     spr->x=fix16Add(spr->x,spr->vel_x);
     spr->y=fix16Add(spr->y,spr->vel_y);       
 }

 void Sprite_setVelocity(SpriteObj *spr,fix16 vx,fix16 vy)
 {
     spr->vel_x=vx;
     spr->vel_y=vy;
     
 }

 void Sprite_setVelocityX(SpriteObj *spr,fix16 vx)
 {
     spr->vel_x=vx;
 }


 void Sprite_setVelocityY(SpriteObj *spr,fix16 vy)
 {
     spr->vel_y=vy;
 }

 void  Sprite_setPosition(SpriteObj *spr,fix16 x,fix16 y)
 {
     spr->x=x;
     spr->y=y;    
 }
 
 void Sprite_incXPos(SpriteObj *spr,fix16 deltaX)
 {
     spr->x=fix16Add(spr->x,deltaX);  
 }

 void Sprite_incYPos(SpriteObj *spr,fix16 deltaY)
 {
     spr->y=fix16Add(spr->y,deltaY);
    //  char a[32];
    // sprintf(a,"%d",fix16ToInt(spr->y));
    //   VDP_drawText(a,10,7);
    // VDP_clearText(10,7,10);
   

 }


 void Sprite_setXPos(SpriteObj *spr,fix16 x)
 {
     spr->x=x;
  
 }

 void Sprite_setYPos(SpriteObj *spr,fix16 y)
 {
     spr->y=y;    
 }