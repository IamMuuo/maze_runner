#include "../headers/maze_runner.h"

/**
 * Converts a hexadecimal color value to an SDL_Color structure.
 *
 * @param hex_value The hexadecimal color value to be converted.
 * @return The SDL_Color structure representing the converted color.
 */
SDL_Color convert_color(int hex_value) {
  SDL_Color color;
  color.r = ((hex_value >> 16) & 0xFF);
  color.g = ((hex_value >> 8) & 0xFF);
  color.b = ((hex_value)&0xFF);

  return (color);
}

/**
 * Sets the wall color based on the map coordinates.
 *
 * @param map_x The x-coordinate of the map.
 * @param map_y The y-coordinate of the map.
 * @return The SDL_Color structure representing the picked wall color.
 */
SDL_Color pick_wall_color(int map_x, int map_y) {
  SDL_Color color;
  if (worldMap[map_x][map_y] == 1 || worldMap[map_x][map_y] == 4)
    color = convert_color(WHITE);
  else if (worldMap[map_x][map_y] == 2)
    color = convert_color(GREEN);
  else if (worldMap[map_x][map_y] == 3)
    color = convert_color(BLUE);
  else if (worldMap[map_x][map_y] == 7)
    color = convert_color(RED);
  else
    color = convert_color(BLACK);
  return (color);
}

/**
 * Applies a night effect to the color based on distance.
 *
 * @param color The original color.
 * @param distance The distance to the color's source.
 * @return The modified color with the applied night effect.
 */
SDL_Color night_effect(SDL_Color color, double distance) {
  if (color.r / distance * AMBIENT_LIGHT <= color.r)
    color.r = color.r / distance * AMBIENT_LIGHT;
  if (color.g / distance * AMBIENT_LIGHT <= color.g)
    color.g = color.g / distance * AMBIENT_LIGHT;
  if (color.b / distance * AMBIENT_LIGHT <= color.b)
    color.b = color.b / distance * AMBIENT_LIGHT;
  return (color);
}
