
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
        std::map<char, Node>& getVoisin_() ;

    private:
        std::vector<Node> automate_;

};