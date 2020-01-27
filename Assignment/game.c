/*  ==========================================================================
**   Author: Alec Maughan 19513869
**  Purpose: Part of implementation of m-n-k tic-tac-toe game as per UCP
**                  assignment spec. Handles the game of tic tac toe itself,
**                  including a bit of user IO
**     Date: 20/10/19
**  ==========================================================================
*/

#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"
#include "game.h"

#define COLOUR_SET() printf( "\033[1;33m" )
    /* Makes all printed text yellow */
#define COLOUR_RESET() printf( "\033[0m" )
    /* Makes all printed text back to normal */
#define IN_BOUNDS(x, y, m, n) ( (x) >= 0 && (y) >= 0 && (x) < (m) && \
    (y) < (n) )
    /* Bounds check for coordinates in the game board */

/*  -----------------------------------------------------------------------
**   Function: playTTT()
**     Import: logs (LinkedList*), game (int), m (int), n (int), k (int)
**     Export: none
**  Assertion: Handles the game of tictactoe itself, this function stores
**                  all neccassary data and calls functions as needed
*/
void playTTT( LinkedList* logs, int game, int m, int n, int k )
{
    char** board;
        /* 2D Matrix of the game board */
    char player = 'O';
        /* Either 'O' or 'X' for which player's turn it currently is */
    int turn = 0;
        /* Turn number */
    char winner = ' ';
        /* Space char if no winner, char of the winning player if they have 
         * won */
    int xPos, yPos;
        /* Coordinates that a turn is taking place */
    int i, j;
        /* For loop indexes for allocating & freeing heap memory for board 
         * matrix */

    /* Heap allocation for game board matrix */
    board = (char**)malloc( m * sizeof(char*) );
    for( i = 0; i < m; i++ )
    {
        board[i] = (char*)malloc( n * sizeof(char) );
        for( j = 0; j < n; j++ )
            /* Initialize board */
            board[i][j] = ' ';
    }

    while( winner == ' ' && !boardFull( board, m, n ) )
    {
        printBoard( board, m, n );
        takeTurn( board, player, &xPos, &yPos, m, n );
        turn++;
        addLog( logs, game, turn, player, xPos, yPos );
        winner = findWinner( board, player, xPos, yPos, m, n, k );
        printf( "\n" );

        /* Swap to next player */
        if( player == 'O' )
        {
            player = 'X';
        }
        else
        {
            player = 'O';
        }
    }

    /* Display Winner */
    printBoard( board, m, n );
    if( winner == ' ' )
    {
        /* Stalemate */
        printf( "\nNobody wins\n" );
    }
    else if( winner == 'O' )
    {
        printf( "\nO Wins!\n" );
    }
    else
    {
        printf( "\nX Wins!\n" );
    }

    /* Heap freeing */
    for( i = 0; i < m; i++ )
    {
        free( board[i] );
    }
    free( board );

}

/*  -----------------------------------------------------------------------
**   Function: printBoard()
**     Import: board (char**), m (int), n (int)
**     Export: none
**  Assertion: Displays the game board to the terminal
*/
void printBoard( char** board, int m, int n )
{
    int i, j;
        /* For loop indexes */

    /* X Coordiantes */
    printf( "\n   " );
    for( i = 0; i < m; i++ )
    {
        if( m < 11 )
        {
            printf( "%d ", i );
        }
        else
        {
            /* If numbers are potentially double-digits, we print the 1st
             * digit here and then the second later */
            printf( "%d ", ( i / 10 ) );
        }
    }
    if ( m >= 11 )
    {
        printf( "\n   " );
        for( i = 0; i < m; i++ )
        {
            /* If numbers are potentially double-digits, print the 2nd digit
             * here */
            printf( "%d ", ( i - ( i / 10 * 10 ) ) );
        }
    }

    /* 1st line '+-+-+-+' */
    printf( "\n  +" );
    for( i = 0; i < m; i++ )
    {
        printf( "-+" );
    }

    /* The board, for each loop: '1 |O| |X|'
     *                           '  +-+-+-+' */
    /* Iterate through each row */
    for( i = 0; i < n; i++ )
    {
        /* Print the Y coordinates */
        if( n < 11 )
        {
            printf( "\n%d |", i );
        }
        else
        {
            /* If numbers are double digits we print leading zeroes */
            printf( "\n%02d|", i );
        }

        /* Print actual entries '|O| |X|' */
        /* Iterate through each column */
        for( j = 0; j < m; j++ )
        {
            COLOUR_SET();
            printf( "%c", board[j][i] );
                /* It's [j][i] not [i][j] as we're iterating through row by
                 * row for each column, as that makes printing much easier
                 * than if we iterated through each column by column */
            COLOUR_RESET();
            printf( "|" );
        }

        /* Print line under each entry line */
        printf( "\n  +" );
        for( j = 0; j < m; j++ )
        {
            printf( "-+" );
        }
    }
}

