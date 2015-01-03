
// Date Created: January 03, 2014
// Last Modified: January 03, 2014
// 
// Author: Vallentin <mail@vallentinsource.com>
// 
// Github: https://github.com/VallentinSource/SimpleBMP


#include "simplebmp\simplebmp.h"


int main(int argc, char *argv[])
{
	int width = 0, height = 0;
	unsigned char *pixels = nullptr;

	SimpleBMP::load(&width, &height, &pixels, "input.bmp");

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			unsigned char red = 0, green = 0, blue = 0;

			SimpleBMP::getPixel(width, height, pixels, i, j, &red, &green, &blue);

			unsigned char gray = (red + green + blue) / 3;

			SimpleBMP::setPixel(width, height, pixels, i, j, gray, gray, gray);
		}
	}

	SimpleBMP::save(width, height, pixels, "output.bmp");
	
	return 0;
}
