/****************************************************************************
 * puff.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * puffs a huff-compressed file 
 *
 * Rob Whittle Feb '13
 ***************************************************************************/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "forest.h"
#include "huffile.h"
#include "tree.h"

// first and last symbols to dump
#define FIRST '!'
#define LAST '~'

// number of columns to use
#define COLS 8

// make a global tree variable
Tree* tree = NULL;

Tree* BuildTree(Forest* forest)
{
      
    // need to create a new tree node
    if(!(tree = mktree()))
        return NULL;        
    
    // remove two trees from forest and combine them    
    tree->left = pick(forest);
    tree->right = pick(forest);
    
    // combine the frequencies for the new tree
    tree->frequency = tree->right->frequency + tree->left->frequency;
    
    // add the combined trees back into the forest (unless this is the last one)
    if(forest->first != NULL && plant(forest, tree))
    {
        BuildTree(forest);
    }
    
    return tree;

}


/*bool contains(Tree* tree, FILE* output)
{    
       
    int bit;
    
    Tree** treeptr = &tree;
    
    while ((bit = bread(input)) != EOF)
    {
        treeptr = bit == 0 ? &(*treeptr)->left : &(*treeptr)->right;
        if(*treeptr == NULL)
        {
            fwrite(&(*treeptr).symbol, sizeof(tree->symbol), 1, output);
            //fputc((*treeptr).symbol, output);
            treeptr = &tree;
        }
        
    }
       
    return true

} */



int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }

    // open output file
    FILE* output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open %s for writing.\n", argv[2]);
        return 1;
    }
    
    
    // open input
    Huffile* input = hfopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // read in header
    Huffeader header;
    if (hread(&header, input) == false)
    {
        hfclose(input);
        printf("Could not read header.\n");
        return 1;
    }

    // check for magic number
    if (header.magic != MAGIC)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // check checksum
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // iterate over frequencies array (in header file) and add
    // a node to forest to represent each element of the array
    // that has non-zero frequency
      
    Forest* forest = mkforest();
    
    if(!forest) // since mkforest returns NULL is failed
    {
        printf("could not make forest!\n");
        return 1;
    }
    
    //Tree* tree = NULL;
    int count = 0;
    
    for (int i = 0; i < SYMBOLS; i++)
    {    
        if(header.frequencies[i] != 0)
        {     
            if (!(tree = mktree())) // since NULL is zero value
            {
                printf("could not make a tree!\n");
                return 1;
            }
            
            tree->symbol = i;
            tree->frequency = header.frequencies[i];
            
            if (!plant(forest, tree))
            {
                printf("Could not plant tree!.\n");
                return 1;    
            }
        
        // keep track of number of trees planted
        count++;
        
        }
    } 
    
    // now build up the tree (unless only planted 1, can exit here!)
    if (count == 1)
    {
        pick(forest);
        fputc(tree->symbol, output);
        rmforest(forest);
        rmtree(tree);
        hfclose(input);
        fclose(output);
        return 0;
    }
        
    tree = BuildTree(forest);    
    
    // check BuildTree was suucessfull
    if (!tree)
    {
        printf("failed to build tree!\n");
        return 1;
    }   
    
    // now need to read in the bits and determine the output 
    int bit;
    Tree* treeptr = tree;
    
    while ((bit = bread(input)) != EOF)
    {
        
        //treeptr = bit == 0 ? treeptr->left : treeptr->right;  
        
        if (bit == 0 && treeptr->left == NULL)
        {
            fputc(treeptr->symbol, output); 
            treeptr = tree->left; 
        }
        
        else if (bit == 1 && treeptr->right == NULL)
        {
            fputc(treeptr->symbol, output);
            treeptr = tree->right;
        } 
        
        else treeptr = bit == 0 ? treeptr->left : treeptr->right;     
     
    }  
 
    // write the last charachter to file
    fputc(treeptr->symbol, output);
 
        
/*    if(!contains(tree, output))
    {
        printf("failed to write output\n");
        return 1;
    }    
*/    
    // tidy up
    rmforest(forest);
    rmtree(tree);
    hfclose(input);
    fclose(output);

    // that's all folks!
    return 0;
}
