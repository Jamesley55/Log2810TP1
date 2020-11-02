
#pragma once

#include <string>
#include <iostream>
#include "Constante.h"
#include <vector>

class Sommet
{

public:
    Sommet();
    Sommet(std::string indentifiant, Constante::Type typeDessence);
    Sommet(std::string indentifiant, std::string typeDessence);

    Sommet(const Sommet &sommet);
    Constante::Type getTypeEnumeration() const;
    std::string getType() const;
    std::string getIdentifiant() const;

     // afficher les composante du sommet
     friend std::ostream& operator<<(std::ostream& os, const Sommet& sommet);

    // overload ces opertateur pour utiliser le hashmap
    bool operator==(const Sommet &sommet) const;
    bool operator!=(const Sommet& sommet) const;
    bool operator<(const Sommet& sommet) const;


private:
    std::string identifiant_;
    Constante::Type type_;
};