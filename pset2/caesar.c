/*****************************************************************************
 CS50x
 pset2
 caesar
 
 accepts a number as argument and implements caesar encryption of that order 
 
 
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
    
    //if any char of input is not an integer return 1
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
        if ( !isdigit((argv[1][i])) ) 
        {
            printf("n must be an integer less than or equal to 100\n");
            return 1;
        } 
        
    //       
    
    //convert cipher input from string to integer. Note argv array (as with all arrays) is zero indexed, hence [1] 
    int k = atoi(argv[1]);        
    
    // get user string 
    //printf("enter text for encryption:\n");
    string s = GetString();
    
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        // only do something if char is alphabetic - done by checking case - using functions from stdlib.h
        
        if ( isupper(s[i]) )
        {
           // s[i] = s[i] - 'A' ;   // Baseline capital A as zero and work from there
           // s[i] = s[i] + k ;     // Add the key
           // s[i] = s[i] % 26;     // Mod 26 to wrap around
           // s[i] = s[i] + 'A';    // add capital A to get back to ascii index
           //result of above is:
           s[i] = ( s[i] - 'A' + k ) % 26 + 'A';
        }
        
        if ( islower(s[i]) )
        {
            s[i] = ( s[i] - 'a' + k ) % 26 + 'a';
        }
    }  
        
        printf("%s\n", s);  
    
    return 0;
}
