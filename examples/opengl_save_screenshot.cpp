
// Date Created: January 05, 2014
// Last Modified: January 05, 2014
// 
// Author: Vallentin <mail@vallentinsource.com>
// 
// Github: https://github.com/VallentinSource/SimpleBMP


#define SIMPLEBMP_OPENGL
#include "simplebmp\simplebmp.h"

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


int main(int argc, char *argv[])
{
	// You can't run this example just as it is
	// as you need to initialize OpenGL, etc.

	const char *path = "screenshot.bmp";

	// The width and the height, would be the width
	// and height of your current scene.
	const int width = 1280;
	const int height = 720;

	SimpleBMP bmp(width, height);

	bmp.glReadPixels();

	if (!bmp.save(path))
	{
		printf("Successfully Saved! <%s>\n", path);
	}
	else
	{
		printf("Save Failed! <%s>\n", path);
	}
	
	getchar();
    
	return 0;
}
