CC = gcc
CCFLAGS = -std=c++11 -Wall -g

SRC1 = main.c manager.c
OBJ1 = $(SRC1:.c=.o)
EXE1 = main

all: $(EXE1)

$(EXE1): $(OBJ1)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -DDEBUG $(CCFLAGS) $<

.PHONY: all clean install
clean:
	rm -f *.o manager
