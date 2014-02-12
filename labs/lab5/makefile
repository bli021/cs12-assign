#Distance makefile

COMPILER=g++
FLAGS=-W -Wall -Werror -ansi -pedantic
OBJS=Distance.o

all: main.cpp $(OBJS)
	$(COMPILER) $(FLAGS) main.cpp $(OBJS) -o main

Date.o: Distance.cpp Distance.o
	$(COMPILER) $(FLAGS) -c Distance.cpp

clean:
	rm *.o main