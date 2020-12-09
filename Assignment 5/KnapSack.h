//
// Created by aaron on 12/8/2020.
//

#ifndef ASSIGNMENT_5_KNAPSACK_H
#define ASSIGNMENT_5_KNAPSACK_H

#include "Spice.h"
#include <vector>
using namespace std;

class KnapSack{

private:
    int cap;
    double currQuantity;
    double currValue;
    vector<Spice> items; //items

    vector<Spice> results; //result of knapsack
public:
    KnapSack(const vector<Spice>& spices);
    KnapSack(int newCap, const vector<Spice>& spices);
    void setCurrentQuantity(double newQuan);
    void setCurrentValue(double newValue);
    int getCapacity();
    double getCurrentQuantity();

    float execute();
    vector<Spice> getResults();
};

#endif //ASSIGNMENT_5_KNAPSACK_H