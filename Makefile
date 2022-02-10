all:
	@echo "choices are silent/old/old-silent/libraries"

silent:
	@gcc *.c -o MC2D
	@./MC2D

old:
	gcc GUI.c -o GUI
	./GUI

old-silent:
	@gcc GUI.c -o GUI
	@./GUI

libraries:
	gcc GUI.c $(sdl2-config --cflags --libs) -o GUI
	./MC2D
