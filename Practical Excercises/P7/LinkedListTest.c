/*
 * File: LinkedListTest.c
 * File Created: Friday, 6th September 2019 11:40:35 am
 * Author: Jonathon Winter
 * -----
 * Last Modified: Tuesday, 24th September 2019 2:29:59 pm
 * Modified By: Jonathon Winter
 * -----
 * Purpose: Semi complete Test harness for a Generic Linked List in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

#define PASS() printf( "%c[1;32mPASSED%c[0;00m\n", 27, 27 )
#define FAIL() printf( "%c[1;31mFAILED%c[0;00m\n", 27, 27 )

char* toString( void* var )
{
    return (char*)var;
}

void freeString( void* var )
{
    free( (char*)var );
}

int main(int argc, char const *argv[])
{
    LinkedList* list = NULL;
    char* value;
    char* input1 = (char*)malloc(sizeof(char)*6);
    char* input2 = (char*)malloc(sizeof(char)*4);
    char* input3 = (char*)malloc(sizeof(char)*3);
    char* input4 = (char*)malloc(sizeof(char)*8);

    char* (*toStringPtr)( void* ) = &toString;
    void (*freeStringPtr)( void* ) = &freeString;

    strncpy(input1,"hello",6);
    strncpy(input2,"bye",4);
    strncpy(input3,"hi",3);
    strncpy(input4,"goodbye",8);

    /* CREATING */
    printf("Creating List: ");
    list = createLinkedList();
    if(list == NULL || list->head != NULL)
    {
        FAIL();
    }
    else
    {
        PASS();
    }

    printf("Testing Count: ");
    if(list->count == 0)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    /* INSERTING FIRST */
    printf("Inserting First: ");
    insertFirst(list,input1);
    if(list->head == NULL)
    {
        FAIL();
    }
    else if(strncmp((char*)list->head->value, input1, strlen(input1)+1)==0)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    printf("Testing Count: ");
    if(list->count == 1)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    printf("Inserting First (2): ");
    insertFirst(list,input2);
    if(list->head == NULL)
    {
        FAIL();
    }
    else if(strncmp((char*)list->head->value, input2, strlen(input2)+1)==0 && 
        strncmp((char*)list->tail->value, input1, strlen(input1)+1)==0)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    printf("Testing Count: ");
    if(list->count == 2)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    /* INSERTING LAST */
    printf( "Inserting Last: " );
    insertLast( list, input3 );
    if(list->tail == NULL)
    {
        FAIL();
    }
    else if(strncmp((char*)list->tail->value, input3, strlen(input3)+1)==0 && 
        strncmp((char*)list->head->value, input2, strlen(input2)+1)==0)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    printf("Testing Count: ");
    if(list->count == 3)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    printf( "Inserting Last (2): " );
    insertLast( list, input4 );
    if(list->tail == NULL)
    {
        FAIL();
    }
    else if(strncmp((char*)list->tail->value, input4, strlen(input4)+1)==0 && 
        strncmp((char*)list->head->value, input2, strlen(input2)+1)==0)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    printf("Testing Count: ");
    if(list->count == 4)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    /* REMOVING FIRST */
    printf("Remove First: ");
    value = (char*)removeFirst(list);

    if(strncmp(value, input2, strlen(input2)+1) == 0)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    printf("Testing Count: ");
    if(list->count == 3)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    /* REMOVING LAST */
    printf("Remove Last: ");
    value = (char*)removeLast(list);

    if(strncmp(value, input4, strlen(input4)+1) == 0)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    printf("Testing Count: ");
    if(list->count == 2)
    {
        PASS();
    }
    else
    {
        FAIL();
    }

    /* PRINTING */
    printf("Print Linked List: ");
    printLinkedList( list, &toStringPtr );
    printf( "\t Expected: [ hello, hi ]\n" );

    /* FREEING */
    printf("Freeing Linked List.\n");
    freeLinkedList( list, &freeStringPtr );

    /* Freeing Test Harness variables not in list */
    free( input2 );
    free( input4 );

    return 0;
}
