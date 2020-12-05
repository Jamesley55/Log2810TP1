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
    char back = mot[mot.size() - 2];
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
        cout << "felicitation tu as trouvé le mot cacher";
        isGagner_ = true;
    }
    else
    {
        cout << "vous n'avez pas trouvé le mot cacher" << endl;
        cout << "vous avez eu: " << count << " mot a la bonne place" << endl;
    }
}

Node *Automate::findStart(const std::string &entree)
{
    bool findFirstLetter = false;
    size_t indexFirst = 0;
    Node *start;

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


std::vector<string> Automate::getDictionnaire(){

    return dictionnaire_; 
}

void Automate::setMotSecret(std::string motSecret){
  motSecret_ = motSecret;
}

bool Automate::partiGagner(){
 return isGagner_;
}