#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Player1.h"
#include "Player2.h"
#include <iostream>

using namespace std;
///playernode adt
class PlayerNode {
public:
    string name;
    int score = 0;
    PlayerNode * next;

};


///board adt
class Board{
public:
    void PrintGame(Player1& player1, Player2& player2, Board& board, int& movement, string& dummy1, int& turn, string& dummy2, bool& flag, PlayerNode* FirstPlayer, PlayerNode* SecondPlayer); ///cls clear to keep updated.


};
///nodes for the board
class Node {
    public:
        string data;
    Node * next;
    Node * prev;


};






#endif // BOARD_H_INCLUDED
