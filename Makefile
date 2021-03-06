CC=g++
DEBUG=-g
CXXFLAGS=-std=c++11 -Werror -Wall -pedantic-errors $(DEBUG)

tests_all: queue_test list_test vector_test set_test

set_test: set_test.o
	$(CC) $(CXXFLAGS) $^ -o $@
vector_test: vector_test.o
	$(CC) $(CXXFLAGS) $^ -o $@
queue_test: queue_test.o
	$(CC) $(CXXFLAGS) $^ -o $@
list_test: list_test.o
	$(CC) $(CXXFLAGS) $^ -o $@

list_test.o: list_test.cpp list.h iterable.h base_iterator.h comparable.h \
const_iterator.h exceptions.h indexable.h container.h test_utils.h
	$(CC) $(CXXFLAGS) -c $^
queue_test.o: queue_test.cpp queue.h pushpop.h list.h iterable.h \
base_iterator.h comparable.h const_iterator.h exceptions.h indexable.h \
container.h test_utils.h
	$(CC) $(CXXFLAGS) -c $^
vector_test.o: vector_test.cpp vector.h list.h iterable.h base_iterator.h \
comparable.h const_iterator.h exceptions.h indexable.h container.h \
test_utils.h
	$(CC) $(CXXFLAGS) -c $^
set_test.o: set_test.cpp set.h comparable.h container.h list.h iterable.h \
base_iterator.h const_iterator.h exceptions.h indexable.h test_utils.h
	$(CC) $(CXXFLAGS) -c $^

clean: clean_o clean_gch
	rm -f list_test queue_test vector_test set_test
clean_o:
	rm -f *.o
clean_gch:
	rm -f *.gch