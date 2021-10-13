/*
  Millard A. Arnold V
  threeCardPoker main file
  Last Updated: 2021-10-12

  This file will contain the code to run threeCardPoker
*/
#include "threeCardPoker.h"

#include <map>
#include <string>
#include <iostream>

int main(int argc, char const *argv[]) {
  std::map<std::string,int> hands;
  threeCardPoker(hands);
  int sum=0;
  for(auto hand: hands)
  {
    sum+=hand.second;
  }
  std::cout << "Hand\tDescription\tFreq\tProb\tPayout\tReturn";
  return 0;
}
