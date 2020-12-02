#include "Automate.h"
#include <iostream>
#include <fstream>

using namespace std; 

void Automate::creerLexique(const std::string fichierText){

    ifstream myFile;
    myFile.open(fichierText);
    string ligne;

    if (!myFile) //si le fichier n'existe pas
    {
        cerr << "Ne peut pas ouvrir ce fichier!";
        exit(1);
    }
    else{

        while(!myFile.eof()){
            std::string tmp;
            getline(myFile, tmp); 
            dictionnaire_.push_back(tmp);
        }
        myFile.close();
    }
    
}

void Automate::creerVerif(std::vector<std::string> mot){
    etat_ = 0;
    int compteErreur = 0;

    switch(etat_){
        case 0:
            if (mot[0] == dictionnaire_[0]){
                etat_ = 1;
            }
            else{
                compteErreur++;
                for(int j = 0; j < dictionnaire_.size(); j++){
                    if(mot[0] == dictionnaire_[j]){
                        cout << "Lettre 1 est au mauvais endroit"
                    }
                }
            }
        case 1:        
    }
    
}