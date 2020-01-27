#ifndef GAME_H
    
    #define GAME_H

    /* Log entry */
    typedef struct
    {
        int game;
            /* Game number */
        int turn;
            /* Turn number */
        char player;
            /* Player char, either 'O' or 'X' */
        int xPos, yPos;
            /* Coordinates that a turn took place */
    } LogEntry;

    /* Function forward declarations */
    void playTTT( LinkedList*, int, int, int, int );
    void printBoard( char**, int, int );
    void takeTurn( char**, char, int*, int*, int, int );
    void addLog( LinkedList*, int, int, char, int, int );
    char findWinner( char**, char, int, int, int, int, int );
    int boardFull( char**, int, int );
    void freeLogEntry( void* );

#endif
