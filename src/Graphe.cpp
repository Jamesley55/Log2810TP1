#include <iostream>
#include <fstream>
#include "Graphe.h"
#include <math.h>

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

    plusCourtChemin(sommet_[1], sommet_[7]);

}

Sommet Graphe::sommetWithMinDistance(std::map<Sommet, informationStation> station)
{
    size_t minimumDistance = Infinity;
    Sommet Winner = Sommet();

    for (auto& it : station)
    {
        if (!it.second.visited && it.second.distance <= minimumDistance)
        {
            minimumDistance = it.second.distance;
            Winner = it.first;
        }
    }
    return Winner;
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

                // rajouter la station parent pour avoir un cree des lien entre la nouvelle station trouver
                // et la station qu'il doit prendre pour retourner vers l'origine dans une distance minimale
                station[arc.getDestination()].stationParent = arc.getOrigin();
            }
        }
    }
}

void Graphe::deplacerVoitureSurleGraphe(std::map<Sommet, informationStation>& station,  Sommet& origine,  Sommet& destination)
{

    cout << "1";
    // on utilise le stack grace a sa proprieter dernier arriver premier eliminer
    // alors lorsqu'on va  rajouter les station a partir de la destination
    // la derniere station rajouter serais la statiion origine
    // ensuite lorsque la voiture va voyager sur le map en utilisant le stack
    // il eliminera chaque station qu'il visite du stack a partir de l'origine jusqua la destination
    // tout en calculant l'autonomie de la voiture
    std::stack<Sommet> pathWay;

    // note: si on aurait voulu  utiliser un queue  on aurait changer la ligne :
    /** station[arc.getDestination()].stationParent = arc.getOrigin();  **/
    // de la fonction dijkstra par :
    /** station[arc.getOrigine()].prochaine Station = arc.getDestination();  **/

    Sommet currentStation = destination;
    cout << "1";

    // a partir de la destination on cherche la station parent qui a la plus petite distance de l'origine
   while (currentStation != origine)
    {
        // on rajoute cette station dans le stack jusqu'a arriver vers l'origine
        pathWay.push(currentStation);

        // on trouve la station parents jusqu'a arriver vers l'origine
        currentStation = station[currentStation].stationParent;
    }
    

    bool voitureFull;
    Sommet PointDeDepart = origine;
    if (!pathWay.empty())
        std::cout << PointDeDepart.getIdentifiant() << " -> ";
    while (!pathWay.empty())
    {
        Sommet destination = pathWay.top();
        pathWay.pop();

       // voitureFull = voiture_.deplacer(trouverArc(PointDeDepart, destination));
        PointDeDepart = destination;
        cout << "4";

        if (voitureFull)
            std::cout << destination.getIdentifiant();
        else
        {
            std::cout << " L'autonomie de votre vehicule ne permet pas d'aller plus loin. " << std::endl;
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
size_t Graphe::plusCourtChemin(Sommet& origine, Sommet& destination)
{

    std::map<Sommet, informationStation> station;

    for (auto& sommet : sommet_)
    {
        station[sommet].distance = Infinity;
        station[sommet].visited = false;
    }

    station[origine].distance = 0;

    // dijkstra's algorithm
    dijkstra(station);

    // faut changer cette fonction cause ca marche pas

    // verifie qu'il y a un chemin qui existe entre la pathway et l'origine
    // si il n'y a pas de  pathway alors la distance serais infinie
    cout << bool(station[destination].distance != Infinity) << "fini"<< endl;
    if ( station[destination].distance != Infinity)
    {
         deplacerVoitureSurleGraphe(station,origine,destination);
    }
    cout << endl;
    cout << "distance entre l'origine et la destination : " << station[destination].distance << endl;
    cout << endl;
    return station[destination].distance;
}
