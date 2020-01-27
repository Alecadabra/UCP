/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: Host of array modification utilites
**        Date: 05/09/19
**  ==============================================================
*/
#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

/*
int test()
{
    int array[length];
    int i, j, k;
    Variables for string conversion
    char* strArr[length] = { "12", "-43", "0", "123", "-0" };
    int intArr[length];

    printf( "\nInitial array: " );
    for( i = 0; i < length; i++ )
    {
        array[i] = i;
        printf( "%d, ", i );
    }

    printf( "\n\nSum: %d", sum( array ) );

    printf( "\n\nMax: %d", max( array ) );

    printf( "\n\nReversed array: " );
    reverse( array );
    for( j = 0; j < length; j++ )
    {
        printf( "%d, ", array[j] );
    }

    printf( "\n\nString conversion:\n" );
    stringToInt( strArr, intArr, length );
    printf( "\tString array: " );
    for( k = 0; k < length; k++ )
    {
        printf( "%s, ", strArr[k] );
    }
    printf( "\n\tResulting int array: " );
    for( k = 0; k < length; k++ )
    {
        printf( "%d, ", intArr[k] );
    }

    printf( "\n\nArray output:\n" );
    printf( "First array for sum, max and reverse: " );
    printArray( array, length );
    printf( "\nArray converted from string: " );
    printArray( intArr, length );
    printf( "\n\n" );

    return 0;
}
*/


/*  --------------------------------------------------------------
**    Function: sum
**      Import: array (int*), length (int)
**      Export: sum (int)
**   Assertion: Returns the sum of all elements in the given array
*/
int sum( int* array, int length )
{
    int i;
    int sum = 0;

    /* Adds all values in array together */
    for( i = 0; i < length; i++ )
    {
        sum += array[i];
    }

    return sum;
}

/*  --------------------------------------------------------------
**    Function: max
**      Import: array (int*), length (int)
**      Export: currMaxIdx (int)
**   Assertion: Returns the max value in the given array
*/
int max( int* array, int length )
{
    int i;
    int currMax = array[0];
    int currMaxIdx = 0;

    /* Overwrites the current max when it finds a larger value */
    for( i = 1; i < length; i++ )
    {
        if( array[i] > currMax )
        {
            currMaxIdx = i;
            currMax = array[i];
        }
    }

    return currMaxIdx;
}

/*  --------------------------------------------------------------
**    Function: reverse
**      Import: array (int*), length (int)
**      Export: none
**   Assertion: Reverses the order of the given array
*/
void reverse( int* array, int length )
{
    int* revArr = (int*)calloc( length, sizeof( int ) );
        /* Array to put reversed elements into */
    int i;
    int j = length - 1;

    /* Two indexes, one goes forward, one goes backward, reversing order of
    original array */
    for( i = 0; i < length; i++ )
    {
        revArr[j] = array[i];
        j--;
    }

    /* Copies elements of reversed array into original array */
    for( i = 0; i < length; i++ )
    {
        array[i] = revArr[i];
    }
}

/*  --------------------------------------------------------------
**    Function: stringToInt
**      Import: charArr (char**), intArr (int*), length (int)
**      Export: none
**   Assertion: Converts a string array to an int array
*/
void stringToInt( char** charArr, int* intArr, int length )
{
    int i;
    for( i = 0; i < length; i++ )
    {
        intArr[i] = atoi( charArr[i] );
            /* atoi() converts string to int */
    }
}

/*  --------------------------------------------------------------
**    Function: printArray
**      Import: array (int*), length (int)
**      Export: none
**   Assertion: Prints an array of integers to screen
*/
void printArray( int* array, int length )
{
    int i = 0;

    printf( "{" );
    for( i = 0; i < length; i++ )
    {
        printf( "%d", array[i] );
            /* Print the current element */
        
        if( i + 1 < length )
        {
            /* If this is not the last element to display, add a comma */
            printf( ", " );
        }
    }
    printf( "}" );
}
