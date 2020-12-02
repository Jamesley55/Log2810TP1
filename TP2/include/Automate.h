
#include <vector>
#include<string>

class Automate {
    public:
        void creerLexique(const std::string fichierText);
        void creerVerif();
        void modeAuto(); 
        void modeVersus(); 
        enum Etat {0,1,2,3,4,5}

    private:
        std::vector<std::string> dictionnaire_;
        Etat etat_;
};