// Name: Tahmina Akther Munni
// Course: CSCI 135
// Instructor: Tong Yi
// Assignment: Project 3 - Competition

#include "Competition.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

Competition::Competition() {
  srand(1); //submit to autograder,
      //otherwise, the game may have different running results,
      //which cannot be checked by scripts.

  rabbit = new Hare;
  //create a rabbit with default constructor
       //of Hare class.
       //Same as rabbit = new Hare();
   //If rabbit is not a pointer to Hare, that is,
   //rabbit is not Hare* type,
   //then it is not easy to call a default constructor
   //in two lines:
   //Hare rabbit; //suppose it were in Competition.h
   //rabbit = Hare();

  tor = new Tortoise;
  rd = new Road;
}

Competition::Competition(Hare *rabbit, Tortoise *tor, int length) {
  srand(1);
  //this->rabbit = rabbit; //not easy to delete data member
         //rabbit, since by this approach,
         //this->rabbit is not created by new 
         //as in default constructor,
         //so in destructor, when we use delete,
         //if rabbit object is created through new,
         //it is ok, but will cause problems if
         //rabbit is not created by new.

  this -> rabbit = new Hare(rabbit -> getPattern(),rabbit -> getPatternLength(),
                  rabbit -> getPosition());
  //this->tor = tor;

  this -> tor = new Tortoise(tor -> getPattern(), tor -> getPatternLength(),
                tor -> getPosition());

  rd = new Road(length);
}

Competition::~Competition() {
  delete rabbit;
  rabbit = 0; //avoid dangling pointer problem
  delete tor;
  tor = 0;
  delete rd;
  rd = 0;
}

void Competition::start()  {
  int lastBlock = rd -> getLastBlock();
        //rd->getLastBlock() can be rewritten as
        //(*rd).getLastBlock(), () cannot be omitted
        //since . operator has higher precedence than
        //* dereference operator.
        //since Road* rd; so *rd can be thought as
        //an object of Road.
  int round = 1;
   
  while (rabbit -> getPosition() < lastBlock && tor -> getPosition() < lastBlock) {
    rabbit -> move();
    if (rabbit -> getPosition() < 0 ) {
      rabbit -> setPosition(0);
    }
    else if (rabbit -> getPosition() > lastBlock) {
      rabbit -> setPosition(lastBlock);
    }

    tor -> move();
    if (tor -> getPosition() < 0 ) {
      tor -> setPosition(0);
    }
    else if (tor -> getPosition() > lastBlock) {
      tor -> setPosition(lastBlock);
    }

    //TODO: Move tor.
    rd -> mark(rabbit -> getPosition(), 'H');
    rd -> mark(tor -> getPosition(), 'T');

    cout << setw(3) << round << " ";
    cout << rd -> toString() << endl;

    if (rabbit -> getPosition() == tor -> getPosition()) {
      cout << "Ouch, Tortoise bites Hare." << endl;
    }

    rd -> mark(tor -> getPosition(), ' ');
    rd -> mark(rabbit -> getPosition(), ' ');
    round++;
  }

  if (rabbit -> getPosition() == lastBlock && tor -> getPosition() == lastBlock) {
    cout << "It is a tie." << endl;
  }
  else if (rabbit -> getPosition() == lastBlock) {
    cout << "Yuck, hare wins." << endl;
  }
  else if (tor -> getPosition() == lastBlock) {
      cout << "Yay!!! tortoise wins!" << endl;
  }
}
