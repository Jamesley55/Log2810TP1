/*-----------------------------
Classe Node
Author: Steven Diep 2010339
        Jamesley Joseph 1990552
        Alex Hua 1994253
Date: 7 decembre 2020
------------------------------*/

#include "Node.h"

Node::Node() : symbole_(char(0)),
			   isEtatFinal_(false)
{
}

Node::Node(char symbole) : symbole_(symbole),
						   isEtatFinal_(false)
{
}

Node::Node(char symbole, bool isEtatFinal) : symbole_(symbole),
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

char Node::getSymbole() const
{
	return symbole_;
}

std::map<char, Node> &Node::getMe()
{
	return soisMeme_;
}

void Node::setEtatFinal(bool EtatFinal)
{
	isEtatFinal_ = EtatFinal;
}

void Node::setNext(const Node *next)
{
	next_.push_back(next);
}

Node *Node::getNext(char letter)
{

	
	for (auto next : next_)
	{
		if (next->getSymbole() == letter)
		{

			return const_cast<Node *>(next);
		}
	}
	return NULL;
}

bool Node::operator==(char letter)
{
	return symbole_ == letter;
}