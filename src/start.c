#include "../headers/main.h"

void loadMedia(SDL_Instance *instance) {

  instance->texture = loadTexture("/home/ernest/personal/maze_runner/assets/textures/eagle.png", instance);
  if (instance->texture == NULL) {
    fprintf(stderr, "Could not load textures image: %s\n", IMG_GetError());
  }
}

void loadImage() {
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    fprintf(stderr, "Could not load image: %s\n", IMG_GetError());
  }
}

SDL_Texture *loadTexture(char *path, SDL_Instance *instance) {

  SDL_Surface *loadedSurface = IMG_Load(path);
  SDL_Texture *finalTexture = NULL;
  if (loadedSurface == NULL)
    fprintf(stderr, "Could not load image: %s\n", IMG_GetError());

  finalTexture = SDL_CreateTextureFromSurface(instance->renderer, loadedSurface);
  if (finalTexture == NULL) {
    fprintf(stderr, "Could not create texture: %s\n", SDL_GetError());
  }
  SDL_FreeSurface(loadedSurface);

  return finalTexture;
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
      if (key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        return (1);
      break;
    }
  }
  return (0);
}
