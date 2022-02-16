all:
	@g++ src/*.cpp -I/lib/SDL2/include/SDL.h -D_REENTRANT -lSDL2 -o MC2D
	@./MC2D