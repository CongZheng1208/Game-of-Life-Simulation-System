/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golGameOfLife_h
#define golGameOfLife_h

#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <thread>     
#include <chrono> 

#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdio.h>
#include<unistd.h>
#include"golGameGrid.h"

namespace gol {

typedef unsigned char byte;
class GameOfLife {
public:
    GameOfLife( GameGrid* gamegrid );
    ~GameOfLife();
    bool HasLivingCells();
    void SwapGrids();
    bool IsStillLifes();
    void TakeStep();
    void PrintGridForGame();

private:
    GameGrid *grid_now, *grid_next;
};


} // end namespace

#endif