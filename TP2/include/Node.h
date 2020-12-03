
#pragma once 
#include <map>
#include <iostream>
#include <memory>
#include <vector>

class Node {

    public:
        Node();
        Node(char symbole);
        Node(char symbole, bool isEtatFinal);
        Node(const Node& node);

		~Node(); 

        bool getEtat() const ;
        char getSymbole() const ;
        std::map<char,Node>& getMe();
        void setEtatFinal(bool EtatFinal);
        void setNext(const Node*  next);
        std::vector<const Node*>  getNext();


	private:
		bool isEtatFinal_;
		char symbole_;
        std::vector<const Node*> next_; 
		std::map<char, Node> soisMeme_;

};