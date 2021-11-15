/*
  Millard A. Arnold V
  main.cpp
  2021-10-13

  Main file for homework 03
*/

#include "threeCardPoker.h"
#include "card.h"

#include <iostream>
#include <map>
//Sum == 132600
int main(int argc, char** argv)
{
  auto deck{makeDeck()};
  std::map<std::string, int> quants;
  int sum{0};
  std::vector<Hand> hands;
  for(int c1=0; c1<(int)deck.size(); ++c1)
  {
    for(int c2=0; c2<(int)deck.size(); ++c2)
    {
      for(int c3=0; c3<(int)deck.size(); ++c3)
      {
        if(c1!=c2 && c2!=c3 && c1!=c3)
        {
          hands.push_back({{deck[c1], deck[c2], deck[c3]}});
        }
      }
    }
  }

  std::map<std::string, int> payouts;
  payouts["Straight Flush"]=2000;
  payouts["Three of a Kind"]=250;
  payouts["Straight"]=30;
  payouts["Flush\t"]=15;
  payouts["Pair\t"]=2;
  payouts["High Card"]=0;

  for(auto hand: hands)
  {
      double keep = computeHand(payouts, hand).second;
      double swapC1 = 0;
      double swapC2 = 0;
      double swapC3 = 0;
      for(int i = 0; i<(int)deck.size(); ++i)
      {
        if((deck[i].getRank() != hand.cards[0].getRank() && deck[i].getSuit() != hand.cards[0].getSuit()))
        {
          swapC1 += computeHand(payouts, {{deck[i], hand.cards[1], hand.cards[2]}}).second;
        }
        if((deck[i].getRank() != hand.cards[1].getRank() && deck[i].getSuit() != hand.cards[1].getSuit()))
        {
          swapC2 += computeHand(payouts, {{hand.cards[0], deck[i], hand.cards[2]}}).second;
        }
        if((deck[i].getRank() != hand.cards[2].getRank() && deck[i].getSuit() != hand.cards[2].getSuit()))
        {
          swapC3 += computeHand(payouts, {{hand.cards[0], hand.cards[1], deck[i]}}).second;
        }
      }
      swapC1 /= hands.size()-1;
      swapC2 /= hands.size()-1;
      swapC3 /= hands.size()-1;

      if(keep >= swapC1 && keep >= swapC2 && keep >= swapC3)
      {
        ++quants[computeHand(payouts, hand).first];
        ++sum;
      }
      else if(swapC1 >= swapC2 && swapC1 >= swapC3)
      {
        for(int i = 0; i<(int)deck.size(); ++i)
        {
          if((deck[i].getRank() != hand.cards[0].getRank() && deck[i].getSuit() != hand.cards[0].getSuit()))
          {
            ++quants[computeHand(payouts, {{deck[i], hand.cards[1], hand.cards[2]}}).first];
            ++sum;
          }
        }
      }
      else if (swapC2 >= swapC3)
      {
        for(int i = 0; i<(int)deck.size(); ++i)
        {
          if((deck[i].getRank() != hand.cards[1].getRank() && deck[i].getSuit() != hand.cards[1].getSuit()))
          {
            ++quants[computeHand(payouts, {{hand.cards[0], deck[i], hand.cards[2]}}).first];
            ++sum;
          }
        }
      }
      else
      {
        for(int i = 0; i<(int)deck.size(); ++i)
        {
          if((deck[i].getRank() != hand.cards[2].getRank() && deck[i].getSuit() != hand.cards[2].getSuit()))
          {
            ++quants[computeHand(payouts, {{hand.cards[0], hand.cards[1], deck[i]}}).first];
            ++sum;
          }
        }
      }
  }

  double totalReturn{0};
  std::cout<<"\n\n\n\n\n\n\n\n\tMillard A. Arnold V\n\n\t";
  std::cout<<"Hand\t\tFreq\tProb\t\tPayout\tReturn\n\n\t";
  for(auto hand: quants)
  {
    std::cout << hand.first << "\t" << hand.second << "\t" << (double) hand.second / sum << "\t" << payouts[hand.first] << "\t" << (double) hand.second / sum * payouts[hand.first] - 1 << "\n\t";
    totalReturn += (double) hand.second / sum * payouts[hand.first] - 1;
  }
  std::cout<<"\t\t\t\t\tTotal Return:\t"<<totalReturn<<"\n\n\n\n\n\n\n\n\n";
  return 0;
}
