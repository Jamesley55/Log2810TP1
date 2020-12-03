#include "Interface.h"
#include <iostream>

using namespace std;

void Interface::afficherMenu()
{
    std::cout << "selectionner une option: " << std::endl
              << "(1) Initialisation du jeu" << std::endl
              << "(2) Partie contre l'ordinateur" << std::endl
              << "(3) Deux joueurs" << std::endl
              << "(4) Quitter" << std::endl;
}


void Interface::menu()
{
    Interface::MENU option;
    std::string nomLexique;

    do
    {
        afficherMenu();
        option = optionUtilisateur();

        switch (option)
        {
            case Interface::INITIALISATION_DU_JEU:
                initialiserJeu();
                break;

            case Interface::PARTI_CONTRE_ORDINATEUR:
                modeAuto();
                break;

            case Interface::DEUX_JOUEURS:
                modeVersus();
                break;

            case Interface::QUITTER:
                std::cout << "au revoir" << std::endl;
                break;

            default:
                std::cout << "selection l'un des quatre option" << std::endl;
                break;
        }

    } while (option != Interface::QUITTER);
}



void Interface::initialiserJeu()
{
    std::string nomLexique;
    do
    {
        nomLexique = getEntreeUtilisateur("Veuillez saisir le nom du lexique: ");
    } while (!automate_.creerLexique(nomLexique));

    isJeuInitialise_ = true;
}


