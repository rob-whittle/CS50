/* swap variables using xor */

#include <cs50.h>
#include <stdio.h>

int main(void)
{

    printf("what is a?\n");
    int a = GetInt();
    
    printf("what is b?\n");
    int b = GetInt();
    
    a ^= b;  // shorthand for a = a ^ b
    b ^= a;
    a ^= b;
    
    printf("a is %d\n", a);
    printf("b is %d\n", b);


    return 0;
}
