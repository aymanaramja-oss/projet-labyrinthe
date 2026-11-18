labyrinthe: src/*.c include/*.h
	gcc -Wall -Wextra -Wpedantic -Iinclude src/*.c -o labyrinthe

clean:
	rm -f labyrinthe src/*.o