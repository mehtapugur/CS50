#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
int main(int argc, char* argv[])
{
// ensure proper usage -- DS MOD
if (argc != 4)
{
printf("Usage: ./copy factor infile outfile\n");
return 1;
}
// remember factor and filenames -- DS MOD
int factor = atoi(argv[1]);
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
BITMAPFILEHEADER bf;
fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
BITMAPFILEHEADER outBf = bf;
BITMAPINFOHEADER bi;
fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
BITMAPINFOHEADER outBi = bi;
int inHeight = bi.biHeight;
int inWidth = bi.biWidth;
// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
bi.biBitCount != 24 || bi.biCompression != 0)
{
fclose(outptr);
fclose(inptr);
fprintf(stderr, "Unsupported file format.\n");
return 4;
}
// determine padding for scanlines -- DS MOD
int inPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
int totalInPadding = inPadding * bi.biHeight;
int outPadding = (4 - ((bi.biWidth * factor) * sizeof(RGBTRIPLE)) % 4) % 4;
int totalOutPadding = outPadding * (bi.biHeight * factor);
// modifies file header to reflect resize -- DS MOD
DWORD newBfSize = ((bf.bfSize - 54 - totalInPadding) * factor) + totalOutPadding + 54;
outBf.bfSize = newBfSize;
fwrite(&outBf, sizeof(BITMAPFILEHEADER), 1, outptr);
// modifies info header to reflect resize -- DS MOD
DWORD newBiSize = ((bi.biSize - totalInPadding) * factor) + totalOutPadding;
LONG newBiWidth = bi.biWidth * factor;
LONG newBiHeight = bi.biHeight * factor;
outBi.biSize = newBiSize;
outBi.biWidth = newBiWidth;
outBi.biHeight = newBiHeight;
fwrite(&outBi, sizeof(BITMAPINFOHEADER), 1, outptr);
for (int i = 0, biHeight = abs(inHeight); i < biHeight; i++)
{
// iterate over pixels in scanline
for (int j = 0; j < inWidth; j++)
{
// temporary storage
RGBTRIPLE triple;
// read RGB triple from infile
fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
// write RGB triple to outfile
for (int k = 0; k < factor; k++)
{
for (int l = 0; l < factor; l++)
{
fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
}
// skip over padding, if any
fseek(inptr, inPadding, SEEK_CUR);
// add padding, if any
for (int m = 0; m < outPadding; outPadding++)
{
fputc(0x00, outptr);
}
}
}
}
// close infile
fclose(inptr);
// close outfile
fclose(outptr);
return 0;
}
