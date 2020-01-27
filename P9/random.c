#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RAND_ELEMENT(arr,len) ( (arr)[ rand() % (len) ] )

/*
void* randElement( void** arr, int len )
{
    return arr[ ( rand() % len ) ];
}
*/

int main()
{
    void* arr[5];
    int intArr[] = { 1, 2, 3, 4, 5 };
    int len = 5;
    int i;

    srand( time( NULL ) );

    for( i = 0; i < len; i++ )
    {
        /* Set fields of arr = &intArr */
        arr[i] = (void*)&intArr[i];
    }

    printf( "Chosen element (1-5): %d\n", *(int*)RAND_ELEMENT( arr, len ) );

    /*
    printf( "Chosen element (1-5): %d\n", *(int*)randElement( arr, len ) );
    */

    return 0;
}
