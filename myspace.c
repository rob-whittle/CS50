#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    // ask for input
    printf("type something\n");
    
    // put input in string
    string s = GetString();
    
    // loop over string - checking if is alphabetical and then setting odd positions to uppercase and even positions to lower case
    int count = 0;  // set counter for counting letters
    
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        // check if its alphabetical
        if ((s[i] >= 'A' && s[i] <= 'Z')  ||// if capital
            (s[i] >= 'a' && s[i] <= 'z'))   // or if lowercase
        {
            if (!(count % 2))                // if count is odd - % is modulus operator divides count by 2 and gives remainder - if its zero then count must be an even number, otherwise it must be odd (any none zero value is true)
               s[i] &= ~('a' - 'A');        // bit wise AND operator - could use ~32 (as 32 bit distinguishes between upper and lower) instead of ~('a' - 'A').  Converts lower to upper, leaves upper as they are. ~ bit wise operator flips all the bits representing 'a' - 'A'
            else
                s[i] |= ('a' - 'A');        // bit wise OR operator.  Make letter lowercase
            count++;
         }
    }
    
    printf("%s\n", s);
        
    return 0;
}
