/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// number of "children" each node will have -> 1 for each char of alphabet and apostrophy
#define CHILDREN 27

typedef struct node
{
    // the value to store in this node
    bool is_word;

    // the link an array of child nodes each representing a char a to z and "'"
    struct node* children[CHILDREN];
}
node;

// function prototype (where necessary)
void unloadhelp(node* newptr);

// declare the root of the trie as a global variable
node* root = NULL;

// declare the word counter as a global variable
int count = 0;


// Builds a new node
node* build()
{
    node* new_node = malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "out of memory!\n");
        exit(1);
    }

    // Initialise node
    new_node->is_word = false;
    
    for (int i = 0; i < CHILDREN; i++)
        {
        new_node->children[i] = NULL;
        } 
        
    return new_node;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* newptr = root;
    
    // iterate over each char of word, detecting end of word by checking for null charachter  
    for (int i = 0; word[i] != '\0'; i++)
        {        
        
        // convert char in word to an integer, such that zero represents 'a' (make all lowercase first!)
        int j = tolower(word[i]) - 'a';  
        
        // apostrophe at end of children array, i.e. 27th char    
        if (j == ('\'' - 'a'))
            j = CHILDREN - 1;     
        
        // if not pointing to NULL then letter is present - move onto the next one
        if (newptr->children[j] != NULL)
            newptr = newptr->children[j];
                 
        // if just points to NULL then return false
        else if (newptr->children[j] == NULL)
            return false;     
        
        }   
        
    // if we completed the loop without returning then check if current node marked as word
    if (newptr->is_word)     
        return true;
    
    return false;
}


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    // create a buffer to load word in, size as defined in dictionary.h  +1 to account for null char at end of string
    char buffer[LENGTH + 1];
    
    // open file
    FILE* inptr = fopen(dictionary, "r");
    
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return 1;
    }
       
    // build a new node and point root at it
    root = build();    
    
    // new pointer to walk through the trie
    node* predptr = root;
    
    // for each word in dictionary
    while (fscanf(inptr,"%s", buffer) != EOF)
        {                  
        
        // iterate over each char of word in the buffer, detecting end of word by checking for null charachter  
        for (int i = 0; buffer[i] != '\0'; i++)    
            {
            
            int j = buffer[i] - 'a';  // convert char in buffer to an integer, such that zero represents 'a', could put some code in to deal with uppercase but no need for this dictionary
            
            if (j == ('\'' - 'a'))
                j = CHILDREN - 1;      // put apostrophe at end of children array, i.e. 27th char
            
                      
            // if ith char already represented, move onto the next one
            if (predptr->children[j] != NULL) //return char in buffer as an index to the children array - assumes dictionary is al lower case
                {
                predptr = predptr->children[j];                        
                }  
            
            
            
            // if ith char is not in trie put a new node in
            else if (predptr->children[j] == NULL) //return char in buffer as an index to the children array
                {
                // build a new node
                node* new_node = build();
                
                // append new node to trie
                predptr->children[j] = new_node;
                
                // update pointer ready for next char of word
                predptr = new_node;
                }
                           
            }
          
          // need to mark is_word as true on last char  
          predptr->is_word = true;
          
          // update word counter
          count++;
          
          // set predptr back to root, ready to walk through trie
          predptr = root;
          
          }
        
    // close dictionary
    fclose(inptr);
    
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
        
    if (root == NULL)
        return true;
       
    unloadhelp(root);
 
    free(root); 
    
    return true;
}


void unloadhelp(node* newptr)
{

    // move to bottom of tree
    for (int i = 0; i < CHILDREN; i++)
        {      
        if (newptr->children[i] != NULL)
            {
            unloadhelp(newptr->children[i]);
            free(newptr->children[i]);
            }
        } 

}
