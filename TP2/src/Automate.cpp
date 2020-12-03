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
        
        auto it = std::find(automate_.begin(), automate_.end(), caractere->getSymbole() );
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
    char premierCaractere = entree[0]; 
    Node * start; 
     
    auto it = std::find_if(automate_.begin(), automate_.end(), [=](const Node& node) {return node.getSymbole() == premierCaractere;});
    std::size_t index = std::distance(automate_.begin(), it);
    
    	if(it == automate_.end())
		{
            cout << "you have zero letter right";
            cout << "try again";

		}
        else{
            start = automate_.at(index);
        }

    
    int count = 1; 
    for (int i = 0; i < entree.size(); i++)
	{
        
        auto next = std::find_if(start->getNext().begin(), start->getNext().end(), [=](const Node& node) {return node.getSymbole() == motSecret_[i];});
        std::size_t index = std::distance(start->getNext().begin(), it);

        if(it != automate_.end())
		{
            count++; 
            start = start->getNext().at(index);


		}
        else{
            start = start->getNext()[0];
        }

        if(count == entree.size() && start->getNext().at(index)->getEtat()){

            cout << "felicitation tu a trouver le mot cacher"
        }
        else{
             cout << "vous n'avez pas trouver le mot cacher" << endl;
             cout <<  "vous avez eu: " << count << " mot a la bonne place"
        }
	} 
    
    
} 

