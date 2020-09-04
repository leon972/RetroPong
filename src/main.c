/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include <resources.h>
#include "utils.h"

extern u16 g_screen_width_tiles; //320
extern u16 g_screen_height_tiles; //224

void splashScreen()
{
    VDP_setPalette(PAL1,splash.palette->data);
    VDP_drawImageEx(BG_B, &splash, TILE_ATTR_FULL(PAL1, 0, 0, 0, TILE_USERINDEX), Utils_centerHorizTiles(10), 2, 0,DMA);
    Utils_drawTextCenter("Press START",15);
}

void out_debug_info()
{
    char a[20];
    sprintf(a,"w=%d",g_screen_width_tiles);    
    VDP_drawText(a, 1,0);
    memset(a,0,20);
    sprintf(a,"h=%d",g_screen_height_tiles);  
    VDP_drawText(a, 10,0);  

}

int main()
{

    Utils_init();

    SYS_disableInts();

    out_debug_info();    

    splashScreen();
    
    SYS_enableInts();

    while(1)
    {
        VDP_waitVSync();
    }
    return (0);
}
