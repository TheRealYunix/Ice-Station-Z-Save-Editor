//The Includes for the HexConverter(HexEditor)
#include <stdlib.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>


/*HexConverter*/
void HexEdit(char inputv[10]) {
	int decimalNum, dec, i = 0;
	

	char hexaDecimalNum[50];
	decimalNum = std::stoi(inputv);

	while (decimalNum != 0)
	{
		dec = decimalNum % 16;
		if (dec<10)
			dec= dec + 48;
		else
			dec = dec + 55;
		hexaDecimalNum[i] = dec;
		i++;
		decimalNum = decimalNum / 16;
	}

	std::cout << "\nHex Value: ";
	for (i = i - 1; i >= 0; i--)
		std::cout << hexaDecimalNum[i];
	std::cout << std::endl;
}

int HexLetterEdit(char vl[5], char vl2[5], char vl3[5], char vl4[5], char DataValue[6], char vl5[5], char vl6[5], char vl7[5], char vl8[5]) {

	HINSTANCE hInstance = GetModuleHandle(0);

	/*Health buffer convert*/
	 uint32_t vd;
	vd = std::stoi(vl);
	FILE *fp;

	/*Food buffer convert*/
	unsigned int vd2;
	vd2= std::stoi(vl2);

	/*Water buffer convert*/
	unsigned int vd3;
	vd3 = std::stoi(vl3);
	
	/*Water buffer convert*/
	unsigned int vd4;
	vd4 = std::stoi(vl4);
	
	/*Day buffer convert*/
	unsigned int vd5;
	vd5 = std::stoi(vl5);

	/*Walked KM buffer convert*/
	unsigned int vd6;
	vd6 = std::stoi(vl6);

	/*Killed Zombie's buffer convert*/
	unsigned int vd7;
	vd7 = std::stoi(vl7);

	/*Killed Player's buffer convert*/
	unsigned int vd8;
	vd8 = std::stoi(vl8);

	if (fopen(DataValue, "r+") == NULL) {
		MessageBox(nullptr, "The File does not exist!", "Error", MB_OK | MB_ICONERROR);
		printf("The file '%s' doesn't exist!\n", DataValue);
	}

	else {
		printf("File '%s' was Created, succesfully!\n", DataValue);
		
		fp = fopen(DataValue, "r+");
		fseek(fp, 32, 0);
		fwrite(&vd, sizeof(vd), sizeof(unsigned char), fp);
		fclose(fp);
	
		fp = fopen(DataValue, "r+");
		fseek(fp, 36, 0);
		fwrite(&vd2, sizeof(vd2), sizeof(unsigned char), fp);
		fclose(fp);
	
		fp = fopen(DataValue, "r+");
		fseek(fp, 40, 0);
		fwrite(&vd3, sizeof(vd3), sizeof(unsigned char), fp);
		fclose(fp);
	
		fp = fopen(DataValue, "r+");
		fseek(fp, 48, 0);
		fwrite(&vd4, sizeof(vd4), sizeof(unsigned char), fp);
		fclose(fp);

		fp = fopen(DataValue, "r+");
		fseek(fp, 64, 0);
		fwrite(&vd5, sizeof(vd5), sizeof(unsigned char), fp);
		fclose(fp);

		fp = fopen(DataValue, "r+");
		fseek(fp, 72, 0);
		fwrite(&vd6, sizeof(vd6), sizeof(unsigned char), fp);
		fclose(fp);

		fp = fopen(DataValue, "r+");
		fseek(fp, 76, 0);
		fwrite(&vd7, sizeof(vd7), sizeof(unsigned char), fp);
		fclose(fp);

		fp = fopen(DataValue, "r+");
		fseek(fp, 80, 0);
		fwrite(&vd8, sizeof(vd8), sizeof(unsigned char), fp);
		fclose(fp);

	}

	return 0;
}