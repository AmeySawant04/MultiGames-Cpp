#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

class hangMan
{
public:
    int tries;
    string guesses;
    string hints[21] = {"FOOD", "FRUITS", "SITCOM", "ANIMAL", "SPORTS", "COUNTRIES", "TRANSPORT", "MUSICAL INSTRUMENT", "PROFESSIONS", "BODY", "COLORS", "FLOWERS", "VERBS", "NATURE", "CALENDER", "IN THE CITY", "SCHOOL", "BEACH", "COUNTRIES", "COFFEE", "SITCOM"};
    string words[21] = {"CHEESE", "APPLE", "FRIENDS", "LION", "BASKETBALL", "FRANCE", "PLANE", "PIANO", "LAWYER", "HEART", "ORANGE", "DAISY", "UNDERSTAND", "FOREST", "DECEMBER", "MUSEUM", "PENCIL", "UMBRELLA", "DUBAI", "WOMEN", "HIMYM"};
    int a;
    string hint = "HINT : " + hints[a];
    string word = words[a];
    bool win = false;
    void draw(string message, bool top = true, bool bottom = true)
    {
        if (top)
            cout << "+---------------------------------+\n";
        cout << "|";
        bool where = true;
        for (int i = message.length(); i < 33; i++)
        {
            if (where)
                message = " " + message;
            else
                message = message + " ";

            where = !where;
        }
        cout << message;
        cout << "|\n";
        if (bottom)
            cout << "+---------------------------------+\n";
    }
    void table()
    {
        draw("+-----------+", false, false);
        draw("|           |", false, false);
    }

    void drawHangMan(int Wrong)
    {
        if (Wrong >= 1)
            draw("|", false, false);
        else
            draw("", false, false);

        if (Wrong >= 2)
            draw("|", false, false);
        else
            draw("", false, false);

        if (Wrong >= 3)
            draw("O", false, false);
        else
            draw("", false, false);

        if (Wrong == 4)
            draw("/  ", false, false);

        if (Wrong == 5)
            draw("/| ", false, false);

        if (Wrong >= 6)
            draw("/|\\", false, false);
        else
            draw("", false, false);

        if (Wrong == 7)
            draw("/  ", false, false);

        if (Wrong >= 8)
            draw("/ \\", false, false);
        else
            draw("", false, false);

        table();
    }
    void letters(string input, char from, char to)
    {
        string a;
        for (char i = from; i <= to; i++)
        {
            if (input.find(i) == string::npos)
            {
                a += i;
                a += " ";
            }
            else
            {
                a += "  ";
            }
        }
        draw(a, false, false);
    }
    void letters(string taken)
    {
        draw("AVAILABLE LETTERS");
        letters(taken, 'A', 'M');
        letters(taken, 'N', 'Z');
    }

    bool verify(string word, string guessed)
    {
        string a;
        bool won = true;
        for (int i = 0; i < word.length(); i++)
        {
            if (guessed.find(word.at(i)) == string::npos)
            {
                a += "_ ";
                won = false;
            }
            else
            {
                a += word.at(i);
                a += " ";
            }
        }
        draw("Guess The Word");
        draw(a, false);
        return won;
    }

    int checkTries(string word, string guessed)
    {
        int a = 0;
        for (int i = 0; i < guessed.length(); i++)
        {
            if (word.find(guessed.at(i)) == string::npos)
                a++;
        }
        return a;
    }

    void youWon(string hint, string guesses, string word)
    {
        system("cls");
        draw("HANGMAN");
        draw("", true, false);
        draw("", false, false);
        draw("x  x  x   xxxx  x    x", false, false);
        draw("x  x  x   x  x  x x  x", false, false);
        draw("x  x  x   x  x  x  x x", false, false);
        draw("  x x     xxxx  x    x", false, false);
        draw("", false);
        draw(hint, false, false);
        letters(guesses);
        verify(word, guesses);
    }
    void gameOver(string guesses, string word, int tries)
    {
        system("cls");
        draw("HANGMAN");
        drawHangMan(tries);
        draw("***GameOver***", true, false);
        letters(guesses);
        verify(word, guesses);
    }
    hangMan(int x, int y)
    {
        a = y;
        tries = x;
        do
        {
            system("cls");
            draw("HANGMAN");
            drawHangMan(tries);
            draw(hint, true, false);
            letters(guesses);
            win = verify(word, guesses);
            if (win)
                break;
            char x;
            cout << ">";
            cin >> x;

            if (guesses.find(x) == string::npos)
                guesses += x;

            tries = checkTries(word, guesses);
        } while (tries < 8);

        if (win)
            youWon(hint, guesses, word);
        else
            gameOver(guesses, word, tries);
    }
};

// int main()
// {
//     srand(time(0));
//     hangMan amey(0, (rand() % 20));

//     return 0;
// }
//                 |
//                 |
//                 O
//                /|\
//                / \
             +-----_-----+
// |           |
// +---------------------------------+

//  x  x  x   xxxx  x    x
//  x  x  x   x  x  x x  x
//  x  x  x   x  x  x  x x
//    x x     xxxx  x    x
