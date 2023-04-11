#ifndef BETTERPONG_H
#define BETTERPONG_H

#include <iostream>
#include <time.h>
#include <conio.h>
#include <cstdlib>

using namespace std;
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};
class cBall
{
protected:
    int x, y;
    int originalX, originalY;
    eDir direction;
public:
    cBall(int posX, int posY);
    void Reset();
    void changeDirection(eDir d);
    void randomDirection();
    inline int getX();
    inline int getY();
    inline eDir getDirection();
    void Move();
    friend ostream & operator<<(ostream & o, cBall c);
};
cBall:: cBall(int posX, int posY)
    {
        originalX = posX;
        originalY = posY;
        x = posX; y = posY;
        direction = STOP;
    }
void cBall:: Reset()
    {
        x = originalX; y = originalY;
        direction = STOP;
    }
void cBall:: changeDirection(eDir d)
    {
        direction = d;
    }
void cBall:: randomDirection()
    {
        direction = (eDir)(rand() % 7);
    }
inline int cBall:: getX() { return x; }
inline int cBall:: getY() { return y; }
inline eDir cBall:: getDirection() { return direction; }
void cBall:: Move()
    {
        switch (direction)
        {
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UPLEFT:
            x--; y--;
            break;
        case DOWNLEFT:
            x--; y++;
            break;
        case UPRIGHT:
            x++; y--;
            break;
        case DOWNRIGHT:
            x++; y++;
            break;
        default:
            break;
        }
    }
ostream & operator<<(ostream & o, cBall c)
    {
        o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
        return o;
    }
class cPaddle
{
protected:
    int x, y;
    int originalX, originalY;
public:
    cPaddle();
    cPaddle(int posX, int posY) : cPaddle()
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }
    inline void Reset();
    inline int getX();
    inline int getY();
    inline void moveUp();
    inline void moveDown();
    friend ostream & operator<<(ostream & o, cPaddle c);
};
cPaddle:: cPaddle()
    {
        x = y = 0;
    }
inline void cPaddle:: Reset() { x = originalX; y = originalY; }
inline int cPaddle:: getX() { return x; }
inline int cPaddle:: getY() { return y; }
inline void cPaddle:: moveUp() { y--; }
inline void cPaddle:: moveDown() { y++; }
ostream & operator<<(ostream & o, cPaddle c)
    {
        o << "Paddle [" << c.x << "," << c.y << "]";
        return o;
    }

class cGameManger
{
protected:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall * ball;
    cPaddle *player1;
    cPaddle *player2;
    
public:
    cGameManger(int w, int h)
    {
        srand(time(NULL));
        quit = false;
        up1 = 'w'; up2 = 'i';
        down1 = 's'; down2 = 'k';
        score1 = score2 = 0;
        width = w; height = h;
        ball = new cBall(w / 2, h / 2);
        player1 = new cPaddle(1, h / 2 - 3);
        player2 = new cPaddle(w - 2, h / 2 - 3);
        
    }
    ~cGameManger()
    {
        delete ball, player1, player2;
    }
    void ScoreUp(cPaddle * player)
    {
        if (player == player1)
            score1++;
        else if (player == player2)
            score2++;
 
        ball->Reset();
        player1->Reset();
        player2->Reset();
    }
    void Draw()
    {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";
        cout << endl;
 
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int ballx = ball->getX();
                int bally = ball->getY();
                int player1x = player1->getX();
                int player2x = player2->getX();
                int player1y = player1->getY();
                int player2y = player2->getY();
 
                if (j == 0)
                    cout << "\xB2";
 
                if (ballx == j && bally == i)
                    cout << "O"; //ball
                else if (player1x == j && player1y == i)
                    cout << "\xDB"; //player1
                else if (player2x == j && player2y == i)
                    cout << "\xDB"; //player2
 
                else if (player1x == j && player1y + 1 == i)
                    cout << "\xDB"; //player1
                else if (player1x == j && player1y + 2 == i)
                    cout << "\xDB"; //player1
                else if (player1x == j && player1y + 3 == i)
                    cout << "\xDB"; //player1
 
                else if (player2x == j && player2y + 1 == i)
                    cout << "\xDB"; //player1
                else if (player2x == j && player2y + 2 == i)
                    cout << "\xDB"; //player1
                else if (player2x == j && player2y + 3 == i)
                    cout << "\xDB"; //player1
                else
                    cout << " ";
 
                if (j == width - 1)
                    cout << "\xB2";
            }
            cout << endl;
        }
 
        for (int i = 0; i < width + 2; i++)
            cout << "\xB2";
        cout << endl;
 
        cout << "Score 1: " << score1 << endl << "Score 2: " << score2 << endl;
    }
    void Input()
    {
        ball->Move();
 
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();
 
        if (_kbhit())
        {
            char current = _getch();
            if (current == up1)
                if (player1y > 0)
                    player1->moveUp();
            if (current == up2)
                if (player2y > 0)
                    player2->moveUp();
            if (current == down1)
                if (player1y + 4 < height)
                    player1->moveDown();
            if (current == down2)
                if (player2y + 4 < height)
                    player2->moveDown();
 
            if (ball->getDirection() == STOP)
                ball->randomDirection();
 
            if (current == 'q')
                quit = true;
        }
    }
    void Logic()
    {
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();
 
        //left paddle
        for (int i = 0; i < 4; i++)
            if (ballx == player1x + 1)
                if (bally == player1y + i)
                    ball->changeDirection((eDir)((rand() % 3) + 4));
 
        //right paddle
        for (int i = 0; i < 4; i++)
            if (ballx == player2x - 1)
                if (bally == player2y + i)
                    ball->changeDirection((eDir)((rand() % 3) + 1));
 
        //bottom wall
        if (bally == height - 1)
            ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
        //top wall
        if (bally == 0)
            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
        //right wall
        if (ballx == width - 1)
            ScoreUp(player1);
        //left wall
        if (ballx == 0)
            ScoreUp(player2);

        if (score1 == 5)
            end(1);
        else if(score2 == 5)
            end(2);

    }
