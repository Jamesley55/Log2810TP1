/*-----------------------------
Classe Voiture
Author: Steven Diep 2010339
        Jamesley Joseph 1990552
        Alex Hua 1994253
Date: 3 novembre 2020
------------------------------*/

#include "Voiture.h"

Voiture::Voiture() : typeDessence_(Constante::Type::Rien),
                     autonomieMaximale_(Constante::Rien),
                     autonomieActuelle_(Constante::Rien),
                     coefficientDePerte_(Constante::Rien)
{
}

Voiture::Voiture(Constante::Type typeDessence, const int autonomieMaximale, const int autonomieActuelle, const double coefficientDePerte) : typeDessence_(typeDessence),
                                                                                                                                               autonomieMaximale_(autonomieMaximale),
                                                                                                                                               autonomieActuelle_(autonomieActuelle),
                                                                                                                                               coefficientDePerte_(coefficientDePerte)
{
}
double Voiture::getAutonomiePourcentage() const
{
    return ((100.0 * autonomieActuelle_) / autonomieMaximale_);
}

int Voiture::getAutonomieMaximale() const
{
    return autonomieMaximale_;
}

double Voiture::getAutonomieActuelle() const
{
    return autonomieActuelle_;
}

double Voiture::getCoefficientDePerte() const
{
    return coefficientDePerte_;
}

bool Voiture::peutArriverADestination(const int distance) const
{
    return ((distance * coefficientDePerte_ * autonomieMaximale_) <= autonomieActuelle_);
}
bool Voiture::deplacer(const Arc &arc)
{
    if (peutArriverADestination(arc.getDistance()))
    {
        diminuerAutonomieActuelle(arc.getDistance());
        recharger(arc.getDestination().getTypeEnumeration());
        return true;
    }

    return false;
}

void Voiture::recharger(Constante::Type typeDessenceStation)
{
    if (typeDessenceStation != Constante::Type::Rien)
    {
        if (typeDessence_ == typeDessenceStation || typeDessence_ == Constante::Type::Hybride || typeDessenceStation == Constante::Type::Hybride)
            autonomieActuelle_ = getAutonomieMaximale();
    }
}

void Voiture::diminuerAutonomieActuelle(const int distance)
{
    peutArriverADestination(distance) ? autonomieActuelle_ -= ((distance * coefficientDePerte_) * autonomieMaximale_) + distance : autonomieActuelle_ = Constante::Rien;
}

Voiture Voiture::clone() const
{
    return Voiture(typeDessence_, autonomieMaximale_, autonomieActuelle_, coefficientDePerte_);
}
