#include "../headers/main.h"

int main(void) {
  bool running = true;
  SDL_Instance instance;

  if (init_instance(&instance) != 0) {
    return (1);
  }
  loadImage();
  loadMedia(&instance);
  while (running) {
    SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    if (poll_events() == 1) {
      running = false;
    }
    SDL_RenderClear(instance.renderer);
    SDL_RenderCopy(instance.renderer, instance.texture, NULL, NULL);
    SDL_RenderPresent(instance.renderer);
  }
  destroy(&instance);
  return (0);
}
