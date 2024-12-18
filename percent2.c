#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for non-negative numerator
    float n;
    do
    {
        printf("non-negative numerator: ");
        n = GetFloat();
    }
    while (n < 0);
    
    // ask user for a positive denominator
    float d;
    do
    {   
        printf("non-negative denominator: ");
        d = GetFloat(); 
    }
    while ( d < 0);
    
    // calculate answer
    float a = (n / d) * 100;
    
    //display result
    printf("%.2f%%\n",a);
    
    return 0;
}
