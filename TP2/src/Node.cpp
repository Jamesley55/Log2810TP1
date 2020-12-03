#include "Node.h"

Node::Node(char symbole) :
	symbole_(symbole) ,
	isEtatFinal_(false)
{
}

Node::Node(char symbole, bool isEtatFinal) :
    symbole_(symbole) ,
    isEtatFinal_(isEtatFinal)
{
}

Node::~Node()
{
	symbole_ = char(0);
	isEtatFinal_ = false;
	voisin_.clear();
}

 bool Node::getEtat() const 
{
	return isEtatFinal_;
}

char Node::getSymbole() const 
{
	return symbole_;
}

std::map<char, Node>& Node::getVoisin()
{
	return voisin_;
}

void Node::setEtatFinal(bool EtatFinal)
{
	isEtatFinal_ = EtatFinal;
}