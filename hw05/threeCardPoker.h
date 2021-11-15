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

struct Hand {
  std::vector<Card> cards;
};

std::pair<std::string, int> computeHand(std::map<std::string, int>& payouts, Hand hand);

#endif
