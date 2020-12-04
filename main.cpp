// Simple game of chips. The game is currently incomplete but playable. 
// Will push completed update shortly
//
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;

int main()
{
  bool player1Turn =  true;
  bool gameOver = false;

  int chipsInPile = 0;
  int chipsTaken = 0;
  //int maxPerTurn = 0;
  string playerNames [2];

// Seed random number generator
  srand(time(0));

  // Ask players for names and store in array
  cout << "Player 1, please enter your name: \n";
  cin >> playerNames[0];
  cout << "\nThanks and good luck!" << endl << "Player 2, please enter your name: ";
  cin >> playerNames[1];
  cout <<  "\nThanks and good luck! \n";
  
  // Start the game with a random number of chips in the pile
  chipsInPile = (rand() % MAX_CHIPS) +1;
  cout << "This round will start with " << chipsInPile << " chips in the pile \n";

while (gameOver == false)
{
  do
  {
  if (player1Turn)
  {
    cout << playerNames[0] << " How many chips would you like?\n";
  }
  else 
  {
    cout << playerNames[1] << " How many chips would you like?\n";
  }
   cout << " You can take up to " <<static_cast<int>(MAX_TURN * chipsInPile) << endl;
 // cout << "Number taken: " << chipsTaken << endl;
  cin >> chipsTaken;  
  } while (chipsTaken > (static_cast<int>(MAX_TURN * chipsInPile) ) &&(chipsInPile > 1));

  chipsInPile = chipsInPile - chipsTaken;

  cout << "There are " << chipsInPile << " left in the pile\n";
  if (chipsInPile == 0)
  {
    gameOver = true;
  }
  else 
  {
    player1Turn = ! player1Turn;
  }
  
  }

  return 0; 
}