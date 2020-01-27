#include <stdio.h>

int factorial( int n );

int main(void)
{
    int n;

    printf( "Enter a number\n" );
    scanf( "%d", &n );
    while( n >= 0 )
    {
        printf( "%d! = %d\n", n, factorial( n ) );
        printf( "Enter another number\n" );
        scanf( "%d", &n );
    }
    printf( "No negatives >:(((( Bye\n" );

    return 0;
}

int factorial( int n )
{
    int answer = n, i;

    for( i = n - 1; i > 0; i = i - 1 )
    {
        answer = answer * i;
    }

    return answer;
}
