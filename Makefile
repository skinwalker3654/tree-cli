#files
SRC = src/main.c
FUNCS = src/tree.c
HEADER = src/tree.h

#compiler
CC = gcc
all: bin/main

bin/main: $(SRC) $(FUNCS)
	@echo "comiling files..."
	mkdir -p bin
	$(CC) $^ -o $@

run:
	@echo "running the program..."
	./bin/main

clean:
	@echo "deleting bin..."
	rm -rf bin

.PHONY: all run clean

