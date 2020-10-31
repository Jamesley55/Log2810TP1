#include <iostream>
#include <fstream>
#include "Graphe.h"
#include <math.h>

using namespace std;

Sommet Graphe::TrouverSommet(const string sommet, vector<Sommet> arraySommet)
{

    for (const Sommet &currentsommet : arraySommet)
    {
        if (sommet == currentsommet.getIdentifiant())
            return Sommet(sommet, currentsommet.getType());
    }

    return Sommet();
}

void Graphe::creerGraphe(const string fichierText)
{
    ifstream myFile;
    myFile.open(fichierText);
    string ligne1;
    string ligne2;
    vector<Sommet> arraySommet;

    if (!myFile)
    {
        cerr << "Ne peut pas ouvrir ce fichier!";
        exit(1);
    }
    else
    {
        getline(myFile, ligne1);
        getline(myFile, ligne2);
        for (size_t i = 0; i < ligne1.size(); i++)
        {
            std::size_t virgule = ligne1.find(",", i);
            std::size_t pointVirgule = ligne1.find(";", i);
            string identifiant = ligne1.substr(i, 1);
            string type = ligne1.substr(virgule + 1, pointVirgule - virgule - 1);

            sommet_.push_back(Sommet(identifiant, type));

            i = pointVirgule;
        }
        for (size_t i = 0; i < ligne2.size(); i++)
        {
            int pointVirgule = ligne2.find(";", i);
            Sommet origine = TrouverSommet(ligne2.substr(i, 1), sommet_);
            Sommet destination = TrouverSommet(ligne2.substr(i + 1, 1), sommet_);
            int distance = stoi(ligne2.substr(i + 2, 1));
            arc_.push_back(Arc(origine, destination, distance));
            i = pointVirgule;
        }
    }

    for (auto itSommet : sommet_)
    {
        vector<Arc> arcVoisin;
        for (auto itArc : arc_)
        {
            if (itArc.getOrigin().getIdentifiant() == itSommet.getIdentifiant())
            {
                arcVoisin.push_back(itArc);
            }
        }
        graphe_.insert(std::pair<Sommet, vector<Arc>>(itSommet, arcVoisin));
        arcVoisin.clear();
    }
}

void Graphe::lireGraphe()
{

    for (auto it = graphe_.begin(); it != graphe_.end(); ++it)
    {
        std::cout << "(" << it->first;

        if (it->second.size() != 0)
        {
            cout << "(";
            for (size_t i = 0; i < it->second.size(); i++)
            {
                std::cout << "station: " << it->second[i].getDestination().getIdentifiant() << ", ";
            }

            cout << ")";
        }
        cout
            << ")" << endl;
    }
    for (auto it = graphe_.begin(); it != graphe_.end(); ++it)
    {
        plusCourtChemin(it->second[1].getOrigin(), it->second[3].getOrigin());
    }
}

Sommet Graphe::sommetWithMinDistance(std::map<Sommet, informationSommmet> map) const
{
    size_t minimumDistance = INFINITY;
    Sommet Winner;

    for (auto it : map)
    {
        if (!it.second.visited && it.second.distance <= minimumDistance)
        {
            minimumDistance = it.second.distance;
            Winner = it.first;
        }
    }
    return Winner;
}
size_t Graphe::plusCourtChemin(const Sommet& origine, const Sommet&destination)
{
    std::map<Sommet, informationSommmet> station;

    for (const Sommet &sommet : sommet_)
    {
        station[sommet].distance = INFINITY;
        station[sommet].visited = false;
    }

    station[origine].distance = 0;


    for (size_t i = 0; i < sommet_.size(); i++)
    {
        Sommet minimizePathway = sommetWithMinDistance(station);
        station[minimizePathway].visited = true;
        for (auto arc : graphe_[minimizePathway])
        {
            if (!station[arc.getDestination()].visited && station[minimizePathway].distance + arc.getDistance() < station[arc.getDestination()].distance
            && station[minimizePathway].distance != INFINITY)
            {

                // Station D ou J ou A ou U
                station[arc.getDestination()].distance =
                    // distance entre station A et station D ou J ou A ou U
                arc.getDistance() +
                    // station B
                station[minimizePathway].distance;
            }
        }
    }
    for (auto it : station)
    {
        cout << "name: " << it.first.getIdentifiant() << " distance from origin: " << it.second.distance << endl;
    }
}

/*size_t Graphe::plusCourtChemin(Sommet origine, Sommet destination)
{
    int distance;
    int currentDistance;
    int currentArc;
    Sommet currentSommet;
    int totalDistance;


    //need to add if(voiture_.getType == graphe_.Sommet.type)
    for(auto it: graphe_){
        if (origine.getIdentifiant() == it.first.getIdentifiant()){
            for(size_t i =0; i < it.second.size(); i++){
                distance = it.second[i].getDistance();
                if(distance < currentDistance){
                    currentDistance = distance;
                    currentArc += it.second[i].getOrigin();
                }
            }
            totalDistance += currentDistance;                 
            if(destination == it.second[i])
                break;
            else{
                currentSommet = graphe_[it].Arc[i].destination;
            }
        }
    }   
}
*/