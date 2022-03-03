/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/
#include "catch.hpp"
#include "golCatchMain.h"
#include "golGameGrid.h"
#include "golGameOfLife.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

TEST_CASE("check GameGrid GetCell ","[GameGrid]"){
    gol::GameGrid gameGrid("../Testing/Data/oscillators.txt");

    SECTION("check gGameGrid GetCell  input","[GameGrid]") {
        REQUIRE(gameGrid.GetCell(0,2)==0);
        REQUIRE(gameGrid.GetCell(1,2)==0);
        REQUIRE(gameGrid.GetCell(2,2)==1);
        REQUIRE(gameGrid.GetCell(3,2)==0);
    }

    SECTION("check GameGrid GetCell output","[GameGrid]"){
        REQUIRE(gameGrid.GetCell(1,2)==0);
        REQUIRE(gameGrid.GetCell(-1,2)==0);
        REQUIRE(gameGrid.GetCell(2,-3)==0);
        REQUIRE(gameGrid.GetCell(2,300)==0);
        REQUIRE(gameGrid.GetCell(2,-300)==0);
    }
}

TEST_CASE("check grid structure","[GameGrid]"){
    gol::GameGrid gameGrid(200,120);

    SECTION("check grid object structure","[GameGrid]") {
        REQUIRE(gameGrid.GetWid()==200);
        REQUIRE(gameGrid.GetHei()==120);
    }

    SECTION("check grid constructor input","[GameGrid]") {
        REQUIRE_NOTHROW(gameGrid.SetCell(10,15,1));
        REQUIRE_NOTHROW(gameGrid.SetCell(20,30,0));
        REQUIRE_THROWS(gameGrid.SetCell(10,-45,1));
        REQUIRE_THROWS(gameGrid.SetCell(-10,-45,1));
        REQUIRE_THROWS(gameGrid.SetCell(300,15,1));
        REQUIRE_THROWS(gameGrid.SetCell(-300,15,1));
    }

    SECTION("check grid statu input","[GameGrid]") {
        REQUIRE_NOTHROW(gameGrid.SetCell(10,15,1));
        REQUIRE_NOTHROW(gameGrid.SetCell(10,15,0));
        REQUIRE_THROWS(gameGrid.SetCell(10,15,2));
        REQUIRE_THROWS(gameGrid.SetCell(10,15,-1));
    }
}

TEST_CASE(" different patterns of random alive cells","[GameGrid]"){
    gol::GameGrid gameGrid1(20,12,20);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    gol::GameGrid gameGrid2(20,12,20);

    bool equal=true;
    for (int i = 0; i < gameGrid1.GetWid(); ++i) {
        for(int j = 0; j < gameGrid1.GetHei(); ++j) {  
            if(gameGrid1.GetCell(i,j)!=gameGrid2.GetCell(i,j)){
                equal=false;
                break;
            }
        }
    }
    REQUIRE(equal==false);
}

TEST_CASE(" check the number of alive cells","[GameGrid]"){
    gol::GameGrid gameGrid(20,12,20);

    int sum = 0;
    for (int i = 0; i < gameGrid.GetWid(); ++i) {
        for(int j = 0; j < gameGrid.GetHei(); ++j) {  
            if(gameGrid.GetCell(i,j) == 1){
                sum++;
            }
        }
    }
    REQUIRE(sum==20);
}

TEST_CASE("check input of parameters","[GameGrid]"){
    gol::GameGrid gameGrid;
    REQUIRE_NOTHROW(gameGrid.ValidForRandom(10,10,5));
    REQUIRE_NOTHROW(gameGrid.ValidForRandom(20,10,3));
    REQUIRE_THROWS(gameGrid.ValidForRandom(-3,10,4));
    REQUIRE_THROWS(gameGrid.ValidForRandom(20,-20,3));
    REQUIRE_THROWS(gameGrid.ValidForRandom(-2,-2,1));
}

TEST_CASE("check input of file path","[]"){
    gol::GameGrid gameGrid;
    REQUIRE_NOTHROW(gameGrid.ValidForFile("../Testing/Data/glider.txt"));
    REQUIRE_NOTHROW(gameGrid.ValidForFile("../Testing/Data/oscillators.txt"));
    REQUIRE_THROWS(gameGrid.ValidForFile("../Testing/Data/gliderXXX.txt"));
    REQUIRE_THROWS(gameGrid.ValidForFile("../Testing/DaXXXta/glider.txt"));
}

TEST_CASE("check number of neighbours","[GameGrid]"){
    gol::GameGrid gameGrid("../Testing/Data/oscillators.txt");

    SECTION("check output for conut neighbours function","[GameGrid]"){
        REQUIRE(gameGrid.Neighbours(0,0)==0);
        REQUIRE(gameGrid.Neighbours(0,1)==0);
        REQUIRE(gameGrid.Neighbours(0,2)==0);
        REQUIRE(gameGrid.Neighbours(1,0)==1);
        REQUIRE(gameGrid.Neighbours(1,1)==2);
        REQUIRE(gameGrid.Neighbours(2,1)==1);
    }

    SECTION("check input for conut neighbours function","[GameGrid]"){
        REQUIRE_NOTHROW(gameGrid.Neighbours(0,0));
        REQUIRE_NOTHROW(gameGrid.Neighbours(2,4));
        REQUIRE_THROWS(gameGrid.Neighbours(-2,1));
        REQUIRE_THROWS(gameGrid.Neighbours(2,-1));
        REQUIRE_THROWS(gameGrid.Neighbours(1,350));
        REQUIRE_THROWS(gameGrid.Neighbours(1200,1));
    }
}


TEST_CASE("check TakeStep function","[GameOfLife]"){

    gol::GameGrid gameGrid("../Testing/Data/oscillators.txt");
    gol::GameOfLife gameOfLife(&gameGrid);
    gameOfLife.TakeStep();

    REQUIRE(gameOfLife.GetNowGrid()->GetCell(1,1)==0);
    REQUIRE(gameOfLife.GetNowGrid()->GetCell(1,2)==0);
    REQUIRE(gameOfLife.GetNowGrid()->GetCell(1,3)==0);
    REQUIRE(gameOfLife.GetNowGrid()->GetCell(2,1)==1);
    REQUIRE(gameOfLife.GetNowGrid()->GetCell(2,2)==1);
    REQUIRE(gameOfLife.GetNowGrid()->GetCell(2,3)==1);

    REQUIRE(gameOfLife.GetNextGrid()->GetCell(1,1)==0);
    REQUIRE(gameOfLife.GetNextGrid()->GetCell(1,2)==1);
    REQUIRE(gameOfLife.GetNextGrid()->GetCell(1,3)==0);
    REQUIRE(gameOfLife.GetNextGrid()->GetCell(2,1)==0);
    REQUIRE(gameOfLife.GetNextGrid()->GetCell(2,2)==1);
    REQUIRE(gameOfLife.GetNextGrid()->GetCell(2,3)==0);
}

