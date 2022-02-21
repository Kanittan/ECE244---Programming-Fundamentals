//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

//
void playMove(GameState& game_state) {
    
    // Set Move Valid
    
    if((game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) == X) || (game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) == O))
    {
//        game_state.get_moveValid() == false;
        game_state.set_moveValid(false);
    }
    else
    {
//        game_state.get_moveValid() == true;
        game_state.set_moveValid(true);
    }
    
//    if(game_state.get_moveValid() == true)
//    {
//        game_state.set_moveValid(true);
//    }
//    else
//    {
//        game_state.set_moveValid(false);
//    }
//    
    // Set gameBoard
    if(game_state.get_moveValid() == true)
    {
        if(game_state.get_turn() == true)
        {
            game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), 1); // Place X (+1)
        }
        
        else
        {
            game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), -1); // Place O (-1)
        }
    }
//    else //if(game_state.get_moveValid() == false)
//    {
//        
//    }
    
    
    // Set gameOver

    // CHECK If "X" OR "o" ACROSS ROW:
    if(((game_state.get_gameBoard(0, 0)==1) && (game_state.get_gameBoard(0, 1)==1) && (game_state.get_gameBoard(0, 2)==1)) || ((game_state.get_gameBoard(0, 0)==-1) && (game_state.get_gameBoard(0, 1)==-1) && (game_state.get_gameBoard(0, 2)==-1)))
    {
        game_state.set_winCode(1);
    }
    else if(((game_state.get_gameBoard(1, 0)==1) && (game_state.get_gameBoard(1, 1)==1) && (game_state.get_gameBoard(1, 2)== 1)) || ((game_state.get_gameBoard(1, 0)==-1) && (game_state.get_gameBoard(1, 1)==-1) && (game_state.get_gameBoard(1, 2)==-1)))
    {
        game_state.set_winCode(2);
    }
    else if(((game_state.get_gameBoard(2, 0)==1) && (game_state.get_gameBoard(2, 1)==1) && (game_state.get_gameBoard(2, 2)== 1)) || ((game_state.get_gameBoard(2, 0)==-1) && (game_state.get_gameBoard(2, 1)==-1) && (game_state.get_gameBoard(2, 2)==-1)))
    {
        game_state.set_winCode(3);
    }
    
    // CHECK If "X" OR "o" ACROSS COLUMN:
    else if(((game_state.get_gameBoard(0, 0)==1) && (game_state.get_gameBoard(1, 0)==1) && (game_state.get_gameBoard(2, 0)== 1)) || ((game_state.get_gameBoard(0, 0)==-1) && (game_state.get_gameBoard(1, 0)==-1) && (game_state.get_gameBoard(2, 0)==-1)))
    {
        game_state.set_winCode(4);
    }
    else if(((game_state.get_gameBoard(0, 1)==1) && (game_state.get_gameBoard(1, 1)==1) && (game_state.get_gameBoard(2, 1)== 1)) || ((game_state.get_gameBoard(0, 1)==-1) && (game_state.get_gameBoard(1, 1)==-1) && (game_state.get_gameBoard(2, 1)==-1)))
    {
        game_state.set_winCode(5);
    }
    else if(((game_state.get_gameBoard(0, 2)==1) && (game_state.get_gameBoard(1, 2)==1) && (game_state.get_gameBoard(2, 2)== 1)) || ((game_state.get_gameBoard(0, 2)==-1) && (game_state.get_gameBoard(1, 2)==-1) && (game_state.get_gameBoard(2, 2)==-1)))
    {
        game_state.set_winCode(6);
    }
            
    //CHECK IF "X" OR "O" ACROSS DIAGONAL (LEFT Down to Right)
    else if(((game_state.get_gameBoard(0, 0)==1) && (game_state.get_gameBoard(1, 1)==1) && (game_state.get_gameBoard(2, 2)== 1)) || ((game_state.get_gameBoard(0, 0)==-1) && (game_state.get_gameBoard(1, 1)==-1) && (game_state.get_gameBoard(2, 1)==-1)))
    {
        game_state.set_winCode(7);             
    }
            
    //CHECK IF "X" OR "O" ACROSS DIAGONAL (RIGHT Down to LEFT)
    else if(((game_state.get_gameBoard(0, 2)==1) && (game_state.get_gameBoard(1, 1)==1) && (game_state.get_gameBoard(2, 0)== 1)) || ((game_state.get_gameBoard(0, 2)==-1) && (game_state.get_gameBoard(1, 1)==-1) && (game_state.get_gameBoard(2, 0)==-1)))
    {
        game_state.set_winCode(8);             
    }
    else //NO WIN Scenario
    {
        game_state.set_winCode(0);
    }
    
    
    
    // Set GameOver
    //if(game_state.get_winCode() != 0)
    if((game_state.get_winCode() == 1) || (game_state.get_winCode() == 2) || (game_state.get_winCode() == 3) || (game_state.get_winCode() == 4) || (game_state.get_winCode() == 5) || (game_state.get_winCode() == 6) || (game_state.get_winCode() == 7) || (game_state.get_winCode() == 8))
    {
        game_state.set_gameOver(true);
    }
    else //if((game_state.get_winCode == 0)
    {
        game_state.set_gameOver(false);
    }
    
    
    // Set Turn (LAST STEP)
    if((game_state.get_gameOver() == false) && (game_state.get_moveValid() == true))
    {
        //CHANGE TURN
        if(game_state.get_turn() == true)
        {
            game_state.set_turn(false);
        }
        else
        {
            game_state.set_turn(true);
        }
    }
    
}

