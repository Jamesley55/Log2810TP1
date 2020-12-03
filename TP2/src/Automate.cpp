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

	} 
}


 void Automate::creerVerif(const std::string& entree){
    
} 

