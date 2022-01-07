/*
Author: Tahmina Akther Munni
Course: CSCI-135
Instructors: Tong
Description: project 3
*/

#include "Road.h"

Road::Road()
{
    length = 70;
    squares = new char[length];
    
    clear();
}
Road::Road(int len)
{
    if (len <= 0)
        length = 70;
    else length = len;
    

    squares = new char[length];
    
    clear();
}

Road::~Road()
{
  delete[] squares;
  squares = 0; //some c++ does not make squares = nullprt
}

void Road::clear(){
  for (int i = 0; i < length; i++)
  squares[i] = ' ';
}

void Road::mark(int pos, char ch)
{
  squares[pos] = ch;
}

int Road::getLastBlock() const
{
  return length-1;
}

char* Road::toString() const
{
  return squares;
}

