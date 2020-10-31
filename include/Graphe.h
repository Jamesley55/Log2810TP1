#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Arc.h"
#include "Sommet.h"
#include "Voiture.h"
#include <map>


struct informationSommmet{
    bool visited; 
    int distance; 
};

class Graphe
{

public:
    void creerGraphe(const std::string fichierText);
    void lireGraphe();
    Graphe extractionGraphe(); 


    size_t plusCourtChemin(const Sommet& origine, const Sommet&destination);

private:
    Sommet TrouverSommet(const std::string sommet, std::vector<Sommet> arraySommet);
    Sommet sommetWithMinDistance(std::map<Sommet, informationSommmet> map) const; 
    Voiture voiture_;
    std::vector<Arc> arc_;
    std::vector<Sommet> sommet_;
    std::map<Sommet, std::vector<Arc>> graphe_;
};