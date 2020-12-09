//
// Created by aaron on 12/8/2020.
//

#include "KnapSack.h"

KnapSack::KnapSack() {
    cap = 0;
    currQuantity = 0;
    currValue = 0;
}

KnapSack::KnapSack(int newCap){
    cap = newCap;
    currQuantity = 0;
    currValue = 0;
}
void KnapSack::setCurrentQuantity(double newQuan){
    currQuantity = currQuantity + newQuan;
}

void KnapSack::setCurrentValue(double newValue){
    currValue = currValue + newValue;
}

int KnapSack::getCapacity(){
    return cap;
}


double KnapSack::getCurrentQuantity(){
    return currQuantity;
}
