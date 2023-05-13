CC := gcc
SRC_DIR := ./src
HEADER_DIR := ./headers
BIN_DIR := ./bin

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SOURCES))

CFLAGS := -Wall -Werror -Wextra -pedantic $(shell sdl2-config --cflags)
LIBS := $(shell sdl2-config --libs) -lSDL2_ttf -lSDL2_image

EXECUTABLE := $(BIN_DIR)/output

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	$(EXECUTABLE)

clean:
	rm -rf $(BIN_DIR)/*.o $(EXECUTABLE)
