#include "Board.h"
#include "Player1.h"
#include "Player2.h"
#include "Referee.h"
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <windows.h>
#include "Board.h"
using namespace std;

void Board::PrintGame(Player1& player1, Player2& player2, Board& board, int& movement, string& dummy1, int& turn, string& dummy2, bool& flag, PlayerNode* FirstPlayer, PlayerNode* SecondPlayer)
{
    Referee referee;
    ///nodes for player cycling
    FirstPlayer = new PlayerNode();
    SecondPlayer = new PlayerNode();

    FirstPlayer->name = "Player1";
    FirstPlayer->score = 0;
    FirstPlayer->next = SecondPlayer;

    SecondPlayer->name = "Player2";
    SecondPlayer->score = 0;
    SecondPlayer->next = FirstPlayer;

    ///nodes for board
    Node * circle[10];
    Node * vertical[8];
    circle[0] = new Node();
    circle[1] = new Node();
    circle[2]  = new Node();
    circle[3]  = new Node();
    circle[4]  = new Node();
    circle[5]  = new Node();
    circle[6]  = new Node();
    circle[7]  = new Node();
    circle[8]  = new Node();
    circle[9]  = new Node();
    vertical[0]  = new Node();
    vertical[1]  = new Node();
    vertical[2]  = new Node();
    vertical[3]  = new Node();
    vertical[4]  = new Node();
    vertical[5]  = new Node();
    vertical[6]  = new Node();
    vertical[7] = new Node();

    ///semi circularly linked list for movement around board
    circle[0]->data = "C";
    circle[0]->next = circle[1];
    circle[0]->prev = vertical[0];

    circle[1]->data = "B";
    circle[1]->next = circle[2];
    circle[1]->prev = vertical[0];

    circle[2]->data = "A";
    circle[2]->next = circle[3];

    circle[3]->data = "1";
    circle[3]->next = circle[4];

    circle[4]->data = "2";
    circle[4]->next = circle[5];
    circle[4]->prev = vertical[4];

    circle[5]->data = "3";
    circle[5]->next = circle[6];
    circle[5]->prev = vertical[4];

    circle[6]->data = "4";
    circle[6]->next = circle[7];
    circle[6]->prev = vertical[4];

    circle[7]->data = "5";
    circle[7]->next = circle[8];

    circle[8]->data = "E";
    circle[8]->next = circle[9];

    circle[9]->data = "D";
    circle[9]->next = circle[0];
    circle[9]->prev = vertical[0];

    vertical[0]->data = "";
    vertical[0]->next = vertical[1];
    vertical[0]->prev = circle[1];

    vertical[1]->data = "";
    vertical[1]->next = vertical[2];
    vertical[1]->prev = circle[1];

    vertical[2]->data = "";
    vertical[2]->next = vertical[3];
    vertical[2]->prev = circle[1];

    vertical[3]->data = "";
    vertical[3]->next = NULL;
    vertical[3]->prev = circle[1];

    vertical[4]->data = "";
    vertical[4]->next = vertical[5];
    vertical[4]->prev = circle[6];

    vertical[5]->data = "";
    vertical[5]->next = vertical[6] ;
    vertical[5]->prev = circle[6];

    vertical[6] ->data = "";
    vertical[6] ->next = vertical[7];
    vertical[6] ->prev = circle[6];

    vertical[7]->data = "";
    vertical[7]->next = NULL;
    vertical[7]->prev = circle[6];


    ///temp nodes to make comparisons with
    Node* temp;
    PlayerNode* temp2;

    temp2 = FirstPlayer;

    ///loop will run until one player reaches a score of 5
        while((FirstPlayer->score < 5) && (SecondPlayer->score < 5))
        {
 label5:       system("CLS");
        ///map the game board

                              cout   << "\t----"  << endl
                                      << "\t|" << vertical[3]->data <<  " |" << endl
                                     << "\t----"  << endl
                                        << "\t|" << vertical[2]->data <<  " |" << endl
                                     << "\t----"  << endl
                                        << "\t|" << vertical[1]->data <<  " |" << endl
                                     << "\t----"  << endl
                                        << "\t|" << vertical[0]->data <<  " |" << endl
                                             <<  "      --------" << endl
        << "      |" << circle[1]->data << "|" <<      circle[0]->data << "|" << circle[9]->data << "|" << endl
                                        << setw(16)<<"------------" << endl
       << "   |" << circle[2]->data <<             "|        |" <<                      circle[8]->data << "|" << endl
                                        << setw(16)<<"------------" << endl
       << "   |" << circle[3]->data <<             "|        |" <<                      circle[7]->data << "|" << endl
                                        << setw(16)<<"------------" << endl
        << "      |" << circle[4]->data << "|" <<       circle[5]->data << "|" << circle[6]->data << "|" << endl
                                            <<  "      --------" << endl
                                        << "\t|" << vertical[4]->data <<  " |" << endl
                                         << "\t----"  << endl
                                        << "\t|" << vertical[5]->data <<  " |" << endl
                                         << "\t----"  << endl
                                        << "\t|" << vertical[6]->data <<  " |" << endl
                                         << "\t----"  << endl
                                        << "\t|" << vertical[7]->data <<  " |" << endl
             << "\t----"  << endl;

        ///first player turn
             if (temp2 == FirstPlayer)
           {
        ///output basic information about game
             cout << FirstPlayer->name << "'s turn!" << endl;
            cout << "Player 1 Score: " << FirstPlayer->score << endl;
            cout << "Player 2 Score: " << SecondPlayer->score << endl;
        ///dice roll function
             player1.DiceRoll(movement, dummy1);
        ///label used mainly for invalid movement
            label:cout << "Select Piece: ";
        ///player enters letter
            cin >> dummy1;
        ///function doesn't actually do much of anything, I added the logic for turn passing here instead.
             referee.TurnPassFunctionality(dummy1, dummy2, turn, FirstPlayer);
             if ((dummy1 == "P"))
             {
                 temp2 = FirstPlayer->next;
                 goto label5;
             }

        ///function determines if it is player1's piece (ABCDE)
            referee.DeterminePlayerPiece(dummy1, dummy2, flag);
            if (flag == false)
               {
        ///goes back to cin for dummy1
                goto label;
               }




        ///function determines if it is a playable piece or P. (ABDCE12345)
            referee.DeterminePlayable(dummy1, dummy2, flag);
             if (flag == false)
                goto label;


        ///loop. if dummy1 is equal to anywhere in the circle, temp gets assigned the data stored in circle[i]
        /// int x is then equal to i for later use.
            int x;
            for (int i = 0; i < 10; i++)
            {
                if(dummy1 == circle[i]->data)
                {

                    temp = circle[i];
                    x = i;
                }
            }
        ///same as above but for in the vertical portions of board and y
            int y;
            for (int i = 0; i < 8; i++)
            {
                if(dummy1 == vertical[i]->data)
                {

                    temp = vertical[i];
                    y = i;
                }
            }

        ///movement around the board
           for(int i = 0; i < movement; i++)
           {

            ///movement for being one square away from the sacred line.
             if ((temp == circle[4]) && (movement == 1))
            {
                temp = temp->prev;
                goto label80;
            }





            ///since you have to land on the base line to enter the sacred line, movement from the baseline's logic is here
            if (i == 0)
            {
                if (temp == circle[9])
                    {
                    temp = temp->next;
                    continue;

                    }
                if (temp == circle[0])
                {
                    temp = temp->next;
                    continue;

                }
                if (temp == circle[1])
                {
                    temp = temp->next;
                    continue;

                }
               if (temp == circle[4])
                {
                    temp = temp->next;
                    continue;

                }
                if (temp == circle[5])
                {
                    temp = temp->next;
                    continue;

                }
               if (temp == circle[6])
                {
                    temp = temp->next;
                    continue;

                }

            }



            ///if moving from the sacred line, it must be on first turn to do so. lose a point when moving piece out of line
               if (i == 0)
               {
               for(int j = 0; j < 8; j++)
               {
                   if ((temp == vertical[j]))
                        {
                            temp = temp->prev;

                            if(FirstPlayer->score > 0)
                            {
                            FirstPlayer->score--;
                            }

                        }
               }
               }
               temp = temp->next;
                ///if land on base of sacred line, piece gets pushed into first empty space in sacred line
               if ((i == (movement - 1)) && (temp == circle[0]))
               {

                if((temp == circle[0]) && ((temp->prev->data.length() == 0) || (temp->prev->next->data.length() == 0) || (temp->prev->next->next->data.length() == 0) || (temp->prev->next->next->next->data.length() == 0)))
               {
                   temp = temp->prev;

        label80:  if (temp->data.length() == 0)
                    break;
                   else if(temp->next->data.length() == 0)
                   {
                       temp = temp->next;
                       break;
                   }
                   else if(temp->next->next->data.length() == 0)
                   {
                       temp = temp->next->next;
                       break;
                   }
                   else if(temp->next->next->next->data.length() == 0)
                   {
                       temp = temp->next->next->next;
                       break;
                   }

               }

               }



            ///same as above but for top of bottom vert area
            if (i == (movement - 1) && (temp == circle[5]))
              {
                if((temp == circle[5]) && ((temp->prev->data.length() == 0) || (temp->prev->next->data.length() == 0) || (temp->prev->next->next->data.length() == 0) || (temp->prev->next->next->next->data.length() == 0)))
               {
                   temp = temp->prev;

                   if (temp->data.length() == 0)
                    break;
                   else if(temp->next->data.length() == 0)
                   {
                       temp = temp->next;
                       break;
                   }
                   else if(temp->next->next->data.length() == 0)
                   {
                       temp = temp->next->next;
                       break;
                   }
                   else if(temp->next->next->next->data.length() == 0)
                   {
                       temp = temp->next->next->next;
                       break;
                   }

               }


               ///temp = temp->next;
             }


           }

            ///score increases for player1 if their piece is located on sacred line
            if (player1.IsItMyTurn(turn) == true)
                {
                    for(int i = 5; i < 6; i++)
                    {
                        if(temp == circle[i])
                    {
                        FirstPlayer->score++;
                    }
                    }

                }
            ///score increases for player1 if their piece is located on vertical lower line
            if (player1.IsItMyTurn(turn) == true)

                    for(int i = 4; i < 8; i++)
                    {
                        if(temp == vertical[i])
                    {
                        FirstPlayer->score++;
                    }
                    }

        ///If temp has a character length of more than 0, the space is full and it will tell the user that. if the space is not full, it's location will equal
        /// whatever piece was chosen initially.

    for (int i = 0; i < 10; i++)
        {
            if ((x == i))
        {
            if (temp->data.length() == 1)
                {
                  cout << "Space Full." << endl;
                 goto label;


                }

                else
                {
                   temp->data = circle[i]->data;
                  circle[i]->data = "";

               }
        }
        }

        ///If temp has a character length of more than 0, the space is full and it will tell the user that. if the space is not full, it's location will equal
        /// whatever piece was chosen initially.
     for (int i = 0; i < 8; i++)
    {
            if ((y == i))
        {
            if (temp->data.length() == 1)
                {
                  cout << "Space Full." << endl;
                 goto label;


                }

                else
                {
                   temp->data = vertical[i]->data;
                  vertical[i]->data = "";

               }
        }
        }



}
    ///player2 comes into play if the turn gets passed. everything is identical with the exception being the areas where
    ///score is determined
        if (temp2 == SecondPlayer)
           {
             cout << SecondPlayer->name << "'s turn!" << endl;
            cout << "Player 1 Score: " << FirstPlayer->score << endl;
            cout << "Player 2 Score: " << SecondPlayer->score << endl;

             player2.DiceRoll(movement, dummy1);
            label3:cout << "Select Piece: ";
             cin >> dummy2;


             referee.TurnPassFunctionality2(dummy1, dummy2, turn, SecondPlayer);
             if ((dummy2 == "P"))
             {
                 temp2 = SecondPlayer->next;
                 goto label5;
             }





            referee.DeterminePlayerPiece2(dummy1, dummy2, flag);
            if (flag == false)
               {
                goto label3;
               }





            referee.DeterminePlayable(dummy1, dummy2, flag);
             if (flag == false)
                goto label3;



            int x;
            for (int i = 0; i < 10; i++)
            {
                if(dummy2 == circle[i]->data)
                {

                    temp = circle[i];
                    x = i;
                }
            }
            int y;
            for (int i = 0; i < 8; i++)
            {
                if(dummy2 == vertical[i]->data)
                {

                    temp = vertical[i];
                    y = i;
                }
            }

            for(int i = 0; i < movement; i++)
           {
        ///if the letter entered earlier is found on vert part of board, and on first move, piece will move back to sacred line
        ///and a point is deducted. This logic is wrong.


        if ((temp == circle[9]) && (movement == 1))
            {
                temp = temp->prev;
                goto label90;
            }


            if (i == 0)
            {
                if (temp == circle[9])
                    {
                    temp = temp->next;
                    continue;
                    }
                if (temp == circle[0])
                {
                    temp = temp->next;
                    continue;
                }
                if (temp == circle[1])
                {
                    temp = temp->next;
                    continue;
                }
               if (temp == circle[4])
                {
                    temp = temp->next;
                    continue;
                }
                if (temp == circle[5])
                {
                    temp = temp->next;
                   continue;
                }
               if (temp == circle[6])
                {
                    temp = temp->next;
                    continue;
                }

            }



               if (i == 0)
               {
               for(int j = 0; j < 8; j++)
               {
                   if ((temp == vertical[j]))
                        {
                            temp = temp->prev;

                            if(SecondPlayer->score > 0)
                            {
                            SecondPlayer->score--;
                            }

                        }
               }
               }
               temp = temp->next;

               if ((i == (movement - 1)) && (temp == circle[0]))
               {
                ///circle[9] is D's starting location. if something moves there, its next move will take it to lower vert portion
                if((temp == circle[0]) && ((temp->prev->data.length() == 0) || (temp->prev->next->data.length() == 0) || (temp->prev->next->next->data.length() == 0) || (temp->prev->next->next->next->data.length() == 0)))
               {
                   temp = temp->prev;

        label90:   if (temp->data.length() == 0)
                    break;
                   else if(temp->next->data.length() == 0)
                   {
                       temp = temp->next;
                       break;
                   }
                   else if(temp->next->next->data.length() == 0)
                   {
                       temp = temp->next->next;
                       break;
                   }
                   else if(temp->next->next->next->data.length() == 0)
                   {
                       temp = temp->next->next->next;
                       break;
                   }

               }
               }

                ///circle[4] is 2's starting location. if something moves there, its next move will take it to the upper vert portion


            if (i == (movement - 1) && (temp == circle[5]))
              {
                if((temp == circle[5]) && ((temp->prev->data.length() == 0) || (temp->prev->next->data.length() == 0) || (temp->prev->next->next->data.length() == 0) || (temp->prev->next->next->next->data.length() == 0)))
               {
                   temp = temp->prev;

                   if (temp->data.length() == 0)
                    break;
                   else if(temp->next->data.length() == 0)
                   {
                       temp = temp->next;
                       break;
                   }
                   else if(temp->next->next->data.length() == 0)
                   {
                       temp = temp->next->next;
                       break;
                   }
                   else if(temp->next->next->next->data.length() == 0)
                   {
                       temp = temp->next->next->next;
                       break;
                   }

               }


               temp = temp->next;
             }


           }








    ///old movement
    #if 0
           for(int i = 0; i < movement; i++)
           {

               for(int j = 0; j < 8; j++)
               {
                   if ((temp == vertical[j]) && (i == 0))
                        {
                            temp = temp->prev;

                            if(SecondPlayer->score > 0)
                            {
                            SecondPlayer->score--;
                            }
                            goto label4;
                        }
               }



               if (temp->next == NULL)
                {
                    cout << "You can't move that far." << endl;
                    goto label3;
                }

                if(temp == circle[9])
               {
                   temp = temp->prev;
                    goto label4;
               }


               if(temp == circle[4])
               {
                   temp = temp->prev;
                    goto label4;
               }

                else if (temp->next != NULL)
                {
                    temp = temp->next;
                }

                label4:;
               }

         #endif


            if (player1.IsItMyTurn(turn) == true)
                {
                    for(int i = 0; i < 1; i++)
                    {
                        if(temp == circle[i])
                    {
                        SecondPlayer->score++;
                    }
                    }

                }



            if (player1.IsItMyTurn(turn) == true)

                    for(int i = 0; i < 4; i++)
                    {
                        if(temp == vertical[i])
                    {
                        SecondPlayer->score++;
                    }
                    }





    for (int i = 0; i < 10; i++)
        {
            if ((x == i))
        {
            if (temp->data.length() == 1)
                {
                  cout << "Space Full." << endl;
                 goto label3;


                }

                else
                {
                   temp->data = circle[i]->data;
                  circle[i]->data = "";

               }

        }
        }
        ///this shouldnt break functionality but for some reason it does... not sure why. not sure if needed either at this point.
    #if 0
        for (int i = 0; i < 8; i++)
    {
            if ((y == i))
        {
            if (temp->data.length() == 1)
                {
                  cout << "Space Full." << endl;
                 goto label;


                }

                else
                {
                   temp->data = vertical[i]->data;
                  vertical[i]->data = "";

               }
        }
        }
        #endif





}
///if either player's score equals 5, that player wins
if (FirstPlayer->score == 5)
        {
            cout << "Player 1 Wins!";

        }
        else if (SecondPlayer->score == 5)
        {
            cout << "Player 2 Wins!";

        }
    }










































};
