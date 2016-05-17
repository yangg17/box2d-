#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<stdio.h>
#include <GLFunctions.h>
#define WINDOW_TITLE "Physics Ball"
#define WIDTH 1080
#define HEIGHT 800
#define M_2_PI 60// conversion between meter and pixel
#include "physicsworld.h"
#include "obstacles.h"
#include "easymaze.h"

//the scene to store everything
Physicsworld physicsworld;

// the window we'll be rendering to
SDL_Window* gWindow = NULL;

//OpenGL context
SDL_GLContext gContext;

///---------------------------------------------------------------------------
/// @brief timerCallback, trigger when the timer has reached its elaspsed time
/// @param interval
/// @return inerval time
///--------------------------------------------------------------------------
Uint32 timerCallback(Uint32 interval, void *)
{
    physicsworld.update();;
    return interval;
}

///---------------------------------------------------------------
/// @brief This function will initalise either using SDL or OpenGL
/// @return EXIT_SUCESS or EXIT_FAILURE
///--------------------------------------------------------------
int initSDL()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }
    else
    {
        //Use OpenGL 3.1 core
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

        //Create window
        gWindow = SDL_CreateWindow( "Physics Ball",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    WIDTH,
                                    HEIGHT,
                                    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

/// ---------------------------------
/// @brief Main, the main loop
/// @param argc Not used
/// @param args Not used
/// @return EXIT_SUCESS if its true
/// ----------------------------------
int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( initSDL() == EXIT_FAILURE ) return EXIT_FAILURE;

    //Create context
    gContext = SDL_GL_CreateContext( gWindow );
    if( gContext == NULL ) return EXIT_FAILURE;

    //initalise the screen
   physicsworld.init();
    // intialise the resize windowtypedef
   physicsworld.resize(WIDTH,HEIGHT);

   //Timer for the animation
   SDL_TimerID timerID = SDL_AddTimer(15, /*elapsed time in milliseconds*/
                                    timerCallback, /*callback function*/
                                    (void*) NULL /*parameters (none)*/);

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Enable text input
    SDL_StartTextInput();

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            // The window has been resized
            if ((e.type == SDL_WINDOWEVENT) && (e.window.event == SDL_WINDOWEVENT_RESIZED)) {
                SDL_SetWindowSize(gWindow, e.window.data1, e.window.data2);
                physicsworld.resize(e.window.data1, e.window.data2);
            }
            //User requests quit
            else if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            else if( e.type == SDL_KEYDOWN)
            {
              switch (e.key.keysym.sym)
              {
              case SDLK_ESCAPE :
                quit=1;
                break;
              case SDLK_l:
                physicsworld.addPinkObject(Vec4(1.0,10.0,0.0),Vec4(-0.02f,0.0f,0.0f));
                break;
              case SDLK_o:
                physicsworld.addBlueObject(Vec4(1.0,10.0,0.0),Vec4(-0.02f,0.0f,0.0f));
                break;
              case SDLK_v:
                physicsworld.addYellowObject(Vec4(1.0,10.0,0.0),Vec4(-0.02f,0.0f,0.0f));
                break;
              case SDLK_e:
                physicsworld.addWhiteObject(Vec4(1.0,10.0,0.0),Vec4(-0.02f,0.0f,0.0f));
                break;

              }
            }

        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //Set Background colour
        glClearColor(0.0f,0.0f,0.0f,1.0f);



        //Render the scene
        physicsworld.draw();

        //Update screen
        SDL_GL_SwapWindow( gWindow );
    }

    //Disable text input
    SDL_StopTextInput();
    //Remove timer
    SDL_RemoveTimer(timerID);

    //Destroy window
    SDL_DestroyWindow( gWindow );

    //Quit SDL subsystems
    SDL_Quit();

    return EXIT_SUCCESS;
}





