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
            int virgule = ligne1.find(",", i);
            int pointVirgule = ligne1.find(";", i);

            string identifiant = ligne1.substr(i, virgule);

            string type = ligne1.substr(virgule + 1, pointVirgule);
            sommet_.push_back(Sommet(identifiant, type));

            i = pointVirgule;
        }
        for (size_t i = 0; i < ligne2.size(); i++)
        {
            int pointVirgule = ligne2.find(";", i);
            Sommet origine = TrouverSommet(ligne2.substr(i), sommet_);
            Sommet destination = TrouverSommet(ligne2.substr(i + 1), sommet_);
            int distance = stoi(ligne2.substr(i + 2));

            arc_.push_back(Arc(origine, destination, distance));
            i = pointVirgule;
        }
    }

    for (auto itSommet : sommet_)
    {
        vector<Arc> arcVoisin;
        for( auto itArc : arc_){
            if(itArc.getOrigin().getIdentifiant() == itSommet.getIdentifiant()){
                arcVoisin.push_back(itArc);
            }
        }
        graphe_[itSommet] = arcVoisin;
        arcVoisin.clear();
    }
}


void Graphe::lireGraphe()
{
    
    for (auto it : graphe_)
    {
        std::cout << "(" << it.first.getIdentifiant()  << it.first.getType()<< ", (";

        for (size_t i = 0; i < it.second.size(); i++)
        {
            std::cout <<"rentre dans fonction" << endl; 
            std::cout << "second" << it.second[i].getOrigin().getIdentifiant();
        
            if (i != it.second.size() - 1)
            {
                std::cout << ", ";
            }
            else 
			{
                std::cout << ")";
            }
        }
        std::cout << ")" << std::endl;
    } 

    cout << endl;
    
}

/*size_t Graphe::plusCourtChemin(Sommet origine, Sommet destination)
{
    int distance;
    int CurrentDistance = 100;
    int TotalDistance;
    int CurrentSommet =  origine;
    int CurrentArc;

    //need to add if(voiture_.getType == graphe_.Sommet.type)
    for(auto it: graphe_){
        if (origine == graphe_.Sommet){
            for(auto it: graphe_.Arc){
                distance = graphe_.Arc.distance;
                if(distance < CurrentDistance){
                    CurrentDistance = distance;
                    CurrentArc += graphe_.Arc;
                }
            }
            TotalDistance += CurrentDistance;                 
            if(destination == graphe_.Arc.destination)
                break;
            else{
                CurrentSommet = graphe_Arc.destination;
            }
        }
    }
}
*/