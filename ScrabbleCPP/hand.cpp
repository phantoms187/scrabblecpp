//David Davis Program 1 and 2 Scrabble Game
//CS202 978105326

//hand.cpp file holds the function definitions for the hand class, comp_hand, and human_hand sub-classes

//Include scrabble.h file 
#include "scrabble.h"

//Use of standard namespace
using namespace std;
//Hand class constructor
hand::hand()
{//Set current_hand pointer to NULL
  current_hand = NULL;
}
//Destructor
hand::~hand()
{
  if(current_hand)
    delete [] current_hand;
}
//Function to draw original 7 tiles for a hand
void hand::draw_7(tiles &pieces)
{//Dynamically allocate character array
  current_hand = new char[7];
//Loop through array calling random tile pick to assign each array location
  for(int i = 0; i < 7; ++i)
  {
    current_hand[i] = pieces.pick_tile();
  }
}
//Function to display a player's hand
void hand::show_hand()
{//Initial line space padding
  cout << endl;
//Loop through hand array and display each character
  for(int i = 0; i < 7; ++i)
  {
    cout << "\t" 
         << current_hand[i];
  }
//End with line space padding
  cout << endl;
}

//Remove a desired tile from hand to be traded in for a new random tile
int hand::remove_tile(char to_remove)
{//Character variable to hold desired tile to remove
  char compare;
  int i = 0;
//Loop through hand array to find desired tile
  for(i = 0; i < 7; ++i)
  {//Set compare variable to each array location going through the loop
    compare = current_hand[i];
//Compare variable to desired tile to be removed 
    if(compare == to_remove)
    {//If the same set to indication character
      current_hand[i] = '%';
     //Set loop condition to end loop
      i = 8;
    }
  }
  //If no match is found function returns 0 to calling routine
  if(i == 7)
    return 0;
  else
    return 1;
}
 
bool hand::check_tile(char to_check)
{
  for(int i = 0; i < 7; ++i)
  {//  cout << "\n\t" << current_hand[i];
    if(current_hand[i] == to_check)
      return true;
  }
  return false;
}
//Function to fill removed tiles with new tiles
int hand::fill_hand(tiles &pieces)
{//Run loop to check for indication character
  int count = 0;
  for(int i = 0; i < 7; ++i)
  {//If indication character found use pick_tile function to add random tile
    if(current_hand[i] == '%')
    {
      current_hand[i] = pieces.pick_tile();
      ++count;
    }  
  }
  //Returns the number of tiles replaced
  return count;
}
//Constructors to be implemented in part 2  
/*human_hand::human_hand()
{

}
*/
comp_hand::comp_hand(): hand()
{

}

//comp_hand::comp_hand(const comp_hand

//Vowel check function to determine if holding more than three vowels and remove one if there is more than 3 vowels
int comp_hand::vowel_check()
{ //Integer variable for count and location of vowel
  int count = 0;
  int location = 0;
//Loop through each tile in hand
  for(int i = 0; i < 7; ++i)
  {//Character variable to hold current tile in loop
    char vowel = current_hand[i];
    //Compare between all real vowels. Y does not count
    if(vowel == 'A' || vowel == 'E' || vowel == 'I' || vowel == 'O' || vowel == 'U') 
    {//If vowel found set location to current i value
      location = i;
     //Increase count to determine if over 3 found
      ++count;
    }
  }
  //If count is more than 3 replace last vowel found with indicator character
  if(count > 3)
  {
    current_hand[location] = '%';
    //If vowel is replaced return 1
    return 1;
  }
  else
   //If not more than three vowels return 0
    return 0;
}
//Function to find word to play for the computer from the library text fil    
int comp_hand::find_word(node *&board, hand &players_hand)
{
  int length = 0;
  char * read = new char[50];
 //Set read-in variable 
  ifstream file_in; 
  //Open text file
  file_in.open("library.txt");
  //If file does not open return 0
  if(!file_in)
    return 0;
//If open read first line
  else
    file_in.getline(read, 50, '\n');

  length = strlen(read);
//Could not get function to work properly so I used a temp fix to get the flow if the game going
  board->set_space(board, read[0], 8,8);
  board->set_space(board, read[1], 8,9);
  board->set_space(board, read[2], 8,10);

/*  for(int i = 0; i < length; ++i)
  {
    if(!players_hand.check_tile(read[i]));
   {
    file_in.getline(read, 50, '\n');
    length = strlen(read);
    i = 0;
   }  
  }  
 */
//Close file
  file_in.close();
//Clear variable
  file_in.clear();
//Delete dynamic memory
  if(read)
    delete [] read;
  return 1;
}  
    
  

