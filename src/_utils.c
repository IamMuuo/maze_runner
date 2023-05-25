#include "../headers/maze_runner.h"

// Create a static player
int handle_movement(raycaster_t *rc) {

  SDL_Event event;
  double oldDirX;
  double oldPlaneX;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      return (1);
    if (event.type == SDL_KEYDOWN) {
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        return (1);
      }
      if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w) {
        if (worldMap[(int)(rc->player_pos_x + rc->player_dir_x * MV_SPEED)]
                    [(int)(rc->player_pos_y)] == 0)
          rc->player_pos_x += rc->player_dir_x * MV_SPEED;
        if (worldMap[(int)(rc->player_pos_x)][(
                int)(rc->player_pos_y + rc->player_dir_y * MV_SPEED)] == 0)
          rc->player_pos_y += rc->player_dir_y * MV_SPEED;
      }
      if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) {
        if (worldMap[(int)(rc->player_pos_x - rc->player_dir_x * MV_SPEED)]
                    [(int)(rc->player_pos_y)] == 0)
          rc->player_pos_x -= rc->player_dir_x * MV_SPEED;
        if (worldMap[(int)(rc->player_pos_x)][(
                int)(rc->player_pos_y - rc->player_dir_y * MV_SPEED)] == 0)
          rc->player_pos_y -= rc->player_dir_y * MV_SPEED;
      }
      if (event.key.keysym.sym == SDLK_RIGHT ||
          event.key.keysym.sym == SDLK_d) {
        oldDirX = rc->player_dir_x;
        rc->player_dir_x = rc->player_dir_x * cos(-ROT_SPEED) -
                           rc->player_dir_y * sin(-ROT_SPEED);
        rc->player_dir_y =
            oldDirX * sin(-ROT_SPEED) + rc->player_dir_y * cos(-ROT_SPEED);
        oldPlaneX = rc->player_plane_x;
        rc->player_plane_x = rc->player_plane_x * cos(-ROT_SPEED) -
                             rc->player_plane_y * sin(-ROT_SPEED);
        rc->player_plane_y =
            oldPlaneX * sin(-ROT_SPEED) + rc->player_plane_y * cos(-ROT_SPEED);
      }
      if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a) {
        oldDirX = rc->player_dir_x;
        rc->player_dir_x = rc->player_dir_x * cos(ROT_SPEED) -
                           rc->player_dir_y * sin(ROT_SPEED);
        rc->player_dir_y =
            oldDirX * sin(ROT_SPEED) + rc->player_dir_y * cos(ROT_SPEED);
        oldPlaneX = rc->player_plane_x;
        rc->player_plane_x = rc->player_plane_x * cos(ROT_SPEED) -
                             rc->player_plane_y * sin(ROT_SPEED);
        rc->player_plane_y =
            oldPlaneX * sin(ROT_SPEED) + rc->player_plane_y * cos(ROT_SPEED);
      }
    }
  }

  return (0);
}

void render_frames(SDL_Instance *instance) {
  SDL_RenderPresent(instance->renderer);
  SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 0);
  SDL_RenderClear(instance->renderer);
}

/**
 * Initializes the SDL instance, creating a window and renderer.
 *
 * @param instance - Pointer to an SDL_Instance struct.
 * @return 0 if successful, 1 if there was an error.
 * */
int init_instance(SDL_Instance *instance, raycaster_t *rc) {
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

  rc->player_pos_x = 22;
  rc->player_pos_y = 12;
  rc->player_dir_x = -1;
  rc->player_dir_y = 0;
  rc->player_plane_x = 0;
  rc->player_plane_y = 0.66;

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
