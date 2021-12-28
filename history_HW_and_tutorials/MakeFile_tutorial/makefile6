.PHONY: directories

CC = g++
SRC = ./src
OBJ = ./obj
BIN = ./bin
TEST = ./test
LIB = -lgtest -lpthread
CFLAGS = -std=c++11

all: directories $(BIN)/ut_all

$(BIN)/ut_all: $(OBJ)/ut_main.o
	$(CC) $(CFLAGS) -o $@ $< $(LIB)

$(OBJ)/ut_main.o: $(TEST)/ut_main.cpp $(TEST)/ut_vector.h
	$(CC) $(CFLAGS) -o $@ -c $<

directories:
	mkdir -p $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc $(SRC)/* $(TEST)/*
