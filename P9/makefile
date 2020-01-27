# UCP P9 makefile

# Variables ------------------------------------------------------------------

GCC = gcc -Wall -ansi -pedantic -Werror
EXEC = random wait even odd

all: $(EXEC)

# Random Numbers (Question 1) ------------------------------------------------

random : random.c
	$(GCC) random.c -o random

# Timing (Question 2) --------------------------------------------------------

wait : wait.c
	$(GCC) wait.c -o wait

# Bit Manipulation (Question 3) ----------------------------------------------

even : even.c
	$(GCC) even.c -o even

odd : odd.c
	$(GCC) odd.c -o odd

# Clean ----------------------------------------------------------------------

clean :
	rm $(EXEC)
