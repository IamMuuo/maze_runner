#include "../headers/maze_runner.h"

// Create a static player
Player player = {17, 6};

int renderMap(int worldMap[][MAPSIDES], SDL_Instance *instance) {

  int cellWidth = SCREEN_WIDTH / MAPSIDES;
  int cellHeight = SCREEN_HEIGHT / MAPSIDES;

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
      // Move up or down
      if (key.keysym.scancode == SDL_SCANCODE_UP ||
          key.keysym.scancode == SDL_SCANCODE_W) {
        if (player.y > 0 && worldMap[player.y - 1][player.x] == 0) {
          player.y--;
        }
      };
      if (key.keysym.scancode == SDL_SCANCODE_DOWN ||
          key.keysym.scancode == SDL_SCANCODE_S) {
        if (player.y < MAPSIDES - 1 && worldMap[player.y + 1][player.x] == 0) {
          player.y++;
        }
      };

      // MOve left right
      if (key.keysym.scancode == SDL_SCANCODE_LEFT ||
          key.keysym.scancode == SDL_SCANCODE_A) {
        if (player.x > 0 && worldMap[player.y][player.x - 1] == 0) {
          player.x--;
        }
      };
      if (key.keysym.scancode == SDL_SCANCODE_RIGHT ||
          key.keysym.scancode == SDL_SCANCODE_D) {
        if (player.y < MAPSIDES - 1 && worldMap[player.y][player.x + 1] == 0) {
          player.x++;
        }
      };
      break;
    }
  }

  SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255);
  SDL_RenderClear(instance->renderer);

  for (int i = 0; i < MAPSIDES; i++) {
    for (int j = 0; j < MAPSIDES; j++) {
      int x = j * cellWidth;
      int y = i * cellHeight;

      if (worldMap[i][j] > 0) {
        SDL_SetRenderDrawColor(instance->renderer, 255, 255, 255, 255);
      } else {
        SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255);
      }

      SDL_Rect cellRect = {x, y, cellWidth, cellHeight};
      SDL_RenderFillRect(instance->renderer, &cellRect);

      if (i == player.y && j == player.x) {
        SDL_Rect playerRect = {x, y, cellWidth, cellHeight};
        SDL_SetRenderDrawColor(instance->renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(instance->renderer, &playerRect);
      }
    }
  }
  SDL_RenderPresent(instance->renderer);

  return (0);
}

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
                       SDL_WINDOW_BORDERLESS, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
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
 * @return: void
 */
void destroy(SDL_Instance *instance) {
  SDL_DestroyTexture(instance->texture);
  instance->texture = NULL;

  SDL_DestroyRenderer(instance->renderer);
  SDL_DestroyWindow(instance->window);
  instance->renderer = NULL;
  instance->window = NULL;
  IMG_Quit();
  SDL_Quit();
}
