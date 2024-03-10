/* Program: Number scrabble is played with the list of numbers between 1 and 9. Each player takes
            turns picking a number from the list. Once a number has been picked, it cannot be picked
            again. If a player has picked three numbers that add up to 15, that player wins the game.
            However, if all the numbers are used and no player gets exactly 15, the game is a draw. */
// Author: Ammar Ali Ghazi Afifi (no section yet) (20230246)
// Version: 3.0
// Date: 1/3/2024


#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


bool check_winer(int s, int list2[5]) {
    int n = s + 1;
    if (n < 3) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (list2[i] + list2[j] + list2[k] == 15) {
                    return true;
                }
            }
        }
    }
    return false;
}


bool check_empty(int list2[9]) {
  for(int i = 0; i < 9; i++)
  {
    if (list2[i] != 0)
    {
      return false;
    }
  }
  return true;
}


void out_list(int l[9]) {
  cout << "The current list is {";  // print list
    for(int i = 0; i < 9; i++)
    {
      cout << l[i];
      if (i < 8)
        cout << ",";
    }
    cout << "}\n";
}


int main()
{
  // list of the numbers, player1 and player2
  int list1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int player1[5];
  int player2[5];

  // declare the game
  cout << "# This game starts with list of numbers from 1 to 9,\n";
  cout << "# Two players play this game, every player should choose a number from the list,\n";
  cout << "# the player who have 3 numbers that their sum is 15 wins.\n\n";

  int turn = 0;
  //loop of the game
  while(true)
  {
    int choose = 0;

    // player1 turn
    out_list(list1);  // print list1
    while (true)  // check user input
    {
      cout << "player1 => choose number: ";
      if (cin >> choose && find(begin(list1), end(list1), choose) != end(list1) && choose != 0)
      { 
        break;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "# choose valid number,\n";
        continue;
      }
    }
    for(int i = 0; i < 9; i++)  // set choosen number = 0
    {
      if(list1[i] == choose)
      {
        list1[i] = 0;
        break;
      }
    }
    player1[turn] = choose;  // add choose to player list
    if (check_winer(turn, player1))  // check if player wins
    {
      cout << "player1 wins.";
      break;
    }

    // check if draw
    if (check_empty(list1)) {
          cout << "It's a draw.";
          break;
        }

    // player2 turn
    out_list(list1);  // print list1
    while (true)  // check user input
    {
      cout << "player2 => choose number: ";
      if (cin >> choose && find(begin(list1), end(list1), choose) != end(list1) && choose != 0)
      {
        break;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "# choose valid number,\n";
        continue;
      }
    }
    for(int i = 0; i < 9; i++)  // set choosen number = 0
    {
      if(list1[i] == choose)
      {
        list1[i] = 0;
        break;
      }
    }
    player2[turn] = choose;  // add choose to player list
    if (check_winer(turn, player2))  // check if player wins
    {
      cout << "player2 wins.";
      break;
    }
        
    turn++;
  }
  return 0;
}