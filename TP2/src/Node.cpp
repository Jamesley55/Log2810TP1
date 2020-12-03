#include "Node.h"

Node::Node():
	symbole_(char(0)) ,
	isEtatFinal_(false)
{
}

Node::Node(char symbole):
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
	soisMeme_.clear();
}

 bool Node::getEtat() const 
{
	return isEtatFinal_;
}

char Node::getSymbole()  
{
	return symbole_;
}

std::map<char, Node>& Node::getMe()
{
	return soisMeme_;
}

void Node::setEtatFinal(bool EtatFinal)
{
	isEtatFinal_ = EtatFinal;
}


void Node::setNext(const Node* next){
	next_.push_back(next);
}

std::vector<const Node*> Node::getNext(){
return next_;
}


bool Node::operator==(Node& letter)
{
       return symbole_ == letter.symbole_; 
}