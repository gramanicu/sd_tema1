# Races - 1st Data Structures Homework
<!-- NOTE FOR WHO IS CHECKING THIS - THE README IS WRITTEN IN MARKDOWN -->

The problem statement can be found [here](https://ocw.cs.pub.ro/courses/sd-ca/teme/tema1).

# SkipList


As it was pointed out [here](http://ticki.github.io/blog/skip-lists-done-right/), linking the nodes vertically leads to some problems:
- Wasted Space
- Cache Misses

To solve this problems, the skiplist is a singly linked list, "in which each node contains an array (representing the nodes above) with pointers to later nodes". Also, because dynamically allocated arrays can still lead to cache misses, the arrays have a fixed size, determined when the node is created.


## Sources
Skip Lists: A Probabilistic Alternative to Balanced Trees by William Pugh - [link]( https://www.epaperpress.com/sortsearch/download/skiplist.pdf)

Skip Lists: Done Right - [link](http://ticki.github.io/blog/skip-lists-done-right/)

# Makefile
The esential commands included are:
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