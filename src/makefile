CC = g++
DB = gdb
CFLAGS = -O2 -std=c++11 -Wall -Wextra
VFLAGS = valgrind -v --track-origins=yes --leak-check=full --show-leak-kinds=all
SOURCE = main.cpp data.cpp
EXEC = exec

all: FORCE
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXEC)
test:
	./$(EXEC) ../data/SJC1.dat
debug:
	$(DB) ./$(EXEC)
valgrind:
	valgrind $(VFLAGS) ./$(EXEC)
clear:
	rm -rf $(EXEC)
FORCE:

