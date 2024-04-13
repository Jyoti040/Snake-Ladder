#include<iostream>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class player{
    public:
    string name;
    string email;
    long phoneNo;
    int age;

    void setAllDetails(){
        string n,e;
        long p;
        int a;
        cout<<endl<<"Enter player details  "<<endl;
        cout<<"Enter player name : ";
        cin>>n;
         cout<<"Enter player email : ";
        cin>>e;
         cout<<"Enter player phone number : ";
        cin>>p;
         cout<<"Enter player age : ";
        cin>>a;
        name=n;
        email=e;
        phoneNo=p;
        age=a;
        
    }

    string getName(){
        return name;
    }

     void  getAllDetails(){
         cout<<endl;
        cout<<"Player name  is : "<<name<<endl;
   
         cout<<"Player email : "<<email<<endl;
    
         cout<<"Player phone number : "<<phoneNo<<endl;

         cout<<"Player age : "<<age<<endl;
    }

};

#endif