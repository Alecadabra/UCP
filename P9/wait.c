#include <stdlib.h>
#include <time.h>

int main( int argc, char* argv[] )
{
    time_t initTime = time( NULL );

    while( time( NULL ) - initTime < atoi( argv[1] ) );
        /* Loop until time is elapsed */
    
    return 0;
}
