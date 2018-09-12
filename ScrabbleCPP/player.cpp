//David Davis CS202 Program 1 and 2
//978105326
//Player class file for class functions

#include "scrabble.h"
using namespace std;
//Constructor
players::players()
{
  score = 0;
  

}
//Return score when needed
int players::return_score()
{
  return score;
}
//Add to total score when word played
int players::add_to_total(char  word[])
{
  score += calc_score(word);
  return score;
}
//Determine worth of word in points 
int players::calc_score( char word[])
{
  int sum = 0;
  int length = strlen(word);
  //Loop to add each letter in word together
  for(int i =0; i < length; ++i)
  {
    sum += letter_value(word[i]);
  }
  //Return total 
  return sum;
}
//Function to determine letter value
int players::letter_value(char tile)
{
  //Use of arrays to hold letters to easily loop through when comparing
  int value = 0;
  char singles[11] = {'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U'};
  char triple[5] = {'B', 'C', 'M', 'P'};
  char quads[6] = {'F', 'H', 'V', 'W', 'Y'};

  if( tile == 'D' || 'G' == tile)
    value = 2;
  else if(tile == 'K')
    value = 5;
  else if( 'J' == tile || 'X' == tile)
    value = 8;
  else if( 'Q' == tile || 'Z' == tile)
    value = 10;
     
  //Assign integer value to each group of letters    
  for(int i = 0; i < 11; ++i)
  { 
     if(tile == singles[i])
       value = 1;
  }
  for (int j = 0; j < 5; ++j)
  {
    if(tile == triple[j])
      value = 3;
  }
  for (int k = 0; k < 6; ++k)
  {
     if(tile == quads[k])
       value = 4;
  }
  //Return desired letter value
  return value;

}
