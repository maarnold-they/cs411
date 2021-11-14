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

int main(int argc, char** argv)
{
  auto deck{makeDeck()};
  std::map<std::string, int> quants;
  int sum{0};
  for(int c1=0; c1<(int)deck.size(); ++c1)
  {
    for(int c2=0; c2<(int)deck.size(); ++c2)
    {
      for(int c3=0; c3<(int)deck.size(); ++c3)
      {
        if(c1!=c2 && c2!=c3 && c1!=c3)
        {
          ++sum;
          std::vector<Card> hand{deck[c1],deck[c2],deck[c3]};
          computeHand(quants, hand);
        }
      }
    }
  }
  double totalReturn{0};
  std::map<std::string, int> payouts;
  payouts["Straight Flush"]=2000;
  payouts["Three of a Kind"]=250;
  payouts["Straight"]=30;
  payouts["Flush\t"]=15;
  payouts["Pair\t"]=2;
  payouts["High Card"]=0;
  std::cout<<"\n\n\n\n\n\n\n\n\tMillard A. Arnold V\n\t";
  std::cout<<"Hand\t\tFreq\tProb\t\tPayout\tReturn\n\n\t";
  for(auto hand: quants)
  {
    std::cout<<hand.first<<"\t"<<hand.second<<"\t"<<(double)hand.second/sum<<"\t"<<payouts[hand.first]<<"\t"<<(double)hand.second/sum*payouts[hand.first]-1<<"\n\t";
    totalReturn+=(double)hand.second/sum*payouts[hand.first]-1;
  }
  std::cout<<"\t\t\t\t\tTotal Return:\t"<<totalReturn<<"\n\n\n\n\n\n\n\n\n";
  return 0;
}
