#include "include/text.h"

//screen width in tiles
extern u16 g_screen_width_tiles;
//screen height in tiles
extern u16 g_screen_height_tiles;

void drawTextCenter(const char *text,u16 y)
{
    VDP_drawText(text,(g_screen_width_tiles-strlen(text))/2,y);    
}

void setTextColor(u16 palette,u16 vdp_text_color)
{
    if (palette<PAL3) {
        VDP_setPaletteColor(15+16*palette,vdp_text_color);
    }
}

/**
 * Change the color for text in the palette and draw the text
 * Restore the text palette after drawing
 * */
void drawTextWithColor(const char *text,u16 xtile,u16 ytile,u16 palette,u16 vdp_text_color)
{
    if (palette<PAL3) {  
     VDP_setPaletteColor(15+16*palette,vdp_text_color);  
     u16 curTextPal=VDP_getTextPalette();
     VDP_setTextPalette(palette);
     VDP_drawText(text,xtile,ytile);
     if (palette != curTextPal)
     {
          VDP_setTextPalette(curTextPal);
     }
    }

}