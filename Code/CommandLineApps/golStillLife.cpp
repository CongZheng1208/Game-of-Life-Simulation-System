/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

/**
 * \brief Demo file to check that includes and library linkage is correct.
 */
#include "golGameOfLife.h"
#include "golGameGrid.h"


namespace gol {

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-d,--destination DESTINATION\tSpecify the destination path"
              << std::endl;
}


int main( int argc, char* argv[] ) {

    
    int wid = std::atoi(argv[1]);
    int hei = std::atoi(argv[2]);
    int num = std::atoi(argv[3]);
    int gen = std::atoi(argv[4]);

    while(1){
        world w(wid, hei, num);
        rule rll(&w);
        for(int i = 0; i<gen;i++){
            rll.applyRules();

            if(rll.is_still_lifes() && rll.hasLivingCells()){
                rll.showGame();
                break;
            }
            rll.swapWrds();
            //std::this_thread::sleep_for (std::chrono::seconds(1));
        }
    }
}

}