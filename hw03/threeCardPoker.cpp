/*
  Millard A. Arnold V
  threeCardPoker source file
  Last Updated: 2021-10-12

  This file will contain the source code for homework 03, a three card poker program.
*/
#include "threeCardPoker.h"

void threeCardPoker(std::map<std::string,int> &hands)
{
  auto deck = makeDeck();
  for(int a=0; a < (int)deck.size(); ++a)
  {
    for(int b=0; b < (int)deck.size(); ++b)
    {
      for(int c=0; c < (int)deck.size(); ++c)
      {
        if(a !=b && b != c && c!= a)
        {

        }
      }
    }
  }
}

const int computeTotal(const std::vector<int> &quantities)
{
  return 0;
}

std::vector<std::pair<int,int>> makeDeck()
{
  std::vector<std::pair<int,int>> deck;
  for(int suit = 1; suit <= 4; ++suit)
  {
    for(int rank =1; rank <= 13; ++rank)
    {
      deck.push_back(std::make_pair(suit,rank));
    }
  }
  return deck;
}
