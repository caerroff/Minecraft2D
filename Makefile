all:
	gcc *.c -o MC2D
	./MC2D

silent:
	@gcc *.c -o MC2D
	@./MC2D

old:
	gcc GUI.c -o GUI
	./GUI

old-silent:
	@gcc GUI.c -o GUI
	@./GUI

