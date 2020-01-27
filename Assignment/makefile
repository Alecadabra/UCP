# Alec Maughan 19513869
# UCP Assignment Makefile
# 20/10/19

# Variables ------------------------------------------------------------------

CFLAGS = -Wall -Werror -ansi -pedantic -std=c89
EXEC = tictactoe

all: file_io.o linked_list.o game.o $(EXEC)

# Conditional Compilation ----------------------------------------------------

ifdef EDITOR
CFLAGS += -D EDITOR
EDITOR : clean all
endif

ifdef SECRET
CFLAGS += -D SECRET
SECRET : clean all
endif

# Files ----------------------------------------------------------------------

linked_list.o : linked_list.c linked_list.h
	gcc $(CFLAGS) linked_list.c -c

file_io.o : file_io.c file_io.h game.h linked_list.h
	gcc $(CFLAGS) file_io.c -c

game.o : game.c game.h linked_list.h
	gcc $(CFLAGS) game.c -c

$(EXEC) : tictactoe.c tictactoe.h file_io.o linked_list.o game.o
	gcc $(CFLAGS) tictactoe.c file_io.o linked_list.o game.o -o $(EXEC)

# Clean ----------------------------------------------------------------------

clean :
	rm $(EXEC) *.o
