/* implement mergesort */

#include <stdio.h>

#define SIZE 8

void sort(int array[], int size);
void split(int array[], int start, int end, int size);
void merge(int array[], int start, int end, int size);

void sort(int array[], int size)
{
    // TODO: sort array using mergesort
    int start = 0;
    int end = size - 1;
    split(array, start, end, size);
    //
}

void split(int array[], int start, int end, int size)
{
    if (size < 2)
        return;
    
    int midpoint = (start + end) / 2;
    int leftsize = midpoint - start + 1;
    int rightsize = end - midpoint;
    
    
    split(array, start, midpoint, leftsize);  // split to LHS
    split(array, midpoint + 1, end, rightsize);// split to RHS
    merge(array, start, end, size);
}

void merge(int array[], int start, int end, int size)
{
    int left = start;
    int right = start + size / 2 ;
    
    printf("size %d", size);
    
    int newArray[size];             
    
    for (int i = 0; i < size; i++)  
    {
        if (left <=  (start + end)/2)  // check if LHS has any elements
        {
            if (right > end)
            {
                newArray[i] = array[left];
                left++;
            }
            else if (array[left] < array[right])
            {
                newArray[i] = array[left];
                left++;
            }
            else
            {
                newArray[i] = array[right];
                right++;
            }
        }
        else
        {
            newArray[i] = array[right];
            right++;
        }
    } 

    for (int i = 0; i < SIZE; i++)
        array[i] = newArray[i];
    
    
    for (int i = 0; i < SIZE; i++)
        printf("%d ", newArray[i]);
    printf("\n");
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108 };
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    sort(numbers, SIZE);
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}
