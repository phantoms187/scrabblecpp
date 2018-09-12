//David Davis CS202 Program 1 and 2
//978105326
//This file holds the function definitions for the tiles class
//Include needed headed file
#include "scrabble.h"
//Using standard namespace
using namespace std;

//Constructor for tiles class
tiles::tiles()
{//Seed random function with current time
  srand(time(NULL));
  //set individual tile values to default 0
  value = 0;
  //Call allocate_tiles function to initialize array
  allocate_tiles();  
}
//Destructor
tiles::~tiles()
{
  if(total_tiles)
    delete [] total_tiles;
}
//Function to pick a random tile
char tiles::pick_tile()
{//Character variable to store pick
  char pick;
  //Integer variable to hold random number between 0-97
  int i = 0;
  i = rand() % 98;
//Set pick to random number location of total_tiles array
  pick = total_tiles[i];
//Set that location of total_tiles to indication character to remove it from possible picks
  total_tiles[i] = '@';
//If random pick is indication variable pick again
  while(pick == '@')
  {
    i = rand() % 98;
    pick = total_tiles[i];
  }
 //returns picked tile character 
  return pick; 
}

//Allocation of all possible tiles to pick from based on actual scrabble distribution
void tiles::allocate_tiles()
{//Dynamic array to hold 98 characters
  total_tiles = new char[98]; 
  int i = 0;

  for( i = 0; i < 9; ++i)
    total_tiles[i] = 'A';

  for( i = 9; i < 11; ++i)
    total_tiles[i] = 'B';
  
  for( i = 11; i < 13; ++i)
    total_tiles[i] = 'C';
  
  for( i = 13; i < 17; ++i)
    total_tiles[i] = 'D';

  for( i = 17; i < 29; ++i)
    total_tiles[i] = 'E';

  for( i = 29; i < 31; ++i)
    total_tiles[i] = 'F';
  
  for( i = 31; i < 34; ++i)
    total_tiles[i] = 'G';
  
  for( i = 34; i < 36; ++i)
    total_tiles[i] = 'H';
  
  for( i = 36; i < 45; ++i)
    total_tiles[i] = 'I';

    total_tiles[45] = 'J';
  
    total_tiles[46] = 'K';
  
  for( i = 47; i < 51; ++i)
    total_tiles[i] = 'L';

  for( i = 51; i < 53; ++i)
    total_tiles[i] = 'M';

  for( i = 53; i < 59; ++i)
    total_tiles[i] = 'N';
  
  for( i = 59; i < 67; ++i)
    total_tiles[i] = 'O';
  
  for( i = 67; i < 69; ++i)
    total_tiles[i] = 'P';

  total_tiles[69] = 'Q';
  
  for( i = 70; i < 76; ++i)
    total_tiles[i] = 'R';

  for( i = 76; i < 80; ++i)
    total_tiles[i] = 'S';
  
  for( i = 80; i < 86; ++i)
    total_tiles[i] = 'T';
  
  for( i = 86; i < 90; ++i)
    total_tiles[i] = 'U';

  for( i = 90; i < 92; ++i)
    total_tiles[i] = 'V';

  for( i = 92; i < 94; ++i)
    total_tiles[i] = 'W';
  
  total_tiles[94] = 'X';
  
  for( i = 95; i < 97; ++i)
    total_tiles[i] = 'Y';
  
  total_tiles[97] = 'Z'; 

} 


