SDL = -lSDL2
_OBJ_CORE = Jeu.o Vec2D.o Terrain.o Ball.o Paddle.o Score.o
OBJ_CORE = $(patsubst %,obj/core/%,$(_OBJ_CORE))

_OBJ_SDL = main_sdl.o sdlJeu.o
OBJ_SDL = $(patsubst %,obj/sdl2/%,$(_OBJ_SDL))

_OBJ_TXT = main_txt.o winTxt.o txtJeu.o
OBJ_TXT = $(patsubst %,obj/txt/%,$(_OBJ_TXT))



# TEST_SDL2 = obj/core/main_sdl.o obj/core/sdlJeu.o obj/core/Jeu.o obj/core/Paddle.o obj/core/Ball.o obj/core/Terrain.o obj/core/Vec2D.o obj/core/Score.o
# TEST_TXT = obj/core/main_txt.o obj/core/txtJeu.o obj/core/winTxt.o obj/core/Jeu.o obj/core/Paddle.o obj/core/Ball.o obj/core/Terrain.o obj/core/Vec2D.o obj/core/Score.o

GPP_EX = g++ -Wall -o
GPP_O = g++ -Wall -c

ifeq ($(OS),Windows_NT) # cherche l'OS pour bien mettre les include et lib. 
    os := Windows
else
    os := $(shell uname -s)
endif

ifeq ($(os), Windows_NT) # Windows (À mettre par Mostafa)
	INCLUDE_PATHS = -I/
	LIBRARY_PATHS = -L/
endif

ifeq ($(os), Darwin) # MacOS
	INCLUDE_PATHS_SDL = -I/opt/homebrew/Cellar/sdl2/2.0.20/include/
	LIBRARY_PATHS_SDL = -L/opt/homebrew/Cellar/sdl2/2.0.20/lib/
endif

ifeq ($(os), Linux) # Linux (normalement pas besoin de path)
	
endif

all: bin/sdl2 bin/txt

# bin/app: $(OBJ_CORE)
# 	${GPP_EX} bin/app $^ $(LIBRARY_PATHS_SDL) $(SDL)

bin/sdl2: $(OBJ_SDL) $(OBJ_CORE)
	${GPP_EX} bin/sdl2 $(OBJ_SDL) $(OBJ_CORE) $(LIBRARY_PATHS_SDL) $(SDL)

bin/txt: $(OBJ_TXT) $(OBJ_CORE)
	${GPP_EX} bin/txt $(OBJ_TXT) $(OBJ_CORE)

obj/core/%.o: src/core/%.cpp 
	${GPP_O} -o $@ $< $(INCLUDE_PATHS_SDL)

obj/sdl2/%.o: src/sdl2/%.cpp 
	${GPP_O} -o $@ $< $(INCLUDE_PATHS_SDL)

obj/txt/%.o: src/txt/%.cpp 
	${GPP_O} -o $@ $< 



clean:
ifeq ($(OS),Windows_NT)
	del /f obj\core\* bin\*
else
	rm -f obj/core/* bin/*
endif
	