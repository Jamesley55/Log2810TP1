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

    graphe_.creerGraphe("graphe.txt"); 
    graphe_.lireGraphe();


    char choix;
    string type_choisi;
    int autonomie_max;
    int autonomie_actuel;
    string nom_fichier;
    Sommet origine;
    Sommet destination;

    do{
        cout << endl << "(a) " << "Demander les caractéristique du véhicule." << endl 
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
                cout << "Veuillez entrer le nom du fichier: " << endl;
                cin >> nom_fichier;
                //creer et affiche le nouveau graphe 
                graphe_.creerGraphe(nom_fichier); 
                graphe_.lireGraphe();
            }            
            else if(choix == 'c')
            {
                if(type_choisi == "") //Si le user choisi option e avant option a
                {
                    cout << "Vous avez choisi l'option c avant l'otion a!" << endl;
                }
                else
                {
                    //Extraction sous graphe  
                }
            }
            else if(choix == 'd')
            {
                //Plus court chemin
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

    }while(choix != 'e'); //afficher le menu tant que option e n'est pas choisi

}