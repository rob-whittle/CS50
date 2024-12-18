/*****************************************************************************
 CS50x
 pset2
 vigenere
 
 accepts a keyword as argument and implements vigenere encryption 
 
 
 Robert Whittle
*******************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    //if too many arguments return 1
    if (argc > 2)           
    {
        printf("too many arguments:\n");
        return 1;
    }
    
    //if too few arguments return 1
    if (argc < 2)           
    {
        printf("too few arguments\n");
        return 1; 
    }    
    
    //if any char of input is not alphabetical return 1
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
        if ( !isalpha((argv[1][i])) ) 
        {
            printf("argument must be alphabetical\n");
            return 1;
        }    
        
    //get user string 
    //printf("enter text for encryption:\n");
    string s = GetString();
    
    for (int i = 0, l = strlen(s), j = 0, k, n = strlen(argv[1]); i < l; i++) // k will be used to access jth char of key
    {
        // check char is upper or lower case - using functions from stdlib.h - so that we don't do anything to non-alphabetic chars
        
        if ( isupper(s[i]) )
        {
            k = argv[1][j % n] & ~('a' - 'A');              // [j % n] keeps wrapping around j no matter how long the scentence is. Bitwise AND jth char of key with ~32 to ensure it is upper case so that correct shift is applied later
            s[i] = ( s[i] - 'A' +  (k - 'A')) % 26 + 'A';   // baseline to A to zero, add shift, wrap and return to ascii index by adding A
            j++;                                            // increment to next letter of key
        }
        
        if ( islower(s[i]) )
        {
            k = argv[1][j % n] | ('a' - 'A');               // bitwise OR jth char of key with 32 to ensure it is lower case so that correct shift is applied later
            s[i] = ( s[i] - 'a' + ( k - 'a' )) % 26  + 'a'; 
            j++;
        }
    }  
        
        printf("%s\n", s);  
    
    return 0;
}    
