/*  ==========================================================================
**   Author: Alec Maughan 19513869
**  Purpose: Part of implementation of m-n-k tic-tac-toe game as per UCP
**                  assignment spec. Handles all user interface and contains
**                  the main method
**     Date: 20/10/19
**  ==========================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "linked_list.h"
#include "game.h"
#include "tictactoe.h"
#include "file_io.h"

#define TITLE(x) printf( "\n-----------------\n%s\n-----------------\n", (x) )
    /* Prints the title of the current menu option */

/*  --------------------------------------------------------------------------
**   Function: main
**     Import: argc (int), argv (char**)
**     Export: (int)
**  Assertion: Run when the users launches tictactoe. Uses readSettings()
**                  to read the game settings file and displays any errors
**                  in the file or command line arguments
*/
int main( int argc, char* argv[] )
{
    LinkedList* logs = NULL;
        /* Linked list of log entries, storing the game number, turn number,
         * player and location */
    int numGames = 0;
        /* Number of games that have been run */
    int m, n, k;
        /* Values for m, n, and k game settings. The game board has m*n tiles
         * and the player needs k tiles in a row to win. When the game is
         * compiled in editor mode, these values can be changed */
    char* error;
        /* Error string returned from readSettings() in file_io */
    int menuLoop = 0;
        /* Boolean for looping over the main menu */
    int menuSelect;
        /* User selection of main menu option */
    freeFunc freeLogs = &freeLogEntry;
        /* Function pointer to free a logfile, needed to free logs linked 
         * list, actual function is in game.c */
    #ifdef SECRET
        char menuStr[] = 
            "[1] New Game\n"
            "[2] View Settings\n"
            "[3] View Logs\n"
            "[4] Exit\n"
            "Please Select: ";
    #elif defined( EDITOR )
        char menuStr[] = 
            "[1] New Game\n"
            "[2] View Settings\n"
            "[3] View Logs\n"
            "[4] Save Logs\n"
            "[5] Edit Settings\n"
            "[6] Exit\n"
            "Please Select: ";
    #else
        char menuStr[] = 
            "[1] New Game\n"
            "[2] View Settings\n"
            "[3] View Logs\n"
            "[4] Save Logs\n"
            "[5] Exit\n"
            "Please Select: ";
    #endif
        /* Main menu string to output to terminal, different depending on 
         * conditional compilation */

    if( argc != 2 )
    {
        /* Incorrect syntax in command line arguments, correct syntax is
         * ./tictactoe <fileName.txt> */
        printf( "Error: Wrong number of arguments\n" );
    }
    else
    {
        error = readSettingsFile( argv[1], &m, &n, &k );
            /* Reads the game settings file and assigns m, n and k values. An
             * error message is retuned if anything goes wrong */

        if( error != NULL )
        {
            /* An error occured in reading the settings file */
            printf( "%s\n", error );
            free( error );
            error = NULL;
        }
        else
        {
            /* No errors, allocate required heap memory and run main menu */
            logs = createLinkedList();
            menuLoop = 1;
        }
    }

    /* Main menu */
    while( menuLoop )
    {
        /* Show menu and get user selection */
        TITLE( "Main Menu" );
        printf( "\n%s", menuStr );
        scanf( "%d", &menuSelect );

        switch( menuSelect )
        {
            case 1:
            {
                /* New Game */
                TITLE( "New Game" );
                numGames++;
                playTTT( logs, numGames, m, n, k );
                break;
            }
            case 2:
            {
                /* View Settings */
                viewSettings( m, n, k );
                break;
            }
            case 3:
            {
                /* View Logs */
                viewLogs( logs, m, n, k );
                break;
            }
            case 4:
            {
                #ifdef SECRET
                    /* Exit */
                    printf( "Goodbye\n" );
                    menuLoop = 0;
                    break;
                #else
                    /* Save Logs */
                    saveLogs( logs, m, n, k );
                    break;
                #endif
            }
            #ifndef SECRET
                case 5:
                {
                    #ifdef EDITOR
                        /* Edit Settings */
                        editSettings( &m, &n, &k );
                        break;
                    #else
                        /* Exit */
                        printf( "Goodbye\n" );
                        menuLoop = 0;
                        break;
                    #endif
                }
            #endif
            #ifdef EDITOR
                case 6:
                {
                    /* Exit */
                    printf( "Goodbye\n" );
                    menuLoop = 0;
                    break;
                }
            #endif
            default:
            {
                /* Invalid Input */
                printf( "Invalid menu input '%d'", menuSelect );
                break;
            }
        }
    }

    /* Heap Freeing */
    if( logs != NULL )
    {
        freeLinkedList( logs, &freeLogs );
    }

    return 0;
}

