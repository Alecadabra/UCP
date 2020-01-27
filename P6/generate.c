/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: Randomly generate an array to file from given
**                  dimensions
**        Date: 25/09/19
**  ==============================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "randomarray.h"

int main( int argc, char* argv[] )
{
    FILE* file;
    double** array;
    int rows, columns;
    int i, j;

    if( argc != 4 )
    {
        printf( "Error, wrong no. of arguments\n" );
    }
    else
    {
        if( strstr( argv[1], "-" ) != NULL )
        {
            /* Read from standard output stream */
            file = stdout;
        }
        else
        {
            /* Read from file stream */
            file = fopen( argv[1], "w" );
        }

        if( file == NULL )
        {
            /* Error in opening file */
            perror( "Error, could not open file" );
        }
        else if( ferror( file ) )
        {
            /* Other error */
            perror( "Error in opening file" );
            fclose( file );
        }
        else
        {
            rows = atoi( argv[2] );
            columns = atoi( argv[3] );

            /* Allocate memory for first dimension of array */
            array = (double**)malloc( rows * sizeof(double*) );

            for( i = 0; i < rows; i++ )
            {
                /* Allocate memory for second dimension of array */
                array[i] = (double*)malloc( columns * sizeof(double) );
            }

            /* Fill the array with data */
            randomArray( array, rows, columns, 3 );

            /* Write array to file */
            fprintf( file, "%d %d\n", rows, columns );

            for( i = 0; i < rows; i++ )
            {
                for( j = 0; j < columns; j++ )
                {
                    fprintf( file, "%f ", array[i][j] );
                }

                fprintf( file, "\n" );

                free( array[i] );
            }

            free( array );

            fclose( file );
        }
    }

    return 0;
}
