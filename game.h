#include <iostream>
#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"
#include "dice.h"

class game
{

    board gameBoard;
    player gamePlayers[2];
    bool isAllowed[2];
    int turn;
    dice gameDice;
    coordinates gameCoordinates[2];

 bool checkIfJumperExists(int row, int col) {
      
        int count_jumper=gameBoard.map_jumper.count(gameBoard.matrix[row][col]);
        // cout<<"count is :"<<count_jumper<<endl;
        return (count_jumper<=0)? false : true;
        
    }

    coordinates getNewCoordinates(coordinates oldCoordinates, int num) {
        int row = oldCoordinates.getRow();
        int col = oldCoordinates.getCol();
        // cout<<row <<" , "<<col<<endl;
        while (num>0) {
            if (row%2 != 0) {
                if (col == gameBoard.getBoardSize()-1) row--;
                else col++;

            } else {
                if (col == 0) row--;
                else col--;
            }

            num--;
        }
    //    cout<<row <<" , "<<col<<endl;
        if (row < 0) {
            coordinates temp(row,col);
            // cout<<"row<0"<<temp.printCoordinates()<<endl;
            return temp;}
        if (checkIfJumperExists(row,col)==true) {
            jumper jumper = gameBoard.map_jumper[gameBoard.matrix[row][col]];
            // cout<<"jumper"<<jumper.end.printCoordinates();
            return jumper.end;

        }
      
       coordinates temp(row,col);
            return temp;
        
    }

 

public:
    game(board b, player player[], dice d)
    {
        gameBoard = b;
        gameDice = d;
        turn = 0;

        for (int i = 0; i < 2; i++)
        {
            gamePlayers[i] = player[i];
            // cout << gamePlayers[i].getName() << endl;
            
            isAllowed[i] = false;
            gameCoordinates[i] = coordinates(gameBoard.getBoardSize()-1, 0);
            // cout << gameCoordinates[i].printCoordinates();
        }
        cout<<endl<<"The rules of game are : "<<endl;
        cout<<"1.Given below is the board of size 10 x 10 ."<<endl;
        cout<<"2.The position of snake and ladders are also given. "<<endl;
        cout<<"3.Any player will enter the game only when dice rolls 1 ."<<endl;
        cout<<"4.The player who reaches the 100 or coordinates-[0,0] first will be the winner."<<endl;
        gameBoard.printMatrix();
         map<string,jumper> map_jumper=gameBoard.map_jumper;
         cout<<endl<<"Positions of snake and ladders are "<<endl;
         for(auto c : map_jumper){
            cout<<c.second.name<<" is at "<<c.first<<" number on board . Its coordinates are : "<<c.second.end.printCoordinates()<<endl;
         }
         cout<<endl;
    }
       void play() {
        while(true) {
            int num = gameDice.diceRoll();
            cout<<endl;
            cout<<gamePlayers[turn].getName() << " rolled -> " << num <<" . Its coordinates are : "<< gameCoordinates[turn].printCoordinates()<<endl;

            if (!isAllowed[turn]) {
                if (num != 1) {
                    turn = 1-turn;
                    // turn = 1 => 1-1 = 0;
                    // turn = 0 => 1-0 = 1;
                    continue;
                } else {
                    isAllowed[turn] = true;
                }
            }

            coordinates newCoordinates = getNewCoordinates(gameCoordinates[turn], num);
            cout<<"Now , "<<gamePlayers[turn].getName()<<" is at "<<newCoordinates.printCoordinates()<<endl;
            if (newCoordinates.getRow() < 0) {
                cout<<endl<<gamePlayers[turn].getName()<<" has won";
                return;
            }

            gameCoordinates[turn] = newCoordinates;
            turn  = 1-turn;
        }
    }

};
#endif