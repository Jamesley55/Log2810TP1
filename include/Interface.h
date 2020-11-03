#pragma once
#include "Graphe.h"

class Interface
{

public:
    Interface();
    void menu();
   Constante::Type getTypeEnum(std::string type);


private:
    Graphe graphe_;
};