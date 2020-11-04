/*-----------------------------
Classe Voiture
Author: Steven Diep 2010339
        Jamesley Joseph 1990552
        Alex Hua 1994253
Date: 3 novembre 2020
------------------------------*/

#pragma once
#include "Constante.h"
#include "Arc.h"
class Voiture
{
public:
    Voiture();
    Voiture(Constante::Type type, const int autonomieMaximale, const int autonomieActuelle, const double coefficientDePerte);
    Voiture clone() const;

   
    int getAutonomieMaximale() const;
    double getAutonomieActuelle() const;
    double getCoefficientDePerte() const;

    std::string getType() const;
    bool deplacer(const Arc& arc);
    void recharger(Constante::Type typeStation);
    void diminuerAutonomieActuelle(int distance);
    bool peutArriverADestination(int distance) const;
    double getAutonomiePourcentage() const;
    


private:
     int autonomieMaximale_;
    double autonomieActuelle_;
    double coefficientDePerte_;
    Constante::Type typeDessence_;
};