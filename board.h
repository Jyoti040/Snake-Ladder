#include<iostream>
#include<string>
#include<map>
#include "jumper.h"

#ifndef BOARD_H
#define BOARD_H
using namespace std;

class board{
    public : 
    int size;
    string matrix[10][10];
    map<string,jumper> map_jumper;

    public :
    board(){

    }
    board(map<string,jumper> mj){
        size=10;
        map_jumper=mj;
        // matrix=new string*[size];    // initialising 2d matrix
        // for(int i=0; i<size; i++){
        //     matrix[i]=new string[size];
        // }

        int count=1;
        for(int row=size-1; row>=0; row--){   //begining from last column  in snake and ladder board 
            if(row%2 != 0){
                for(int col=0; col<size; col++ ){
                    matrix[row][col]=to_string(count);
                    count++;
                }
            }else{
                for(int col=size-1; col>=0;col--){
                   matrix[row][col]=to_string(count);
                           count++;
                }
            }
        }
        
    }
    public:
    void printMatrix(){
        cout<<endl<<"The board is : "<<endl;
        for(int i=0;i<size;i++){
            for(int j=0; j<size; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int getBoardSize(){
        return size;
    }


};

#endif