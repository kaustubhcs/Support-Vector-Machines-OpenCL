#!/bin/sh

# Created by KAUSTUBH SHIVDIKAR

TARGET=main.bin
CC=g++
CFLAGS=-Wall -O2 -std=c++0x
LDFLAGS=

ROOT_DIR=$(PWD)
CODE_DIR=$(ROOT_DIR)/src/code
HEADER_DIR=$(ROOT_DIR)/src/headers
INC_DIR=$(ROOT_DIR)/src/inc
LIB_DIR=$(ROOT_DIR)/src/lib
OBJ_DIR=$(ROOT_DIR)/src/obj
BIN_DIR=$(ROOT_DIR)/src/bin
OBJ=$(OBJ_DIR)/main.o $(OBJ_DIR)/functions.o $(OBJ_DIR)/debugger.o

all: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$(TARGET) $(OBJ)
	cp $(BIN_DIR)/$(TARGET) $(ROOT_DIR)

$(OBJ_DIR)/%.o: $(CODE_DIR)/%.cpp
	$(CC) -I$(HEADER_DIR) $(CFLAGS) -c $<
	mv $(@F) $(OBJ_DIR)

clean:
	printf "\n\e[1;32mCleaning all files\e[0m\n"
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*.bin $(ROOT_DIR)/*.bin

run: all
	$(BIN_DIR)/$(TARGET)

test:
	echo "Test Start"
