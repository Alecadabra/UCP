#include <stdio.h>
#include <stdlib.h>

#include "user_input.h"

void readInts( int* ptr1, int* ptr2, int* ptr3, char* ptrChar )
{
    printf( "Enter 1st integer: " );
    scanf( "%d", ptr1 );
    printf( "Enter 2nd integer: " );
    scanf( "%d", ptr2 );
    printf( "Enter 3rd integer: " );
    scanf( "%d", ptr3 );
    printf( "Enter either \"A\" for ascending order or \"D\" for " );
    printf( "descending order: " );
    scanf( " %c", ptrChar );
}
