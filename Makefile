CC = gcc
CFLAGS = -Wall -Werror -I./include

SRC = src/main.c src/sigmoid.c
OBJ = $(SRC:.c=.o)
EXEC = bin/perceptron

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ) $(EXEC)