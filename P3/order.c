#include <stdio.h>
#include <stdlib.h>

#include "order.h"
#include "user_input.h"

int main()
{
    int a, b, c;
    int* ptr1 = &a;
    int* ptr2 = &b;
    int* ptr3 = &c;

#ifdef TEST_HARNESS
    /* Using hardcoded values like a test harness */
    printf( "Testing ascending\n" );
    a = 3;
    b = 2;
    c = 1;
    testAscending( ptr1, ptr2, ptr3 );
    a = 10;
    b = 5;
    c = 0;
    testAscending( ptr1, ptr2, ptr3 );
    a = 100;
    b = 10;
    c = 1000;
    testAscending( ptr1, ptr2, ptr3 );

    printf( "\nTesting descending\n" );
    a = 1;
    b = 2;
    c = 3;
    testDescending( ptr1, ptr2, ptr3 );
    a = 0;
    b = 5;
    c = 10;
    testDescending( ptr1, ptr2, ptr3 );
    a = 1000;
    b = 10;
    c = 100;
    testDescending( ptr1, ptr2, ptr3 );
#else
    /* Using user input */
    char controlFlag;
    char* charPtr = &controlFlag;

    readInts( ptr1, ptr2, ptr3, charPtr );
    if( ( *charPtr == 'A' ) || ( *charPtr == 'a' ) )
    {
        printf( "Ascending order:\n" );
        testAscending( ptr1, ptr2, ptr3 );
    }
    else if( ( *charPtr == 'D' ) || ( *charPtr == 'd' ) )
    {
        printf( "Descending order:\n" );
        testDescending( ptr1, ptr2, ptr3 );
    }
    else
    {
        printf( "Invalid character" );
    }
#endif

    return 0;
}

static void testAscending( int* ptr1, int* ptr2, int* ptr3 )
{
    printf( "[ %d, %d, %d ] --> ", *ptr1, *ptr2, *ptr3 );
    ascending3( ptr1, ptr2, ptr3 );
    printf( "[ %d, %d, %d ]\n", *ptr1, *ptr2, *ptr3 );
}

static void testDescending( int* ptr1, int* ptr2, int* ptr3 )
{
    printf( "[ %d, %d, %d ] --> ", *ptr1, *ptr2, *ptr3 );
    descending3( ptr1, ptr2, ptr3 );
    printf( "[ %d, %d, %d ]\n", *ptr1, *ptr2, *ptr3 );
}

static void ascending2( int* ptr1, int* ptr2 )
{
    int tempVar = 0;
    int* tempPtr = &tempVar;
    if( *ptr1 > *ptr2 )
    {
        *tempPtr = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = *tempPtr;
    }
}

static void ascending3( int* ptr1, int* ptr2, int* ptr3 )
{
    ascending2( ptr1, ptr2 );
    ascending2( ptr2, ptr3 );
    ascending2( ptr1, ptr2 );
}

static void descending2( int* ptr1, int* ptr2 )
{
    int tempVar = 0;
    int* tempPtr = &tempVar;
    if( *ptr1 < *ptr2 )
    {
        *tempPtr = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = *tempPtr;
    }
}

static void descending3( int* ptr1, int* ptr2, int* ptr3 )
{
    descending2( ptr1, ptr2 );
    descending2( ptr2, ptr3 );
    descending2( ptr1, ptr2 );
}
