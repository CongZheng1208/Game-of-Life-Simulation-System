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

/**
* \defgroup internal internal
* \brief Internal stuff, not for end-users.
*/

/**
* \defgroup types types
* \brief Package-wide data types.
*/

/**
* \defgroup utilities utilities
* \brief Groups of c-style functions.
*/

/**
* \defgroup applications applications
* \brief Small, end-user applications, most likely command line.
*/

/**
* \file golBasicTypes.h
* \brief Defines types and typedefs used in this library.
* \ingroup types
*/

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

std::string readFileIntoString(const std::string& path) {
    std::ifstream input_file(path);
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}


std::string& ClearAllSpace(std::string &str){
    int index = 0;
    if( !str.empty())
    {
        while( (index = str.find(' ',index)) != std::string::npos)
        {
            str.erase(index,1);
        }
    }
    return str;
}


class world {
public:
    world( int x, int y ) : _wid( x ), _hei( y ) {
        int s = _wid * _hei * sizeof( byte );
        _cells = new byte[s];
        memset( _cells, 0, s );

    }
    world( int x, int y, int n ) : _wid( x ), _hei( y ) {
        int s = _wid * _hei * sizeof( byte );
        _cells = new byte[s];
        memset( _cells, 0, s );
        srand(time(0));
        int i, j, num[n];
        for(i = 1 ; i <= n ; i++){
            do{
                num[i-1] = rand() % s;
                for(j = 1 ; j < i ; j++){
                    if(num[i-1] == num[j-1])
                        break;
                }
            }while(j != i);
            _cells[num[i-1]] = 1;
        }
    } 

    world(std::string filename){

        std::ifstream infile; 
        std::string file_contents = readFileIntoString(filename);
        file_contents = ClearAllSpace(file_contents);

        int value = 0;
        
        for (int i = 0; i< file_contents.length(); i++){
            if (file_contents[i] == '\n'){
                _wid = i;
                break;
            }            
        }

        file_contents.erase(std::remove(file_contents.begin(), file_contents.end(), '\n'),
            file_contents.end());

        int s = file_contents.length() * sizeof( byte );
        _cells = new byte[s];
        memset( _cells, 0, s );
      
        for (int i = 0; i< file_contents.length(); i++){
            if(file_contents[i] =='-'){
                _cells[i] = 0;
            }else if(file_contents[i] =='o'){
                _cells[i] = 1;
            }
            
        }
        _hei = file_contents.length()/_wid;

    }
    ~world() {
        delete [] _cells;
    }
    int wid() const {
        return _wid;
    }
    int hei() const {
        return _hei;
    }
    byte at( int x, int y ) const {
        if (x >=_wid || x < 0 || y >=_hei || y <0){
            return 0;
        }else{
            return _cells[x + y * _wid];
        }        
    }
    void set( int x, int y, byte c ) {
        _cells[x + y * _wid] = c;
    }
    void swap( world* w ) {
        memcpy( _cells, w->_cells, _wid * _hei * sizeof( byte ) );
    }

    void show() {
        for( int y = 0; y < _hei; y++ ) {
            for( int x = 0; x < _wid; x++ ) {
                if( _cells[x + y * _wid] ) std::cout << "o";
                else std::cout << "-";
            }
            std::cout << "\n";
        }  
        std::cout << " "<<std::endl;
            
    }

    int neighbours( int xx, int yy ) {
        int n = 0, nx, ny;
        for( int y = -1; y < 2; y++ ) {
            for( int x = -1; x < 2; x++ ) {
                if( !x && !y ) continue;
                nx = xx + x;
                ny = yy + y;
                n += at( nx, ny ) > 0 ? 1 : 0;
            }
        }
        return n;
    }

private:
    int _wid, _hei;
    byte* _cells;
};

} // end namespace

#endif