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
    etat_ = 0;
    int compteErreur = 0;
    std::vector<std::string> mot;

    switch(etat_){
        case 0:
            cout << "Entrer votre reponse:"
            cin >> mot;

            if(mot == nullptr){
                cout << "ce mot ne peut pas etre utilise"
                etat_ = 0;
            }
            else{
                etat_ = 1;
            }
        case 1:
            for(int i = 0; i < dictionnaire_.size(); i++){}
                if (mot[i] == dictionnaire_[i]){
                    compteErreur++
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
    
}