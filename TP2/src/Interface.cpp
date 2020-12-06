#include "Interface.h"
#include <iostream>

using namespace std;

void Interface::afficherMenu()
{
    std::cout << "selectionner une option: " << std::endl
              << "(1) Initialisation du jeu" << std::endl
              << "(2) Partie contre l'ordinateur" << std::endl
              << "(3) Deux joueurs" << std::endl
              << "(4) Quitter" << std::endl;
    std::cout << endl;
}

void Interface::menu()
{
    Interface::MENU option;
    std::string nomLexique;

    do
    {
        option = optionUtilisateur();
        switch (option)
        {
        case Interface::INITIALISATION_DU_JEU:
            initialiserJeu();
            break;

        case Interface::PARTI_CONTRE_ORDINATEUR:
            modeAuto();
            break;

        case Interface::DEUX_JOUEURS:
            modeVersus();
            break;

        case Interface::QUITTER:
            std::cout << "Au revoir" << std::endl;
            break;

        default:
            std::cout << "Selectionner l'un des quatre options" << std::endl;
            break;
        }

    } while (option != Interface::QUITTER);
}

Interface::MENU Interface::optionUtilisateur()
{
    afficherMenu();
    bool optionSelectionner = false;
    int optionUtilisateur;
    while (!(cin >> optionUtilisateur))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "choisisez la valeur numerique  associer a votre choix: " << endl;
    }
    switch (optionUtilisateur)
    {
    case 1:
        optionSelectionner = true;
        return Interface::INITIALISATION_DU_JEU;
        break;
    case 2:
        optionSelectionner = true;
        return Interface::PARTI_CONTRE_ORDINATEUR;
        break;
    case 3:
        optionSelectionner = true;
        return Interface::DEUX_JOUEURS;
        break;
    case 4:
        optionSelectionner = true;
        return Interface::QUITTER;
        break;
    default:
        break;
    }
}
void Interface::initialiserJeu()
{
    string nomLexique;
    cout << "Entrer le nom de la lexique que vous voulez acceder" << endl;
    cin >> nomLexique;
    automate_.creerLexique(nomLexique);
    jeuxACommencer_ = true;
}

void Interface::modeAuto()
{

    if (jeuxACommencer_)
    {
        std::vector<string> dictionnaire = automate_.getDictionnaire();
        std::string motSecret = dictionnaire[rand() % dictionnaire.size()];
        automate_.setMotSecret(motSecret);
        cout << "Le nombre de lettre du mot est: " << motSecret.length() << endl;
        cout << endl;
        devinerMot(motSecret);
    }
    else
    {
        cout << "Initialiser le jeux avant de commencer a jouer";
    }
}

void Interface::modeVersus()
{
    if (jeuxACommencer_)
    {
        int confirm;
        std::string motChoisi;

        do
        {
            cout << "Quel code?" << endl;
            std::string choixInitial;

            cin >> choixInitial;
            //verifier que le mot existe ou donner des suggestions
            std::vector<string> suggestions = automate_.motSuggere(choixInitial);
            if (!suggestions.empty())
            {

                cout << "vos suggestion sont: " << endl;
            }
            cout << endl;
            for (string suggestion : suggestions)
            {
                cout << suggestion << endl;
            }
            cout << "choisisez un nouvezu mot secret d'apres les suggestion" << endl;
            cin >> motChoisi;
            //   cout << "test mot choisi: "  << motChoisi << " verfication: " << automate_.verifMotChoisi(motChoisi) << endl;
            if (automate_.verifMotChoisi(motChoisi))
            { // ca sort toujours false
                cout << "Voulez-vous s ́electionner ce code? (1:oui/0:non)" << endl;
                int confirmation;
                cin >> confirmation;
                if (confirmation == 1)
                {
                    confirm = 1;
                }
                else
                {
                    confirm = 0;
                }
            }

        } while (confirm != 1);

        // commence a jouer
        automate_.setMotSecret(motChoisi);
        cout << "Le nombre de lettre du mot est: " << motChoisi.length() << endl;
        cout << endl;
        devinerMot(motChoisi);
    }
    else
    {
        cout << "Initialiser le jeux avant de commencer a jouer";
        cout << endl;
    }
}
void Interface::devinerMot(std::string motSecret)
{

    int compteur = 0;
    std::string motJoueur;

    do
    {
        do
        {
            cout << "Entrée votre réponse:" << endl;
            cin >> motJoueur;
        } while (!isAlphabet(motJoueur));

        compteur++;
        cout << endl;
        cout << compteur << " tentative de faite " << endl;

        automate_.creerVerif(motJoueur);
    } while (automate_.partiGagner() == false && compteur <= 15);

    if (automate_.partiGagner() == false)
    {
        cout << "Vous avez faites 15 tentatives. Le mot secret est " << motSecret << endl;
        cout << endl;
    }
}

bool Interface::isAlphabet(std::string string)
{

    for (char letter : string)
    {
        if (letter <= 'A' && letter >= 'Z' || letter <= 'a' && letter >= 'z')
            return false;
    }
    return true;
}
