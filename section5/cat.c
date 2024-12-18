#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: cat filename [filename ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        // open argv[i]
        FILE* file = fopen(argv[i], "r");
        
        for (int ch = fgetc(file); ch != EOF; ch = fgetc(file))
        {
            fputc(ch, stdout);
        }
                
        fclose(file);
        
    }

    return 0;
}

