#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "ventana.h"


typedef struct Widget
{
    SDL_Rect* screen_rect;
    SDL_Rect* sprite_rect;
    int number_frames;
    int actual_frame;
    SDL_Surface* frames;
} Widget;

Widget make_widget(char *src,int n_frames, SDL_Rect sprite_rect,SDL_Rect screen_rect)
{
    Widget ret;
    ret.actual_frame = 1;
    ret.frames = IMG_Load(src);
}

int draw_widget(SDL_Surface* s,Widget wid)
{
    SDL_BlitSurface(wid.frames, wid.sprite_rect, s, wid.screen_rect);
}

#endif // WIDGET_H_INCLUDED
