all:
	@g++ -c src/*.cpp -lib/SFML-2.5.1/include -DSFML_STATIC 
	@g++ main.o  -Llib/SFML-2.5.1/lib -DSFML_STATIC -lsfml-graphics -lsfml-window -lsfml-system -o MC2D
	@./MC2D