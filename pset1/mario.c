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

    // print pyramid
    for (int i = 1; i <= h; i++)
    {
        // print spaces
        for (int j = 1; j <= (h - i); j++)
            printf(" ");
       
        // print #
        for (int k = 1; k <= (i + 1); k++)
            printf("#");
            
        // new line
        printf("\n");
    }    
    return 0;
}
        

