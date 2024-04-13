#include<iostream>
#include<cstdlib>
#ifndef DICE_H
#define DICE_H

using namespace std;

class dice{
    //lb-1 ub-6  = (rand()%(ub-lb+1))+lb
    int mini=1;
    int maxi=6;
    public:
    int diceRoll(){
        // for(int i=0;i<10;i++){
        //      double d=(rand()%(maxi-mini+1))+mini;
        //      cout<<d<<endl;
        // }
        double d=(rand() % (maxi)) + mini; //RANDOM NO BTW 1 TO 6
        return int(d);
    }
};

#endif