# UCP P07 makefile

# Variables ------------------------------------------------------------------

GCC = gcc -Wall -ansi -pedantic -Werror
EXEC = reader LinkedListTest

all: reader linked_list.o LinkedListTest

# reader (Question 1) --------------------------------------------------------

reader : reader.c reader.h
	$(GCC) reader.c -o reader

# linked_list (Questions 3 & 4) ----------------------------------------------

linked_list.o : linked_list.c linked_list.h
	$(GCC) linked_list.c -c

LinkedListTest : LinkedListTest.c linked_list.o
	$(GCC) LinkedListTest.c linked_list.o -o LinkedListTest

# Clean ----------------------------------------------------------------------

clean :
	rm $(EXEC) *.o
