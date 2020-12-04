#include "Automate.h"
#include <iostream>
#include <fstream>

using namespace std; 

bool Automate::creerLexique(const std::string fichierText){

    ifstream myFile;
    myFile.open(fichierText);
    string ligne;

    if (!myFile) //si le fichier n'existe pas
    {
        cerr << "Ne peut pas ouvrir ce fichier!";
        exit(1);
        return false;
    }
    else{

        while(!myFile.eof()){
            std::string mot;
            getline(myFile, mot); 
            creeAutomate(mot);
           
        }
        myFile.close();

        return true;
    }
    
}

void Automate::creeAutomate(const std::string& mot){

 
    Node * caractere =  new Node(mot[0]);

	for (int i = 0; i < mot.size(); i++)
	{
        
        auto it = std::find_if(automate_.begin(), automate_.end(), [&](const Node* node) {return node == caractere;});
        // if symbole  does not exist already we create a  new Node for it
		if(it == automate_.end())
		{
            automate_.push_back(caractere);

		}
         
        Node *prochainCaractere =  new Node(mot[i+1]);
        i == mot.size()-1? caractere->setEtatFinal(true): caractere->setNext(prochainCaractere);
        caractere = prochainCaractere;

	} 
}


 void Automate::creerVerif(const std::string& entree){
    Node* start =  findStart(entree)
    int count = 1;
    isGagner_ = false; 
    for (int i = 0; i < entree.size(); i++)
	{
        
        auto next = std::find_if(start->getNext().begin(), start->getNext().end(), [&](const Node* node) {return node ==  new Node(motSecret_[i]);});
        std::size_t index = std::distance<std::vector<const Node*>::const_iterator>(start->getNext().begin(), it);

        if(it != automate_.end())
		{
            count++; 
            start = const_cast<Node*>(start->getNext().at(index));

		}
        else{
            // on cherche si cela cree une boucle 
            if(start->getSymbole() == motSecret_[i]){
               count++;
            }
            // si la il n'y a pas de boucle on continue quand meme l'iteration vers la prochaine valeur 
            else{
                size_t increment =0;
                do{auto itRetstart = std::find_if(automate_.begin(), automate_.end(), [&](const  Node* node) {return node ==  new Node(motSecret_[i+incement]);});
                std::size_t indexRestart = std::distance(automate_.begin(), itRetstart);
                start = const_cast<Node*>(start->getNext().at(indexRestart));
                incrememnt++;
                }
                while(itRestart !=  automate_.end && increment < entree.size()-i;)
            }
        }
	} 

    if(count == entree.size() && start->getEtat()){

            cout << "felicitation tu a trouver le mot cacher";
            isGagner_ = true;
    }
    else{
             cout << "vous n'avez pas trouver le mot cacher" << endl;
             cout <<  "vous avez eu: " << count << " mot a la bonne place";
    }
 
    
} 



Node* Automate::findStart(const std::string& entree){
    bool findFirstLetter = false;
    size_t indexFirst = 0; 
    while(!findFirstLetter){
        char premierCaractere = entree[indexFirst]; 
        Node * start; 
        auto it = std::find_if(automate_.begin(), automate_.end(), [&](const  Node* node) {return node ==  new Node(premierCaractere);});
        std::size_t index = std::distance(automate_.begin(), it);
    
    	if(it != automate_.end())
		{
            start = automate_.at(index);
            findFirstLetter = true;
        }
        else{
            indexFirst++; 
        }
    }
    return start;

}
