/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: User Interface for arrays.c
**        Date: 05/09/19
**  ==============================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "arrays.h"

int main( int argc, char* argv[] )
{
    int length = argc - 2;
    int menu;
    int* intArr = (int*)calloc( length, sizeof( int ) );
        /* calloc array of int */

    if( argc < 3 )
    {
        /* Set menu to invalid argument if there aren't enough arguments */
        menu = 4;
    }
    else
    {
        /* If correct number of arguments */
        menu = argToMenu( argv[1] );
        stringToInt( ( &argv[2] ), intArr, length );
    }

    switch( menu )
    {
        case 1:
        {
            /* sum() */
            printf( "Sum of " );
            printArray( intArr, length );
            printf( " = %d\n", sum( intArr, length ) );
            break;
        }
        case 2:
        {
            /* max() */
            printf( "Max value of " );
            printArray( intArr, length );
            printf( " = %d\n", intArr[ max( intArr, length ) ] );
            break;
        }
        case 3:
        {
            /* reverse() */
            printf( "Reverse of " );
            printArray( intArr, length );
            printf( " = " );
            reverse( intArr, length );
            printArray( intArr, length );
            printf( "\n" );
            break;
        }
        case 4:
        {
            /* Error */
            printf( "Error in syntax\n" );
            break;
        }
    }
    return 0;
}

/*  --------------------------------------------------------------
**    Function: argToMenu()
**      Import: arg (char*)
**      Export: menu (int)
**   Assertion: Returns an integer based on String menu selection
*/
int argToMenu( char* arg )
{
    int menu;

    strToUpper( arg );
        /* Convert to uppercase */

    if( strcmp( "SUM", arg ) == 0 )
    {
        /* sum() */
        menu = 1;
    }
    else if( strcmp( "MAX", arg ) == 0 )
    {
        /* max() */
        menu = 2;
    }
    else if( strcmp( "REVERSE", arg ) == 0 )
    {
        /* reverse() */
        menu = 3;
    }
    else
    {
        /* Invalid argument */
        menu = 4;
    }

    return menu;
}

/*  --------------------------------------------------------------
**    Function: strToUpper
**      Import: str (char*)
**      Export: none
**   Assertion: Converts a given string to uppercase
*/
void strToUpper( char* str )
{
    int i;

    /* (c) Not using array index notation or strlen() */
    i = 0;
    while( *( str + i ) != '\0' )
    {
        if( ( *( str + i ) > 96 ) && ( *( str + i ) < 123 ) )
        {
            /* If lowercase */
            *( str + i ) -= 32;
        }

        i++;
    }
 

    /* (b) Not using strlen(), using array index notation
    i = 0;
    while( str[i] != '\0' )
    {
        if( ( str[i] > 96 ) && ( str[i] < 123 ) )
        {
            str[i] -= 32;
        }

        i++;
    }
    */
 

    /* (a) Using strlen(), using array index notation
    for( i = 0; i < strlen( str ); i++ )
    {
        if( ( str[i] > 96 ) && ( str[i] < 123 ) )
        
            str[i] -= 32;
        }
    }
    */
}
