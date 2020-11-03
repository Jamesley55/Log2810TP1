#include <iostream>
#include <fstream>
#include "Graphe.h"
#include <math.h>
#include <queue>

using namespace std;
#define Infinity 2147483647

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
}

size_t Graphe::plusCourtChemin(Sommet &origine, Sommet &destination)
{

    std::map<Sommet, informationStation> station;

    for (auto &sommet : sommet_)
    {
        station[sommet].distance = Infinity;
        station[sommet].visited = false;
    }

    station[origine].distance = 0;

    // dijkstra's algorithm
    dijkstra(station);

    // verifie qu'il y a un chemin qui existe entre la pathway et l'origine
    // si il n'y a pas de  pathway alors la distance serais infinie
    if (station[destination].distance != Infinity)
    {
        // on deplace la voiture sur le graphe jusqu'a arriver a la destination
        // cette fonction permet de controller l'autonomie de la voiture
        // et determiner si on peut arriver a destination
        deplacerVoitureSurleGraphe(station, origine, destination);
    }
    return station[destination].distance;
}

void Graphe::dijkstra(std::map<Sommet, informationStation> &station)
{

    for (size_t i = 0; i < sommet_.size(); i++)
    {
        // cherche la distance minimale entre les station de l'ensemble des station voisin non visiter
        Sommet minimizePathway = sommetWithMinDistance(station);

        station[minimizePathway].visited = true;

        // trouve tout les arcs de cette station voisin avec la distance minimale
        for (auto &arc : graphe_[minimizePathway])
        {

            if (!station[arc.getDestination()].visited &&
                station[minimizePathway].distance != Infinity &&
                // on cherche si le chemin trouver est plus petit que le chemin trouve  dans l'iteration precedent pour cette meme destination
                station[minimizePathway].distance + arc.getDistance() < station[arc.getDestination()].distance)
            {
                // si la destination pointer par l'arc n'est pas encore visiter alors la nouvelle distance
                // de la destination a partir de l'origin serais la longeur de l'arc et la distance minimale de la station precedent a partir de l'origine
                station[arc.getDestination()].distance = arc.getDistance() + station[minimizePathway].distance;

                station[arc.getDestination()].closestStation = arc.getOrigin();
            }
        }
    }
}

Sommet Graphe::sommetWithMinDistance(std::map<Sommet, informationStation> station)
{
    size_t minimumDistance = Infinity;
    Sommet Winner = Sommet();

    for (auto &it : station)
    {
        if (!it.second.visited && it.second.distance <= minimumDistance)
        {
            minimumDistance = it.second.distance;
            Winner = it.first;
        }
    }
    return Winner;
}

void Graphe::deplacerVoitureSurleGraphe(std::map<Sommet, informationStation> &station, Sommet &origine, Sommet &destination)
{
    std::stack<Sommet> pathWay;
    Sommet currentStation = destination;
    // a partir de l'origine on cherche la station la plus proche et on le rajoute dans le queue
   do
    {
        // on rajoute cette station dans le queue jusqu'a arriver vers la destination
        cout << "Origine station" << currentStation << endl;

        pathWay.push(currentStation);
        // on trouve la station la plus proche pour la prochaine0 iteration jusqu'a arriver vers la destination
        currentStation = station[currentStation].closestStation;
        cout << currentStation << endl; 
    } while (currentStation.getIdentifiant() != origine.getIdentifiant());
  
    bool voitureFull;
    Sommet PointDeDepart = origine;
   

    if (!pathWay.empty())
        std::cout << PointDeDepart.getIdentifiant() << " -> ";
    while (!pathWay.empty())
    {
        Sommet currentStationVoiture = pathWay.top();
        pathWay.pop();
        voitureFull = voiture_.deplacer(trouverArc(PointDeDepart, currentStationVoiture));
        PointDeDepart = currentStationVoiture;
        if (voitureFull)
            std::cout << currentStationVoiture.getIdentifiant();
        else
        {
            std::cout << "vous ne pouvez plus vous deplacer " << std::endl;
            break;
        }

        if (!pathWay.empty())
            std::cout << " -> ";
    }

    std::cout << std::endl;
}
Arc Graphe::trouverArc(const Sommet &origine, const Sommet &destination) const
{
    for (Arc arc : graphe_.at(origine))
    {
        if (arc.getDestination() == destination)
            return arc;
    }

    return Arc();
}

bool Graphe::sommetInGraphe(const std::string &SommetToFind)
{
    for (const Sommet &sommet : sommet_)
        if (sommet.getIdentifiant() == SommetToFind)
            return true;
    return false;
}

Sommet Graphe::trouverSommet(const std::string &SommetToFind)
{
    for (const Sommet &sommet : sommet_)
        if (sommet.getIdentifiant() == SommetToFind)
            return sommet;
    return Sommet();
}

void Graphe::Clear()
{
    arc_.clear();
    sommet_.clear();
    graphe_.clear();
}


void Graphe::VoiturePropriety(Constante::Type typeDessence, const int autonomieMaximale, const double autonomieActuelle, const double coefficientDePerte)
{

    voiture_ = Voiture(typeDessence, autonomieMaximale, autonomieActuelle, coefficientDePerte);
}

Voiture Graphe::getVoiture()
{
    return voiture_;
}