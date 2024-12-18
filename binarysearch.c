#include <cs50.h>
#include <stdio.h>

#define SIZE 8

bool search(int needle, int haystack[], int size)
{
    // TODO: return true iff needle is in haystack, using binary search
    int begin = 0;
    int end = size - 1;
        
    while (begin <= end)
    {
        int midpoint = (end + begin) /2;
        
        // check midpoint value first
        if (needle == haystack[midpoint])
            return 1;
        
        // check LHS    
        if (needle < haystack[midpoint])
            end = midpoint - 1;
            
        // check RHS
        if (needle > haystack[midpoint])
            begin = midpoint + 1; 
    }
    return 0;
}


int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("> ");
    int n = GetInt();
    if (search(n, numbers, SIZE))
        printf("YES\n");
    return 0;
}
