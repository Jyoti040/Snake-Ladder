#include<iostream>
#include<map>
#include "player.h"
#include "dice.h"
#include "coordinates.h"
#include "jumper.h"
#include "board.h"
#include "game.h"

using namespace std;

int main(){
    map<string,jumper> map_jumper;
    map_jumper["6"]=jumper(coordinates(9,5),coordinates(6,6));
     map_jumper["97"]=jumper(coordinates(0,1),coordinates(9,9));
    map_jumper["21"]=jumper(coordinates(7,0),coordinates(0,9));
     map_jumper["64"]=jumper(coordinates(3,3),coordinates(7,4));

    player p1,p2;
    p1.setAllDetails();
    // p1.getAllDetails();
     p2.setAllDetails();
    // p2.getAllDetails();
  
    dice d;

    // cout<<(d.diceRoll());
    // coordinates c1(4,5);
    // cout<<c1.printCoordinates();

    board b(map_jumper);
    // b.printMatrix();

    player allPlayers[]={p1,p2};
    game g(b,allPlayers,d);
   g.play();

    return 0;
}