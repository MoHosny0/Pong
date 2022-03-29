SDL = -lSDL2
_OBJ = main.o Vec2D.o txt.o Terrain.o
OBJ = $(patsubst %,obj/%,$(_OBJ))

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

obj/%.o: src/%.cpp
	${GPP_O} -o $@ $< $(INCLUDE_PATHS_SDL) 

clean:
	rm -f obj/* bin/*