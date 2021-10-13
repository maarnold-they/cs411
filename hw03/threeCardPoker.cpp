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
          evaluateHand(hands, {deck[a], deck[b], deck[c]});
        }
      }
    }
  }
}

void evaluateHand(std::map<std::string,int> &hands,
   const std::vector<Card>& hand)
{
  std::stable_sort(hand.begin(), hand.end());
  if( hand[0].suit == hand[1].suit &&
      hand[1].suit == hand[2].suit &&
      hand[0].rank == hand[2].rank-2)
  {
    ++hands["Straight Flush"];
    return;
  }
  if( hand[0].rank == hand[1].rank &&
        hand[1].rank == hand[2].rank)
  {
    ++hands["Three of a Kind"];
    return;
  }
  if( hand[0].rank == hand[1].rank-1 &&
      hand[1].rank == hand[2].rank-2)
  {
    ++hands["Straight"];
    return;
  }
  if( hand[0].suit == hand[1].suit &&
      hand[1].suit == hand[2].suit)
  {
    ++hands["Flush"];
    return;
  }
  if( hand[0].rank == hand[1].rank ||
      hand[1].rank == hand[2].rank ||
      hand[2].rank == hand[0].rank)
  {
    ++hands["Pair"];
    return;
  }
  ++hands["High Card"];
}


const int computeTotal(const std::vector<int> &quantities)
{
  return 0;
}

std::vector<Card> makeDeck()
{
  std::vector<Card> deck;
  for(int suit = 1; suit <= 4; ++suit)
  {
    for(int rank =1; rank <= 13; ++rank)
    {
      deck.push_back({suit, rank});
    }
  }
  return deck;
}
