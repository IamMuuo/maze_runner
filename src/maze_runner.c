#include "../headers/maze_runner.h"


int main(void) {
  bool running = true;
  SDL_Instance instance;
  raycaster_t rc;

  if (init_instance(&instance, &rc) != 0) {
    return (1);
  }
  // loadImage();
  while (running) {
      for (int x = 0; x < SCREEN_WIDTH; x++) {
          initial_calc(&rc,x);
          perform_dda(&rc);
          calc_wall_height(&rc);
          draw_vertical_line(&instance, &rc, x);
      }
      render_frames(&instance);
      if (handle_movement(&rc) != 0){
          running = false;
      }

  }

  destroy(&instance);
  return (0);
}
