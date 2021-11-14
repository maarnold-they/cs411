/*
  Millard A. Arnold V
  card.h
  2021-10-13

  Card header file defines cards
*/

#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card
{

//ctors
public:
  Card() = delete;
  Card(int suit, int rank)
    : _suit(suit), _rank(rank)
  {}

//big 5 defaulted
public:
  ~Card()=default;
  Card(const Card& other)=default;
  Card(Card&& other)=default;
  Card& operator=(const Card& other)=default;
  Card& operator=(Card&& other)=default;

public:
  bool operator==(const Card& other) const;
  bool operator<(const Card& other) const;
  bool operator<=(const Card& other) const;

  int getRank();
  const int getRank() const;
  int getSuit();
  const int getSuit() const;

//data members
private:
  int _suit;
  int _rank;
};

#endif
