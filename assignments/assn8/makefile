#!bash

# Makefile for Assignment 8
#	Message board of death

COMPILER=g++
FLAGS=-std=c++11 -W -Wall -Werror -ansi -pedantic
OBJS=BBoard.o Message.o Reply.o Topic.o User.o

all: main.cpp $(OBJS)
	$(COMPILER) $(FLAGS) main.cpp $(OBJS) -o main

BBoard.o: BBoard.cpp BBoard.h User.o Message.o Reply.o Topic.o
	$(COMPILER) $(FLAGS) -c BBoard.cpp

Message.o: Message.cpp Message.h
	$(COMPILER) $(FLAGS) -c Message.cpp

Reply.o: Reply.cpp Reply.h
	$(COMPILER) $(FLAGS) -c Reply.cpp

Topic.o: Topic.cpp Topic.h
	$(COMPILER) $(FLAGS) -c Topic.cpp

User.o: User.cpp User.h
	$(COMPILER) $(FLAGS) -c User.cpp

clean:
	rm -f *.o *.exe main