/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: Read a logfile and display any entries containing
**                  the word "fail"
**        Date: 25/09/19
**  ==============================================================
*/

#include <stdio.h>
#include <string.h>

#include "logreader.h"

int main( int argc, char* argv[] )
{
    FILE* log;    
    char message[512];
    char month[4];
    int day, hour, minute, second;


    if( argc != 2 )
    {
        printf( "Error: Wrong number of arguments" );
    }
    else
    {
        log = fopen( argv[1], "r" );
        
        if( log == NULL )
        {
            /* Check for file opening error */
            perror( "Error in opening logfile" );
        }
        else if( ferror( log ) )
        {
            /* Check for other file reading errors */
            perror( "Error in reading logfile" );
            fclose( log );
        }
        else
        {
            do
            {
                fscanf( log, "%3s %d %d:%d:%d %[^\n]", 
                    month, &day, &hour, &minute, &second, message );

                if( strstr( message, "fail" ) != NULL )
                {
                    printf( "%s\n", message );
                }

            }
            while( !feof( log ) );

            fclose( log );
        }
    }

    return 0;
}
            
