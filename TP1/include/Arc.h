/*-----------------------------
Classe Arc
Author: Steven Diep 2010339
        Jamesley Joseph 1990552
        Alex Hua 1994253
Date: 3 novembre 2020
------------------------------*/

#pragma once

#include "Sommet.h"
class Arc
{

public:
    Arc();
    Arc(Sommet origin, Sommet destination, int distance); 
    int getDistance() const; 
    Sommet getOrigin() const; 
    Sommet getDestination() const; 
    void setDistance(int distance); 
    

private:
    Sommet origin_;
    Sommet destination_;
    int distance_;
};