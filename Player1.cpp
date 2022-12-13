#include "Player1.h"
#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


///I don't think I need this but whenever I delete it something breaks somehow. same as for player2
Player1::Player1()
{
        string name = "Player 1";
};

Player1::~Player1()
{
    string name = "";

};

///dice rool function
void Player1::DiceRoll(int& movement, string& dummy1)
{
    ///Dice[rand()%6];
    srand(time(NULL));
    int Dice[6] = {1, 2, 3, 4, 5, 6};
    movement = Dice[rand()%6];
    cout << "Roll: " << movement << endl;
};


///honestly not even sure how necessary this is at this point
bool Player1::IsItMyTurn(int& turn)
{
    turn = 2;
    if (turn % 2 == 0)
    return true;
    else if (turn % 2 != 0)
    return false;
};

