#ifndef _MAZE_RUNNER_H_
#define _MAZE_RUNNER_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

typedef struct SDL_Instance {
  SDL_Window *window;
  SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
void drawStuff(SDL_Instance instance);
#endif
