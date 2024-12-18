/****************************************************************************
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize n infile outfile\n");
        return 1;
    }
    
    // ensure scale argument is integer
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
        if ( !isdigit((argv[1][i])) ) 
        {
            printf("n must be a positive integer less than or equal to 100\n");
            return 1;
        } 
    
    //convert scale input n from string to integer and check is < 101 
    int n = atoi(argv[1]); 
    if (n < 1 || n > 100)
        {
            printf("n must be a positive integer less than or equal to 100\n");
            return 1;
        }
    
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // create new BITMAPFILEHEADER for resized image
    BITMAPFILEHEADER bfNew = bf;
    
    // create new BITMAPINFOHEADER for resized image
    BITMAPINFOHEADER biNew = bi;
    
    // calculate resized image's file header attributes
    biNew.biWidth = bi.biWidth * n;
    biNew.biHeight = bi.biHeight * n;
    
    // determine padding for scanlines with new image size
    int newpadding =  (4 - (biNew.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // now we can calculate new image size and file size attributes
    biNew.biSizeImage = ((biNew.biWidth * sizeof(RGBTRIPLE) + newpadding) * abs(biNew.biHeight));
    bfNew.bfSize = biNew.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER now that bf has been updated
    fwrite(&bfNew, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER now that bi has been updated
    fwrite(&biNew, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    
    // determine padding for scanlines if any in original file
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
     
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int m = 0; m < n; m++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                           
                // write RGB triple to outfile n times to resize image width
                for (int k = 0; k < n; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add any padding required with scaled image
            for (int k = 0; k < newpadding; k++)
                fputc(0x00, outptr);
        }
    }





    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
