#include "../include/Graphe.h"
#include <iostream>
#include <fstream>

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
        for (int i = 0; i < ligne1.size(); i++)
        {
            int virgule = ligne1.find(",", i);
            int pointVirgule = ligne1.find(";", i);

            string identifiant = ligne1.substr(i, virgule);

            string type = ligne1.substr(virgule + 1, pointVirgule);
            sommet_.push_back(Sommet(identifiant, type));

            i = pointVirgule;
        }
        for (int i = 0; i < ligne2.size(); i++)
        {
            int pointVirgule = ligne2.find(";", i);
            Sommet origine = TrouverSommet(ligne2.substr(i), sommet_);
            Sommet destination = TrouverSommet(ligne2.substr(i + 1), sommet_);
            int distance = stoi(ligne2.substr(i + 2));

            arc_.push_back(Arc(origine, destination, distance));
            i = pointVirgule;
        }
    }
}
