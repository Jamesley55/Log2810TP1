
#pragma once 
#include <map>

class Node {

    public:
        Node(char symbole);
        Node(char symbole, bool isEtatFinal);
        Node(const Node& node);

		~Node(); 

        bool getEtat() const ;
       char getSymbole() const ;
        std::map<char,Node>& getVoisin();
        void setEtatFinal(bool EtatFinal);


	private:
		bool isEtatFinal_;
		char symbole_;
		std::map<char, Node> voisin_;

};