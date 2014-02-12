#Date makefile

COMPILER=g++
FLAGS=-W -Wall -Werror -ansi -pedantic
OBJS=Date.o

all: main.cpp $(OBJS)
	$(COMPILER) $(FLAGS) main.cpp $(OBJS) -o main

Date.o: Date.cpp Date.h
	$(COMPILER) $(FLAGS) -c Date.cpp

clean:
	rm *.o main