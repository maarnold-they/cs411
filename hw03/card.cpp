/*
  Millard A. Arnold V
  card.cpp
  2021-10-13

  Card source file defines cards
*/

#include "card.h"

bool Card::operator==(const Card& other) const
{
  return _rank==other.getRank() && _suit==other.getSuit();
}
bool Card::operator<(const Card& other) const
{
  return _rank<other.getRank();
}
bool Card::operator<=(const Card& other) const
{
  return *this == other || *this < other;
}

int Card::getRank()
{
  return _rank;
}
int Card::getSuit()
{
  return _suit;
}

const int Card::getRank() const
{
  return this->getRank();
}
const int Card::getSuit() const
{
  return this->getSuit();
}
