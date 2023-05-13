#include "../headers/main.h"

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 480;

/**
 * Initializes the SDL instance, creating a window and renderer.
 *
 * @param instance - Pointer to an SDL_Instance struct.
 * @return 0 if successful, 1 if there was an error.
 * */
int init_instance(SDL_Instance *instance) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Initialization error: %s\n", SDL_GetError());
    return (1);
  }

  // Create a new window
  instance->window =
      SDL_CreateWindow("Maze Runner 0.9", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (instance->window == NULL) {
    fprintf(stderr, "Window creation error: %s\n", SDL_GetError());
    SDL_Quit();
    return (1);
  }

  // Create renderer
  instance->renderer =
      SDL_CreateRenderer(instance->window, -1,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (instance->renderer == NULL) {
    fprintf(stderr, "Could not create new renderer: %s\n", SDL_GetError());
    SDL_Quit();
    return (1);
  }
  instance->surface = SDL_GetWindowSurface(instance->window);
  return (0);
}

/*
 * destroy - frees all the unused resources
 * @instance: SDL_Instance
 * @return: none
 */
void destroy(SDL_Instance instance) {
  SDL_DestroyTexture(instance.texture);
  instance.texture = NULL;

  SDL_DestroyRenderer(instance.renderer);
  SDL_DestroyWindow(instance.window);
  instance.renderer = NULL;
  instance.window = NULL;
  IMG_Quit();
  SDL_Quit();
}
