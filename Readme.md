# Races - 1st Data Structures Homework

<!-- NOTES 
- this is written in markdown, so it isn't readable as plain text.
- because I tend to use english variable and function names, I decided to write everything in english, to keep it cohesive (also, I had points taken at a computer programming homework because I had english names for function and romanian comments and readme )
-->

The problem statement can be found [here](https://ocw.cs.pub.ro/courses/sd-ca/teme/tema1).

## Project Structure

## SkipList

As it was pointed out [here](http://ticki.github.io/blog/skip-lists-done-right/), linking the nodes vertically leads to some problems:

- Wasted Space
- Cache Misses

To solve this problems, the skiplist is a singly linked list, "in which each node contains an array (representing the nodes above) with pointers to later nodes". Also, because dynamically allocated arrays can still lead to cache misses, the arrays have a fixed size, determined when the node is created.

### References

**Skip Lists: A Probabilistic Alternative to Balanced Trees** by William Pugh - [link]( https://www.epaperpress.com/sortsearch/download/skiplist.pdf)

**Skip Lists: Done Right** - [link](http://ticki.github.io/blog/skip-lists-done-right/)

## CoinFlip

Even though it is overkill and I could have implemented this operation with `rand()` and `srand()`, they have some problems, as it was pointed out [here](https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful) by Stephan T. Lavavej (Visual Studio C++ STL). So, I wanted to do it properly and after some research, I discovered this method, based on the `random` header.

1. Generate a TRUE random number using `random_device`
2. Generate all numbers with a PRNG, that has that true random number used as a seed (`mt19937`)
3. Use a uniform number distribution that produces random numbers only in a closed interval (`uniform_int_distribution<int>`)

## Reference

**Generating random numbers in C++** - [link](https://diego.assencio.com/?index=6890b8c50169ef45b74db135063c227c)

## Makefile

The essential commands included are:

- `build` - compiles the code and generates the executable ("tema1")
- `run` - compiles, then runs the binary
- `clean` - deletes all binaries and object files

For development and testing purposes, the makefile includes some other commands:

- `beauty` - beautifies the code, using the google standard
- `pack` - creates the archive to be sent to vmchecker
- `update` - downloads and "installs" the checker
- `memory` - checks the program for memory leaks
- `check` - prepares the files required and runs the checker
- `purge` - removes all files that will not be included in the git repository
- `gitignore` - adds unnecessary files to gitignore

The makefile will hide some of the output and show custom messages (for example the "build" command)

© 2018 Grama Nicolae, 312CA