
// Name: Tahmina Akther Munni
// Course: CSCI 135
// Instructor: Tong Yi
// Assignment: Project 3


#include "Tortoise.h"
#include <cstdlib>

Tortoise::Tortoise() : length(10) {
  pattern = new int[length]; //dynamically allocated 10-ints
  int defaultPattern[] = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
  for (int i = 0; i < length; i++) {
    pattern[i] = defaultPattern[i];
  }
  position = 0;
}

Tortoise::Tortoise(int* pattern, int size, int position) : length(size > 0 ? size : 10) {
  // "this" points to the current object
  // (*this).pattern also works
  this->pattern = new int[this->length];
  if (size > 0) {
    for (int i = 0; i < size; i++) {
      this->pattern[i] = pattern[i];
    }
  }
  //size <= 0
  else {
    int defaultPattern[] = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
    for (int i = 0; i < length; i++) {
      this->pattern[i] = defaultPattern[i];
    }
  }

  this->position = position;
}

Tortoise::~Tortoise() {
  delete[] pattern;
  pattern = 0; //set pattern to be nullptr
}

int Tortoise::getPosition() const {
  return position;
}

void Tortoise::setPosition(int newPosition) {
  position = newPosition;
}

int* Tortoise::getPattern() const {
  return pattern;
}

int Tortoise::getPatternLength() const {
  return length;
}

void Tortoise::move() {
    int index = rand() % length;
    int stepsToMove = pattern[index];
    position += stepsToMove;
    //warning: cannot write
    //int position += stepsToMove;
    //otherwise, the int declaration before position
    //means position is a local variable,
    //so position is not data member position now.
}
