
// Date Created: January 03, 2014
// Last Modified: January 03, 2014
//
// Author: Vallentin <vallentin.source@gmail.com>
//
// Github: https://github.com/vallentin/SimpleBMP


#include "simplebmp\simplebmp.h"


int main(int argc, char *argv[])
{
	// BMP's pixel format is BGR and pixels are
	// stored flipped around the x-axis

	const int width = 2;
	const int height = 2;

	// We need to mulitply by 3 as there are 3 color values per pixel!
	const unsigned char pixels[width * height * 3] =
	{
		// Pixel 0, 1 - Red
		0, 0, 255,

		// Pixel 1, 1 - Green
		0, 255, 0,

		// Pixel 0, 0 - Blue
		255, 0, 0,

		// Pixel 1, 0 - Purple
		255, 0, 255,
	};

	// test.bmp should then be saved in your project folder.
	SimpleBMP::save(width, height, pixels, "test.bmp");

	return 0;
}
