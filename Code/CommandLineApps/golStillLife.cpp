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

int main( int argc, char* argv[] ) {

    try{
        int gen = 0;
        int pattern;
        int wid, hei, num;
        std::string filename;

        if ((strcmp(argv[1], "--help")==0) || (strcmp(argv[1], "-h") == 0)) {
            //If the input parameter is -h or --help
            std::cout<<"Hello users! Welcome to the GameLife golStillLife application.\n";
            std::cout<<"Apply a mesh based on the given parameters and use the loop solver to find still life. You can initialize your mesh by entering parameters.\n";
            std::cout<<"The input command has 4 parameters, rows, columns, the number of surviving cells and the number of iterations per mesh. The statements are as follows.\n";
            std::cout<<"        ./bin/golStillLife 20 12 30 10";
        }else if (argc == 5){
            //If the number of input parameters is 5
            int wid = std::atoi(argv[1]);
            int hei = std::atoi(argv[2]);
            int num = std::atoi(argv[3]);
            int gen = std::atoi(argv[4]);
            //Check the plausibility of the input parameter data
            if(wid<=0 || hei<=0 || num<0|| gen<0){
                    std::cout<<"Should input integer > 0\n";
                    throw std::runtime_error("value error of command line arguments");
                }
                else if(num>wid*hei){
                    std::cout<<"alive cells number should less than cells number\n";
                    throw std::runtime_error("value error of command line arguments");
                }

            // for each cell
            for(int grid_id = 0; grid_id<10; grid_id++){
                std::this_thread::sleep_for(std::chrono::seconds(1));
                gol::GameGrid gameGrid(wid, hei, num);
                gol::GameOfLife gameOfLife(&gameGrid);
                // all need to loop gen times
                for(int i = 0; i<gen;i++){
                    gameOfLife.TakeStep();
                    // if the grid remains stationary and there are still cells alive
                    if(gameOfLife.IsStillLifes() && gameOfLife.HasLivingCells()){
                        gameOfLife.PrintGridForGame();
                        break;
                    }
                    gameOfLife.SwapGrids();
                }
            }
        }else{
            std::cout<<"More information is provided by the instruction --h ot -h\n";
            std::cout<<"\n"<<std::endl;
            throw std::runtime_error("Command line arguments error");
        }
    }catch(std::exception& error) {
        std::cerr << "Caught Exception: " << error.what() << std::endl;
        throw;
    }
    return 0;
}


