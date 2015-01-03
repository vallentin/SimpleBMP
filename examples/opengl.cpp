
// Date Created: January 03, 2014
// Last Modified: January 03, 2014
// 
// Author: Vallentin <mail@vallentinsource.com>
// 
// Github: https://github.com/VallentinSource/SimpleBMP


#define SIMPLEBMP_OPENGL
#include "simplebmp\simplebmp.h"


int main(int argc, char *argv[])
{
	SimpleBMP bmp;
	bmp.load("texture.bmp");
	
	GLuint texture_handle;
	glGenTextures(1, &texture_handle);
	glBindTexture(GL_TEXTURE_2D, texture_handle);
	
	bmp.glTexImage2D();
    
	return 0;
}
