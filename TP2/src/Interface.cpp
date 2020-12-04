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
               //  initialiserJeu();
                break;

            case Interface::PARTI_CONTRE_ORDINATEUR:
                // modeAuto();
                break;

            case Interface::DEUX_JOUEURS:
               //  modeVersus();
                break;

            case Interface::QUITTER:
                std::cout << "Au revoir" << std::endl;
                break;

            default:
                std::cout << "Selection l'un des quatre option" << std::endl;
                break;
                
        }

    } while (option != Interface::QUITTER); 
    cout << "hello world";
}



void Interface::initialiserJeu()
{
   /* std::string nomLexique;
    do
    {
        nomLexique = getEntreeUtilisateur("Veuillez saisir le nom du lexique: ");
    } while (!automate_.creerLexique(nomLexique));

    isJeuInitialise_ = true;

    */

   string nomLexique;

   cout << "Quelle lexique voulez vous choisir?: (Lexique_1.txt, Lexique_2.txt, Lexique_3.txt) " << endl
   cin >> nomLexique;

   creerLexique(nomLexique);

}

void Interface::modeAuto(){

    int compteur = 0;

    std::string motSecret_ = automate_[rand() % automate_.size()];

    cout << "Le nombre de lettre du mot est: " + motSecret_.length() << end;

    do{
        do{
            cout << "Entrée votre réponse:";
            std::string motJoueur;
            cin >> motJoueur;
        } 
        while(motJoueur.length() != motSecret_.length()) //faut aussi check que c'est juste des lettres //okok

        compteur++;
        cout << compteur << "essaie de faite";
        
        creerVerif(motJoueur);
    }while(isGagner_ = false && count <= 15)

    if(isGagner == false)
    {
        cout << "Vous avez faites 15 tentatives. Le mot secret est " + motSecret_;
    }
}     

void Interface::modeVersus(){

    int confirm;
    int compteur = 0;
    string motChoisi;

    do{
        cout << "Quel code?" << endl;
        cin >> motChoisi;
        //verifier que le mot existe ou donner des suggestions

    }
    while(confirm != 1)

    //steven, je comprend pas comment on va faire avec 2 utilisateur, comme 2 terminal
    //cuz la le probleme
}