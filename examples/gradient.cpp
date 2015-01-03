
// Date Created: January 03, 2014
// Last Modified: January 03, 2014
// 
// Author: Vallentin <mail@vallentinsource.com>
// 
// Github: https://github.com/VallentinSource/SimpleBMP


#include "simplebmp\simplebmp.h"

#include <math.h>


int main(int argc, char *argv[])
{
	SimpleBMP bmp(300);

	for (int i = 0; i < bmp.width; i++)
	{
		for (int j = 0; j < bmp.height; j++)
		{
			unsigned char red = 0, green = 0, blue = 0;

			float dx = static_cast<float>(i - (bmp.width / 2));
			float dy = static_cast<float>(j - (bmp.height / 2));

			float distance = bmp.width - sqrtf(dx * dx + dy * dy);

			if (distance > 255.0f) { distance = 255.0f; }
			else if (distance < 0.0f) { distance = 0.0f; }

			unsigned char gray = static_cast<unsigned char>(distance);

			bmp.setPixel(i, j, gray, gray, gray);
		}
	}

	bmp.save("gradient.bmp");
	
	return 0;
}
