CC = g++
DB = gdb
CFLAGS = -O2 -std=c++11 -Wall -Wextra
VFLAGS = valgrind -v --track-origins=yes --leak-check=full --show-leak-kinds=all
SOURCE = main.cpp data.cpp ant.cpp
EXEC = exec
ANTS = 0
U_MODIFIER = 0.01
P_MODIFIER = 1000
DECAY = 0.8
ITERATIONS = 100

all: FORCE
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXEC)
test:
	./$(EXEC) ../data/SJC1.dat $(ANTS) $(U_MODIFIER) $(P_MODIFIER) $(DECAY) $(ITERATIONS)
debug:
	$(DB) ./$(EXEC)
valgrind:
	$(VFLAGS)
clear:
	rm -rf $(EXEC)
FORCE:

