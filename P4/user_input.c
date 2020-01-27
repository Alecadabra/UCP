/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: User input utility for use with utils.c
**        Date: 05/09/19
**  ==============================================================
*/
#include <stdio.h>
#include <stdlib.h>

#include "user_input.h"

/*  --------------------------------------------------------------
**    Function: readInts()
**      Import: ptr1 (int*), ptr2 (int*), ptr3 (int*), ptrChar (char*)
**      Export: none
**   Assertion: Reads 3 integers and a character from user input
*/
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
