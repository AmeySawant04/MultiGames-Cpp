#ifndef BETTERSNAKE_H
#define BETTERSNAKE_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;



class Snake{
    public:
        int random;
        int score;
        enum edir {STOP = 0, LEFT, RIGHT, UP, DOWN};
        int fruitX;
        int fruitY;
        int x;
        int y;
        int width, height;
        int size;
        int followX [100], followY [100];
        bool status;
        edir direction;
        void Draw();
        void Input();
        void Logic();
        // void endGame();
        Snake(int widthX, int heigthY){
            width = widthX;
            height = heigthY;
            x = (width / 2);
            y = (height / 2);
            fruitX = (rand() % 25);
            fruitY = (rand() % 11);
            score = 0;
            size = 0;
            direction = STOP;
            status = false;
            random = 0;
            while(!status)
            {
                Draw();
                Input();
                Logic();
                _sleep(80);
            }
            cout<<"\n****TO RESTART PRESS CTRL + R + CTRL + R****";
                getch();
            
        }
};


void Snake:: Draw (){
    system("cls");
    for(int i = 0; i < width; i++){
        cout<<"\xCD";
    }
    cout<<endl;
    for(int i = 0; i < height ; i++){
        for(int j = 0; j < width; j++){

            
            if(j == 0)
                cout<<"\xF1";
            else if(j == fruitX && i == fruitY)
                cout<<"\x9D";
            else if(j == width - 1)
                cout<<"\xF1";
            else if(j == x && i == y)
                cout<<"\xDB";
            else{
                bool print = false;
                for(int a = 0; a < size; a++){
                    
                if(followX[a] == j && followY[a] == i){
                    if(a%2 == 0)
                        cout<<"\xDC";
                    else
                        cout<<"\xDF";
                    print = true; 
                }   
            }
              if(!print)
                cout<<" ";
            }
               
        }
        cout<<endl;
    }
    
    for(int i = 0; i < width; i++){
        cout<<"\xCD";
    }
    cout<<endl;
    cout<<"Score : "<<score;
}

void Snake:: Input(){
    if(_kbhit()){
        switch(direction){
            case STOP :
                switch(_getch()){
            case 'w':
                direction = UP;
                break;
            case 's':
                direction = DOWN;
                break;
            case 'a':
                direction = LEFT;
                break;
            case 'd':
                direction = RIGHT;
                break;
            case 'k':
                status = true;
            }
            break;
            case UP :
                switch(_getch()){
            case 'a':
                direction = LEFT;
                break;
            case 'd':
                direction = RIGHT;
                break;
            case 'k':
                status = true;
            }
            break;
            case DOWN :
            switch(_getch()){
            case 'a':
                direction = LEFT;
                break;
             case 'd':
                direction = RIGHT;
                break;
            case 'k':
                status = true;
            }
            break;
            case LEFT:
            switch(_getch()){
            case 'w':
                direction = UP;
                break;
            case 's':
                direction = DOWN;
                break;
            case 'k':
                status = true;
            }
            break;
            case RIGHT:
            switch(_getch()){
            case 'w':
                direction = UP;
                break;
            case 's':
                direction = DOWN;
                break;
            case 'k':
                status = true;
            }
            break;
        }
        

        
    }
}
void Snake:: Logic(){

    int prevX = followX[0];
    int prevY = followY[0];
    int prev2X, prev2Y;
    followX[0] = x;
    followY[0] = y;
    for(int i = 1; i < size; i++){
        prev2X = followX[i];
        prev2Y = followY[i];
        followX[i] = prevX;
        followY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(direction){
        case STOP:
        break;
        case LEFT:
            x--;
        break;
        case RIGHT:
            x++;
        break;
        case UP:
            y--;
        break;
        case DOWN:
            y++;
        break;
    }
    
    if(x == fruitX && y == fruitY){
        fruitX = (rand() % 20);
        fruitY = (rand() % 10);
        random++;
        if(random > 15 && random < 20){
            fruitX = (rand() % 21);
            fruitY = (rand() % 11);
        }
        if(random > 20){
            fruitX = (rand() % 19);
            fruitY = (rand() % 9);
        }
        size++;
        score += 100;
    }

    if(x < 0)
        x = width - 1;
    else if(x >= width)
        x = 0;
    else if(y < 0)
        y = height - 1;
    else if(y >= height)
        y = 0;

    for(int i = 0; i < size; i++)
        if(followX[i] == x && followY[i] == y)
            status = true;    
}

// void Snake:: endGame(){
//     status = true;
//     system("cls");

//      for(int i = 0; i < width; i++){
//         cout<<"#";
//     }
//     cout<<endl;
    
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";
//     cout<<"#                            #";

//     for(int i = 0; i < width; i++){
//         cout<<"#";
//     }
//     cout<<endl;
// }
#endif
// int main (){
//     Snake s(30, 15);
//     return 0;
// }