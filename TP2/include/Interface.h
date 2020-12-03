#pragma once
#include "Automate.h"

class Interface
{
    public:
        enum MENU { INITIALISATION_DU_JEU = 0, PARTI_CONTRE_ORDINATEUR = 1, DEUX_JOUEURS = 2, QUITTER = 3 };
        void menu();
        
    private:
        void afficherMenu();
        MENU choixMenu();
        void initialiserJeu();
        void modeAuto();
        void modeVersus();
        const std::string& getEntreeUtilisateur(const std::string& entree);
        MENU optionUtilisateur();


        Automate automate_;
        bool isJeuInitialise_;
};