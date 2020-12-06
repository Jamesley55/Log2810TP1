/*-----------------------------
Classe Automate
Author: Steven Diep 2010339
        Jamesley Joseph 1990552
        Alex Hua 1994253
Date: 7 decembre 2020
------------------------------*/

#include <vector>
#include<string>
#include <map>
#include <algorithm>    
#include "Node.h"

class Automate {
    public:
        bool creerLexique(const std::string fichierText);
        void creeAutomate(const std::string& mot);
        void creerVerif(const std::string& entree);
        void setMotSecret(std::string motSecret);
        void afficherLexique();
        std::string choisirMotAleatoire();
        std::map<char, Node>& getVoisin_();
        Node* findStart(const std::string &entree);
        std::vector<std::string> getDictionnaire(); 
        bool partiGagner();
        std::vector<std::string> motSuggere(const std::string &motEntree);
        bool verifMotChoisi(std::string &motChoisi);


    private:
        std::vector<Node*> automate_;
        std::vector<std::string> dictionnaire_;
        std::string motSecret_;
        bool isGagner_; 

};