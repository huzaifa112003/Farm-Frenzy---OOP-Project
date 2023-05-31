#include "countp.hpp"

countP::countP(int init_pr) : countproduct(init_pr){};


int countP::  collectedProducts(){
    return countproduct;

}

void countP::operator++(){
    countproduct++;
}