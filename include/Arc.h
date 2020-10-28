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
    Arc clone(); 
    

private:
    Sommet origin_;
    Sommet destination_;
    int distance_;
};