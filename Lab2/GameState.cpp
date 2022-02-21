//
//  GameState.cpp
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

#include "globals.h"
#include "GameState.h"

// ECE244 Student: add you code below

    // The constructor. It initializes:
    //     selectedRow to 0
    //     selectedColum to 0
    //     moveValid to true
    //     gameOver to false
    //     winCode to 0
    //     turn to true
    //     gameBoad locations to Empty (see globals.h)
    GameState::GameState()
    {
        selectedRow = 0;
        selectedColumn = 0;
        moveValid = true;
        gameOver = false;
        winCode = 0;
        turn = true;
        
        for(int i=0; i<(boardSize); i++)
        {
            for(int j=0; j<(boardSize); j++)
            {
                gameBoard[i][j] = Empty; //Set gameBoard locations = 0
            }
        }
        
    }

    // Return the selected row (in the range 0..boardSize-1)
    int GameState::get_selectedRow()
    {
        return selectedRow;
    }

    // Return the selected column (in the range 0..boardSize-1)
    int GameState::get_selectedColumn()
    {
        return selectedColumn;
    }
    
    // Set the selected row to value in the range (in the range 0..boardSize-1)
    // An out of range value is ignored and the function just returns
    void GameState::set_selectedRow(int value)
    {
        selectedRow = value;
    }    

    // Set the selected column in the range (in the range 0..boardSize-1)
    // An out of range value is ignored and the function just returns
    void GameState::set_selectedColumn(int value)
    {
        selectedColumn = value;
    }
    
    // Get the moveValid value
    bool GameState::get_moveValid()
    {
        return moveValid; //Dueng kaar value of "moveValid". Must use this function to do because moveVaid is Prvate.
    }                     //But, member(functions) inside the SAME class as moveValid can be used outside of its class.

    // Set the moveValid variable to value
    void GameState::set_moveValid(bool value)
    {
        moveValid = value;
    }

    // Get the gameOver value
    bool GameState::get_gameOver()
    {
        return gameOver;
    }

    // Set the gameOver variable to value
    void GameState::set_gameOver(bool value)
    {
        gameOver = value;
    }

    // Get the winCode [0..8]
    int GameState::get_winCode()
    {
        return winCode;
    }
    
    // Set the winCode to value in the range (0..8)
    // An out of range value is ignored and the function just returns
    void GameState::set_winCode(int value)
    {
        winCode = value;
    }
    
    // Get the value of turn
    bool GameState::get_turn()
    {
        return turn;
    }

    // Set the value of turn
    void GameState::set_turn(bool value)
    {
        turn = value;
    }
    
    // Get the game board value at the board location at row and col
    // This method checks that row, col and value are in range/valid
    // and if not it returns Empty
    int GameState::get_gameBoard(int row, int col)
    {
        return gameBoard[row][col];
    }

    // Set the game board value at the board location at row and col to value
    // This method checks that row, col and value are in range/valid and if not it
    // just returns
    void GameState::set_gameBoard(int row, int col, int value)
    {
        gameBoard[row][col] = value;
    }


