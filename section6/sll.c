/*************************************************************************
 * sll.c
 *
 * Implements a simple singly-linked list structure for ints.
 ************************************************************************/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// the size of our test list: feel free to adjust as you wish!
#define TEST_SIZE 10

typedef struct node
{
    // the value to store in this node
    int i;

    // the link to the next node in the list
    struct node* next;
}
node;

// prototypes
node* build(int i);
int length(void);
bool contains(int i);
void append(int i);
void insert_sorted(int i);



// declare the first node of our list (as a global variable)
node* first = NULL;


// Builds a new node
node* build(int i)
{
    node* new_node = malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "out of memory!\n");
        exit(1);
    }

    new_node->i = i;
    new_node->next = NULL;
    
    return new_node;
}


/**
 * Returns the length of the list.
 */
int length(void)
{
    int length = 0;
    
    for (node* n = first; n != NULL; n = n->next)
        {
            length++;
        }
    printf("%d\n", length);
    return length;
}

/**
 * Returns true if a node in the list contains the value i and false
 * otherwise.
 */
bool contains(int i)
{
    for (node* n = first; n!= NULL; n = n->next)
    {
        if (n->i == i)
            return true;
    }
    return false;
}

/**
 * Puts a new node containing i at the front (head) of the list.
 */
void prepend(int i)
{
    node* new_node = build(i);
    new_node->next = first;
    first = new_node;
}

/**
 * Puts a new node containing i at the end (tail) of the list.
 */
void append(int i)
{
    node* new_node = build(i);
    
    
    // can't append if there's nothing to append to so check if first is pointing to NULL
    if (first == NULL)
    {   
        first = new_node;
        //first->next = NULL;
        return; 
    }
    
    // walk through link list until you find the node with next pointing to NULL
    for (node* n = first; n!= NULL; n = n->next)
    {        
        
        if (n->next == NULL)
            {           
            n->next = new_node;
            //new_node->i = i;
            //new_node->next = NULL;
            return;
            }
    }
    
    return;
}

/**
 * Puts a new node containing i at the appropriate position in a list
 * sorted in ascending order.
 */
void insert_sorted(int i)
{

    node* new_node = build(i);
    
    // check if there's anything else in the list  
    if (first == NULL)
        first = new_node;

    
    // else check if number belongs at lists head
    else if (new_node->i < first->i)
    {
        new_node->next = first;
        first = new_node;
    }
    
    // else try to insert number in middle or tail
    else
    {
        // new node to walk through list
        node* predptr = first;
        while(true)
        {
            //avoid duplicates
            /*if (predptr->i == new_node->i)
            {
                free(new_node);
                break;
            }*/
            
            // check for insertion at tail, i.e. if predptr gets to end of list
            if (predptr->next == NULL)
            {
                predptr->next = new_node;
                break;
            }
            
            // check for insertion in middle
            else if (predptr->next->i > new_node->i)
            {
                new_node->next = predptr->next;
                predptr->next = new_node;
                break;
            }
            
            // update pointer
            predptr = predptr->next;
            
        }
     }
    
    
   /* // walk through the link list and check the size of n
    else for (node* n = first; n!= NULL; n = n->next)
    {
        if (n->next->i >= i)
            {
            new_node->next = n->next;
            n->next = new_node;
            //return;
            }
    }*/
    
}

/**
 * Implements some simple test code for our singly-linked list.
 */
int main(void)
{
    printf("Prepending ints 0-%d onto the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        prepend(i);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in descending order...");
    node* n = first;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i == TEST_SIZE - i - 1);
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("Appending ints 0-%d to the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        append(i);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in ascending order...");
    n = first;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i == i);
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("Inserting %d random ints to the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        insert_sorted(rand() % TEST_SIZE);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in sorted order...");
    n = first;
    int prev = 0;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i >= prev);
        prev = n->i;
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("\n********\nSuccess!\n********\n");

    return 0;
}
