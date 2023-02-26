//POP_2020_01_14_projekt_2_Mierzwa_Wojciech_ACIR_3_176824 GNU GCC COMPILER CODEBLOCKS mingw32-g++


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//informacje o lokalizacji w pamieci pliku bmp jego parametrow
    const int pixelArrPos = 10;
    const int widthPos = 0x12;
    const int heightPos = 0x16;
    const int sizeofBMP = 0x2;
    const int bitsPerPixelPos = 0x1C;
    const int compresionTypePos = 0x1E;


//struktura przechowujaca informacje o obrazie
struct img_info
{
    int width;          //szerokosc obrazu
    int height;         //wysokosc obrazu
    int pixelArrOffset;	// przesuniecie w pamieci do tablicy pikseli
    int	bitsPerPixel;	// 24 bit na piksel 8+8+8
    int	rowSize;		// liczba bajtow w wierszu tablicy pikseli
    int compresionType;	// rodzaj kompresji o ile zostal jakikolwiek zastostoawny
    int sizeofBMP;		// rozmiar pliku w bajtach
};

//zaladowanie informacji o obrazie
void load_img_info(FILE* img, img_info& info)
{
	fseek(img, pixelArrPos, SEEK_SET);
	fread(&info.pixelArrOffset, sizeof(int), 1, img);
	fseek(img, widthPos, SEEK_SET);
	fread(&info.width, sizeof(int), 1, img);
	fseek(img, heightPos, SEEK_SET);
	fread(&info.height, sizeof(int), 1, img);
	fseek(img, bitsPerPixelPos, SEEK_SET);
	fread(&info.bitsPerPixel, sizeof(int), 1, img);
	fseek(img, compresionTypePos, SEEK_SET);
	fread(&info.compresionType, sizeof(int), 1, img);
	fseek(img, sizeofBMP, SEEK_SET);
	fread(&info.sizeofBMP, sizeof(int), 1, img);
	info.rowSize = ((info.bitsPerPixel * info.width + 31) / 32) * 4;
}

//przepisanie naglowka
bool copy_header(FILE * img,FILE * result_img, img_info & info)
{
	fseek(img, 0, SEEK_SET);
	unsigned char* header = NULL;
	header = new unsigned char[info.pixelArrOffset];
	if (header == NULL)
	{
		printf("Blad z alokacja pamieci na naglowek");
		return false;
	}
	fread(header, sizeof(unsigned char), info.pixelArrOffset, img);
	fwrite(header, sizeof(unsigned char), info.pixelArrOffset, result_img);
	delete[] header;
	return true;
}

//zwraca wartosc z inta na wartosc koloru rgb zapisana na 1 bajcie
unsigned char itoRGB(int i)
{
	if (i > 255)
		return (unsigned char) 255;
	if (i < 0)
		return  (unsigned char) 0;
	return (unsigned char) i;
}
const int MATRIX_SIZE_X = 3;		//rozmiar macierzy transformacji - kolumny
const int MATRIX_SIZE_Y = 3;		//rozmiar macierzy transformacji - wiersze
const int BUFFOR_COUNTS = 3;		//liczba wierszy bufora
const int PIXEL_SIZE = 3;		    //libcza bajtow potrzebna do zapisania 1 pixela

//pobiera nowy wiersz pikseli z pliku img a nastepnie ustawia go jako ostatni wczytany
const int matrix[MATRIX_SIZE_X] [MATRIX_SIZE_Y] =
                    {0,-1,0,
                    -1,5,-1,
                    0,-1,0};
void read_and_rotate(unsigned char * bufor[BUFFOR_COUNTS], img_info & info, FILE* img)
{
	fread(bufor[0], sizeof(unsigned char), info.rowSize, img);
	swap(bufor[0], bufor[2]);
	swap(bufor[0], bufor[1]);
}




int main()
{

	FILE * img = NULL, * result_img = NULL;
	char  filename[256], result_name[] = "result.bmp";
	printf("Input file name: ");
	scanf("%s", filename);
	img = fopen(filename, "rb");
	if (img == NULL)
	{
		printf("Error: Can't open image %s", filename);
		return 0;
	}
	img_info info;
	load_img_info(img, info);
	result_img = fopen(result_name, "wb");
	if (copy_header(img, result_img, info) != true)
	{
		fclose(result_img);
		fclose(img);
		return 0;
	}

	const unsigned char zero = 0;										//bajt o wartosci 0
	int value = 0;														//wartosc bajtu koloru
	int y = 0;															//nr ostatniego wczytanego wiersza
	int zeroBytes = info.sizeofBMP / info.height - 3 * info.width;		//liczba bajtow zerowych na koncu kazdego wiersza
	int bytesToIterate = info.rowSize - PIXEL_SIZE - zeroBytes;			//liczba bajtow do przeiterowania od 2. piksela do przedostatniego
	unsigned char ** bufor = new unsigned char * [3] ;					//deklaracja bufora na 3 wiersze pikseli
	unsigned char colorValue;											//zmienna do przechowywania wartosci wpisywanego koloru
	for (int i = 0; i < BUFFOR_COUNTS; i++)
	{
		bufor[i] = new unsigned char [info.rowSize];					//inicjalizacja bufora i zapisanie go
		fread(bufor[i], sizeof(unsigned char), info.rowSize , img);		//pierwszymi 3 wierszami z pliku wejsciowego
	}
	y += BUFFOR_COUNTS;
	fwrite(bufor[0], sizeof(unsigned char), info.rowSize, result_img);  //przepisanie dolnych pikseli

	do {
		//przepisanie pierwszego piksela w wierszu
		fwrite(bufor[1], sizeof(unsigned char), PIXEL_SIZE, result_img);
		for (int i = PIXEL_SIZE; i < bytesToIterate; i++)
		{
			value = 0;
			for (int y = 0; y < MATRIX_SIZE_Y; y++)
				for (int x = 0; x < MATRIX_SIZE_X; x++)
				{
					value += bufor[y][i + 3 * (x - 1)] * matrix[y][x];
				}
			colorValue = itoRGB(value);
			fwrite(&colorValue, sizeof(char), 1, result_img);
		}
		//przepisanie ostatniego piksela w wierszu
		fwrite(bufor[1]+ bytesToIterate, sizeof(unsigned char), PIXEL_SIZE, result_img);
		//wpisanie bajtow zerowych o ile takie sa
		for(int i=0;i<zeroBytes;i++)
			fwrite(&zero, sizeof(unsigned char), 1, result_img);

		if (y < info.height)			//warunek petli
		{
			read_and_rotate(bufor, info, img);
			y++;
		}
		else break;
	} while (true);

	//przepisanie ostatniego wiersza pikseli z pliku wejsciowego
	fwrite(bufor[2], sizeof(unsigned char), info.rowSize, result_img);

	delete[] bufor;
	fclose(result_img);
	fclose(img);
	return 0;
}
