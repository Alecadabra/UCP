/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: Copy the contents of one file to another
**        Date: 25/09/19
**  ==============================================================
*/

#include <stdio.h>

#include "fileCopy.h"

int main( int argc, char* argv[] )
{
    FILE* srcFile;
    FILE* desFile;
    int read;

    if( argc != 3 )
    {
        printf( "Error: Wrong number of arguments\n" );
    }
    else
    {
        srcFile = fopen( argv[1], "r" );
        desFile = fopen( argv[2], "w" );
        
        if( srcFile == NULL )
        {
            /* Check that srcFile was opened */
            perror( "Error: Could not open source file" );
            fclose( desFile );
        }
        else if( desFile == NULL )
        {
            /* Check that desFile was opened */
            perror( "Error: Could not open destination file" );
            fclose( srcFile );
        }
        else if( ferror( srcFile ) )
        {
            /* Check for errors in srcFile */
            perror( "Error in reading from source file" );
            fclose( srcFile );
        }
        else if( ferror( desFile ) )
        {
            /* Check for errors in desFile */
            perror( "Error with destination file" );
            fclose( desFile );
        }
        else
        {
            read = fgetc( srcFile );
            while( !feof( srcFile ) )
            {
                fputc( (char)read, desFile );
                    /* Insert next char into dest file */

                read = fgetc( srcFile );
                    /* Read next char */
            }
            fclose( srcFile );
            fclose( desFile );
        }
    }

    return 0;
}
