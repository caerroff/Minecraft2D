all:
	@g++ -c src/*pp -lib/SFML-2.5.1/include -DSFML_STATIC 
	@g++ *.o  -Llib/SFML-2.5.1/lib -Lsrc/*.hpp -DSFML_STATIC -lsfml-graphics -lsfml-window -lsfml-system -o MC2D
	@./MC2D