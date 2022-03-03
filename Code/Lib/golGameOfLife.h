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
#include"golGameGrid.h"

namespace gol {

class rule {
public:
    rule( world* w ) : wrd( w ) {
        wrdT = new world( wrd->wid(), wrd->hei() );
    }
    ~rule() {
        if( wrdT ) delete wrdT;
    }
    bool hasLivingCells() {
        for( int y = 0; y < wrd->hei(); y++ )
            for( int x = 0; x < wrd->wid(); x++ )
                if( wrd->at( x, y ) ) return true;
        return false;
    }
    void swapWrds() {
        wrd->swap( wrdT );
    }

    bool is_still_lifes(){
        for( int y = 0; y < wrd->hei(); y++ )
            for( int x = 0; x < wrd->wid(); x++ )
                if( wrd->at( x, y )!= wrdT->at( x, y )) return false;
        return true;
    }
    
 
    void applyRules() {
        int n;
        for( int y = 0; y < wrd->hei(); y++ ) {
            for( int x = 0; x < wrd->wid(); x++ ) {
                n = wrd->neighbours( x, y );
                if( wrd->at( x, y ) ) {
                    if(n == 2 || n==3){
                        wrdT->set( x, y, 1 );
                    }else{
                        wrdT->set( x, y, 0 );
                    }
                } else if(n==3) {
                    wrdT->set( x, y, 1 );
                }else{
                    wrdT->set( x, y, 0 );
                }
            }
        }
    }

    void showGame() {
        for( int y = 0; y < wrd->hei(); y++ ) {
            for( int x = 0; x < wrd->wid(); x++ ) {
                if( wrd->at( x, y ) ) std::cout << "o";
                else std::cout << "-";
            }
            std::cout << "\n";
        }  
        std::cout << " "<<std::endl;
    }

private:
    world *wrd, *wrdT;
};

} // end namespace

#endif