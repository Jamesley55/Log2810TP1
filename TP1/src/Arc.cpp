/*-----------------------------
Classe Arc
Author: Steven Diep 2010339
        Jamesley Joseph 1990552
        Alex Hua 1994253
Date: 3 novembre 2020
------------------------------*/

#include "Arc.h"

Arc::Arc() : origin_(Sommet()),
             destination_(Sommet()),
             distance_(0) {}

Arc::Arc(Sommet origin, Sommet destination, const int distance)
    : origin_(origin),
      destination_(destination),
      distance_(distance) {}

int Arc::getDistance() const
{
    return distance_;
}

Sommet Arc::getOrigin() const
{
    return origin_;
}

Sommet Arc::getDestination() const
{
    return destination_;
}

void Arc::setDistance(int distance)
{
    distance = distance_;
}

