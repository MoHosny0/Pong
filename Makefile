#SDL = -lSDL2
_OBJ = main_txt.o Jeu.o Vec2D.o Terrain.o Ball.o txtJeu.o Paddle.o winTxt.o Score.o
OBJ = $(patsubst %,obj/core/%,$(_OBJ))

TEST_SDL2 = obj/core/main_sdl.o obj/core/Jeu.o obj/core/Paddle.o obj/core/Ball.o obj/core/Terrain.o obj/core/Vec2D.o

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

all: bin/app

bin/app: $(OBJ)
	${GPP_EX} bin/app $^ $(LIBRARY_PATHS_SDL) $(SDL)

# bin/sdl2: $(TEST_SDL2)
# 	${GPP_EX} bin/sdl2 $(TEST_SDL2) $(LIBRARY_PATHS_SDL) $(SDL)

obj/core/%.o: src/core/%.cpp 
	${GPP_O} -o $@ $< $(INCLUDE_PATHS_SDL)

clean:
ifeq ($(OS),Windows_NT)
	del /f obj\core\* bin\*
else
	rm -f obj/core/* bin/*
endif
	