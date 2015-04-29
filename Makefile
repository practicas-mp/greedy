CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./include
BIN = ./bin
ALGS = max_containers max_value max_value_density

install:
	mkdir -p $(BIN) build

all: $(ALGS)

$(ALGS): %: $(SRC)/%.cpp $(INCLUDE)/container.h
	$(CC) $(CPPFLAGS) $(SRC)/$@.cpp -o $(BIN)/$@

pdf: build/memoir.pdf

compare:
	$(CC) $(CPPFLAGS) $(SRC)/random_comparer.cpp -o $(BIN)/compare
	$(BIN)/compare 10000 | tee algorithms_comparison | less

build/memoir.pdf: memoir.tex
	pdflatex memoir.tex 
	mkdir -p build
	mv memoir.pdf build/memoir.pdf


clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc pdf compare