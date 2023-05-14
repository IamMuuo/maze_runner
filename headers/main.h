#ifndef _MAZE_RUNNER_H_
#define _MAZE_RUNNER_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct SDL_Instance {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Surface *image;
  SDL_Texture *texture;
} SDL_Instance;

int init_instance(SDL_Instance *);
int poll_events();
SDL_Texture *loadTexture(char *path, SDL_Instance *instance);
void loadImage();
void loadMedia(SDL_Instance *instance);
void destroy(SDL_Instance *instance);
#endif
