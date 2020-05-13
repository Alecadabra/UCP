/*  ==============================================================
**      Author: Alec Maughan 19513869
**     Purpose: Implementation of double ended, doubly-linked list
**        Date: 27/09/19
**  ==============================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linked_list.h"

/*  -----------------------------------------------------------------------
**    Function: createLinkedList()
**      Import: none
**      Export: list (LinkedList*)
**   Assertion: Creates a pointer to a linked list, allocates memory, sets 
**                  head and tail fields to null and sets count to zero
*/
LinkedList* createLinkedList()
{
    LinkedList* list = (LinkedList*)malloc( sizeof(LinkedList) );
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;

    return list;
}

/*  -----------------------------------------------------------------------
**    Function: insertFirst()
**      Import: list (LinkedList*), inValue (void*)
**      Export: none
**   Assertion: Inserts a new node at the start of the list with the given
**                  value
*/
void insertFirst( LinkedList* list, void* inValue )
{
    ListNode* newNode = (ListNode*)malloc( sizeof(ListNode) );
    ListNode* prevHead;

    /* Initialise node fields */
    newNode->value = inValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    if( list->head == NULL )
    {
        /* If the list is empty, the new node will be the head and the tail */
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        /* If the list has atleast one node in it already */
        newNode->next = list->head;
        prevHead = newNode->next;
        prevHead->prev = newNode;
            /* Update prev of the previous head node */
        list->head = newNode;
            /* Update the head of the list */
    }

    list->count += 1;
}

/*  -----------------------------------------------------------------------
**    Function: insertLast()
**      Import: list (LinkedList*), inValue (void*)
**      Export: none
**   Assertion: Inserts a new node at the end of the list with the given
**                  value
*/
void insertLast( LinkedList* list, void* inValue )
{
    ListNode* newNode = (ListNode*)malloc( sizeof(ListNode) );
    ListNode* prevTail;

    /* Initialise node fields */
    newNode->value = inValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    if( list->head == NULL )
    {
        /* If the list is empty, the new node will be the head and the tail */
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        /* If the list has atleast one node in it already */
        newNode->prev = list->tail;
        prevTail = newNode->prev;
        prevTail->next = newNode;
            /* Update next of the previous head node */
        list->tail = newNode;
            /* Update the tail of the list */
    }

    list->count += 1;
}

/*  -----------------------------------------------------------------------
**    Function: removeFirst()
**      Import: list (LinkedList*)
**      Export: nodeValue (void*)
**   Assertion: Removes the first node from the list and returns it's value
*/
void* removeFirst( LinkedList* list )
{
    void* nodeValue;
        /* Value to return */
    ListNode* prevHead;
        /* Temp copy of previous head to free */

    if( list->count == 0 )
    {
        /* List is empty */
        nodeValue = NULL;
    }
    else if( list->count == 1 )
    {
        /* List has one element */
        nodeValue = ( list->head )->value;
        prevHead = list->head;

        list->head = NULL;
        list->tail = NULL;
        free( prevHead );
    }
    else
    {
        /* List has > 1 elements */
        nodeValue = ( list->head )->value;
        prevHead = list->head;

        list->head = ( list->head )->next;
        list->head->prev = NULL;
        free( prevHead );
    }

    list->count -= 1;

    return nodeValue;
}

/*  -----------------------------------------------------------------------
**    Function: removelast()
**      Import: list (LinkedList*)
**      Export: nodeValue (void*)
**   Assertion: Removes the last node from the list and returns it's value
*/
void* removeLast( LinkedList* list )
{
    void* nodeValue;
        /* Value to return */
    ListNode* prevTail;
        /* Temp copy of previous tail to free */

    if( list->count == 0 )
    {
        /* List is empty */
        nodeValue = NULL;
    }
    else if( list->count == 1 )
    {
        /* List has one element */
        nodeValue = ( list->tail )->value;
        prevTail = list->tail;

        list->head = NULL;
        list->tail = NULL;
        free( prevTail );
    }
    else
    {
        /* List has > 1 elements */
        nodeValue = ( list->tail )->value;
        prevTail = list->tail;

        list->tail = ( list->tail )->prev;
        list->tail->next = NULL;
        free( prevTail );
    }

    list->count -= 1;

    return nodeValue;
}

/*  -----------------------------------------------------------------------
**    Function: printLinkedList()
**      Import: list (LinkedList*), toString (toStringFunc* function ptr)
**      Export: none
**   Assertion: Prints each element in the list using the imported toString
**                  function pointer
*/
void printLinkedList( LinkedList* list, toStringFunc* toString )
{
    ListNode* currNode;

    if( list->count == 0 )
    {
        printf( "[]\n" );
    }
    else
    {
        currNode = list->head;
        printf( "[" );
        while( currNode != NULL )
        {
            if( currNode->next == NULL )
            {
                /* If current node is the last node */
                printf( " %s ]\n", (*toString)( currNode->value ) );
            }
            else
            {
                /* If there are more nodes to go after this one */
                printf( " %s,", (*toString)( currNode->value ) );
            }

            currNode = currNode->next;
        }
    }
}

/*  -----------------------------------------------------------------------
**    Function: freeLinkedList()
**      Import: list (LinkedList*), freeValue (freeFunc* function ptr)
**      Export: none
**   Assertion: Frees all memory used by list
*/
void freeLinkedList( LinkedList* list, freeFunc* freeValue )
{
    ListNode* currNode;
    ListNode* nextNode;

    if( list->count > 0 )
    {
        currNode = list->head;
        while( currNode != NULL )
        {
            nextNode = currNode->next;
            (*freeValue)( currNode->value );
            free( currNode );
            currNode = nextNode;
        }
    }

    free( list );
}
