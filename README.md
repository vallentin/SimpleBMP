
# SimpleBMP

SimpleBMP is a small, simple, self-contained and cross-platform library for loading, saving and
handling [BMP (Bitmap) image files](http://en.wikipedia.org/wiki/BMP_file_format). 

*The only thing that SimpleBMP uses/requires is the standard library header `<fstream>`.*

---

*SimpleBMP is a young library, so any feedback for improvements and/or missing features are welcome!*

---

## Why SimpleBMP?

Before making SimpleBMP I was looking for a simple and upfront library for loading and saving BMP files. The only
thing that I found was cluttered and complex libraries. BMP files are and they should have a simple library, when
having to deal with them!

SimpleBMP mainly has two functions `simplebmp_load()` and `simplebmp_save()`. SimpleBMP then also offers a class which
is built around those two functions.

---


# Examples

> **There are a lot of examples on how SimpleBMP can be used, in the "examples" directory!**

But basically there are two general ways of using SimpleBMP.

The first way is, where you store and maintain the `width, height` and `pixels`.

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

for (int i = 0; i < width; i++)
{
	for (int j = 0; j < height; j++)
	{
		unsigned char red = 0, green = 0, blue = 0;

		bmp.getPixel(i, j, &red, &green, &blue);

		unsigned char gray = (red + green + blue) / 3;

		bmp.setPixel(i, j, gray, gray, gray);
	}
}

bmp.save("output.bmp");
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
