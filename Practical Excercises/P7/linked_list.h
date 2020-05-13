#ifndef LINKED_LIST
#define LINKED_LIST

/* Linked List Node */
typedef struct ListNode
{
    void* value;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

/* Linked List */
typedef struct
{
    ListNode* head;
    ListNode* tail;
    int count;
} LinkedList;

/* Function pointer for use in printLinkedList() */
typedef char* (*toStringFunc)( void* );

/* Function pointer for use in freeLinkedList() */
typedef void (*freeFunc)( void* );

/* Function forward declarations */
LinkedList* createLinkedList();

void insertFirst( LinkedList*, void* );
void insertLast( LinkedList*, void* );

void* removeFirst( LinkedList* );
void* removeLast( LinkedList* );

void printLinkedList( LinkedList*, toStringFunc* );
void freeLinkedList( LinkedList*, freeFunc* );

#endif
