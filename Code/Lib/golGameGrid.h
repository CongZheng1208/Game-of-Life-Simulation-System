/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golGameGrid_h
#define golGameGrid_h

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



//! Single namespace for all code in this package
namespace gol
{
typedef unsigned char byte;

std::string ReadFileIntoString(const std::string& path);
std::string& ClearAllSpace(std::string &str);

class GameGrid {

public:
    GameGrid( );
    GameGrid( int x, int y );
    GameGrid( int x, int y, int alive_cells_num );
    GameGrid(std::string filename);
    ~GameGrid();
    int GetWid() const;
    int GetHei() const;
    byte GetCell( int x, int y ) const;
    void SetCell( int x, int y, byte statu );
    void SwapCells( GameGrid* gamegrid );
    void PrintGrid();
    int Neighbours( int x, int y );
    void ValidForRandom(int x, int y, int alive_cells_num);
    void ValidForFile(const std::string& path);

private:
    int _wid, _hei;
    byte* _cells;
};

} // end namespace

#endif