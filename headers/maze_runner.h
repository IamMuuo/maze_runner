#ifndef _MAZE_RUNNER_H_
#define _MAZE_RUNNER_H_
#define MAPSIDES 24
#define SCREEN_WIDTH 820
#define SCREEN_HEIGHT 720

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct SDL_Instance {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Surface *image;
  SDL_Texture *texture;
} SDL_Instance;

typedef struct Player {
  int x;
  int y;
} Player;

int init_instance(SDL_Instance *);
SDL_Texture *loadTexture(char *path, SDL_Instance *instance);
void loadImage();
void loadFlooring(SDL_Instance *instance);
void loadWalls(SDL_Instance *instance);
int renderMap(int worldMap[][MAPSIDES], SDL_Instance *instance);
void destroy(SDL_Instance *instance);

#endif
