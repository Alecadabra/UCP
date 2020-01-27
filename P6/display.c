/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: Display an array from file using gnuplot
**        Date: 25/09/19
**  ==============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "plot.h"
#include "display.h"

int main( int argc, char* argv[] )
{
    FILE* file;
    double** data;
    int rows, columns;
    int i, j;

    if( argc != 2 )
    {
        printf( "Error in no. of arguments\n" );
    }
    else
    {
        if( strstr( argv[1], "-" ) != NULL )
        {
            /* Read from standard input stream */
            file = stdin;
        }
        else
        {
            /* Read from a file stream */
            file = fopen( argv[1], "r" );
        }

        if( file == NULL )
        {
            /* Check for file opening error */
            perror( "Error, file could not be opened\n" );
        }
        else if( ferror( file ) )
        {
            /* Check for other error in opening file */
            perror( "Error in opening file" );
            fclose( file );
        }
        else
        {
            fscanf( file, "%d %d", &rows, &columns );
                /* Read row/column dimensions */

            data = (double**)malloc( rows * sizeof(double*) );
                /* Allocate memory for first dimension of array */

            for( i = 0; i < rows; i++ )
            {
                /* Allocate memory for each element in array */
                data[i] = (double*)malloc( columns * sizeof(double) );

                for( j = 0; j < columns; j++ )
                {
                    fscanf( file, "%lf ", &( data[i][j] ) );
                    /* printf( "%f ", data[i][j] ); */
                }
                /* printf( "\n" ); */
            }

            fclose( file );

            plot( data, rows, columns );

            for( i = 0; i < rows; i++ )
            {
                free( data[i] );
            }
            free( data );
        }
    }

    return 0;
}
