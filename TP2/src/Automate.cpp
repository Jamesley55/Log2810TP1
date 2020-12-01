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

void Automate::creerVerif(){

    
}