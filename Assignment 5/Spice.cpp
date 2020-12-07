//
// Created by aaron on 12/5/2020.
//
#include<string>
#include "Spice.h"


Spice::Spice(){
    name = "";
    Value = -1;
    quantity = -1;
    next = nullptr;

};

Spice::Spice(string N, int Q, int V){
    name = N;
    quantity = Q;
    Value = V;
    next = NULL;
};


void Spice::setSpice(Spice* next){
    next = next;
};



string Spice::getName(){
    return name;
};


int Spice::getValue(){
    return Value;
};


int Spice::getQuanity(){
    return quantity;
};
