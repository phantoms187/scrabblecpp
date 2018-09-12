//David Davis CS202 Program 1 and 2
//978105326
/*This is the header file for the Scrabble game program. Below are the class definitions for each part of the game.
*/

//Included libraries for entire program
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<fstream>

//Constants used in this program
const int TILES = 99;
const int BOARD_WIDTH = 15;
const int BOARD_HEIGHT = 15;

//Begin tiles class to handle each actual tile game piece
#ifndef TILES 
#define TILES
class tiles
{
  public:
  tiles();//Constructor
  ~tiles();//Destructor
  char pick_tile();//Pick a random tile from array
  int tile_value(const char &tile);//returns the tile value based on it's character value

  protected:
  void allocate_tiles();//Allocation of all 98 tiles from which to pick from and is protected to keep it from being altered

  private:
  char tile;//Character value of a tile
  int value;//Point value for tile
  char * total_tiles; //Pointer to array of total tiles
};
#endif


//Begin hand class to handle a player's 7 tiles in a hand
#ifndef HAND
#define HAND
class hand
{
  public:
  hand();//Constructor
  ~hand();//Destructor
  void draw_7( tiles &pieces);//Draw seven tiles to start the game
  void show_hand();//Display current tiles in hand
  int remove_tile(char to_remove);//Remove a tile from a hand
  int fill_hand(tiles &pieces);//Fill hand to total of seven tiles for trading in tiles
  bool check_tile(char to_check);

  char * current_hand;//Pointer to current hand 

};
#endif

//Begin human_hand class. Derived from hand class to handle human hand specifics
#ifndef HUMAN_HAND
#define HUMAN_HAND
class human_hand: public hand
{
  public:
//  human_hand();//Constructor
//  ~human_hand();//Destructor
 
};
#endif
  
//Begin computer hand class. Derived from hand class to handle computer hand specifics
#ifndef COMP_HAND
#define COMP_HAND
class comp_hand: public hand
{
  public:
  comp_hand();//Constructor
 // comp_hand(const comp_hand &to_copy); 
  int vowel_check();//Check if computer hand has more than three vowels
  int find_word(class node *& board, hand &players_hand);
};
#endif

//Begin player class to handle points and game specifics for each player
#ifndef PLAYER
#define PLAYER 
class players
{
  public:
  players();//Constructor
//  ~player();//Destructor
  int calc_score( char  word[]);
  int letter_value(char tile);
  int add_to_total( char  word[]);
  int return_score();

  private:
  //hand players_hand;//Hand for each player
  int score;

};
#endif

//Begin node class to build board with a doubly-linked list of doubly-linked lists
#ifndef NODE
#define NODE
class node
{
  public: 
  node();//Constructor
  ~node();//Destructor
  int display_board(node * &board);//Displays whole board with row and column indices
  int set_space(node *&board, char space,int x, int y);//Set a certain node on the board to play a tile
  void DLL(node *&board);//Build single doubly-linked list
  void build_board(node *&board);//Build whole board with each node of a doubly-linked list being a doubly-linked list
 
  private:
  node * head;//Head pointer to begin a doubly-linked list from a node 
  node * next;//Next pointer to next node
  node * previous;//Previous pointer to prior node
  char char_data;//Character value to change when tile is played
  int special_data;//Special square information for double word bonus
};
#endif

//Base game class to hold random unneccessary but awesome and interesting functions
#ifndef GAME
#define GAME
class game
{
  public:
  game();
  void stars();//Prints line of stars
  void welcome();//Welcome message
  int instructions();//Opening instructions
  void show_human_hand();//Title for showing user's hand
  void play_word(node * &board, players &player, hand &players_hand);
  int choice_of_play(node *&board, players &player, hand &players_hand);
  int find_word();
};
#endif

class trial
{
  public:
  int find_word();
};
