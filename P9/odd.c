#include <stdlib.h>
#include <stdio.h>

int main( int argc, char* argv[] )
{
    printf( "%d\n", atoi( argv[1] ) | 1 );

    return 0;
}
