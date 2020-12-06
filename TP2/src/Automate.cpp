/*-----------------------------
Classe Automate
Author: Steven Diep 2010339
        Jamesley Joseph 1990552
        Alex Hua 1994253
Date: 7 decembre 2020
------------------------------*/

#include "Automate.h"
#include <iostream>
#include <fstream>

using namespace std;

bool Automate::creerLexique(const std::string fichierText)
{

    ifstream myFile;
    myFile.open(fichierText);
    string ligne;

    if (!myFile) //si le fichier n'existe pas
    {
        cerr << "Ne peut pas ouvrir ce fichier!";
        exit(1);
        return false;
    }
    else
    {
        while (!myFile.eof())
        {
            std::string mot;
            getline(myFile, mot);
            if (myFile.eof())
                break;
            mot.pop_back();
            creeAutomate(mot);
            dictionnaire_.push_back(mot);
        }

        myFile.close();

        return true;
    }
}

void Automate::creeAutomate(const std::string &mot)
{

    char caractere = mot[0];
    auto current = std::find_if(automate_.begin(), automate_.end(), [&](Node *node) { return node->operator==(caractere); });
    // if symbole  does not exist already we create a  new Node for it
    Node *currentNode = new Node(caractere);
    if (current == automate_.end())
    {
        automate_.push_back(currentNode);
    }

    for (size_t i = 1; i < mot.size(); ++i)
    {

        auto next = std::find_if(automate_.begin(), automate_.end(), [&](Node *node) { return node->operator==(mot[i]); });
        if (next == automate_.end())
        {

            Node *nextNode = new Node(mot[i]);
            currentNode->setNext(nextNode);
            currentNode = nextNode;
            automate_.push_back(nextNode);
            caractere = mot[i];
        }
        else
        {
            currentNode->setNext((*next));
            currentNode = (*next);
            caractere = mot[i];
        }
    }

    // mettre la derniere valeur comme un etat Finale.
    char back = mot[mot.size() - 1];
    auto it = std::find_if(automate_.begin(), automate_.end(), [&](Node *node) { return node->operator==(back); });
    (*it)->setEtatFinal(true);
}
void Automate::creerVerif(const std::string &entree)

{
    Node *start = Automate::findStart(entree);
    int count = 0;
    isGagner_ = false;

    std::size_t found = entree.find(start->getSymbole());

    for (int i = found; i < entree.size(); i++)
    {
        if (start->getSymbole() == motSecret_[i] && motSecret_[i] == entree[i])
        {

            count++;
            start = start;

            continue;
        }
        Node *next = start->getNext(motSecret_[i]);

        if (next != nullptr && motSecret_[i] == entree[i])
        {
            count++;
            start = next;
        }
        else
        {
            do
            {
                auto itRetstart = std::find_if(automate_.begin(), automate_.end(), [&](Node *node) { return node->operator==(motSecret_[i]); });
                std::size_t indexRestart = std::distance(automate_.begin(), itRetstart);
                if (itRetstart != automate_.end())
                {
                    start = const_cast<Node *>(automate_.at(indexRestart));
                    break;
                }
                else
                {
                    i++;
                }
            } while (i < entree.size());
        }
    }

    if (count == motSecret_.size() && start->getEtat())
    {
        cout << "felicitation tu as trouvé le mot cacher"<< endl;
        cout << endl;
        isGagner_ = true;
    }
    else 
    {
        cout << "vous n'avez pas trouvé le mot cacher" << endl;
        cout << "vous avez eu: " << count << " mot a la bonne place" << endl;
        cout << endl; 
    }
}

Node *Automate::findStart(const std::string &entree)
{
    bool findFirstLetter = false;
    size_t indexFirst = 0;
    Node *start = new Node();

    while (!findFirstLetter && indexFirst < entree.size())
    {
        char premierCaractere = entree[indexFirst];

        auto it = std::find_if(automate_.begin(), automate_.end(), [&](Node *node) { return node->operator==(entree[indexFirst]); });

        if (it != automate_.end())
        {
            start = (*it);
            findFirstLetter = true;
        }
        else
        {
            indexFirst++;
        }
    }
    return start;
}

std::vector<string> Automate::getDictionnaire()
{

    return dictionnaire_;
}

void Automate::setMotSecret(std::string motSecret)
{
    motSecret_ = motSecret;
}

bool Automate::partiGagner()
{
    return isGagner_;
}

std::vector<string> Automate::motSuggere(const std::string &motEntree)
{
    std::string motDictionnaire;
    std::vector<string> suggestion;
    size_t count = 0;

    for (int i = 0; i < dictionnaire_.size(); i++)
    {

        motDictionnaire = dictionnaire_[i];
        for (int j = 0; j < motEntree.size(); j++)
        {
            if (motDictionnaire[j] == motEntree[j])
            {
                count++;
            }
            else
            {
                // break ppur sortir de la boucle quand un mot n'est pas a la bonne place a la place de continuer la boucle
                break;
            }
        }
        if (count == motEntree.size())
        {
            suggestion.push_back(motDictionnaire);
        }
        count = 0;
    }
    return suggestion;
}

bool Automate::verifMotChoisi(std::string &motChoisi)
{
    for (int i = 0; i < dictionnaire_.size(); i++)
    {
        if (dictionnaire_[i].compare(motChoisi) ==0 )
        {
            return true;
        }
    }
    return false;
}