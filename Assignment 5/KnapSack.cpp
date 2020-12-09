//
// Created by aaron on 12/8/2020.
//

#include "KnapSack.h"

KnapSack::KnapSack(const vector<Spice>& spices) {
    cap = 0;
    currQuantity = 0;
    currValue = 0;
}

KnapSack::KnapSack(int newCap, const vector<Spice>& spices) {
    cap = newCap;
    currQuantity = 0;
    currValue = 0;
    items = spices;
}

void KnapSack::setCurrentQuantity(double newQuan) {
    currQuantity = currQuantity + newQuan;
}

void KnapSack::setCurrentValue(double newValue) {
    currValue = currValue + newValue;
}

int KnapSack::getCapacity() {
    return cap;
}


double KnapSack::getCurrentQuantity() {
    return currQuantity;
}

/*
execute the KnapSack by greedy algorithm
*/
float KnapSack::execute() {
    results.clear();
    float totalVal = 0;

    for (size_t i = 0; i < items.size(); i++)
    {
        if (items[i].getQuantity() <= cap) //take all
        {
            Spice spice(items[i].getName(), items[i].getValue(), items[i].getQuantity());
            results.push_back(spice);

            totalVal += items[i].getValue() * items[i].getQuantity();

            cap -= items[i].getQuantity();
        }
        else {//take a part

            Spice spice(items[i].getName(), items[i].getValue(), cap);
            results.push_back(spice);

            totalVal += items[i].getValue() * cap;

            cap = 0;

            break;
        }
    }

    return totalVal;
}


vector<Spice> KnapSack::getResults() {
    return results;
}