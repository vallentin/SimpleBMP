
SimpleBMP is a small, simple, self-contained and cross-platform library for loading, saving and
handling [BMP (Bitmap) image files](http://en.wikipedia.org/wiki/BMP_file_format). 

*The only thing that SimpleBMP uses/requires is the standard library header `<fstream>`.*

---

*SimpleBMP is a young library, so any feedback for improvements and/or missing features are welcome!*

---

Why SimpleBMP? Looking at some of the current existing libraries for handling BMP files. Well, they were just
cluttered and complex if you wanted to use them. BMP files are simple and they should have a simple library
when dealing with them!

SimpleBMP mainly has two functions `simplebmp_load()` and `simplebmp_save()`, a class is then built around those
two functions.

---



```ruby
require 'redcarpet'
markdown = Redcarpet.new("Hello World!")
puts markdown.to_html
```

- [x] @mentions, #refs, [links](), **formatting**, and <del>tags</del> supported
- [x] list syntax required (any unordered or ordered list supported)
- [x] this is a complete item
- [ ] this is an incomplete item

