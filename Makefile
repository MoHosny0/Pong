
LIBS = 
_OBJ = main.o Ball.o Paddle.o
OBJ = $(patsubst %,obj/%,$(_OBJ))


all: bin/app

obj/%.o: src/%.cpp
	g++ -Wall -c -o $@ $< 

bin/app: $(OBJ)
	g++ -Wall -o bin/app $^ $(LIBS)

clean:
	rm -f obj/* bin/*