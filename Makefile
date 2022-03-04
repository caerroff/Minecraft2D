all:
	@g++ -c src/*pp -lib/SFML-2.5.1/include -DSFML_STATIC
	@mv *.o bin/
	@g++ bin/*.o  -Llib/SFML-2.5.1/lib -Lsrc/*.hpp -DSFML_STATIC -lsfml-graphics -lsfml-window -lsfml-system -o MC2D

normal: all
	@./MC2D

log: all
	@echo "`date` NEW LAUNCH" >> log.txt
	@./MC2D >> log.txt
