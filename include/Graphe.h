#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Arc.h"
#include "Sommet.h"
#include "Voiture.h"
#include <map>


class Graphe
{

public:
    void creerGraphe(const std::string fichierText);
    void lireGraphe();
    Graphe extractionGraphe(); 

    size_t plusCourtChemin(Sommet origine, Sommet destination);

private:
    Sommet TrouverSommet(const std::string sommet, std::vector<Sommet> arraySommet);
    Voiture voiture_;
    std::vector<Arc> arc_;
    std::vector<Sommet> sommet_;
    std::map<Sommet, std::vector<Arc>> graphe_;
};