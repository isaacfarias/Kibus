#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#define debug

#include <SDL/SDL.h>
#include "ventana.h"



int main ( int argc, char** argv )
{
    // initialize SDL video
    Ventana ventana =  init_ventana("images/background.png");

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        //SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // draw bitmap
        //

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(ventana.screen);
    } // end main loop

    // free loaded bitmap
    end_ventana(ventana);

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
