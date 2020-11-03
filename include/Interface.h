#pragma once
#include "Graphe.h"

class Interface
{

public:
    Interface();
    void menu();
    void afficherPlusLongChemin();
   Constante::Type getTypeEnum(std::string type);


private:
    Graphe graphe_;
};