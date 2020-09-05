#ifndef __TEXT_INCLUDE__
#define __TEXT_INCLUDE__

#include <genesis.h>

/**
 * @param text text to be drawn
 * @param y in tiles
 * */
void drawTextCenter(const char *text,u16 y);

/**
 * Set the text color for the palette
 * @param vdp_text_color vdp color
 * */
void setTextColor(u16 palette,u16 vdp_text_color);

/**
 * Chane the color for text in the palette and draw the text
 * */
void drawTextWithColor(const char *text,u16 x_tile,u16 y_tile,u16 palette,u16 vdp_text_color);

#endif