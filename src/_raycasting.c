#include "../headers/maze_runner.h"

void initial_calc(raycaster_t *rc, int x) {
  double cameraX;

  cameraX = 2 * x / (double)(SCREEN_WIDTH)-1;
  rc->ray_dir_x = rc->player_dir_x + rc->player_plane_x * cameraX;
  rc->ray_dir_y = rc->player_dir_y + rc->player_plane_y * cameraX;
  rc->map_x = (int)rc->player_pos_x;
  rc->map_y = (int)rc->player_pos_y;
  rc->delta_dist_x = sqrt(1 + pow(rc->ray_dir_y, 2) / pow(rc->ray_dir_x, 2));
  rc->delta_dist_y = sqrt(1 + pow(rc->ray_dir_x, 2) / pow(rc->ray_dir_y, 2));

  if (rc->ray_dir_x < 0) {
    rc->step_x = -1;
    rc->side_dist_x = (rc->player_pos_x - rc->map_x) * rc->delta_dist_x;
  } else {
    rc->step_x = 1;
    rc->side_dist_x = (rc->map_x + 1.0 - rc->player_pos_x) * rc->delta_dist_x;
  }

  if (rc->ray_dir_y < 0) {
    rc->step_y = -1;
    rc->side_dist_y = (rc->player_pos_y - rc->map_y) * rc->delta_dist_y;
  } else {
    rc->step_y = 1;
    rc->side_dist_y = (rc->map_y + 1.0 - rc->player_pos_y) * rc->delta_dist_y;
  }
}

void perform_dda(raycaster_t *rc) {
  int hit;

  hit = 0;
  while (hit == 0) {
    if (rc->side_dist_x < rc->side_dist_y) {
      rc->side_dist_x += rc->delta_dist_x;
      rc->map_x += rc->step_x;
      rc->side = 0;
    } else {
      rc->side_dist_y += rc->delta_dist_y;
      rc->map_y += rc->step_y;
      rc->side = 1;
    }
    if (worldMap[rc->map_x][rc->map_y] > 0) {
      hit = 1;
    }
  }
}

void calc_wall_height(raycaster_t *rc) {
  int line_height;

  if (rc->side == 0) {
    rc->perp_wall_dist =
        (rc->map_x - rc->player_pos_x + (1 - (double)rc->step_x) / 2) /
        rc->ray_dir_x;
  } else {
    rc->perp_wall_dist =
        (rc->map_y - rc->player_pos_y + (1 - rc->step_y) / 2) / rc->ray_dir_y;
    line_height = (int)(SCREEN_HEIGHT / rc->perp_wall_dist);
    rc->draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
    if (rc->draw_start < 0)
      rc->draw_start = 0;
    rc->draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
    if (rc->draw_end >= SCREEN_HEIGHT)
      rc->draw_end = SCREEN_HEIGHT - 1;
  }
}

void draw_vertical_line(SDL_Instance *instance, raycaster_t *rc, int x) {
  SDL_Color color;
  color =
      night_effect(pick_wall_color(rc->map_x, rc->map_y), rc->perp_wall_dist);
  if (rc->side == 1) {
    color.r /= 2;
    color.g /= 2;
    color.b /= 2;
  }

  SDL_SetRenderDrawColor(instance->renderer, color.r, color.g, color.b,
                         SDL_ALPHA_OPAQUE);
  SDL_RenderDrawLine(instance->renderer, x, rc->draw_start, x, rc->draw_end);
}
