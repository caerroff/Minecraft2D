all:
	@echo "choices are silent/old/old-silent/libraries"

GUI:
	@gcc GUI.c $(sdl2-config --cflags --libs) -o GUI
	@./GUI
