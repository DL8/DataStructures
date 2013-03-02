CC=g++
DEBUG=-g
CXXFLAGS=-std=c++11 -Werror -Wall -pedantic-errors $(DEBUG)

test: main.o
	$(CC) $(CXXFLAGS) $^ -o $@

main.o: main.cpp list.h
	$(CC) $(CXXFLAGS) -c $^

clean: clean_o clean_gch
	rm -f test
clean_o:
	rm -f *.o
clean_gch:
	rm -f *.gch