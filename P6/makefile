# UCP P06 makefile

# Variables ------------------------------------------------------------------

GCC = gcc -Wall -ansi -pedantic -Werror -g
EXEC = logreader fileCopy display generate

all: fileCopy logreader display generate

# fileCopy (Question 1) ------------------------------------------------------

fileCopy : fileCopy.c fileCopy.h
	$(GCC) fileCopy.c -o fileCopy

# logreader (Question 2) -----------------------------------------------------

logreader : logreader.c logreader.h
	$(GCC) logreader.c -o logreader

# display (Question 3) -------------------------------------------------------

plot.o : plot.c plot.h
	$(GCC) plot.c -c

display : display.h plot.o
	$(GCC) display.c plot.o -o display

# generate (Question 4) ------------------------------------------------------

randomarray.o : randomarray.c randomarray.h plot.o
	$(GCC) randomarray.c -c

generate : generate.c randomarray.o plot.o
	$(GCC) generate.c randomarray.o plot.o -o generate

# Clean ----------------------------------------------------------------------

clean :
	rm $(EXEC) *.o
