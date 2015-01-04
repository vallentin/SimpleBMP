
// Date Created: January 04, 2014
// Last Modified: January 04, 2014
// 
// Author: Vallentin <mail@vallentinsource.com>
// 
// Github: https://github.com/VallentinSource/SimpleBMP


#define SIMPLEBMP_OPENGL
#include "simplebmp\simplebmp.h"


int main(int argc, char *argv[])
{
    // This will create a 2x2 bmp image. We could also do bmp(2, 2).
	SimpleBMP bmp(2);

	bmp.setRGB(0, 0, 0xFF0000); // Red
	bmp.setRGB(1, 0, 0x00FF00); // Green
	bmp.setRGB(0, 1, 0x0000FF); // Blue
	bmp.setRGB(1, 1, 0xFF00FF); // Magenta

	// const int rgb = bmp.getRGB(0, 0); // if we want to read it again (red)

	bmp.save("output.bmp");
	
	return 0;
}
