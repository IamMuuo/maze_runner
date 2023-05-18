cmake_minimum_required(VERSION 3.12)
project(MazeRunner)

# Check if SDL library is already installed
find_package(SDL2 REQUIRED)

# If SDL is not found, download and install it
if(NOT SDL2_FOUND)
    message(STATUS "Downloading and installing SDL library...")
    # Todo
    # Download and install SDL here
endif()

# Check if SDL_image library is already installed
find_package(SDL2_image REQUIRED)

# If SDL_image is not found, download and install it
if(NOT SDL2_image_FOUND)
    message(STATUS "Downloading and installing SDL_image library...")
    # Todo
    # Download and install SDL_image here
endif()

# libraries
add_library(
  engine
  src/_load_graphics.c 
  src/utility.c
)

# Add your game source files here
add_executable(
  runner 
  src/_maze_runner.c 
)

# Link your game executable with SDL and SDL_image libraries
target_link_libraries(runner engine SDL2 SDL2_image)

