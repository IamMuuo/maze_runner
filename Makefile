CC := gcc
SRC_DIR := ./src
HEADER_DIR := ./headers
BIN_DIR := ./build
EXTERNAL_DIR := ./external

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SOURCES))

CFLAGS := -Wall -Werror -Wextra -pedantic $(shell sdl2-config --cflags)
LIBS := -L$(EXTERNAL_DIR)/sdl/build/lib -L$(EXTERNAL_DIR)/sdl_image/build/lib -lSDL2 -lSDL2_ttf -lSDL2_image -lm

EXECUTABLE := $(BIN_DIR)/maze_runner

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	$(EXECUTABLE)

clean:
	rm -rf $(BIN_DIR)/*.o $(EXECUTABLE)

# install:
# 	@echo "Cloning SDL2 repository..."
# 	@git clone https://github.com/libsdl-org/SDL.git $(EXTERNAL_DIR)/sdl
#
# 	@echo "Building and installing SDL2..."
# 	@cd $(EXTERNAL_DIR)/sdl && \
# 		mkdir build && \
# 		cd build && \
# 		cmake .. && \
# 		make && \
# 		sudo make install
#
# 	@echo "Cloning SDL2_image repository..."
# 	@git clone https://github.com/libsdl-org/SDL_image.git $(EXTERNAL_DIR)/sdl_image
#
# 	@echo "Building and installing SDL2_image..."
# 	@cd $(EXTERNAL_DIR)/sdl_image && \
# 		mkdir build && \
# 		cd build && \
# 		cmake .. && \
# 		make && \
# 		sudo make install

