
#include <vector>
#include<string>

class Automate {
    public:
        void creerLexique(const std::string fichierText);
        void creerVerif();
        void modeAuto(); 
        void modeVersus(); 

    private:
        std::vector<std::string> dictionnaire_; 
};