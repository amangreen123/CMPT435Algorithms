//
// Created by aaron on 12/8/2020.
//

#ifndef ASSIGNMENT_5_KNAPSACK_H
#define ASSIGNMENT_5_KNAPSACK_H

#endif //ASSIGNMENT_5_KNAPSACK_H

class KnapSack{

private:
    int cap;
    double currQuantity;
    double currValue;

public:
    KnapSack();
    KnapSack(int newCap);
   void setCurrentQuantity(double newQuan);
   void setCurrentValue(double newValue);
   int getCapacity();
   double getCurrentQuantity();




};