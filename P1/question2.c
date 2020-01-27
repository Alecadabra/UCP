#include <stdio.h>

int main( void )
{
    int num1, num2;

    /* (a) */
    printf( "Please enter two integers\n" );
    scanf( "%d", &num1 );
    scanf( "%d", &num2 );

    /* (b), (c) */
    if( num1 % num2 == 0 )
    {
        printf( "%d and %d are divisible\n", num1, num2 );
    }
    else
    {
        printf( "%d and %d are not divisible\n", num1, num2 );
    }

    return 0;

}
