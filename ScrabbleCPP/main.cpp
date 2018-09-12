//David Davis Program 1 and 2 Scrabble Game
//CS202 978105326
//Main function of program

//Includes neccessary header file 
#include "scrabble.h"

//Using standard namespace
using namespace std;

//Begin main function
int main()
{ //Use integer variable to hold instruction response
  int begin = 2;
  //Make instance of game class
  game scrabble;
//Make instance of hand for computer and human player
  human_hand human_player;
  comp_hand comp_player;
//Make new node pointer to build DLL board
  node * board;

  //Make instance for tiles
  tiles pieces;
  //Make instance for players score
  players trip;
  do
  {//Use welcome and instruction functions to begin program
    cout << "\n\n";
    scrabble.welcome();
  
    begin = scrabble.instructions();
//Continue asking until user is ready
  }while(begin == 0);

//Use build board function to make DLL of DLL's
  board->build_board(board);
//Set middle space to begin game
  board->set_space(board, '#', 8, 8); 
//Begin by using draw_7 function to make starting hands for computer and human
  human_player.draw_7(pieces); 
  cout << "\n\tAfter the initial draw,";
  scrabble.show_human_hand();
  human_player.show_hand();
//Computer use of draw_7
  comp_player.draw_7(pieces);
//Computer goes first   
  cout << "\n\tThe computer will play: ";
//Function to find word from dictionary and play on board
  comp_player.find_word(board,comp_player);
//Display board after computer's turn
  board->display_board(board);
//Show player their hand
  scrabble.show_human_hand();
  human_player.show_hand();

  //Users turn and are given a choice to play, trade, or skip their turn
  scrabble.choice_of_play(board, trip, human_player);
  //Fill players hand if needed
  human_player.fill_hand(pieces);
  //Display board
  board->display_board(board);
  //Show hand
  scrabble.show_human_hand();
  human_player.show_hand();
  //Display score
  cout << "\n\tYour current score is: "
       << trip.return_score() << endl;



 return 0;
}
