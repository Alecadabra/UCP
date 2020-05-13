# Variables
OBJ = download.o download_stats.o
CFLAGS = -Wall -pedantic -ansi -Werror

# Conditional Compilation for ALL_STATS
ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean download
endif

download : $(OBJ)
	gcc  $(CFLAGS) $(OBJ) -o download

download.o : download.c download.h download_stats.h
	gcc $(CFLAGS) -c download.c

download_stats.o : download_stats.c download_stats.h download.h
	gcc $(CFLAGS)  -c download_stats.c

clean :
	rm -f download $(OBJ)
