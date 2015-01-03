
// Date Created: January 03, 2014
// Last Modified: January 03, 2014
// 
// Author: Vallentin <mail@vallentinsource.com>
// 
// Github: https://github.com/VallentinSource/SimpleBMP


#include "simplebmp\simplebmp.h"


int main(int argc, char *argv[])
{
	SimpleBMP bmp;
	bmp.load("input.bmp");

	for (int i = 0; i < bmp.width; i++)
	{
		for (int j = 0; j < bmp.height; j++)
		{
			unsigned char red = 0, green = 0, blue = 0;

			bmp.getPixel(i, j, &red, &green, &blue);

			unsigned char gray = (red + green + blue) / 3;

			bmp.setPixel(i, j, gray, gray, gray);
		}
	}

	bmp.save("output.bmp");
}
