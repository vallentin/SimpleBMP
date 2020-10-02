
// Date Created: January 03, 2014
// Last Modified: January 03, 2014
//
// Author: Vallentin <vallentin.source@gmail.com>
//
// Github: https://github.com/vallentin/SimpleBMP


#define SIMPLEBMP_OPENGL
#include "simplebmp\simplebmp.h"


int main(int argc, char *argv[])
{
	// You can't run this example just as it is
	// as you need to initialize OpenGL, etc.

	// Always remember that the texture must have
	// a width and height of Power of Two
	//
	// http://en.wikipedia.org/wiki/Power_of_two

	SimpleBMP bmp;
	bmp.load("texture.bmp");

	GLuint texture_handle;
	glGenTextures(1, &texture_handle);
	glBindTexture(GL_TEXTURE_2D, texture_handle);

	bmp.glTexImage2D();

	return 0;
}
