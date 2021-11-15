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
std::pair<std::string, int> computeHand(std::map<std::string, int>& payouts, Hand hand)
{
  for(int j=0; j<2; ++j)
  {
    for(int i=0; i<2; ++i)
    {
      if(hand.cards[i].getRank()<hand.cards[i+1].getRank())
      {
        Card temp = hand.cards[i];
        hand.cards[i] = hand.cards[i+1];
        hand.cards[i+1] = temp;
      }
    }
  }
  if( hand.cards[0].getSuit()==hand.cards[1].getSuit() &&
      hand.cards[1].getSuit()==hand.cards[2].getSuit() &&
      (hand.cards[0].getRank()==hand.cards[2].getRank()+2 ||
      (hand.cards[1].getRank()==12 && hand.cards[2].getRank()==1)))
  {
    return{"Straight Flush", payouts["Straight Flush"]};
  }
  if( hand.cards[0].getRank()==hand.cards[1].getRank() &&
      hand.cards[1].getRank()==hand.cards[2].getRank())
  {
    return{"Three of a Kind", payouts["Three of a Kind"]};
  }
  if( (hand.cards[0].getRank()==hand.cards[1].getRank()+1 &&
      hand.cards[0].getRank()==hand.cards[2].getRank()+2) ||
      (hand.cards[0].getRank()==13 &&
      hand.cards[1].getRank()==12 &&
      hand.cards[2].getRank()==1))
  {
    return{"Straight", payouts["Straight"]};
  }
  if( hand.cards[0].getSuit()==hand.cards[1].getSuit() &&
      hand.cards[1].getSuit()==hand.cards[2].getSuit())
  {
    return{"Flush\t", payouts["Flush\t"]};
  }
  if( hand.cards[0].getRank()==hand.cards[1].getRank() ||
      hand.cards[1].getRank()==hand.cards[2].getRank() ||
      hand.cards[2].getRank()==hand.cards[0].getRank())
  {
    return{"Pair\t", payouts["Pair\t"]};
  }
  return{"High Card", payouts["High Card"]};
}
