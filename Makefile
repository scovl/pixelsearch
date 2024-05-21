CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lgdi32

SRC = src/main.c src/FastFind.c src/User.c
OBJ = $(SRC:.c=.o)

EXEC = pixelSearch

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)
