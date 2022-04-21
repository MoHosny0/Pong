SDL = -lSDL2
_OBJ_CORE = Jeu.o Vec2D.o Terrain.o Ball.o Paddle.o Score.o
OBJ_CORE = $(patsubst %,obj/core/%,$(_OBJ_CORE))

_OBJ_SDL = main_sdl.o sdlJeu.o
OBJ_SDL = $(patsubst %,obj/sdl2/%,$(_OBJ_SDL))

_OBJ_TXT = main_txt.o winTxt.o txtJeu.o
OBJ_TXT = $(patsubst %,obj/txt/%,$(_OBJ_TXT))

GPP_EX = g++ -Wall -o
GPP_O = g++ -Wall -c

ifeq ($(OS),Windows_NT) # cherche l'OS pour bien mettre les include et lib. 
    os := Windows
else
    os := $(shell uname -s)
endif

ifeq ($(os), Windows_NT) # Windows (À mettre par Mostafa)
	INCLUDE_PATHS_SDL = -I/
	LIBRARY_PATHS_SDL = -L/
	INCLUDE_PATHS_TTF = -I/
	Library_PATHS_TTF = -L/
endif

ifeq ($(os), Darwin) # MacOS
	INCLUDE_PATHS_SDL = -I/opt/homebrew/Cellar/sdl2/2.0.20/include/
	LIBRARY_PATHS_SDL = -L/opt/homebrew/Cellar/sdl2/2.0.20/lib/
	INCLUDE_PATHS_TTF = -I/opt/homebrew/Cellar/sdl_ttf/2.0.11_1/include/
	LIBRARY_PATHS_TTF = -L/opt/homebrew/Cellar/sdl_ttf/2.0.11_1/lib/

endif

ifeq ($(os), Linux) # Linux (normalement pas besoin de path)
	
endif

all: bin/sdl2 bin/txt

bin/sdl2: $(OBJ_SDL) $(OBJ_CORE)
	${GPP_EX} bin/sdl2 $(OBJ_SDL) $(OBJ_CORE) $(LIBRARY_PATHS_SDL) $(LIBRARY_PATHS_TTF) $(SDL)

bin/txt: $(OBJ_TXT) $(OBJ_CORE)
	${GPP_EX} bin/txt $(OBJ_TXT) $(OBJ_CORE)

obj/core/%.o: src/core/%.cpp 
	${GPP_O} -o $@ $< $(INCLUDE_PATHS_SDL)

obj/sdl2/%.o: src/sdl2/%.cpp 
	${GPP_O} -o $@ $< $(INCLUDE_PATHS_SDL) $(INCLUDE_PATHS_TTF)

obj/txt/%.o: src/txt/%.cpp 
	${GPP_O} -o $@ $< 


# docu: doc/pacman.doxy
# 	cd doc ; doxygen pacman.doxy

clean:
ifeq ($(OS),Windows_NT)
	del /f obj\* bin\*
else
	rm -f obj/*/* bin/*
endif
	