// Lesson 1
// Open a SDL window and fill the background with red

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL.h>
#include <glib.h>
#include <glib-object.h>

static const int width = 800;
static const int height = 600;

gint _vala_main (const gchar* args, int args_length1);

int main(int argc, char **argv)
{
	return _vala_main (argv, argc);
    // Initialize SDL
//    SDL_Init(SDL_INIT_VIDEO);
//
//    // Create a SDL window
//    SDL_Window *window = SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
//
//    // Create a renderer (accelerated and in sync with the display refresh rate)
//    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//
//    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//    bool running = true;
//    int index = 0;
//    SDL_Event event;
//    while(running)
//    {
//        // Process events
//        while(SDL_PollEvent(&event))
//        {
//            switch (event.type) {
//                case SDL_QUIT:
//                    running = false;
//                    break;
//                case SDL_MOUSEBUTTONDOWN:
//                    index = index+1;
//                    if (index > 2) index = 0;
//                    break;
//                default:
//                    break;
//            }
//        }
//
//        // Clear screen
//        SDL_RenderClear(renderer);
//        switch (index) {
//            case 0:
//                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//                break;
//            case 1:
//                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//                break;
//            case 2:
//                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
//                break;
//            default:
//                break;
//
//        }
//
//        // Draw
//
//        // Show what was drawn
//        SDL_RenderPresent(renderer);
//    }
//
//    // Release resources
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
}