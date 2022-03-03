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

TEST_CASE("check grid structure","[GameGrid]"){
    gol::GameGrid bg(1997,2022);
    REQUIRE(bg.GetWid()==1997);
    REQUIRE(bg.GetHei()==2022);
}


//get和set的上界需要判定//set函数的第三个参数需要判定
TEST_CASE("check grid constructor input","[GameGrid]"){
    gol::GameGrid bg(1997,2022);
    REQUIRE_NOTHROW(bg.SetCell(1,2,1));
    REQUIRE_THROWS(bg.SetCell(-1,-2,1));
    REQUIRE_THROWS(bg.SetCell(1,-2,1));
    REQUIRE_THROWS(bg.SetCell(20000,10,1));
}

TEST_CASE("check GameGrid GetCell ","[GameGrid]"){
    gol::GameGrid bg("/workspaces/CMakeHelloWorld/glider.txt");
    REQUIRE(bg.GetCell(0,0)==0);
    REQUIRE(bg.GetCell(2,0)==1);
}

TEST_CASE("check GameGrid GetCell input","[GameGrid]"){
    gol::GameGrid bg("/workspaces/CMakeHelloWorld/glider.txt");
    REQUIRE_NOTHROW(bg.GetCell(1,1));
    REQUIRE_THROWS(bg.GetCell(-1,0));
    REQUIRE_THROWS(bg.GetCell(2,-5));
    REQUIRE_THROWS(bg.GetCell(2,500));
}


TEST_CASE("check number of alive cells","[GameGrid]"){
    gol::GameGrid bg("/workspaces/CMakeHelloWorld/glider.txt");
    REQUIRE(bg.Neighbours(0,0)==0);
    REQUIRE(bg.Neighbours(2,1)==5);
}

TEST_CASE("check input for conut alive number function","[GameGrid]"){
    gol::GameGrid bg("/workspaces/CMakeHelloWorld/glider.txt");
    REQUIRE_NOTHROW(bg.Neighbours(0,0));
    REQUIRE_THROWS(bg.Neighbours(-2,1));
    REQUIRE_THROWS(bg.Neighbours(2000,1));
}


/*
TEST_CASE("check file reader","[GameGrid]"){
    gol::GameGrid bg;
    REQUIRE_NOTHROW(bg.FileReader("/workspaces/CMakeHelloWorld/glider.txt"));
    REQUIRE_THROWS(bg.FileReader("/Datalalala/glider.txt"));
}*/

/*
TEST_CASE("check file input data","[GameGrid]"){
    GameGrid bg;
    //modify the error input data
    std::vector<int> error_vector_line = {0,0,0,0,0,0,0,0,0};
    std::vector<int> error_vector_line_2 = {0,0,0,2,6,0,0,0,0};
    //modify standard input size
    int standard_size=10;
    //modify standard input data
    std::vector<int> standard_vector_line = {0,0,0,0,0,0,0,0,0,0};
    REQUIRE_NOTHROW(bg.FileDataValidation(standard_vector_line.size(),standard_size));
    REQUIRE_THROWS(bg.FileDataValidation(error_vector_line.size(),standard_size));
    REQUIRE_THROWS(bg.FileDataValidation(error_vector_line_2.size(),standard_size));
}*/

TEST_CASE(" different patterns of random alive cells","[GameGrid]"){
    gol::GameGrid bg1(10,10,10);
    std::this_thread::sleep_for (std::chrono::seconds(1));
    gol::GameGrid bg2(10,10,10);

    bool equal=true;
    for (int i = 0; i < bg1.GetWid(); ++i) {
        for(int j = 0; j < bg1.GetHei(); ++j) {  
            if(bg1.GetCell(i,j)!=bg2.GetCell(i,j)){
                equal=false;
                break;
            }
            
        }
    }
    //If equal==false, which means the aliive cells have different patterens
    REQUIRE(equal==false);
}

/*
TEST_CASE("check TakeStep function","[Game]"){

    gol::GameGrid bg("/workspaces/CMakeHelloWorld/glider.txt");
    Game g(bg, bg);
    g.TakeStep();
    REQUIRE(g.GetcurrentGrid().GetCell(1,1)==1);
    REQUIRE(g.GetcurrentGrid().GetCell(0,0)==0);
    REQUIRE(g.GetcurrentGrid().GetCell(1,3)==0);
    REQUIRE(g.GetcurrentGrid().GetCell(2,1)==0);
    REQUIRE(g.GetcurrentGrid().GetCell(2,3)==1);
    REQUIRE(g.GetcurrentGrid().GetCell(3,2)==1);
}*/

