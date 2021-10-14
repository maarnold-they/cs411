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
#include <iostream>
void computeHand(std::map<std::string, int>& quants, std::vector<Card>& hand)
{
  for(int j=0; j<2; ++j)
  {
    for(int i=0; i<2; ++i)
    {
      if(hand[i].getRank()<hand[i+1].getRank())
      {
        Card temp = hand[i];
        hand[i] = hand[i+1];
        hand[i+1] = temp;
      }
    }
  }
  if( hand[0].getSuit()==hand[1].getSuit() &&
      hand[1].getSuit()==hand[2].getSuit() &&
      (hand[0].getRank()==hand[2].getRank()+2 ||
      (hand[1].getRank()==12 && hand[2].getRank()==1)))
  {
    ++quants["Straight Flush"];
    return;
  }
  if( hand[0].getRank()==hand[1].getRank() &&
      hand[1].getRank()==hand[2].getRank())
  {
    ++quants["Three of a Kind"];
    return;
  }
  if( (hand[0].getRank()==hand[1].getRank()+1 &&
      hand[0].getRank()==hand[2].getRank()+2) ||
      (hand[0].getRank()==13 &&
      hand[1].getRank()==12 &&
      hand[2].getRank()==1))
  {
    ++quants["Straight"];
    return;
  }
  if( hand[0].getSuit()==hand[1].getSuit() &&
      hand[1].getSuit()==hand[2].getSuit())
  {
    ++quants["Flush\t"];
    return;
  }
  if( hand[0].getRank()==hand[1].getRank() ||
      hand[1].getRank()==hand[2].getRank() ||
      hand[2].getRank()==hand[0].getRank())
  {
    ++quants["Pair\t"];
    return;
  }
  ++quants["High Card"];
}
