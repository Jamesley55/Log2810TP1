#include "Interface.h"
#include <iostream>
#include "Graphe.h"
#include <stack>

using namespace std;
#define Infinity 2147483647

Interface::Interface()
{
    graphe_ = Graphe();
}
void Interface::menu()
{

    graphe_.creerGraphe("graphe.txt");
    graphe_.lireGraphe();

    /* ---- Initiation des variables -----*/
    char choix;

    string type_choisi;
    int autonomie_max;
    int autonomie_actuel;
    double coefficientDePerte;

    string nom_fichier;

    Sommet origine;
    Sommet destination;
    string origine_identifiant;
    string origine_type;
    string destination_identifiant;
    string destination_type;
    /*---------------------*/

    bool voitureACaracteristique = false;

    do
    {
        cout << endl
             << "(a) "
             << "Demander les caractéristique du véhicule." << endl
             << "(b) "
             << "Mettre à jour la carte." << endl
             << "(c) "
             << "Extraire un sous-graphe." << endl
             << "(d) "
             << "Determinerle plus court chemin." << endl
             << "(e) "
             << "Quiter" << endl;

        cin >> choix;

        if (choix == 'a') //demander les caracteristique de la voiture
        {
            cout << "Veuillez choisir le type de carburant: (rien, hybrid, electrique, essence) " << endl;
            cin >> type_choisi;

            cout << "Quel est l'autonomie maximal?: " << endl;
            cin >> autonomie_max;

            cout << "Quel est l'autonomie actuel?: " << endl;
            cin >> autonomie_actuel;

            cout << "Quel est le coeficient de pertre de la voiture?: " << endl;
            cin >> coefficientDePerte;

            graphe_.VoiturePropriety(getTypeEnum(type_choisi), autonomie_max, autonomie_actuel, coefficientDePerte);
            voitureACaracteristique = true;
        }
        else if (choix == 'b') //afficher le nouveau graphe
        {
            cout << "Veuillez entrer le nom du fichier: " << endl;
            cin >> nom_fichier;
            graphe_.Clear(); //clear l'ancien graphe pour le nouveau
            graphe_.creerGraphe(nom_fichier);
            graphe_.lireGraphe();
        }
        else if (choix == 'c') //extraction d'un sous-graphe
        {
            if (!voitureACaracteristique) //Si le user choisi option e avant option a
            {
                cout << "Vous avez choisi l'option c avant l'otion a!" << endl;
            }
            else
            {
                cout << "Quel est l'identifiant de l'origine?: " << endl;
                cin >> origine_identifiant;
                Constante::Type type = getTypeEnum(type_choisi);
                graphe_.VoiturePropriety(type,autonomie_max,autonomie_actuel,coefficientDePerte);
                Sommet sommet = graphe_.trouverSommet(origine_identifiant);
                Voiture voiture = graphe_.getVoiture();
                std::vector<Arc>  sousGraphe = graphe_.extractionGraphe(sommet, voiture);
                std::stack<Arc> affichageGraphe;
                  for(auto & arc: sousGraphe){
                    
                    affichageGraphe.push(arc);
                }
                cout << "sous-graphe: " << endl; 
                while(!affichageGraphe.empty()){
                    cout << "-->" << affichageGraphe.top().getOrigin().getIdentifiant();  
                    affichageGraphe.pop();
                }              
                cout << endl;
            }
        }
        else if (choix == 'd') //trouver le plus court chemin
        {
            if (!voitureACaracteristique)
            {
                std::cout << "Veuilliez choisir l'option a avant de continuer" << std::endl;
            }
            else
            {
                std::string sommetDepart, sommetDestination;

                do
                {
                    cout << "Quel est l'identifiant de l'origine?: " << endl;
                    cin >> origine_identifiant;

                    cout << "Quel est l'identifiant de la destination?: " << endl;
                    cin >> destination_identifiant;
                } while (!graphe_.sommetInGraphe(origine_identifiant) || !graphe_.sommetInGraphe(destination_identifiant));
                Sommet origine = graphe_.trouverSommet(origine_identifiant);
                Sommet destination = graphe_.trouverSommet(destination_identifiant);
                size_t distance = graphe_.plusCourtChemin(origine, destination);
                if (distance != Infinity)
                {
                    std::cout << "Le chemin le plus court est de " << distance << " kilometre" << std::endl;
                    std::cout << "L'autonomie restante du vehicule est de " << graphe_.getVoiture().getAutonomieActuelle() << " km" << std::endl;
                    std::cout << "L'autonomie restante du vehicule est de " << graphe_.getVoiture().getAutonomiePourcentage() << "%" << std::endl;
                }
                else
                    std::cout << "Vous ne pourriez pas atteindre votre destination" << std::endl;
            }
        }
        else if (choix == 'e')
        {
            exit(1);
        }
        else
        {
            //Si l'usager entre un index invalide
            cout << "Vous n'avez pas entrer un index valide" << endl;
            cout << "Veuillez reessayer" << endl;
        }

    } while (choix != 'e'); //afficher le menu tant que option e n'est pas choisi
}

Constante::Type Interface::getTypeEnum(string type)
{

    if (type == "hybrid")
    {
        return Constante::Type::Hybride;
    }
    else if (type == "electrique")
    {
        return Constante::Type::Electrique;
    }
    else if (type == "essence")
    {
        return Constante::Type::Essence;
    }
    else
    {
        return Constante::Type::Rien;
    }
}


