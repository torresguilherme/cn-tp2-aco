CC = g++
DB = gdb
CFLAGS = -O2 -std=c++11 -Wall -Wextra
VFLAGS = valgrind -v --track-origins=yes --leak-check=full --show-leak-kinds=all
SOURCE = main.cpp data.cpp ant.cpp
EXEC = exec
P_MODIFIER = 100
DECAY = 0.8

all: FORCE
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXEC)

test1:
	./$(EXEC) ../data/SJC1.dat $(P_MODIFIER) $(DECAY)
test2:
	./$(EXEC) ../data/SJC2.dat $(P_MODIFIER) $(DECAY)
test3:
	./$(EXEC) ../data/SJC3b.dat $(P_MODIFIER) $(DECAY)
valgrind:
	$(VFLAGS)
clear:
	rm -rf $(EXEC)
FORCE:

