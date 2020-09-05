/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include <resources.h>
#include "include/utils.h"
#include "include/text.h"
#include "boot/rom_head.c"


extern u16 g_screen_width_tiles; //40 (320 px)
extern u16 g_screen_height_tiles; //28 (224 px)


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
    char a[20];
    sprintf(a,"w=%d",g_screen_width_tiles);    
    VDP_drawText(a, 1,0);
    memset(a,0,20);
    sprintf(a,"h=%d",g_screen_height_tiles);  
    VDP_drawText(a, 10,0);  
    VDP_drawText(rom_header.copyright,1,1);

}

void setupVDP()
{
   VDP_setPlanSize(64,64);
   VDP_setTextPlane(WINDOW);
}

int main()
{

    Utils_init();

    SYS_disableInts();   

    //out_debug_info();    

    splashScreen();
    
    SYS_enableInts();

    while(1)
    {
        VDP_waitVSync();
    }
    return (0);
}
