//
// Created by aaron on 12/5/2020.
//

#ifndef ASSIGNMENT_5_SPICE_H
#define ASSIGNMENT_5_SPICE_H

#endif //ASSIGNMENT_5_SPICE_H
#include<string>
using namespace std;

class Spice{

private:
    string name;
    int Value;
    int quantity;
    Spice*  next;

public:
    Spice();
    Spice(string N, int Q, int V);
    void setSpice(Spice* next);
    string getName();
    int getValue();
    int getQuanity();

};
