PHAS0100ASSIGNMENT1
------------------

[![Build Status](https://travis-ci.com/[USERNAME]/PHAS0100Assignment1.svg?branch=master)](https://travis-ci.com/[USERNAME]/PHAS0100Assignment1)
[![Build Status](https://ci.appveyor.com/api/projects/status/[APPVEYOR_ID]/branch/master)](https://ci.appveyor.com/project/[USERNAME]/PHAS0100Assignment1)


Purpose
-------

This project serves as a starting point for the PHAS0100 2021/22 Assignment 1 Game of Life Simulation coursework. It has a reasonable folder structure for [CMake](https://cmake.org/) based projects,
that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2). 

Further information on the specific project is left as an exercise for the student.


Credits
-------

This project is maintained by [Dr. Jim Dobson](https://www.ucl.ac.uk/physics-astronomy/people/dr-jim-dobson). It is based on [CMakeCatch2](https://github.com/UCL/CMakeCatch2.git) that was originally developed as a teaching aid for UCL's ["Research Computing with C++"](http://rits.github-pages.ucl.ac.uk/research-computing-with-cpp/)
course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james)
and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).

Build Instructions
------------------

**Contents**<br>

[Introduction](#introduction)<br>
[How to build](#how_to_build)<br>
[How to use golSimulator](#how_to_use_golSimulator)<br>
[How to use golStillLifes](#how_to_use_golStillLifes)<br>
[How to run tests](#how_to_run_tests)<br>

## Introduction

Welcome to the C++-based Conway's "Game of Life".

* In this project, to specifically investigate the way Conway's "Game of Life" evolves, we have provided the command line application `golSimulator` to implement two input methods (file input mesh, random initialisation mesh) and thus Create a grid of your choice. Based on this grid, you can specify the number of iterations and print out the results of each iteration according to [Conway's "Game of Life"](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) rules. The result is printed out.

* In this project, a command line application `golStillLife` is provided in order to explore the way still life (i.e. a mesh that has not changed anything between iterations and is not completely empty) evolves. This application generates a number of random meshes based on the parameters you enter, and performs a process based on [Conway's `Game of Life`](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) rules and eventually prints out a grid that matches the definition of a still life.

* In addition, we provide a unit testing application `golGameGridTest` based on [CTest](https://cmake.org/) and [Catch](https://github.com/catchorg/Catch2) for unit testing the game grid class.


Next, the parameter rules and how to use them are described in the next three chapters.

## How to build

First, go to the root directory of the file with the help of the IDE's terminal.

```Bash
mkdir build
cd build
```
The project is compiled based on Cmake. Therefore, if you are using it for the first time, simply enter the following command line in the newly created build directory.
```Bash
cmake ..
make
```
Normally the program takes close to a minute to compile. When the compilation is complete, you will see the following output.

```
[ 28%] Built target PHAS0100ASSIGNMENT1
[ 38%] Built target golStillLife
[ 47%] Built target golSimulator
[ 57%] Built target golMyFirstApp
Scanning dependencies of target golGameGridTest
[ 61%] Building CXX object Testing/CMakeFiles/golGameGridTest.dir/golGameGridTest.cpp.o
[ 66%] Linking CXX executable ../bin/golGameGridTest
[ 71%] Built target golGameGridTest
[ 85%] Built target golCommandLineArgsTest
[100%] Built target golBasicTest
```

## How to use golSimulator


After compiling, follow the rules below to use the command line application `golSimulator`.

The application `golSimulator` provides the user with two ways to build a grid.

### 1. text input

You can specify an input file and thus build a grid of your choice. Based on this mesh, you need to specify the number of iterations.

The input command has two parameters, the file path and the number of iterations to be attempted. Example.

```Bash
./bin/golSimulator ./Testing/Data/glider.txt 3 
```
 The above command represents our determination that the input file is `. /Testing/Data/glider.txt`. Based on this file, the mesh we build will go through ``3`` iterations.

Normally, you would see output like this!

```
----------
--o-------
o-o-------
-oo-------
----------
----------
----------
----------
----------
----------
 
<----------Inter-iteration-separator---------------->
----------
-o--------
--oo------
-oo-------
----------
----------
----------
----------
----------
----------
 
<----------Inter-iteration-separator---------------->
----------
--o-------
---o------
-ooo------
----------
----------
----------
----------
----------
----------
 
<----------Inter-iteration-separator---------------->
```

### 2. Random initial grid

You can customise the size of the specified grid and the total number of initial live cells to be placed, thus creating a randomised generated grid. Based on this grid, you need to specify the number of iterations and the grid will loop as many times as you specify and print out the current grid.

The input command has 4 parameters, rows, columns, the number of live cells and the number of iterations for each grid. Example.

```Bash
./bin/golSimulator 20 12 30 3
```
This means we will generate an initialised grid with ``30`` surviving cells with a width of ``20`` and a height of ``12``, and follow the rules for ``3`` iterations.

Normally, you would see similar output!

```
--o----o------o--o--
----o-o-------o----o
----o-o-------------
------o-------------
---------o-----o----
--- oo-------o-------
------------------o-
--------o-------o--
--- oo-----o------o--o-
oo---------o--------
-------------------o
---------o-------oo-
 
<----------Inter-iteration-separator---------------->
--------------------
---o--oo ------------
------oo------------
-----o--------------
--------------------
--------------------
--------------------
-----------------o--
oo------------------
oo------------------
------------------o-
------------------o-
 
<----------Inter-iteration-separator---------------->
--------------------
------oo------------
-----o-o------------
------o-------------
--------------------
--------------------
--------------------
--------------------
oo------------------
oo------------------
--------------------
--------------------
 
<----------Inter-iteration-separator---------------->
```



## How to use golStillLifes


You can customize the size of the specified grid and the total number of initial live cells to be placed, thus creating a number (maximum ``10``) of randomized generated grids. For each grid, you need to specify the number of iterations. During these times, the program will check if the mesh meets the still life criteria and print all still life.

The input command has 4 parameters, rows, columns, the number of surviving cells and the number of iterations for each grid. Example.

```Bash
./bin/golStillLifes 4 4 6 10
```

This means that we will generate an initialized grid with ``6`` survival cells with a width of ``4`` and a height of ``4`` and follow the rules for ``10`` iterations.


Normally, you would see output like this!

```
--o-
-o-o
-o-o
--o-
 
<----------Inter-iteration-separator---------------->
----
----
oo--
oo--
 
<----------Inter-iteration-separator---------------->
--oo
-o-o
--o-
----
 
<----------Inter-iteration-separator---------------->
----
-oo-
o--o
-oo-
 
<----------Inter-iteration-separator---------------->
--oo
-o-o
--o-
----
 
<----------Inter-iteration-separator---------------->
----
----
oo--
oo--
 
<----------Inter-iteration-separator---------------->
-o--
o-o--
o-o-
-o--
 
<----------Inter-iteration-separator---------------->
--oo
-o-o
--o-
----
 
<----------Inter-iteration-separator---------------->
```

As you can see, out of the ``10`` random initialization grids, we found ``8`` still lifes.


## How to run tests

In addition, we also provide the unit testing application `golGameGridTest` for unit testing the game grid class.

You can use it with the following command!

```Bash
./bin/golGameGridTest
```