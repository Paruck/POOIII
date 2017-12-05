#include <iostream>
#include <stdlib.h>

typedef char byte;
typedef unsigned short  WORD; // 2bytes
typedef unsigned long  DWORD; //4bytes
typedef long LONG;


#pragma pack(push, 1)

typedef struct tagBITMAPFILEHEADER
{
	WORD bfType;  //specifies the file type
	DWORD bfSize;  //specifies the size in bytes of the bitmap file
	WORD bfReserved1;  //reserved; must be 0
	WORD bfReserved2;  //reserved; must be 0
	DWORD bOffBits;  //species the offset in bytes from the bitmapfileheader to the bitmap bits
}BITMAPFILEHEADER;

#pragma pack(pop)

#pragma pack(push, 1)

typedef struct tagBITMAPINFOHEADER
{

	DWORD biSize;  //specifies the number of bytes required by the struct
	LONG biWidth;  //specifies width in pixels
	LONG biHeight;  //species height in pixels
	WORD biPlanes; //specifies the number of color planes, must be 1
	WORD biBitCount; //specifies the number of bit per pixel
	DWORD biCompression;//spcifies the type of compression
	DWORD biSizeImage;  //size of image in bytes
	LONG biXPelsPerMeter;  //number of pixels per meter in x axis
	LONG biYPelsPerMeter;  //number of pixels per meter in y axis
	DWORD biClrUsed;  //number of colors used by th ebitmap
	DWORD biClrImportant;  //number of colors that are important

}BITMAPINFOHEADER;

#pragma pack(pop)

typedef struct BMP {
	BITMAPFILEHEADER header;
	BITMAPINFOHEADER info;
	unsigned char* data;
	size_t imgSize;
}BMP;

BMP* LoadBitmapFile(char *filename)
{
	FILE *filePtr; //our file pointer
	BMP *bmp;

							//open filename in read binary mode
	filePtr = fopen(filename, "rb");
	if (filePtr == NULL)
		return NULL;
	bmp = new BMP();
	//read the bitmap file header
	fread(&bmp->header, sizeof(BITMAPFILEHEADER), 1, filePtr);

	//verify that this is a bmp file by check bitmap id
	if (bmp->header.bfType != 0x4D42)
	{
		fclose(filePtr);
		return NULL;
	}

	//read the bitmap info header
	fread(&bmp->info, sizeof(BITMAPINFOHEADER), 1, filePtr); // small edit. forgot to add the closing bracket at sizeof

	//allocate enough memory for the bitmap image data
	bmp->imgSize = bmp->info.biHeight * bmp->info.biWidth * (bmp->info.biBitCount / 8);
	bmp->data = new unsigned char[bmp->imgSize];

	for (int i = 0; i < bmp->info.biHeight; ++i)
	{
		for (int j = 0; j < bmp->info.biWidth; ++j)
		{
			int acc = (j + (i*bmp->info.biWidth)) * bmp->info.biBitCount / 8;
			fread(&bmp->data[acc + 2], 1,1, filePtr);
			fread(&bmp->data[acc + 1], 1, 1, filePtr);
			fread(&bmp->data[acc], 1, 1, filePtr);
		}
		fseek(filePtr,bmp->info.biWidth % 4, SEEK_CUR);
	}

	//make sure bitmap image data was read
	if (bmp->data == NULL)
	{
		fclose(filePtr);
		return NULL;
	}

	//swap the r and b values to get RGB (bitmap is BGR)

	//close file and return bitmap iamge data
	fclose(filePtr);
	return bmp;
}

void SetPixel(BMP* const& bmp, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	int acc = (x + (y*bmp->info.biWidth)) * bmp->info.biBitCount / 8;
	bmp->data[acc] = r;
	bmp->data[acc + 1] = g;
	bmp->data[acc + 2] = b;
}

void WriteBMP(const char* filename, BMP* const& bmp)
{
	FILE* file;
	fopen_s(&file, filename, "wb");
	char c = 0;
	if (file == NULL)
		return;
	fwrite(&bmp->header, sizeof(BITMAPFILEHEADER),1,file);
	fwrite(&bmp->info, sizeof(BITMAPINFOHEADER), 1, file);
	for (int i = 0; i < bmp->info.biHeight; ++i)
	{
		for (int j = 0; j < bmp->info.biWidth; ++j)
		{
			int acc = (j + (i*bmp->info.biWidth)) * bmp->info.biBitCount / 8;
			fwrite(&bmp->data[acc + 2], 1, 1, file);
			fwrite(&bmp->data[acc + 1], 1, 1, file);
			fwrite(&bmp->data[acc], 1, 1, file);
		}
		for (int j = bmp->info.biWidth % 4; j--;)
			fwrite(&c, 1, 1, file);
	}
	fclose(file);
}

int main(int argc, char** argv) {
	BMP* bmp;

	bmp = LoadBitmapFile("creeper.bmp");
	for (int i = bmp->info.biHeight; --i;)
		for(int j = bmp->info.biWidth; j--;)
			SetPixel(bmp, i, j, rand()%255, rand()%255, rand()%255);	
	WriteBMP("creeper3.bmp", bmp);
	delete[] bmp->data;
	delete bmp;
	system("Pause");
	return 0;
}
