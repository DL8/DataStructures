CC=g++
DEBUG=-g
CXXFLAGS=-std=c++11 -Werror -Wall -pedantic-errors $(DEBUG)

tests_all: queue_test list_test
queue_test: queue_test.o
	$(CC) $(CXXFLAGS) $^ -o $@
list_test: list_test.o
	$(CC) $(CXXFLAGS) $^ -o $@

queue_test.o: queue_test.cpp queue.h pushpop.h list.h iterable.h base_iterator.h exceptions.h test_utils.h
	$(CC) $(CXXFLAGS) -c $^
list_test.o: list_test.cpp list.h iterable.h base_iterator.h exceptions.h test_utils.h
	$(CC) $(CXXFLAGS) -c $^

clean: clean_o clean_gch
	rm -f list_test queue_test
clean_o:
	rm -f *.o
clean_gch:
	rm -f *.gch