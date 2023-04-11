#include <iostream>
#include "betterHangMan.h"
#include "betterPong.h"
#include "betterSnake.h"

void draw(string message, bool top = true, bool mid = true, bool bottom = true)
{
        if(top)
            cout<<"+---------------------------------+\n";
            cout<<"|";
        
            bool where = true;
            for(int  i = message.length(); i < 33; i++)
            {
                if(mid){
                    if(where)
                        message = " " + message;
                    else
                        message = message + " ";
                    where = !where;
                }else{
                    message += " ";
                }
            }
            cout<<message;
            cout<<"|\n";
        
        if(bottom)
            cout<<"+---------------------------------+\n";
}
void starter (){
    system("cls");
    int a;
    
    draw("Welcome To Old School Games");
    draw("  Games",false, false, false);
    draw("  1.HangMan",false, false, false);
    draw("  2.Pong",false, false, false);
    draw("  3.Snake",false, false);
    cout<<">";cin>>a;
        if(a == 1){
            srand(time(0));
            hangMan man(0);
        }else if(a == 2){
            cGameManger c(40, 20);
            c.Run();
        }else if(a == 3){
            srand(NULL);
            Snake s(30, 15);
        }
            
}
int main()
{
    starter();
    
    return 0;
}
