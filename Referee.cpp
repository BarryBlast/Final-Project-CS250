#include "Player1.h"
#include "Referee.h"
#include "Player2.h"
#include "Board.h"
#include <iostream>
#include <string>

using namespace std;


///this is funny and worthless
bool Referee::TurnPassFunctionality(string& dummy1, string& dummy2, int& turn, PlayerNode* FirstPlayer)
     {
        if ((dummy1 == "P"))
            {
            cout << "Turn Passed to Player2" << endl;
            }
     };

bool Referee::TurnPassFunctionality2(string& dummy1, string& dummy2, int& turn, PlayerNode* SecondPlayer)
     {
        if ((dummy2 == "P"))
            {
                cout << "Turn Passed to Player1" << endl;
            }
     };



///determines if piece chosen is allowed or not for p1
void Referee::DeterminePlayable(string& dummy1, string& dummy2, bool& flag)
          {
            if ((dummy1 != "1") && (dummy1 != "2") && (dummy1 != "3") && (dummy1 != "4") && (dummy1 != "5") && (dummy1 != "A") && (dummy1 != "B") && (dummy1 != "C") && (dummy1 != "D") && (dummy1 != "E") && (dummy1 != "P"))
                {
                    cout << "Invalid Selection: Not a Playable Piece" << endl;
                    flag = false;
                }
                else flag = true;
          };
///same as above but for p2
void Referee::DeterminePlayable2(string& dummy1, string& dummy2, bool& flag)
        {
             if ((dummy2 != "1") && (dummy2 != "2") && (dummy2 != "3") && (dummy2 != "4") && (dummy2 != "5") && (dummy2 != "A") && (dummy2 != "B") && (dummy2 != "C") && (dummy2 != "D") && (dummy2 != "E") && (dummy2 != "P"))
                {
                    cout << "Invalid Selection: Not a Playable Piece" << endl;
                   flag = false;
                }
            else flag = true;

          };
///determines if piece selected is player1's
void Referee::DeterminePlayerPiece(string& dummy1, string& dummy2, bool& flag)
{
            if (dummy1 == "1" || dummy1 == "2" || dummy1 == "3" || dummy1 == "4" || dummy1 == "5")
            {
                cout << "Invalid Selection: Not Your Piece." << endl;
                flag = false;
            }
            else flag = true;
}
///determines if piece selected is player2's
void Referee::DeterminePlayerPiece2(string& dummy1, string& dummy2, bool& flag)
{
            if (dummy2 == "A" || dummy2 == "B" || dummy2 == "C" || dummy2 == "D" || dummy2 == "E")
            {
                cout << "Invalid Selection: Not Your Piece." << endl;
                flag = false;
            }
            else flag = true;
};















