/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include <resources.h>
#include "boot/rom_head.c"
#include "include/utils.h"
#include "include/text.h"
#include "include/game.h"
#include "include/spriteobj.h"

extern u16 g_screen_width_tiles; //40 (320 px)
extern u16 g_screen_height_tiles; //28 (224 px)

Game game;

void splashScreen()
{    
    VDP_setPalette(PAL1,splash.palette->data);
    VDP_drawImageEx(BG_B, &splash, TILE_ATTR_FULL(PAL1, 0, 0, 0, TILE_USERINDEX), Utils_centerHorizTiles(16), 2, 0,DMA);   
    drawTextCenter("Press START",15);
    VDP_drawText(rom_header.copyright,0,0);
    setTextColor(PAL0,RGB24_TO_VDPCOLOR(0x888888));
    VDP_setTextPalette(PAL0);
    
}



void out_debug_info()
{
    //40x28
    char a[32];
    // sprintf(a,"w=%d",g_screen_width_tiles);    
    // VDP_drawText(a, 1,0);
    // memset(a,0,20);
    // sprintf(a,"h=%d",g_screen_height_tiles);  
    // VDP_drawText(a, 10,0);  
    // VDP_drawText(rom_header.copyright,1,1);

    
   // VDP_drawText(game.player1.name,1,2);
}

void setupVDP()
{
   VDP_setPlanSize(64,64);
   VDP_setTextPlane(BG_A);
}

void joyHandler( u16 joy, u16 changed, u16 state)
{
	if (joy == JOY_1)
	{
		/*Set player velocity if left or right are pressed;
		 *set velocity to 0 if no direction is pressed */
		if (state & BUTTON_UP)
		{   
            Game_processInput(&game,BUTTON_UP,FALSE);
		}
		else if (state & BUTTON_DOWN)
		{
            Game_processInput(&game,BUTTON_DOWN,FALSE);			
		} 
        else if (changed & BUTTON_UP)
        {
             Game_processInput(&game,BUTTON_UP,TRUE);
        }
        else if (changed & BUTTON_DOWN)
        {
              Game_processInput(&game,BUTTON_DOWN,TRUE);
        }
        else if (state & BUTTON_START) {
           
            Game_processInput(&game,BUTTON_START,FALSE);			
		} else if (changed & BUTTON_START)        
        {
             Game_processInput(&game,BUTTON_START,TRUE);		
        }
        
	}
}

int main()
{

    Utils_init();

    //create levels structure
    //load sprites paddles and ball
    //init sprite engine
    //set player names
    Game_initData(&game);

    JOY_init();
    
    JOY_setEventHandler(&joyHandler);

    setupVDP();    

    SYS_disableInts();   

    out_debug_info();    

    splashScreen();
    
    SYS_enableInts();   

    while(1)
    {       
      
        Game_update(&game);
        SPR_update();
        VDP_waitVSync();
    }

    return (0);
}
