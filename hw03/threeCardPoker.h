/*
  Millard A. Arnold V
  threeCardPoker header file
  Last Updated: 2021-10-12

  This file will contain the header file for threeCardPoker
*/

#ifndef THREE_CARD_POKER_H
#define THREE_CARD_POKER_H

#include <string>
#include <map>
#include <vector>

void threeCardPoker(std::map<std::string,int> &hands);

const int computeTotal(const std::vector<int> &quantities);

#endif
