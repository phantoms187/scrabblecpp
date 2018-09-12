//David Davis Program 1 and 2 Scrabble Game
//CS202 978105326
//This board.cpp file holds the function definitions for the node and game classes

//Include scrabble.h file 
#include "scrabble.h"

//Use of standard namespace
using namespace std;

//Node constructor to set data members to default values
node::node()
{
  head = NULL;//Set head, next, and previous pointers to NULL
  next = NULL;
  previous = NULL;
  char_data = '-';//Set unassigned spaces to - to show empty location
  special_data = 1;//Set point multiplier for special bonus locations 
}

//Node destructor to delete node's dynamic memory
node::~node()
{
  if(head)//Check if head exists
    delete head;//If so, delete it
  if(next)//Check if next exists
    delete next;//If so, delete it
  if(previous)//Check if previous exists
    delete previous;//If so, delete it
}

//Node function to build single doubly-linked list
//Takes a node pointer for the DLL head pointer
void node::DLL(node *&board)
{//Allocate new node
  node * temp = new node;
//Check if board is NULL
  if(!board)
  {//If board is NULL set to new node
    board = temp;
  }
  else 
  {//Otherwise add at the beginning by setting the new node's next pointer to board and board's previous to the new node. The board pointer is then set to the new node.
    board->previous = temp;
    temp->next = board;
    board = temp;
  }
} 

//Build board to the desired size. A standard size will be 15 x 15 tile locations
void node::build_board(node *&board)
{//A for loop will build initial DLL 
  for(int i = 0; i < BOARD_HEIGHT ; ++i)
  {
    board->DLL(board);
    //As each node is created, it's head pointer will use the DLL function to build another DLL
    for(int i = 0; i < BOARD_WIDTH; ++i)
    {
      board->head->DLL(board->head);
    }
  }
}

//Display function to show current game board
int node::display_board( node * &board)
{ //Integer to display indices
  int j = 1;
  //Pointer to traverse board list
  if(!board)
	return 0;

  node * current = board;
  node * current_head = NULL;
  //Check if current exists, function returns 0 if nothing to display
  if(!current)
    return 0;
  //Use loop to display row indices
  cout << "\n\t  ";
  for(int i = 1; i <= BOARD_WIDTH; ++i)
    cout << setw(2) << i << " "; 
  while(current)
  {//Traverse through main DLL and display column indices
    cout << "\n\t" << setw(2) << j << " "
         << current->char_data; //<< " " << current->head->char_data;
  current_head = current->head;
    while(current_head->next)
    {//Traverse through each DLL and display each character data member
      cout  // << setw(2) << right 
             << "  "
             << current_head->char_data;
      current_head = current_head->next;
    }//Increment j for next index
    ++j;
    //Progress to next node
    current = current->next;
  }//Add blank room and end of display and return 1 to show success
  cout << endl << endl;
  return 1;
}

//Function to set desired space on board when playing tiles
int node::set_space(node *&board, char space, int x, int y)
{//Check if board exists first and return 0 if nothing to access
  if(!board)
    return 0;
//Pointer to traverse through board
  node * height = board;
//Loop till correct row is located
  for(int i = 0; i < y-1 ; ++i)
     height = height->next;
//Set pointer to that node of main DLL

  node * current = height->head;

//Traverse from head pointer of that node to desired node to set played tile 
  for(int j = 0; j < x-2; ++j)
    current = current->next;
//Set node character of desired node
  current->char_data = space;
//Return 1 if successful
  return 1; 
}

//Game class constructor
game::game()
{

}

//Function to print stars for formatting
void game::stars()
{
  for(int i = 0; i < 70; ++i)
    cout << "*";
  cout << endl;
} 

//Welcome note to begin game
void game::welcome()
{
  stars();
  cout << setw(50)<< right << "Welcome to a Game of Scrabble!\n";
  stars();
}

