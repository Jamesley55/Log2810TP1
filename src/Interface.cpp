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

    //Initiation des variables
    char choix;

    string type_choisi;
    int autonomie_max;
    int autonomie_actuel;
    
    string nom_fichier;

    Sommet origine;
    Sommet destination;
    string origine_identifiant;
    string origine_type;
    string destination_identifiant;
    string destination_type;
    /*---------------------*/


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
                cout << "Quel est l'identifiant de l'origine?: " << endl;
                cin >> origine_identifiant;
                cout << "Quel est le type de l'origine?: " << endl;
                cin >> origine_type;

                cout << "Quel est l'identifiant de la destination?: " << endl;
                cin >> destination_identifiant;
                cout << "Quel est le type de la destination: " << endl;
                cin >> destination_type;

                origine = Sommet(origine_identifiant,origine_type);
                destination = Sommet(destination_identifiant,destination_type);

                //graphe_.plusCourtChemin(origine, destination);

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