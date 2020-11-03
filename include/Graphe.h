#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Arc.h"
#include "Sommet.h"
#include "Voiture.h"
#include <map>


struct informationStation{
    bool visited; 
    size_t distance; 
    Sommet closestStation;
};

class Graphe
{

public:
    void creerGraphe(const std::string fichierText);
    void lireGraphe();
    std::vector<Arc> extractionGraphe();
    Voiture getVoiture();


    size_t plusCourtChemin( Sommet& origine,  Sommet& destination);
    void VoiturePropriety(Constante::Type typeDessence, const int autonomieMaximale, const double autonomieActuelle, const double coefficientDePerte);
    bool sommetInGraphe(const std::string& Sommet); 
    Sommet trouverSommet(const std::string& nomSommet);



private:
    Sommet TrouverSommet(const std::string sommet, std::vector<Sommet> arraySommet);
    Sommet sommetWithMinDistance( std::map<Sommet, informationStation>  station); 
    void dijkstra(std::map<Sommet, informationStation> & station); 
    void deplacerVoitureSurleGraphe(std::map<Sommet, informationStation>  & station,  Sommet  &  origine,   Sommet & destination) ;
    Arc trouverArc(const Sommet& origine, const Sommet& destination) const;

    Voiture voiture_;
    std::vector<Arc> arc_;
    std::vector<Sommet> sommet_;
    std::map<Sommet, std::vector<Arc>> graphe_;
};