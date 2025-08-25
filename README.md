# SDL3 Game Development
Repository created based on Shaun Mitchell's book: "SDL Game Development" by Packt Publishing

<img src="https://m.media-amazon.com/images/I/5185H7adhGL.jpg"> 

The book was originally written using **C++** library **SDL(Simple Direct-Media Layer) 2** but the examples I wrote
following along with the book I used **SDL 3** so I had to adapt some parts.

This book looks like an internet tutorial that saw a shooting star and wished to became a book, because the theorical information is very plain and short
and most of the book is focused in following along and code explanation but it still worth it as an introduction to SDL

> [!WARNING]
> If you are planning to read this book and follow the samples I suggest to **pick SDL Version 2** to not suffer as much I did.

I choiced this book as an preparation for SDL (specially version 3) for Sanjay Madhav's "Game Programming in C++" book.

## [Chapter 01 - Breaking main code into functions](https://github.com/felipeguimaraens/SDL3-Game-Development/tree/chapter01/breaking-into-functions)

The core of this chapter was to create the main code that is going to be use in the following chapters (incremental)
but with some good practices and code organization.

OBS: .h files are still messy.


## [Chapter 02 - Rendering](https://github.com/felipeguimaraens/SDL3-Game-Development/commits/chapter02/drawing)

Chapter mainly focused on rendering and drawing objects on screen. The main differences between SDL 2 and 3 starts to appear in this chapter
other topics covered in this chapter:
- Static sprites
- Animated sprites
- Flip sprites
- Singleton (design pattern)


## [Chapter 03 - Game Objects](https://github.com/felipeguimaraens/SDL3-Game-Development/commits/chapter03/objects)
This chapter didn't introduced anything new per se but it main focus was to organize the code into manageable classes and entities into "SDLGameObjects"
to make it easier to call methods like: update() or draw() in each game object (escalability).


## [Chapter 04 - Input](https://github.com/felipeguimaraens/SDL3-Game-Development/commits/chapter04/inputs)
By far the hardest chapter so far because the author introduces game inputs and at same time use data structures (lists) to keep track of the inputs
which could be ok in normal circuinstances but unfortunatelly SDL 3 changed a lot how to implements input when comparing to SDL 2 and also joystick detection
So the joystick detection was totally broken and some input events needs to be handle differently.
Still I was able to enjoy some troubleshooting sections while trying to figure out the author's vision of code organization. Topics covered
- Joystick detection (support for multiple joysticks)
- Mouse detection
- Keyboard detection
- Player following the mouse (specific at this commit but removed later)
- Organizing input logic into functions for each kind of input method

The remaining chapters I didn't followed at the time I wrote this README because it lost its purpose to serve as an introduction to SDL.
