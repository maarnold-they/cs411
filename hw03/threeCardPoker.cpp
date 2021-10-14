/*
  Millard A. Arnold V
  threeCardPoker.h
  2021-10-13

  threeCardPoker header file defines functions for Three Card Poker analysis
*/

#include "threeCardPoker.h"

std::vector<Card> makeDeck()
{
  std::vector<Card> deck;
  for(int suit = 1; suit <=4; ++suit)
  {
    for(int rank = 1; rank<=13; ++rank)
    {
      deck.push_back({suit, rank});
    }
  }
  return deck;
}

void computeHand(std::map<std::string, int> quants, std::vector<Card> hand)
{

}
