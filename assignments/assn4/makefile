#!bash

# Makefile for Assignment 4
#	Message board

COMPILER=g++
FLAGS=-W -Wall -Werror -ansi -pedantic
OBJS=Message.o User.o BBoard.o

all: main.cpp $(OBJS)
	$(COMPILER) $(FLAGS) main.cpp $(OBJS) -o main

Message.o: Message.cpp Message.h
	$(COMPILER) $(FLAGS) -c Message.cpp

User.o: User.cpp User.h
	$(COMPILER) $(FLAGS) -c User.cpp

BBoard.o: BBoard.cpp BBoard.h
	$(COMPILER) $(FLAGS) -c BBoard.cpp

clean:
	rm *.o main