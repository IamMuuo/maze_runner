#include "../headers/main.h"

const int SCREEN_WIDTH = 1260;
const int SCREEN_HEIGHT = 720;

int init_instance(SDL_Instance *instance) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Initialization error: %s\n", SDL_GetError());
    return (1);
  }

  // Create a new window
  instance->window =
      SDL_CreateWindow("It works", SDL_WINDOWPOS_CENTERED,
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
    fprintf(stderr, "Could create new renderer: %s\n", SDL_GetError());
    SDL_Quit();
    return (1);
  }

  return (0);
}

void drawStuff(SDL_Instance instance) {
  SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderDrawLine(instance.renderer, 10, 10, 1200, 700);
}

int main(void) {
  SDL_Instance instance;
  if (init_instance(&instance) != 0) {
    return (1);
  }
  while (1) {
    SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
    SDL_RenderClear(instance.renderer);
    drawStuff(instance);
    SDL_RenderPresent(instance.renderer);
  }
  return (0);
}
