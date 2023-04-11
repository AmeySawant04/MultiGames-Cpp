#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include "finalHangManGame.cpp"
#include "InPong.cpp"
#include "finalSnakeGame.cpp"



int main(){
    system("cls");
    int choice;
    cout<<"  WELCOME TO GAMEVILLA"<<endl;
    cout<<" 1.HangMan"<<endl<<" 2.Pong"<<endl<<" 3.Vegan Snake"<<">";
    cin>>choice;

    
    if(choice == 1)
        hangMan man(0, (rand() % 20));
    else if(choice == 2)
        cGameManger pong(40, 20);
    else if(choice == 3)
        Snake veganSnake(30, 15);
    else
        cout<<"("<<choice<<" is Invalid input)";
    return 0;
}