//Basic game instructions and choice to begin game
int game::instructions()
{//Character to hold choice when prompted
  char * choice ;
  //Instructions for game
  cout <<  "\n\tThis will be a game against the computer.";  
  cout << "\n\tYou will each have the standard 7 tiles. On your turn, \n\tyou may play a word, trade in tiles, or skip." << endl;
//Ask to begin game
  cout << "\n\tAre you ready to play?: ";
  cin.get(choice, 100, '\n');
  cin.ignore(100, '\n');
  char begin = toupper(choice[0]);
 //If ready, returns 1, 0 if not
  if(begin == 'Y')
    return 1;
  else
    return 0;
}

//Function to display wording for when displaying the human player's hand
void game::show_human_hand()
{
  cout << "\n\tYour tiles are: ";
}
//Function to play a word on the game board for human player
void game::play_word(node * &board, players &player, hand &players_hand)
{//Variables for the word and location
  char word[16];
  int x = 0;
  int y = 0;
  int x2 = 0;
  int y2 = 0;
  int end = 0;
  int length = 0;
 //Loop to determine if word to play is valid based on tiles in hand
  do{
  //Set end flag
  end = 0;
  //Get word from user
  cout << "\n\tWhat word will you like to play?: ";
  cin.get(word, 100, '\n');
  cin.ignore(100, '\n');
  //Capitalize all letters in word
  length = strlen(word);
  for(int i = 0; i < length; ++i)
    word[i] = toupper(word[i]);
  //Check each letter in word to tiles in players hand
  for(int i = 0; i < length; ++i)
  {//Using hand check function
    if(!players_hand.check_tile(word[i]))
    {//If tile not in hand error message
      cout << "\n\tThat is not a valid word";
  //Break loop and start from begginng
      i = length;
      end = 111;
    }
  }
 }while(end == 111);
//Get location for word to be played
  cout << "\n\tWhich space will the first letter take?: ";
  cout << "\n\tX: ";
  cin >> x;
  cin.ignore(100, '\n');
  cout << "\tY: ";
  cin >> y;
  cin.ignore(100, '\n');

  cout << "\n\tWhich space will the last letter take?:";
  cout << "\n\tX: ";
  cin >> x2;
  cin.ignore(100, '\n');
  cout << "\tY: ";
  cin >> y2;
  cin.ignore(100, '\n');
 
  //If word to be played horizontally
  if( x == x2 )
    for(int i = 0; i < length; ++i)
    {
      board->set_space(board, word[i], x, y+i);
    }
  else
  //If word to be played vertically
   for(int i = 0; i < length; ++i)
    {
      board->set_space(board, word[i], x+i, y);
    }
  //Add new word score to total score
   player.add_to_total(word);
//Remove played tiles from hand
   for(int i = 0; i < length; ++i)
      players_hand.remove_tile(word[i]);  
} 
//Function to choose turn play
int game::choice_of_play(node * &board, players &player, hand &players_hand)
{
  char choice;
  char letter;
//Get choice from user
  cout << "\n\tIt's your turn. Would you like to play"       << " a word,\n\tskip your turn, or trade some of your tiles?: ";
  cin >> choice;
  cin.ignore(100,'\n');
  choice = toupper(choice);
  //If play call play word function
  if( choice == 'P')
    play_word(board,player,players_hand);
  //If trade find out how many tiles
  if( choice == 'T')
  {
    int trade_amount = 0;
    cout << "\n\tHow many tiles do you want to trade?: ";
    cin >> trade_amount; 
    cin.ignore(100, '\n');
//Get which tiles
    for(int i = 0; i <trade_amount; ++i)
    {
      cout << "\n\tGive a tile you'd like to trade?: ";
      cin >> letter;
      cin.ignore(100, '\n');
      letter = toupper(letter);
   //Remove each from hand
      players_hand.remove_tile(letter);
    } 
  }       
return 1;
}

  
 
