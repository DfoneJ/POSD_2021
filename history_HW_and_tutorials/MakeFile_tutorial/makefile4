.PHONY: directories

SRC = ./src
OBJ = ./obj
BIN = ./bin
TEST = ./test

CC = g++
LIB = -lgtest -lpthread
CFLAGS = -std=c++11

all: directories $(BIN)/ut_all

$(BIN)/ut_all: $(OBJ)/ut_main.o
	$(CC) $(CFLAGS) -o $(BIN)/ut_all $(OBJ)/ut_main.o $(LIB)

$(OBJ)/ut_main.o: $(TEST)/ut_main.cpp $(TEST)/ut_vector.h
	$(CC) $(CFLAGS) -c $(TEST)/ut_main.cpp -o $(OBJ)/ut_main.o

directories:
	mkdir -p $(BIN) $(OBJ)
