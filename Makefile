# Compiler and flags
CC := g++
CFLAGS := -std=c++11 -I"./libs/" -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.4  -o biscotti_engine

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Executable name
EXEC := ./biscotti_engine

$(EXEC): $(OBJ_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

#build:

	#g++ -Wall -std=c++17 -I"./libs/" src/*.cpp src/*/*.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.4  -o biscotti_engine;

run:
	./biscotti_engine
clean:
	rm biscotti_engine
all: $(EXEC)


