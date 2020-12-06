/*-----------------------------
Classe Interface
Author: Steven Diep 2010339
        Jamesley Joseph 1990552
        Alex Hua 1994253
Date: 7 decembre 2020
------------------------------*/

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
        void devinerMot(std::string motSecret);
        bool isAlphabet(std::string string);


        Automate automate_;
        bool isJeuInitialise_;
        bool jeuxACommencer_;
};