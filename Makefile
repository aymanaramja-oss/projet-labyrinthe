CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Iinclude
SRC = src/main.c src/maze.c src/file.c src/generator.c
OBJ = $(SRC:.c=.o)
EXEC = labyrinthe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXEC)

.PHONY: all clean
