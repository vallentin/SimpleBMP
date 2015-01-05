
// Date Created: January 03, 2014
// Last Modified: January 03, 2014
// 
// Author: Vallentin <mail@vallentinsource.com>
// 
// Github: https://github.com/VallentinSource/SimpleBMP


#include "simplebmp\simplebmp.h"

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


int main(int argc, char *argv[])
{
	SimpleBMP bmp;

	const int error = bmp.load("test.bmp"); // or bmp.save("test.bmp")

	switch (error)
	{
	case SIMPLEBMP_NO_ERROR:
		printf("SimpleBMP: No Error");
		break;

	case SIMPLEBMP_FOPEN_ERROR:
		printf("SimpleBMP: fopen() Error");
		break;

	case SIMPLEBMP_INVALID_SIGNATURE:
		printf("SimpleBMP: Invalid Signature (Must be \"BM\")");
		break;

	case SIMPLEBMP_INVALID_BITS_PER_PIXEL:
		printf("SimpleBMP: Invalid Bits Per Pixel (Must be 24 or 32)");
		break;

	default:
		printf("SimpleBMP: Unknown Error");
		break;
	}
	
	getchar();
    
	return 0;
}
