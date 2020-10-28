#include "Interface.h"
#include <iostream>

using namespace std;

void menu()
{
    do{
        cout << "(a) " << "Demander les caractéristique du véhicule." << endl 
            << "(b) " << "Mettre à jour la carte." << endl
            << "(c) " << "Extraire un sous-graphe." <<  endl
            << "(d) " << "Determinerle plus court chemin." << endl
            << "(e) " << "Quiter" << endl;

            char choix;
            cin >> choix;

            switch(choix)
            {
                case 'a':

                    string type_choisi;
                    int autonomie_max;
                    int autonomie_actuel;

                    cout << "Veuillez choisir le type de carburant: (rien, hybrid, electrique, essence) " << endl;
                    cin >> type_choisi;

                    cout << "Quel est l'autonomie maximal?: " << endl;
                    cin >> autonomie_max;

                    cout << "Quel est l'autonomie actuel?: " << endl;
                    cin >> autonomie_actuel;

                case 'b':
                    //faire qque chose
                case 'c':                
                    //faire qque chose
                case 'd':
                    //faire qque chose
                case 'e':
                    //faire qque chose

            }
    }while(choix != 'e');

}