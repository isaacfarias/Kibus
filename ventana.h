#ifndef VENTANA_H_INCLUDED
#define VENTANA_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "Widget.h"
typedef struct Ventana
{
    int error;
    SDL_Surface* screen;
    SDL_Surface* background;
    Widget up_row;
    Widget down_row;
    Widget left_row;
    Widget right_row;
    int n_widgets;
} Ventana;



Ventana init_ventana(char* background)
{
    Ventana ret;
    ret.error = 0;
    ret.n_widgets = 0;
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        #ifdef debug
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        #endif
        ret.error = 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    ret.background = IMG_Load(background);
    if(!ret.background)
        {
            #ifdef debug
            printf("Unable to load background: %s\n", IMG_GetError());
            #endif // debug
            ret.error  = 2;
        }
        else
        {
            ret.screen  = SDL_SetVideoMode(ret.background->w, ret.background->h, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
           if ( !ret.screen)
            {
                #ifdef debug
                printf("Unable to set video: %s\n", SDL_GetError());
                #endif // debug
                ret.error  = 2;
            }
            else
            {
                SDL_BlitSurface(ret.background, NULL, ret.screen, NULL);
            }
        }


    #ifdef debug
    if(!ret.error)
    {
        printf("Video and window created without errors\n");
    }
    #endif // debug
    SDL_Rect tmp_rect;
    tmp_rect.h = 64;
    tmp_rect.w = 64;
    tmp_rect.x = 0;
    tmp_rect.y = 0;

    SDL_Rect tmp_rect2;
    tmp_rect.h = 64;
    tmp_rect.w = 64;
    tmp_rect.x = 4*32;
    tmp_rect.y = 3*32;
    ret.up_row = make_widget("images/up_row.png",3,tmp_rect,tmp_rect2);
    return ret;
}

void end_ventana(Ventana v)
{
    SDL_FreeSurface(v.background);
    SDL_FreeSurface(v.screen);

}

#endif // VENTANA_H_INCLUDED
