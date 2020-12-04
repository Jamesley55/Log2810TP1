
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
        void afficherLexique();
        std::string choisirMotAleatoire();
        std::map<char, Node>& getVoisin_();
        Node* findStart(const std::string &entree);


    private:
        std::vector<Node*> automate_;
        std::string motSecret_;
        bool isGagner_; 

};