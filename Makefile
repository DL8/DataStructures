CC=g++
DEBUG=-g
CXXFLAGS=-std=c++11 -Werror -Wall -pedantic-errors $(DEBUG)

list_test: list_test.o
	$(CC) $(CXXFLAGS) $^ -o $@

list_test.o: list_test.cpp list.h
	$(CC) $(CXXFLAGS) -c $^

clean: clean_o clean_gch
	rm -f list_test
clean_o:
	rm -f *.o
clean_gch:
	rm -f *.gch