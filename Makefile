all:
	gcc *.c -I/Libraries/include/SDL.h -D_REENTRANT -lSDL2 -o MC2D
	./MC2D

silent:
	@gcc *.c -I/Libraries/include/SDL.h -D_REENTRANT -lSDL2 -o MC2D
	@./MC2D

GUI:
	@gcc GUI.c $(sdl2-config --cflags --libs) -o GUI
	@./GUI

debug:
	gcc GUI.c Libraries/include/SDL.h -o GUI
