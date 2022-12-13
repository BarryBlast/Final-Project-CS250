#ifndef REFEREE_H_INCLUDED
#define REFEREE_H_INCLUDED
#include "Player1.h"
#include "Board.h"
#include <string>

using namespace std;




///referee functions
class Referee{

public:

        bool TurnPassFunctionality(string& dummy1, string& dummy2, int& turn, PlayerNode* FirstPlayer);
        bool TurnPassFunctionality2(string& dummy1, string& dummy2, int& turn, PlayerNode* SecondPlayer);
        void DeterminePlayable(string& dummy1, string& dummy2, bool& flag);
        void DeterminePlayable2(string& dummy1, string& dummy2, bool& flag);
        void DeterminePlayerPiece(string& dummy1, string& dummy2, bool& flag);
        void DeterminePlayerPiece2(string& dummy1, string& dummy2, bool& flag);
        void DetermineLocationFull(string& dummy1, string& dummy2, Board& board, int& movement);
};

#endif // REFEREE_H_INCLUDED
