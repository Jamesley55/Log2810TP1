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
    int distance; 
    Sommet closestStation;
};

class Graphe
{

public:
    void creerGraphe(const std::string fichierText);
    void lireGraphe();
    Graphe extractionGraphe();


    size_t plusCourtChemin( Sommet& origine,  Sommet& destination);

private:
    Sommet TrouverSommet(const std::string sommet, std::vector<Sommet> arraySommet);
    Sommet sommetWithMinDistance( std::map<Sommet, informationStation>  station); 
    void dijkstra(std::map<Sommet, informationStation> & station); 
    void deplacerVoitureSurleGraphe(std::map<Sommet, informationStation>  & station,  Sommet  &  origine,   Sommet & destination) ;
    Arc trouverArc(const Sommet& origine, const Sommet& destination) const;
    std::vector<Arc> plusLongChemin(std::map<Sommet,informationStation> stations, const Voiture & voiture, const Sommet origine, std::vector<Arc> & PathwayPossible, std::vector<Arc>& longestPathways);
    Voiture voiture_;
    std::vector<Arc> arc_;
    std::vector<Sommet> sommet_;
    std::map<Sommet, std::vector<Arc>> graphe_;
};