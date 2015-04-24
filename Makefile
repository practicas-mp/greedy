CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc
ALGS = max_containers



$(ALGS): %: $(SRC)/%.cpp $(INCLUDE)/container.h
	$(CC) $(CPPFLAGS) $(SRC)/$@.cpp -o $(BIN)/$@



clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc