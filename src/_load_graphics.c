#include "../headers/maze_runner.h"

// Will work one once RayCasting is done

/* void loadFlooring(SDL_Instance *instance) {

  instance->texture = loadTexture(
      "/home/ernest/personal/maze_runner/assets/textures/wood.png", instance);
  if (instance->texture == NULL) {
    fprintf(stderr, "Could not load textures image: %s\n", IMG_GetError());
  }
}

void loadWalls(SDL_Instance *instance) {

  instance->texture = loadTexture(
      "/home/ernest/personal/maze_runner/assets/textures/colorstone.png",
      instance);
  if (instance->texture == NULL) {
    fprintf(stderr, "Could not load textures image: %s\n", IMG_GetError());
  }
} */

// void load_image() {
//   int imgFlags = IMG_INIT_PNG;
//   if (!(IMG_Init(imgFlags) & imgFlags)) {
//     fprintf(stderr, "Could not load image: %s\n", IMG_GetError());
//   }
// }

/*
 * Loads a texture from the assets
 * @path: path to the texture location(../assets/)
 * @instance: an SDL instance
 * @Return: SDL_Texture
 */
SDL_Texture *loadTexture(char *path, SDL_Instance *instance) {

  SDL_Surface *loadedSurface = IMG_Load(path);
  SDL_Texture *finalTexture = NULL;

  // optimize the loaded surface
  loadedSurface = SDL_ConvertSurface(loadedSurface, loadedSurface->format, 0);
  if (loadedSurface == NULL)
    fprintf(stderr, "Could not load image: %s\n", IMG_GetError());

  finalTexture =
      SDL_CreateTextureFromSurface(instance->renderer, loadedSurface);

  if (finalTexture == NULL) {
    fprintf(stderr, "Could not create texture: %s\n", SDL_GetError());
  }
  SDL_FreeSurface(loadedSurface);

  return finalTexture;
}


