#include "Player2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Player2::Player2()
{
    string name = "Player 2";
    int Score = 0;
};

Player2::~Player2()
{
    string name = "";
    int Score = 0;
};

void Player2::DiceRoll(int& movement, string& dummy2)
{
    //Dice[rand()%6];
    srand(time(NULL));
    int Dice[6] = {1, 2, 3, 4, 5, 6};
    movement = Dice[rand()%6];
    cout << "Roll: " << movement << endl;
};






