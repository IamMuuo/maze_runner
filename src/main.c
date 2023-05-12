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

int poll_events() {
  SDL_Event event;
  SDL_KeyboardEvent key;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      return (1);
    case SDL_KEYDOWN:
      key = event.key;
      // ESC key
      if (key.keysym.scancode == 0x29)
        return (1);
      break;
    }
  }
  return (0);
}

int main(void) {
  SDL_Instance instance;
  if (init_instance(&instance) != 0) {
    return (1);
  }
  while (1) {
    SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
    SDL_RenderClear(instance.renderer);
    if (poll_events() == 1) {
      break;
    }
    drawStuff(instance);
    SDL_RenderPresent(instance.renderer);
  }
  SDL_DestroyRenderer(instance.renderer);
  SDL_DestroyWindow(instance.window);
  SDL_Quit();
  return (0);
}
