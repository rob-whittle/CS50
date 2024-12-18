#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for non-negative numerator
    float n = -1;
    while ( n < 0)
    {
        printf("non-negative numerator: ");
        n = GetFloat();
    }
    
    // ask user for a positive denominator
    float d = 0;
    while (d <= 0)
    {
        printf("positive denominator: ");
        d = GetFloat();
    }
    
    // calculate answer
    float a = (n / d) * 100;
    
    //display result
    printf("%.2f%%\n",a);
    
    return 0;
}