/*  -----------------------------------------------------------------------
**   Function: viewSettings()
**     Import: m (int), n (int), k (int)
**     Export: none
**  Assertion: Displays the game settings to the terminal
*/
void viewSettings( int m, int n, int k )
{
    TITLE( "View Settings" );

    printf( "M = %d\nN = %d\nK = %d\n", m, n, k );
}

/*  -----------------------------------------------------------------------
**   Function: viewLogs()
**     Import: logs (LinkedList*), m (int), n (int), k (int)
**     Export: none
**  Assertion: Displays the game settings and logs to the terminal
*/
void viewLogs( LinkedList* logs, int m, int n, int k )
{
    int currGameNo = 0;
        /* Keeps track of the current game number so that when a new game
         * is started a new 'Game X' header can be printed */
    ListNode* currNode;
        /* Current linked list node of log entry */
    LogEntry* currEntry;
        /* Current log entry, typecast from currNode */

    TITLE( "View Logs" );
       
    /* Print Settings */
    printf( "SETTINGS:\n    M: %d\n    N: %d\n    K: %d\n\n", m, n, k );

    /* Iterate over logs linked list */
    currNode = logs->head;
    while( currNode != NULL )
    {
        /* Typecast linked list node into log entry struct */
        currEntry = (LogEntry*)currNode->value;

        if( currEntry->game > currGameNo )
        {
            /* If at the start of logs for a new game */
            printf( "GAME %d:\n", currEntry->game );
            currGameNo++;
        }

        /* Print turn info */
        printf( "    Turn: %d\n    Player: %c\n    Location: %d,%d\n\n",
            currEntry->turn, currEntry->player,
            currEntry->xPos, currEntry->yPos );

        /* Move to next linked list node */
        currNode = currNode->next;
    }
}

/*  -----------------------------------------------------------------------
**   Function: saveLogs()
**     Import: logs (LinkedList*), m (int), n (int), k (int)
**     Export: none
**  Assertion: Saves game settings and logs to a file using writeLogsFile()
*/
void saveLogs( LinkedList* logs, int m, int n, int k )
{
    char fileName[30];
        /* Name for file to save logs to */
    int hour, min, day, month;
        /* Current time for use in file name */
    time_t currTime;
        /* Stores the current time info */
    struct tm* local;
        /* Struct of all different time formats to use */
    char* error;
        /* Error string returned by writeLogsFile(), null if no error
         * occured */

    TITLE( "Save Logs" );

    time( &currTime );
        /* Get current time */
    local = localtime( &currTime );
        /* Convert time_t to struct of different time values */

    /* Assign time variables */
    hour = local->tm_hour;
    min = local->tm_min;
    day = local->tm_mday;
    month = local->tm_mon + 1;
        /* Months were 0-based in 1989, apparently */

    /* Format filename string */
    sprintf( fileName, "MNK_%d-%d-%d_%02d-%02d_%02d-%02d.log",
        m, n, k, hour, min, day, month );

    /* Call file_io.c function to handle file saving */
    error = writeLogsFile( fileName, logs, m, n, k );

    /* If writeLogsFile() returned an error message, print it */
    if( error != NULL )
    {
        printf( "%s\n", error );
        free( error );
        error = NULL;
    }
    else
    {
        printf( "Saved logs to %s\n", fileName );
    }
}

/*  -----------------------------------------------------------------------
**   Function: editSettings
**     Import: m (int*), n (int*), k (int*)
**     Export: none
**  Assertion: Allows the user to edit the game settings
*/
void editSettings( int* m, int* n, int* k )
{
    TITLE( "Edit Settings" );

    printf( "Enter value for M (Previous value: %d): ", *m );
    scanf( "%d", m );

    printf( "Enter value for N (Previous value: %d): ", *n );
    scanf( "%d", n );

    printf( "Enter value for K (Previous value: %d): ", *k );
    scanf( "%d", k );
}
