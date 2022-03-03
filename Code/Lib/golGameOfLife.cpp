/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golGameOfLife.h"

namespace gol {

int main(int argc,char *argv[]){
    int gen = 0;
    int pattern;
    int wid, hei, num;
    std::string filename; 
  
    world w(5, 6, 10);
    w.show(); 
        
    /*
    world w(filename);
    w.show(); 
    rule rll(&w);
    cout<<"!!!"<<endl;
    for(int i = 0; i<gen;i++){
        rll.showGame();
        rll.applyRules();
        rll.swapWrds();
        std::this_thread::sleep_for (std::chrono::seconds(1));*/
    

    return 0;
}

} // end namespace
