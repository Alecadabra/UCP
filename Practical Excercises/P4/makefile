# Variables

CFLAGS = -Wall -pedantic -ansi -Werror

# ----------------------------------------------------------

# Executables

all: order arrays utils strUtils

# ----------------------------------------------------------

# Conditional Compilation for TEST_HARNESS

ifdef TEST_HARNESS
CFLAGS += -D TEST_HARNESS=1
#TEST_HARNESS : clean download
endif

# ----------------------------------------------------------

# Order compilation

order : order.o user_input.o
	gcc  $(CFLAGS) order.o user_input.o -o order

order.o : order.c order.h user_input.h
	gcc $(CFLAGS) -c order.c

user_input.o : user_input.c user_input.h
	gcc $(CFLAGS)  -c user_input.c

# ----------------------------------------------------------

# Utils compilation

ifndef TEST_HARNESS
utils : utils.o arrays.o
	gcc $(CFLAGS) utils.o arrays.o -o utils

utils.o : utils.c utils.h arrays.h
	gcc $(CFLAGS) -c utils.c

arrays.o : arrays.c arrays.h
	gcc $(CFLAGS) -c arrays.c
endif

# ----------------------------------------------------------

# Clean

clean :
	rm -f order user_input arrays utils *.o
