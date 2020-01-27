#include <stdio.h>

int pow2( void );

int main( void )
{
    int i = 0;
    for( i = 1; i <= 10; i++ )
    {
	/* Print's the next power of 2 from pow2() */
        printf( "Answer %d = %d\n", i, pow2() );
    }

    return 0;
}

int pow2( void )
{
    /* answer starts at 1 and is doubled each time the method is called */
    static int answer = 1;
    answer *= 2;

    return answer;
}
