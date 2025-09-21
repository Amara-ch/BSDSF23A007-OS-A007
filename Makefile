CC = gcc
CFLAGS = -Iinclude -Wall -g
SRC = src
OBJ = obj
BIN = bin

OBJS = $(OBJ)/main.o $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
TARGET = $(BIN)/client

all: $(TARGET)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJ)/*.o $(TARGET)
