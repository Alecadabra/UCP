/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: Read a journal file and display the details of the
**                  entry at the given index
**        Date: 27/09/19
**  ==============================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "reader.h"

int main( int argc, char* argv[] )
{
    FILE* file;
    Entry** entries;
    int numEntries;
    int i, chosenIdx;

    if( argc != 2 )
    {
        printf( "Error, Invalid no. of command line arguments\n" );
    }
    else
    {
        file = fopen( "journal.txt", "r" );

        if( file == NULL )
        {
            perror( "Error, file could not be opened" );
        }
        else if( ferror( file ) )
        {
            perror( "Error in opening file" );
            fclose( file );
        }
        else
        {
            /* Get number of entries from file */
            fscanf( file, "%d", &numEntries );

            /* Get chosen index to display */
            chosenIdx = atoi( argv[1] );

            if( chosenIdx >= numEntries )
            {
                /* Given index to display is outside of index bounds */
                printf( "Error, entry %d is too large\n", chosenIdx );
            }
            else
            {
                /* Allocate malloc array of entry structs */
                entries = (Entry**)malloc( numEntries * sizeof(Entry*) );

                for( i = 0; i < numEntries; i++ )
                {
                    /* Allocate space for entry */
                    entries[i] = (Entry*)malloc( sizeof(Entry) );

                    /* Allocate space for the string field in entry struct */
                    entries[i]->text = (char*)malloc( 101 * sizeof(char) );

                    /* Read entry state from file */
                    fscanf( file, "%d/%d/%d\n%101[^\n]",
                        &( entries[i]->day ), &( entries[i]->month ),
                        &( entries[i]->year ), entries[i]->text );
                }

                /* Print entry at given index */
                printf( "%04d-%02d-%02d: %s\n",
                    entries[chosenIdx]->year, entries[chosenIdx]->month,
                    entries[chosenIdx]->day, entries[chosenIdx]->text );

                for( i = 0; i < numEntries; i++ )
                {
                    free( entries[i]->text );
                    free( entries[i] );
                }
                free( entries );

                fclose( file );
            }
        }
    }

    return 0;
}
