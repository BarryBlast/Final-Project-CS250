#ifndef PLAYER1_H_INCLUDED
#define PLAYER1_H_INCLUDED
#include <string>


using namespace std;

///player1 adt. isitmyturn function made to work for both player1 and 2.
class Player1{

public:
        Player1();
        ~Player1();
        void DiceRoll(int& movement, string& dummy);
        bool IsItMyTurn(int& turn);

};













#endif // PLAYER1_H_INCLUDED
