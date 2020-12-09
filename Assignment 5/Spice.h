//
// Created by aaron on 12/5/2020.
//

#ifndef ASSIGNMENT_5_SPICE_H
#define ASSIGNMENT_5_SPICE_H


#include<string>
using namespace std;

class Spice {

private:
    string name;
    float value;
    int quantity;

public:
    Spice();
    Spice(string N, float V, int Q);
    string getName();
    float getValue();
    int getQuantity();

};

#endif //ASSIGNMENT_5_SPICE_H