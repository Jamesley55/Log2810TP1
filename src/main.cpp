#include "Interface.h"

int main()
{

	Interface grapheInterface = Interface();
   //  grapheInterface.menu();

   Graphe graphe = Graphe(); 
   graphe.creerGraphe("/Users/jamesleyjoseph/School/A2020/Log2810/TD1/graphe.txt"); 
   graphe.lireGraphe();
    return 0;

	

}