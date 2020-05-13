# Variables
OBJ = order.o user_input.o
CFLAGS = -Wall -pedantic -ansi -Werror

# Conditional Compilation for TEST_HARNESS
ifdef TEST_HARNESS
CFLAGS += -D TEST_HARNESS=1
#TEST_HARNESS : clean download
endif

order : $(OBJ)
	gcc  $(CFLAGS) $(OBJ) -o order

order.o : order.c order.h user_input.h
	gcc $(CFLAGS) -c order.c

user_input.o : user_input.c user_input.h
	gcc $(CFLAGS)  -c user_input.c

clean :
	rm -f order $(OBJ)
