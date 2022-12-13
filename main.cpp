#include <iostream>
#include <iomanip>
#include "Board.h"
#include <windows.h>
#include "Referee.h"
#include "Player1.h"
#include "Player2.h"

using namespace std;

///PREFACE BY SAYING I DID NOT MAKE EXTRA TURN FUNCTIONALITY. EACH PLAYER CAN PLAY UNTIL THEY DECIDE TO PASS


int main()
{
    PlayerNode* FirstPlayer;
    PlayerNode* SecondPlayer;
    Player1 player1;
    Player2 player2;
    int movement;
    Board board;
    string dummy1;
    string dummy2;
    bool flag;
    Referee referee;
    int turn;
    ///call essentially the entire game function
    board.PrintGame(player1, player2, board, movement, dummy1, turn, dummy2, flag, FirstPlayer, SecondPlayer);


}






