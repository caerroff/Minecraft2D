CC = clang++
CFLAGS = -w -O2 -std=c++17
LDFLAGS = -Ilib/SFML/include -headerpad_max_install_names
LDFLAGS += lib/SFML/lib/libsfml-graphics.dylib lib/SFML/lib/libsfml-system.dylib lib/SFML/lib/libsfml-window.dylib lib/SFML/lib/libsfml-audio.dylib
LDFLAGS += -Llib/SFML/lib
BUILDNB = $(shell date +%d%m%y%H%M%S)
LINK = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
CURDIR = $(shell pwd)
SRC  = $(wildcard src/*.cpp src/**/*.cpp src/**/**/*.cpp)
BIN  = build
OBJ  = $(SRC:.cpp=.o)
UNAME_S = $(shell uname -s)



.PHONY: all

all:	SFML main

SFML:
	cd lib/SFML && cmake -DBUILD_SHARED_LIBS=TRUE . && make -Iinclude

run: build/MC2D
	./build/MC2D

clean:
	rm -rf $(OBJ) $(BIN)/MC2D

main: $(OBJ)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN)/MC2D $^ $(LINK)
	@if [ `uname -s` = "Darwin" ]; then\
		install_name_tool -change @rpath/libsfml-graphics.3.0.dylib $(CURDIR)/lib/SFML/lib/libsfml-graphics.3.0.dylib build/MC2D;\
		install_name_tool -change @rpath/libsfml-system.3.0.dylib $(CURDIR)/lib/SFML/lib/libsfml-system.3.0.dylib build/MC2D;\
		install_name_tool -change @rpath/libsfml-window.3.0.dylib $(CURDIR)/lib/SFML/lib/libsfml-window.3.0.dylib build/MC2D;\
		install_name_tool -change @rpath/libsfml-audio.3.0.dylib $(CURDIR)/lib/SFML/lib/libsfml-audio.3.0.dylib build/MC2D;\
		install_name_tool -change @rpath/libsfml-network.3.0.dylib $(CURDIR)/lib/SFML/lib/libsfml-network.3.0.dylib build/MC2D;\
	fi
	@echo "Linking complete!"

%.o: %.cpp
	@echo "Compiling "$<"..."
	@$(CC) -DBUILDNB=$(BUILDNB) -o $@ -c $< $(CFLAGS) $(LDFLAGS) $(LINK)
	@echo "Compiled "$<" successfully!"
