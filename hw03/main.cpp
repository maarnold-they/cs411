/*
  Millard A. Arnold V
  main.cpp
  2021-10-13

  Main file for homework 03
*/

#include "threeCardPoker.h"
#include "card.h"

#include <iostream>

int main(int argc, char** argv)
{
  auto deck = makeDeck();
  for(auto c: deck)
  {
    std::cout<<c.getSuit() << "\t" << c.getRank() << "\n";
  }
  return 0;
}
