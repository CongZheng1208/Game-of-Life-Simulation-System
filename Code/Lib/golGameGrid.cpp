/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golGameGrid.h"
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

namespace gol 
{
typedef unsigned char byte;
std::string ReadFileIntoString(const std::string& path) {
    //This function is used to read the file in .txt format and store the content in a string
    std::ifstream input_file(path);
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}


std::string& ClearAllSpace(std::string &str){
    //This function is used to remove all spaces in the string
    int index = 0;
    if( !str.empty()){
        while( (index = str.find(' ',index)) != std::string::npos){
            str.erase(index,1);
        }
    }
    return str;
}

GameGrid::GameGrid( ) {};
GameGrid::GameGrid( int x, int y ) : _wid( x ), _hei( y ) {
    int space_required = _wid * _hei * sizeof(byte);
    _cells = new byte[space_required];
    memset( _cells, 0, space_required );
}
GameGrid::GameGrid( int x, int y, int alive_cells_num ) : _wid( x ), _hei( y ) {
    int space_required = _wid * _hei * sizeof(byte);
    _cells = new byte[space_required];
    memset( _cells, 0, space_required );
    //set random seed
    srand(time(0));
    int i, j, num[alive_cells_num];
    //Conduct a loop judgment, if the random coordinate has not appeared before, it will be selected, so as to realize the random selection of the coordinate.
    for(i = 1 ; i <= alive_cells_num ; i++){
        do{
            num[i-1] = rand() % space_required;
            for(j = 1 ; j < i ; j++){
                if(num[i-1] == num[j-1])
                    break;
            }
        }while(j != i);
        _cells[num[i-1]] = 1;
    }
}
GameGrid::GameGrid(std::string filename){
    std::ifstream infile;
    std::string file_contents = ReadFileIntoString(filename);
    //Remove all spaces in the read content
    file_contents = ClearAllSpace(file_contents);
    //get the width of the grid
    for (int i = 0; i< file_contents.length(); i++){
        if (file_contents[i] == '\n'){
            _wid = i;
            break;
        }
    }
    //Remove newlines from the read content
    file_contents.erase(std::remove(file_contents.begin(), file_contents.end(), '\n'), file_contents.end());
    int space_required = file_contents.length() * sizeof(byte);
    _cells = new byte[space_required];
    memset( _cells, 0, space_required );
    // Traverse the file content to initialize the grid
    for (int i = 0; i< file_contents.length(); i++){
        if(file_contents[i] =='-'){
            _cells[i] = 0;
        }else if(file_contents[i] =='o'){
            _cells[i] = 1;
        }
    }
    _hei = file_contents.length()/_wid;
}
GameGrid::~GameGrid() {
    delete[]_cells;
}
int GameGrid::GetWid() const {
    return _wid;
}
int GameGrid::GetHei() const {
    return _hei;
}
byte GameGrid::GetCell( int x, int y ) const {
    if (x >=_wid || x < 0 || y >=_hei || y <0){
        return 0;
    }else{
        return _cells[x + y * _wid];
    }
}
void GameGrid::SetCell( int x, int y, byte statu ) {
    _cells[x + y * _wid] = statu;
}
void GameGrid::SwapCells( GameGrid* gamegrid ) {
    memcpy( _cells, gamegrid->_cells, _wid * _hei * sizeof( byte ) );
}

void GameGrid::PrintGrid() {
    for( int y = 0; y < _hei; y++ ) {
        for( int x = 0; x < _wid; x++ ) {
            if( _cells[x + y * _wid] ) std::cout << "o";
            else std::cout << "-";
        }
        std::cout << "\n";
    }
    std::cout << " "<<std::endl;
}

int GameGrid::Neighbours( int x, int y ) {
    //This function is used to count the number of neighbors around the cell with coordinates x, y
    int neighbours_num = 0, neighbour_x, neighbour_y;
    for( int direction_y = -1; direction_y < 2; direction_y++ ) {
        for( int direction_x = -1; direction_x < 2; direction_x++ ) {
            if( !direction_x && !direction_y ) continue;
            neighbour_x = x + direction_x;
            neighbour_y = y + direction_y;
            neighbours_num += GetCell( neighbour_x, neighbour_y ) > 0 ? 1 : 0;
        }
    }
    return neighbours_num;
}

} // end namespace
