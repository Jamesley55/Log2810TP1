#include "Interface.h"
#include <iostream>
#include "Graphe.h"

using namespace std;

Interface::Interface() 
{
    graphe_ = Graphe();
}
void Interface::menu()
{

    graphe_.creerGraphe("/Users/stevendiep/Desktop/Log2810TP1/graphe.txt"); 
    graphe_.lireGraphe();

    char choix;
    string type_choisi;
    int autonomie_max;
    int autonomie_actuel;

    do{
        cout << "(a) " << "Demander les caractéristique du véhicule." << endl 
            << "(b) " << "Mettre à jour la carte." << endl
            << "(c) " << "Extraire un sous-graphe." <<  endl
            << "(d) " << "Determinerle plus court chemin." << endl
            << "(e) " << "Quiter" << endl;

            cin >> choix;

            if(choix == 'a')
            {
                cout << "Veuillez choisir le type de carburant: (rien, hybrid, electrique, essence) " << endl;
                cin >> type_choisi;
                
                cout << "Quel est l'autonomie maximal?: " << endl;
                cin >> autonomie_max;

                cout << "Quel est l'autonomie actuel?: " << endl;
                cin >> autonomie_actuel;
                
            }
            else if(choix == 'b')
            {
                //qque chose
            }            
            else if(choix == 'c')
            {
                //qque chose
            }
            else if(choix == 'd')
            {
                //qque chose
            }            
            else if(choix == 'e')
            {
                exit(1);
            }
            else
            {
                cout << "Vous n'avez pas entrer un index valide" << endl;
                cout << "Veuillez reessayer" << endl;
            }

    }while(choix != 'e'); 

}