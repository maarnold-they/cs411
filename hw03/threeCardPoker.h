/*
  Millard A. Arnold V
  threeCardPoker.h
  2021-10-13

  threeCardPoker header file defines functions for Three Card Poker analysis
*/

#ifndef THREE_CARD_POKER_H
#define THREE_CARD_POKER_H

#include "card.h"

#include <vector>
#include <map>
#include <string>
#include <algorithm>

std::vector<Card> makeDeck();

void computeHand(std::map<std::string, int>& quants, std::vector<Card>& hand);

#endif
