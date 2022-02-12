all:
	gcc src/*.c -I/lib/include/SDL.h -D_REENTRANT -lSDL2 -o MC2D
	./MC2D

silent:
	@gcc src/*.c -I/lib/include/SDL.h -D_REENTRANT -lSDL2 -o MC2D
	@./MC2D

GUI:
	@gcc src/GUI.c $(sdl2-config --cflags --libs) -o GUI
	@./GUI

debug:
	gcc src/GUI.c lib/include/SDL.h -o GUI
