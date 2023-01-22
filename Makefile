all:
	g++ -c src/*pp -lsfml -DSFML_STATIC -D BUILDNUMBER="\"`date +"%d%m%y%H%M"`\""
	g++ -Wall *.o  -Llib/SFML-2.5.1/lib -Lsrc/*.hpp -DSFML_STATIC -lsfml-graphics -lsfml-window -lsfml-system -o MC2D

normal: all
	@./MC2D

log: all
	@echo "`date` NEW LAUNCH" >> log.txt
	@./MC2D >> log.txt
