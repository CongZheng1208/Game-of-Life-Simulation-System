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

GameOfLife::GameOfLife( GameGrid* gamegrid ) : grid_now( gamegrid ) {
    grid_next = new GameGrid( grid_now->GetWid(), grid_now->GetHei() );
}
GameOfLife::~GameOfLife() {
    if( grid_next ) delete grid_next;
}
GameGrid* GameOfLife::GetNowGrid() {
    return grid_now;
}
GameGrid* GameOfLife::GetNextGrid() {
    return grid_next;
}
bool GameOfLife::HasLivingCells() {
    for( int y = 0; y < grid_now->GetHei(); y++ )
        for( int x = 0; x < grid_now->GetWid(); x++ )
            if( grid_now->GetCell( x, y ) ) return true;
    return false;
}
void GameOfLife::SwapGrids() {
    grid_now->SwapCells( grid_next );
}

bool GameOfLife::IsStillLifes(){
    for( int y = 0; y < grid_now->GetHei(); y++ )
        for( int x = 0; x < grid_now->GetWid(); x++ )
            if( grid_now->GetCell( x, y )!= grid_next->GetCell( x, y )) return false;
    return true;
}
void GameOfLife::TakeStep() {
    int neighbours_number;
    for( int y = 0; y < grid_now->GetHei(); y++ ) {
        for( int x = 0; x < grid_now->GetWid(); x++ ) {
            neighbours_number = grid_now->Neighbours( x, y );
            //1. If the number of neighbors of a living cell is 2 or 3, the cell can continue to survive
            //2. If the number of neighbors of a dead cell is 3, the cell can be resurrected
            //3. If the number of living cell neighbors is less than 2 and more than 3, it will die immediately
            if( grid_now->GetCell( x, y ) ) {
                if(neighbours_number == 2 || neighbours_number==3){
                    grid_next->SetCell( x, y, 1 );
                }else{
                    grid_next->SetCell( x, y, 0 );
                }
            } else if(neighbours_number==3) {
                grid_next->SetCell( x, y, 1 );
            }else{
                grid_next->SetCell( x, y, 0 );
            }
        }
    }
}
void GameOfLife::PrintGridForGame() {
    grid_now->PrintGrid();
    std::cout << "<----------Inter-iteration-separator---------------->" << std::endl;
}

} // end namespace
