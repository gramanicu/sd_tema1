# Races - 1st Data Structures Homework

<!-- NOTES 
- this is written in markdown, so it isn't readable as plain text.
- because I tend to use english variable and function names, I decided to write everything in english, to keep it cohesive (also, I had points taken at a computer programming homework because I had english names for function and romanian comments and readme )
-->

The problem statement can be found [here](https://ocw.cs.pub.ro/courses/sd-ca/teme/tema1).

## Project Structure

``` bash
 - ./
    |-- .clang-format
    |-- Makefile
    |-- Readme.md
    |-- headers
    |   |-- Athlete.h
    |   |-- Quicksort.h
    |   |-- Random.h
    |   |-- SkipList.h
    |   |-- Time.h
    |   |-- homework.h
    |-- sources
        |-- Athlete.cpp
        |-- Random.cpp
        |-- homework.cpp
        |-- main.cpp
```

- .clang-format - custom formatting (google standard from clang, with 4 space tabs)
- Makefile - a lot of make commands, for compilation, debugging, generating the .gitignore, etc.
- Readme<span></span>.md - this file :)
- headers/ - all .h files
- sources/ - all .cpp files

## SkipList

One of the things that needed to be implemented in this project was a skiplist.
A skiplist is a data structure, similar to a B-tree, but a lot easier to implement, which is also faster for most operations.

Basically, skiplist are singly linked list, with "express lanes". These help to `skip` some nodes, making the search a lot faster. As the number of nodes increases, the number of levels increases, making possible even longer "jumps".

### The wrong way to implement a skiplist

![Bad Skiplist](https://i.imgur.com/nNjOtfa.png "Bad Skiplist")

A lot of times, people implement the levels using copies of the original node, each node having 4 pointers (left, right, up, down).

As it was pointed out [here](http://ticki.github.io/blog/skip-lists-done-right/), linking the nodes vertically (and using multiple nodes) leads to some problems:

- Wasted Space
- Cache Misses

### The right way

To solve those problems, the skiplist is implemented using a singly linked list, "in which each node contains an array (representing the nodes above) with pointers to later nodes". Also, because dynamically allocated arrays can still lead to cache misses, the arrays have a fixed size, determined when the node is created.

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