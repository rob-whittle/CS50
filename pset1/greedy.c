/*********************
 CS50x
 pset1
 greedy
 
 Robert Whittle
**********************/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get change required   
    float c;
    do
    {
        printf("change?: ");
        c = GetFloat();
    }
    while ( c < 0 );
    
    //convert change required to pennies and round
    float pennies = (c * 100.0);
    pennies = round(pennies);
  
    //calcluate quarters
    int quarters = 0;
    if (pennies >= 25)
    {
        quarters = pennies / 25;
        pennies = pennies - quarters * 25;
    }
    
    //calculate dimes
    int dimes = 0;
    if (pennies >= 10)
    {
        dimes = pennies / 10;
        pennies = pennies - dimes * 10;
    }  
            
    //calculate nickels
    int nickels = 0;
    if (pennies >= 5)
    {
        nickels = pennies / 5;
        pennies = pennies - nickels * 5;         
    } 
    
    int coins = quarters + dimes + nickels + pennies;
    
    printf("%d\n", coins);     
/*    
    printf("%d\n", quarters);
    printf("%d\n", dimes);
    printf("%d\n", nickels);
    printf("%f\n", pennies);
*/
    return 0;
}

