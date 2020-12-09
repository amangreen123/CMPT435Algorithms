//
// Created by aaron on 12/5/2020.
//
#include<string>
#include "Spice.h"


Spice::Spice() {
    name = "";
    value = -1;
    quantity = -1;

};

Spice::Spice(string N, float V, int Q) {
    name = N;
    quantity = Q;
    value = V;
};


string Spice::getName() {
    return name;
};


float Spice::getValue() {
    return value;
};


int Spice::getQuantity() {
    return quantity;
};