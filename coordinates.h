#include<iostream>
#ifndef COORDINATES_H
#define COORDINATES_H

using namespace std;

class coordinates{
   public:
   int row,col;

   public:
   coordinates(){

   }
   coordinates(int r, int c){
    row=r;
    col=c;
   }

   string printCoordinates(){
    string cords="";
    cords="[ "+to_string(row)+" , "+to_string(col)+" ]";
    return cords;
   }
   int getRow(){
    return row;
   }
      int getCol(){
    return col;
   }
};


#endif