/*********************
 CS50x
 pset1
 mario
 
 Robert Whittle
**********************/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask for pyramid height
    int h;
    do
    {
        printf("Height: ");
        h = GetInt();
    }
    while ( h > 23 || h < 0 );

    // loop over rows of the printed rectangle
    for (int i = 0; i < h; i++)
    {
        // loop over columns
        for (int j = 0; j < (h + 1); j++)
        {
       
            // decide what char to print based on row/column position
            char block = (j < h-i-1) ? ' ' : '#';
            printf("%c", block);
         }   
            // new line
            printf("\n");
    }    
    return 0;
}
        

