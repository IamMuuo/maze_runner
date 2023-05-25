#ifndef _MAZE_RUNNER_H_
#define _MAZE_RUNNER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAPSIDES 24
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define CELL_SIZE SCREEN_WIDTH / MAPSIDES
#define MV_SPEED 0.15
#define ROT_SPEED 0.1745
#define AMBIENT_LIGHT 5

#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define BLACK 0x000000
#define WHITE 0xFFFFFF

extern int worldMap[MAPSIDES][MAPSIDES];

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
  double dir_x;
  double dir_y;
} Player;

typedef struct raycaster_s {
  double player_pos_x;
  double player_pos_y;
  double player_dir_x;
  double player_dir_y;
  double player_plane_x;
  double player_plane_y;
  double ray_dir_x;
  double ray_dir_y;
  int map_x;
  int map_y;
  double side_dist_x;
  double side_dist_y;
  double delta_dist_x;
  double delta_dist_y;
  int step_x;
  int step_y;
  int side;
  int draw_start;
  int draw_end;
  double perp_wall_dist;
} raycaster_t;

int init_instance(SDL_Instance *, raycaster_t *rc);
SDL_Texture *loadTexture(char *path, SDL_Instance *instance);
void loadImage();
// void loadFlooring(SDL_Instance *instance);
// void loadWalls(SDL_Instance *instance);
int handle_movement(raycaster_t *rc);
void render_frames(SDL_Instance *instance);
void destroy(SDL_Instance *instance);

// colors related
SDL_Color convert_color(int hex_Val);
SDL_Color pick_wall_color(int map_x, int map_y);
Uint8 calc_new_color(Uint8 color_val, double distance);
SDL_Color night_effect(SDL_Color color, double distance);

// Raycasting
void initial_calc(raycaster_t *rc, int x);
void perform_dda(raycaster_t *rc);
void calc_wall_height(raycaster_t *rc);
void draw_vertical_line(SDL_Instance *instance, raycaster_t *rc, int x);
#endif
