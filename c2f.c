#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for temperature
    printf("enter temp in celsius: ");
    float c = GetFloat();
    
    // convert C to F
    float f = (c * 9.0 / 5.0) + 32;
    
    //display result
    printf("%.1f deg C is %.1f F\n", c, f);
    
    return 0;
}
