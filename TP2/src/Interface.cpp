#include "Interface.h"
#include <iostream>

using namespace std;


void Interface::menu()
{

    int choix;

    cout << endl
        << "(1) "
        << "Initialisation du jeu" << endl
        << "(2) "
        << "Partie contre l’ordinateur" << endl
        << "(3) "
        << "Deux joueurs" << endl
        << "(4) "
        << "Quitter" << endl;

        cin >> choix;

        if(choix == 1)
        {
            //Lire lexique afin de creer l'automate
        }
        else if(choix == 2)
        {
            //demarer le jeu v.s. ordi
        }
        else if(choix == 3)
        {
            //demarer le jeu v.s. joueur
        }
        else if(choix == 4)
        {
            exit(1);
        }
        else
        {
            cout << "Vous n'avez pas entré un choix valide!";
        }
}
