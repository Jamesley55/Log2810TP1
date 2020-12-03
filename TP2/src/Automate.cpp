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


	for (const char& symbole: mot)
	{
		Node caractere = Node(symbole);
        
        // if symbole  already existe no need to create a new Node for it
		if(voisin_.find(caractere.getSymbole()) != voisin_.end())
		{
			if(symbole == mot.back())
				voisin_.find(caractere.getSymbole())->second.setEtatFinal(true);
		}
        // if symbole doe not existe we create a new one in the Automate
		else
		{
			if(symbole == mot.back())
				caractere.setEtatFinal(true);
			
			voisin_.insert({caractere.getSymbole(), caractere});
		}

	}
}


