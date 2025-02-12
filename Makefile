CC := gcc
CVERSION := -ansi
CFLAGS := -Wall -pedantic -Wunused-variable -Wunused-function
EXEC := hexcat
###########################################################################
SRC := src
INCLUDE := include
BUILD := build
BIN := bin
TEST := test

all: $(EXEC)

$(EXEC): $(SRC)/main.c $(BUILD)/hexcat.o
	$(CC) $(CVERSION) $(CFLAGS) -o $(BIN)/$(EXEC) $^

$(BUILD)/hexcat.o: $(SRC)/hexcat.c $(INCLUDE)/hexcat.h
	$(CC) $(CVERSION) $(CFLAGS) -c -o $@ $<

test: $(EXEC)
	$(CC) $(CFLAGS) -o $(BIN)/$@ $(TEST)/$@.c
	$(BIN)/$@

.PHONY: clean
clean:
	rm -rf $(BUILD)/*
