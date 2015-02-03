// Example program:
// Using SDL2 to create an application window
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "sdl/SDL.h"
#include <stdio.h>
#include <string>
#include <memory>
#include "level.h"

int main(int argc, char* argv[]) {
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

        SDL_Window *window;                    // Declare a Vec2fer

        SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

        // Create an application window with the following settings:
        window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
        );

        // Check that the window was successfully made
        if (window == NULL) {
                // In the event that the window could not be made...
                printf("Could not create window: %s\n", SDL_GetError());
                return 1;
        }

		SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
		SDL_Surface* surface = SDL_GetWindowSurface(window);


		std::shared_ptr<Level> level = std::make_shared<Level>(Level(renderer));
		level->init();
		while (true) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderClear(renderer);
			level->execute();
			level->cleanup();
			SDL_RenderPresent(renderer);
		}



        // The window is open: enter program loop (see SDL_PollEvent)
        //SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example


        // Close and destroy the window
        SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);


        // Clean up
        SDL_Quit();


        return 0;
}
