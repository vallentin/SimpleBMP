
#include "simplebmp\simplebmp.h"


int main(int argc, char *argv[])
{
	// BMP's pixel format is BGR

	const int width = 2;
	const int height = 3;

	// We need to mulitply by 3 as there are 3 color values per pixel!
	const unsigned char pixels[width * height * 3] =
	{
		// Pixel 0, 0 - Red
		0, 0, 255,

		// Pixel 1, 0 - Green
		0, 255, 0,

		// Pixel 0, 1 - Blue
		255, 0, 0,

		// Pixel 1, 1 - Purple
		255, 0, 255,
	};

	// test.bmp should then be saved in your project folder.
	simplebmp_save(2, 2, pixels, "test.bmp");
	
	return 0;
}
