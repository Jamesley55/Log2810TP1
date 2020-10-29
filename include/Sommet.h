
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

     // affichier les composante du somet
     friend std::ostream& operator<<(std::ostream& os, const Sommet& sommet);

private:
    std::string identifiant_;
    Constante::Type type_;
};