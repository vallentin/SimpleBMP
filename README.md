
# SimpleBMP

SimpleBMP is a small, simple, self-contained and cross-platform C++ library for loading, saving and
handling [BMP (Bitmap) image files](http://en.wikipedia.org/wiki/BMP_file_format). 

*The only thing that SimpleBMP uses/requires is the standard library header `<fstream>`.*

---

*SimpleBMP is a young library, so any feedback for improvements and/or missing features are welcome!*

---

## Why SimpleBMP?

Before making SimpleBMP I was looking for a simple and upfront library for loading and saving BMP files. The only
thing that I found was cluttered and complex libraries. BMP files are and they should have a simple library, when
having to deal with them!

SimpleBMP mainly has two functions `SimpleBMP::load()` and `SimpleBMP::save()`. SimpleBMP then also offers a class which
is built around those two functions.

---


## Examples

> **There are a lot of examples on how SimpleBMP can be used, in
> the ["examples" directory](https://github.com/VallentinSource/SimpleBMP/tree/master/examples)!**

- [Generating a Gradient](https://github.com/VallentinSource/SimpleBMP/blob/master/examples/gradient.cpp)
- [Apply Grayscale Effect to an Image](https://github.com/VallentinSource/SimpleBMP/blob/master/examples/grayscale.cpp)
- [OpenGL Load Texture](https://github.com/VallentinSource/SimpleBMP/blob/master/examples/opengl_load_texture.cpp)
- [OpenGL Save Screenshot](https://github.com/VallentinSource/SimpleBMP/blob/master/examples/opengl_save_screenshot.cpp)
- [Error Codes](https://github.com/VallentinSource/SimpleBMP/blob/master/examples/error_codes.cpp)
- [Packed RGB Values](https://github.com/VallentinSource/SimpleBMP/blob/master/examples/packed_rgb_values.cpp)

But basically there are two general ways of using SimpleBMP.

*The following example, is for loading an image, applying the [grayscale effect](http://en.wikipedia.org/wiki/Grayscale) to the loaded image and then save it again!*

The first way is, where you store and maintain the `width`, `height` and `pixels`.

```cpp
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
```

The second way, is where you use and instanciate a SimpleBMP object.

```cpp
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
```


## SimpleBMP + OpenGL

SimpleBMP also has a simple wrapper function for use with OpenGL. But before you can use it, you need to define `SIMPLEBMP_OPENGL` before you include `simplebmp.h`.

```cpp
#define SIMPLEBMP_OPENGL
#include "simplebmp\simplebmp.h"
```

Again you can both use it with or without having to instanciate a SimpleBMP object.

```cpp
SimpleBMP::glTexImage2D(width, height, pixels);
```

or

```cpp
bmp.glTexImage2D();
```

#### Complete OpenGL Example

```cpp
GLuint texture_handle;
glGenTextures(1, &texture_handle);
glBindTexture(GL_TEXTURE_2D, texture_handle);

bmp.glTexImage2D();
```

## OpenGL Save Screenshot

SimpleBMP also allows for an easy way to save a screenshot!

```cpp
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
```



## Error Codes

The `save` and `load` functions, return error codes. It is guaranteed that `0 (SIMPLEBMP_NO_ERROR)` is returned when
no error has happened!

```cpp
#define SIMPLEBMP_NO_ERROR 0
#define SIMPLEBMP_FOPEN_ERROR 1

#define SIMPLEBMP_INVALID_SIGNATURE 2
#define SIMPLEBMP_INVALID_BITS_PER_PIXEL 3
```
