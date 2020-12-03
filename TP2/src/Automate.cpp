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

/* void Automate::creerVerif(){
    etat_ = 0;
    int compteErreur = 0;
    std::vector<std::string> mot;

    switch(etat_){
        case 0:
            cout << "Entrer votre reponse:";
            cin >> mot;

            if(mot == nullptr){
                cout << "ce mot ne peut pas etre utilise";
                etat_ = 0;
            }
            else{
                etat_ = 1;
            }
        case 1:
            for(int i = 0; i < dictionnaire_.size(); i++){}
                if (mot[i] == dictionnaire_[i]){
                    compteErreur++;
                }
            }
            cout << "il y a " << compteErreur << "erreur";
            if(compteErreur == 0){
                etat_ = 2;
            }
            else{
                for(int i = 0; i < mot.size(); i++){
                    for(int j = 0; j < dictionnaire_.size(); j++){
                        if(i != j){
                            if(mot[i] == dictionnaire_[j]){
                            cout << "la lettre " << i - 1 << " est au mauvais endroit";        
                            }
                        }
                    }
                }
                etat_ = 0;
            }

        case 2:
            cout << "vous avez gagnez";

    }
    
} */
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


