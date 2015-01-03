
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



```ruby
require 'redcarpet'
markdown = Redcarpet.new("Hello World!")
puts markdown.to_html
```

- [x] @mentions, #refs, [links](), **formatting**, and <del>tags</del> supported
- [x] list syntax required (any unordered or ordered list supported)
- [x] this is a complete item
- [ ] this is an incomplete item

