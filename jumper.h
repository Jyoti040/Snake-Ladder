#include<iostream>
#ifndef JUMPER_H
#define JUMPER_H
#include "coordinates.h"

using namespace std;

 // tells we are at ladder or a snake at a particular position 
 // if start > end (row) -> ladder  ex - no = 6 ,  [9,6](s) [6,6](e) // board coordinates 
 // if start < end (row) ->snake    ex - no = 97 , [0,1](s) [9,9](e) 

class jumper    
{
  public:
     coordinates start;
     coordinates end;
     string name;

     public:

      jumper(){

      }
      jumper(coordinates s,coordinates e){
        start=s;
        end=e;
        if(s.getRow() > e.getRow()){
            name="Ladder";
        }
        else{
            name="Snake";
        }
      }
      string getJumperName(){
        return name;
      }
};


#endif