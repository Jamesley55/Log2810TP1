/*-----------------------------
Classe Interface
Author: Steven Diep 2010339
        Jamesley Joseph 1990552
        Alex Hua 1994253
Date: 3 novembre 2020
------------------------------*/

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