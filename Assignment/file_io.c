/*  ==========================================================================
**   Author: Alec Maughan 19513869
**  Purpose: Part of implementation of m-n-k tic-tac-toe game as per UCP
**                  assignment spec. Handles all file IO for saving logs to
**                  file and reading settings from file
**     Date: 20/10/19
**  ==========================================================================
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"
#include "game.h"
#include "file_io.h"

/*  --------------------------------------------------------------------------
**   Function: readSettings
**     Import: fileName (char*), m (int*), n (int*), k (int*)
**     Export: error (char*)
**  Assertion: Reads a tictactoe settings file and sets the values of m,
**                  n and k. Returns an error message with any error that
**                  occured or points the string to NULL if no error occurred
*/
char* readSettingsFile( char* fileName, int* m, int* n, int* k )
{
    FILE* file;
        /* File pointer to settings file stream */
    char* error;
        /* String describing any error that occured, returns NULL if no
         * error occured */
    char setting;
        /* Either m, n, or k, denoting which setting is being set */
    int settingValue;
        /* Temp value to store a setting value in */
    int numRead;
        /* Used for error-checking fscanf() */
    int keepReading = 1;
        /* For use in looping through each line in file */

    file = fopen( fileName, "r" );

    /* The error is initialised to the null terminator so that we can tell if
     * no error was set */
    error = (char*)malloc( 128 * sizeof(char) );
    *error = '\0';

    *m = 0;
    *n = 0;
    *k = 0;

    if( file == NULL )
    {
        /* If file did not open */
        strncpy( error, "Error in opening file: ", 25 );
        strncat( error, strerror( errno ), 50 );
            /* Adds to the error string a custom message and the detailed
             * message returned by strerror */
    }
    else if( ferror( file ) )
    {
        /* If there was an error in opening the file */
        strncpy( error, "Error in file reading: ", 25 );
        strncat( error, strerror( errno ), 50 );
        fclose( file );
    }
    else
    {
        /* Successful file open */
        while( keepReading )
        {
            numRead = fscanf( file, "%c=%d\n", &setting, &settingValue );

            if( numRead != 2 )
            {
                /* If file syntax is incorrect */
                strncpy( error, "Error in settings file syntax", 35 );
                keepReading = 0;
            }
            else if( settingValue <= 0 )
            {
                /* Trying to use values out of bounds */
                sprintf( error, "Error in settings file syntax: \
                    Out of bounds assignment of %c", setting );
                keepReading = 0;
            }
            else if( setting == 'm' || setting == 'M' )
            {
                /* M Setting */
                if( *m != 0 )
                {
                    /* M has previously been set */
                    strncpy( error, "Error in settings file syntax: \
                        Duplicate assignment of M", 50 );
                    keepReading = 0;
                }
                else
                {
                    *m = settingValue;
                }
            }
            else if( setting == 'n' || setting == 'N' )
            {
                /* N Setting */
                if( *n != 0 )
                {
                    /* N has previously been set */
                    strncpy( error, "Error in settings file syntax: \
                        Duplicate assignment of N", 50 );
                    keepReading = 0;
                }
                else
                {
                    *n = settingValue;
                }
            }
            else if( setting == 'k' || setting == 'K' )
            {
                /* K Setting */
                if( *k != 0 )
                {
                    /* K has previously been set */
                    strncpy( error, "Error in settings file syntax: \
                        Duplicate assignment of K", 50 );
                    keepReading = 0;
                }
                else
                {
                    *k = settingValue;
                }
            }

            if( keepReading )
            {
                /* If no error was found in this line, keep reading if not at
                 * the end of file */
                keepReading = !feof( file );
            }

        }

        fclose( file );

        if( *m == 0 || *n == 0 || *k == 0 )
        {
            /* Setting(s) where never set */
            strncpy( error,
                "Error in file syntax: Unassigned settings", 45 );
        }
        else if( *error == '\0' )
        {
            /* No error occured */
            free( error );
            error = NULL;
        }
    }

    return error;
}

/*  --------------------------------------------------------------------------
**   Function: writeLogsFile
**     Import: fileName (char*), logs (LinkedList*), m (int), n (int), k (int)
**     Export: error (char*)
**  Assertion: Writes given game logs to a file
*/
char* writeLogsFile( char* fileName, LinkedList* logs, int m, int n, int k )
{
    FILE* file;
        /* File pointer to write to */
    int currGameNo = 0;
        /* Keeps track of the current game number so that when a new game
         * is started a new 'Game X' header can be printed */
    ListNode* currNode;
        /* Current linked list node of log entry */
    LogEntry* currEntry;
        /* Current log entry, typecast from currNode */
    char* error;
        /* String describing any error that occured, returns NULL if no
         * error occured */
 
    file = fopen( fileName, "w" );

    /* The error is initialised to the null terminator so that we can tell if
     * no error was set */ 
    error = (char*)malloc( 128 * sizeof(char) );
    *error = '\0';

    if( file == NULL )
    {
        /* If file did not open */
        strncpy( error, "Error in opening file: ", 25 );
        strncat( error, strerror( errno ), 50 );
            /* Adds to the error string a custom message and the detailed
             * message returned by strerror */
    }
    else if( ferror( file ) )
    {
        /* If there was an error in opening the file */
        strncpy( error, "Error in file reading: ", 25 );
        strncat( error, strerror( errno ), 50 );
        fclose( file );
    }
    else
    {
        /* Successful file open */
       
        /* Print Settings */
        fprintf( file, "SETTINGS:\n    M: %d\n    N: %d\n    K: %d\n\n", 
            m, n, k );

        /* Iterate over logs linked list */
        currNode = logs->head;
        while( currNode != NULL )
        {
            /* Typecast linked list node into log entry struct */
            currEntry = (LogEntry*)currNode->value;

            if( currEntry->game > currGameNo )
            {
                /* If at the start of logs for a new game */
                fprintf( file, "GAME %d:\n", currEntry->game );
                currGameNo++;
            }

            /* Print Turn info */
            fprintf( file, 
                "    Turn: %d\n    Player: %c\n    Location: %d,%d\n\n",
                currEntry->turn, currEntry->player,
                currEntry->xPos, currEntry->yPos );

            /* Move to next linked list node */
            currNode = currNode->next;
        }

        fclose( file );
    }

    if( *error == '\0' )
    {
        /* If error was never set */
        free( error );
        error = NULL;
    }

    return error;
}