/*  -----------------------------------------------------------------------
**   Function: takeTurn()
**     Import: board (char**), player (char), xPos (int), yPos (int), 
**                  m (int), n (int)
**     Export: none
**  Assertion: Handles a player taking their turn
*/
void takeTurn( char** board, char player, int* xPos, int* yPos, int m, int n )
{
    int numRead = 0;
        /* Error checking for scanf */
    
    *xPos = 0;
    *yPos = 0;

    printf( "\nPlayer %c take turn (X,Y): ", player );
    numRead = scanf( "%d,%d", xPos, yPos );

    while( numRead != 2 || !IN_BOUNDS( *xPos, *yPos, m, n ) || 
        board[*xPos][*yPos] != ' ' )
    {
        /* Invalid input */
        printf( "Invalid coordinates, take turn (X,Y): " );
        numRead = scanf( "%d,%d", xPos, yPos );
    }

    board[*xPos][*yPos] = player;
}

/*  -----------------------------------------------------------------------
**   Function: addLog()
**     Import: logs (LinkedList*), game (int), turn (int), player (char),
**                  xPos (int), yPos (int)
**     Export: none
**  Assertion: Adds a game log entry to the logs linked list
*/
void addLog( LinkedList* logs, int game, int turn, char player, int xPos, 
    int yPos )
{
    LogEntry* newEntry = (LogEntry*)malloc( sizeof(LogEntry) );
        /* Entry to add to list */

    /* Set fields */
    newEntry->game = game;
    newEntry->turn = turn;
    newEntry->player = player;
    newEntry->xPos = xPos;
    newEntry->yPos = yPos;

    insertLast( logs, newEntry );
}

/*  -----------------------------------------------------------------------
**   Function: findWinner()
**     Import: logs (LinkedList*), player (char), xPos (int), yPos (int),
**                  m (int), n (int), k (int)
**     Export: winner (char)
**  Assertion: Looks for a winner by traversing 4 different ways through
**                  the position given
*/
char findWinner( char** board, char player, int xPos, int yPos, int m, int n,
    int k )
{
    int x, y;
        /* Current x & y coordiates */
    int matches;
        /* Current number of consecutive tiles in a row */
    char winner = ' ';
        /* The player that has won, ' ' if no winner */

    /* We go in a line, either horizontal, vertical or diagonal that passes
     * through the point given, if we find k consecutive entries of the given
     * player, they win */

    /* Check horizontal */
    x = 0;
    y = yPos;
    matches = 0;
    while( matches < k && x < m )
    {
        if( board[x][y] == player )
        {
            matches++;
        }
        else
        {
            matches = 0;
        }
        x++;
    }

    /* Check vertical */
    if( matches < k )
    {
        y = 0;
        x = xPos;
        matches = 0;
    }
    while( matches < k && y < n )
    {
        if( board[x][y] == player )
        {
            matches++;
        }
        else
        {
            matches = 0;
        }
        y++;
    }

    /* Check ascending(?) diagonal ( This one: / )
     * As we traverse, x increases and y decreases */
    if( matches < k )
    {
        x = xPos;
        y = yPos;
        matches = 0;
    }
    while( x - 1 >= 0 && y + 1 < n )
    {
        /* Find the initial values of x & y that are still in-line with xPos
         * and yPos for this diagonal */
        x--;
        y++;
    }
    while( matches < k && IN_BOUNDS( x, y, m, n ) )
    {
        if( board[x][y] == player )
        {
            matches++;
        }
        else
        {
            matches = 0;
        }
        x++;
        y--;
    }

    /* Check other diagonal ( This one: \ )
     * As we traverse, x increases and y increases */
    if( matches < k )
    {
        x = xPos;
        y = yPos;
        matches = 0;
    }
    while( x - 1 >= 0 && y - 1 >= 0 )
    {
        /* Find the initial values of x & y that are still in-line with xPos
         * and yPos for this diagonal */
        x--;
        y--;
    }
    while( matches < k && IN_BOUNDS( x, y, m, n ) )
    {
        if( board[x][y] == player )
        {
            matches++;
        }
        else
        {
            matches = 0;
        }
        x++;
        y++;
    }

    /* Check if a winner was found */
    if( matches == k )
    {
        winner = player;
    }
    else
    {
        winner = ' ';
    }

    return winner;
}

/*  -----------------------------------------------------------------------
**   Function: boardFull()
**     Import: board (char**), m (int), n (int)
**     Export: full (int)
**  Assertion: Traverses through the board to find any entry that is empty
*/
int boardFull( char** board, int m, int n )
{
    int full = 1;
        /* Boolean for the board being full, we assume it's full and change
         * if we find an empty entry */
    int x = 0, y = 0;
        /* Current x and y coordiantes */

    /* Iterate through each column */
    while( full && x < m )
    {
        y = 0;
        /* Iterate through each row */
        while( full && y < n )
        {
            if( board[x][y] == ' ' )
            {
                /* If this entry is empty, the board is not full */
                full = 0;
            }
            y++;
        }
        x++;
    }

    return full;
}

/*  -----------------------------------------------------------------------
**   Function: freeLogEntry()
**     Import: inPtr (void*)
**     Export: none
**  Assertion: Frees a given log entry pointer, used to free the logs linked
**                  list
*/
void freeLogEntry( void* inPtr )
{
    LogEntry* inEntry = (LogEntry*)inPtr;
        /* Typecast paramater to usable datatype */
    free( inEntry );
}
