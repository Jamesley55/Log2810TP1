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

