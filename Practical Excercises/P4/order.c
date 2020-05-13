/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: Utilites for modifying int array order
**        Date: 05/09/19
**  ==============================================================
*/
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
    int i;

    printf( "Testing ascending\n" );
    for( i = 0; i < 5; i++ )
    {
        a = ( rand() / 10000000 );
        b = ( rand() / 10000000 );
        c = ( rand() / 10000000 );

        printf( "[ %d, %d, %d ] --> ", *ptr1, *ptr2, *ptr3 );
        ascending3( ptr1, ptr2, ptr3 );
        printf( "[ %d, %d, %d ]\n", *ptr1, *ptr2, *ptr3 );
    }

    printf( "\nTesting descending\n" );
    for( i = 0; i < 5; i++ )
    {
        a = ( rand() / 10000000 );
        b = ( rand() / 10000000 );
        c = ( rand() / 10000000 );

        printf( "[ %d, %d, %d ] --> ", *ptr1, *ptr2, *ptr3 );
        descending3( ptr1, ptr2, ptr3 );
        printf( "[ %d, %d, %d ]\n", *ptr1, *ptr2, *ptr3 );
    }
#else
    /* Using user input */
    char ctrlFlag;
    char* charPtr = &ctrlFlag;
    OrderMethod orderMethod;

    readInts( ptr1, ptr2, ptr3, charPtr );
    orderMethod = order( *charPtr );

    printf( "[ %d, %d, %d ] --> ", *ptr1, *ptr2, *ptr3 );
    (*orderMethod)( ptr1, ptr2, ptr3 );
    printf( "[ %d, %d, %d ]\n", *ptr1, *ptr2, *ptr3 );
#endif

    return 0;
}

/*  --------------------------------------------------------------
**    Function: order()
**      Import: ctrlFlag (char)
**      Export: OrderMethod (function pointer)
**   Assertion: Returns a function pointer based on a char either A or D
*/
#ifndef TEST_HARNESS
static OrderMethod order( char ctrlFlag )
{
    OrderMethod outMethod;

    if( ( ctrlFlag == 'A' ) || ( ctrlFlag == 'a' ) )
    {
        outMethod = &ascending3;
    }
    else if( ( ctrlFlag == 'D' ) || ( ctrlFlag == 'd' ) )
    {
        outMethod = &descending3;
    }
    else
    {
        outMethod = NULL;
    }

    return outMethod;
}
#endif

/*  --------------------------------------------------------------
**    Function: ascending2
**      Import: ptr1 (int*), ptr2 (int*)
**      Export: none
**   Assertion: Converts two integers to ascending order
*/
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

/*  --------------------------------------------------------------
**    Function: ascending3
**      Import: ptr1 (int*), ptr2 (int*), ptr3 (int*)
**      Export: none
**   Assertion: Converts 3 integers to ascending order
*/
static void ascending3( int* ptr1, int* ptr2, int* ptr3 )
{
    ascending2( ptr1, ptr2 );
    ascending2( ptr2, ptr3 );
    ascending2( ptr1, ptr2 );
}

/*  --------------------------------------------------------------
**    Function: descending2
**      Import: ptr1 (int*), ptr2 (int*)
**      Export: none
**   Assertion: Converts two integers to descending order
*/
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

/*  --------------------------------------------------------------
**    Function: descending3
**      Import: ptr1 (int*), ptr2 (int*), ptr3 (int*)
**      Export: none
**   Assertion: Converts 3 integers to descending order
*/
static void descending3( int* ptr1, int* ptr2, int* ptr3 )
{
    descending2( ptr1, ptr2 );
    descending2( ptr2, ptr3 );
    descending2( ptr1, ptr2 );
}
