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


int main(int argc,char *argv[]){
    int gen = 0;
    int pattern;
    int wid, hei, num;
    std::string filename; 

    if (argc > 8) {
        show_usage(argv[0]);
        return 1;
    }

    if (argc == 3){
        pattern = 0;
        filename = argv[1];
        gen = std::atoi(argv[2]);
        
    }else if(argc == 5){
            
        wid = std::atoi(argv[1]);
        hei = std::atoi(argv[2]);
        num = std::atoi(argv[3]);
        gen = std::atoi(argv[4]);

        pattern = 1;
    } 

    if(pattern){
        world w(wid, hei, num);
        w.show(); 
        rule rll(&w);
        for(int i = 0; i<gen;i++){
            rll.showGame();
            rll.applyRules();
            rll.swapWrds();
            std::this_thread::sleep_for (std::chrono::seconds(1));
        }
    }else{
        world w(filename);
        w.show(); 
        rule rll(&w);
        for(int i = 0; i<gen;i++){
            rll.showGame();
            rll.applyRules();
            rll.swapWrds();
            std::this_thread::sleep_for (std::chrono::seconds(1));
        }
    }

    return 0;
}

}