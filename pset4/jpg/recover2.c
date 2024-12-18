/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 
 
 typedef uint8_t  BYTE;
 
 // size of file system block size 
 #define BLOCK 512
 
 int main(void)
 {
    // ensure correct usage
    
    
    // open card file to read
    FILE* card = fopen("card.raw", "r");
    
    if (card == NULL)
    {
        printf("Could not open card.\n");
        return 1;
    }
    
    // create some temporary storage to read in the file 512 bytes at a time
    BYTE buffer[BLOCK];
         
    // keep track of the number of jpegs found
    int count = 0;
    
    // create a char array to hold filename for each jpeg found, format is ###.jpg, therefore need 8 chars, one to hold \0 char denoting end of string
    char filename[8];   
    
    // ready a file stream pointer for creating jpgs, initialise for first jpg
    FILE* outptr = fopen("000.jpg", "w");
    
   
    while (!feof(card))
    {
        // read a block into buffer
        fread(&buffer, BLOCK, 1, card);
        
        //printf("First 4 bytes are: %x %x %x %x \n", buffer[0], buffer[1], buffer[2], buffer[3]);
        
        // check to see if it has jpeg signature
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0) || (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe1)) 
        {
            
            // check to see if this is the first file
            if (count == 0)
            {
                //outptr = fopen(filename, "w");
                fwrite(&buffer, BLOCK, 1, outptr);
                count++;
            }
            
            // if not first file then close current file and open a new one
            else
            {

                fclose(outptr);
                
                // set filename for next photo
                sprintf(filename, "%03d.jpg", count);
                
                outptr = fopen(filename, "w");
                fwrite(&buffer, BLOCK, 1, outptr);
                count++;
            }
                                   

        }
        
        // else if not jpg signature, check to see if there is a file open to write to and if so write to it
        else if (outptr != NULL)
        {
            fwrite(&buffer, BLOCK, 1, outptr);
        }        
           
    }
    
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    
    fclose(card);
    
    return 0;
 }
