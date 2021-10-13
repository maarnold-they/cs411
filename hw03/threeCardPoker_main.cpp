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
  for(auto hand: hands)
  {
    std::cout << hand.first << " : " << hand.second << std::endl;
  }
  return 0;
}
