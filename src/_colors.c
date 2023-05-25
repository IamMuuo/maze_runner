#include "../headers/maze_runner.h"

SDL_Color convert_color(int hex_value) {
  SDL_Color color;
  color.r = ((hex_value >> 16) & 0xFF);
  color.g = ((hex_value >> 8) & 0xFF);
  color.b = ((hex_value)&0xFF);

  return (color);
}

SDL_Color pick_wall_color(int map_x, int map_y) {
  SDL_Color color;
  if (worldMap[map_x][map_y] == 1)
    color = convert_color(RED);
  else if (worldMap[map_x][map_y] == 2)
    color = convert_color(GREEN);
  else if (worldMap[map_x][map_y] == 3)
    color = convert_color(BLUE);
  else if (worldMap[map_x][map_y] == 4)
    color = convert_color(WHITE);
  else
    color = convert_color(BLACK);
  return (color);
}

// Uint8 calc_new_color(Uint8 color_val, double distance) {
//   return (color_val / distance * AMBIENT_LIGHT);
// }

SDL_Color night_effect(SDL_Color color, double distance) {
  if (color.r / distance * AMBIENT_LIGHT <= color.r)
    color.r = color.r / distance * AMBIENT_LIGHT;
  if (color.g / distance * AMBIENT_LIGHT <= color.g)
    color.g = color.g / distance * AMBIENT_LIGHT;
  if (color.b / distance * AMBIENT_LIGHT <= color.b)
    color.b = color.b / distance * AMBIENT_LIGHT;
  return (color);
  return color;
}
