/* pset 2 warm-up - this old man */

#include <stdio.h>
#include <cs50.h>
#include <string.h>

void verses(int i);

int main(void)
{
    // ask user how many verses to print
    int n;
    do
    {
        printf("how many times do you want to play (max 10)?!\n");
        n = GetInt();
    }
    while (n > 10 || n < 0);
    
    // call function to print versus
    for (int i = 0; i < n; i++)
    {
        verses(i);
        printf("\n");
    } 
 
    return 0;
}

void verses(int i)
{
    string num;
    string item;
    
    if (i == 0)
    num = "one", item = "on my thumb"; 
    
    if (i == 1)
    num = "two", item = "on my shoe";
    
    if (i == 2)
    num = "three", item = "on my knee";
    if (i == 3)
    num = "four", item = "on my door";
    if (i == 4)
    num = "five", item = "on my hive";
    if (i == 5)
    num = "six", item = "on my sticks";
    if (i == 6)
    num = "seven", item = "up in heaven";
    if (i == 7)
    num = "eight", item = "on my gate";
    if (i == 8)
    num = "nine", item = "on my spine";
    if (i == 9)
    num = "ten", item = "once again";
    
    //string num = [one two three four five six seven eight night ten];
    //string item = ["on my thumb", "on my shoe", "on my knee", "on my door", "on my hive", "on my sticks", "up in heaven", "on my gate", "on my spine", "once again"];
    
    printf("This old man, he played %s\n", num);
    printf("He played knick-knack %s\n", item);
    printf("Knick-knack paddywhack, give your dog a bone\n");
    printf("This old man came rolling home\n");
}