void end(int a){
    quit = true;
        system("cls");
        for (int i = 0; i < width +1; i++)
            cout << "\xB2";
        cout << endl;
 if (a == 1)
 {

        cout<<"\xB2                                       \xB2"<<endl;
        cout<<"\xB2                   \xB2\xB2                  \xB2"<<endl;
        cout<<"\xB2                 \xB2\xB2\xB2\xB2                  \xB2"<<endl;
        cout<<"\xB2                \xB2\xB2 \xB2\xB2                  \xB2"<<endl;
        cout<<"\xB2               \xB2\xB2  \xB2\xB2                  \xB2"<<endl;
        cout<<"\xB2              \xB2\xB2   \xB2\xB2                  \xB2"<<endl;
        cout<<"\xB2                   \xB2\xB2                  \xB2"<<endl;
        cout<<"\xB2                   \xB2\xB2                  \xB2"<<endl;
        cout<<"\xB2                   \xB2\xB2                  \xB2"<<endl;
        cout<<"\xB2             \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2             \xB2"<<endl;
        cout<<"\xB2             \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2             \xB2"<<endl;
        cout<<"\xB2                                       \xB2"<<endl;
        cout<<"\xB2                            \xB2          \xB2"<<endl;
        cout<<"\xB2          \xB2      \xB2 \xB2\xB2\xB2\xB2 \xB2\xB2  \xB2          \xB2"<<endl;
        cout<<"\xB2           \xB2 \xB2\xB2 \xB2  \xB2  \xB2 \xB2 \xB2 \xB2          \xB2"<<endl;
        cout<<"\xB2            \xB2  \xB2   \xB2\xB2\xB2\xB2 \xB2  \xB2\xB2          \xB2"<<endl;
        cout<<"\xB2                        \xB2              \xB2"<<endl;
        cout<<"\xB2                                       \xB2"<<endl;
 }else
 {

        cout<<"\xB2                                       \xB2"<<endl;
        cout<<"\xB2                 \xB2\xB2\xB2\xB2                  \xB2"<<endl;
        cout<<"\xB2               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2                \xB2"<<endl;
        cout<<"\xB2              \xB2\xB2     \xB2\xB2\xB2               \xB2"<<endl;
        cout<<"\xB2             \xB2\xB2       \xB2\xB2\xB2              \xB2"<<endl;
        cout<<"\xB2                     \xB2\xB2\xB2               \xB2"<<endl;
        cout<<"\xB2                    \xB2\xB2                 \xB2"<<endl;
        cout<<"\xB2                  \xB2\xB2                   \xB2"<<endl;
        cout<<"\xB2                \xB2\xB2                     \xB2"<<endl;
        cout<<"\xB2              \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2              \xB2"<<endl;
        cout<<"\xB2              \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2              \xB2"<<endl;
        cout<<"\xB2                                       \xB2"<<endl;
        cout<<"\xB2                            \xB2          \xB2"<<endl;
        cout<<"\xB2          \xB2      \xB2 \xB2\xB2\xB2\xB2 \xB2\xB2  \xB2          \xB2"<<endl;
        cout<<"\xB2           \xB2 \xB2\xB2 \xB2  \xB2  \xB2 \xB2 \xB2 \xB2          \xB2"<<endl;
        cout<<"\xB2            \xB2  \xB2   \xB2\xB2\xB2\xB2 \xB2  \xB2\xB2          \xB2"<<endl;
        cout<<"\xB2                        \xB2              \xB2"<<endl;
        cout<<"\xB2                                       \xB2"<<endl;
 }
        for (int i = 0; i < width + 1; i++)
            cout << "\xB2";
        cout << endl;
 
        cout << "Score 1: " << score1 << endl << "Score 2: " << score2 << endl;
        cout<<"\n****TO RESTART PRESS CTRL + R + CTRL + R****";
                getch();
    }
    
    
    void Run()
    {
        while (!quit)
        {
            Draw();
            Input();
            Logic();
        }
    }
};
#endif
// int main()
// {
//     cGameManger c(40, 20);
//     c.Run();
//     return 0;
// }