CC = g++
CFLAGS = -c -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SFML_INCLUDE = -I /usr/include/SFML

SRC_DIR = src
OBJ_DIR = obj
EXECUTABLE = SFML_BrickGame

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: $(OBJ_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(SFML_INCLUDE) $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)
