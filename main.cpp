/* 
 * File:   main.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:05
 */
//#include "GoogleTest"
#include "include.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Plateau board;
    Joueur* black = new Joueur(false);
    Joueur* white = new Joueur(true);
    Joueur* current;
    Pierre* tempPierre;
    int i;
    bool verif;
    bool pierreCapturee;
    vector<Groupe*> vecteurGroupe; //utilisé apres la liste des groupes adjacents de couleur opposée au groupe testé
    Groupe* tempGroup;
    
    char answer;
    
    current = black; //black ones begin
    
    do  //game main cycle
    {
      
       
       cout<<"Passe?  (Y/N)"<<endl; //passe or not
       cin>>answer;
       if (answer=='Y') 
       {
           current->passer();
       }
       pierreCapturee = false;
       do {
       tempPierre = current->jouer(board); // play
       tempGroup  = new Groupe(tempPierre, &board, current);
       
       
       vecteurGroupe=tempGroup->presenceLiberteOppose(tempPierre);
       for (i=0; i<vecteurGroupe.size(); i++)
       {
           verif = vecteurGroupe[i]->verifierNbLiberte();
           if (verif==false)
           {
               for (int j=0; j<vecteurGroupe[i]->getListePierre().size(); j++)
               {
                   current->capturePierre();
               }
               vecteurGroupe[i]->~Groupe();
               pierreCapturee = true;
           }
               
       }
       
       tempGroup->fusion();
       
          }
       
       while (!pierreCapturee&&!tempGroup->verifierNbLiberte());
       
       if (current->getColor()==false) //switching the turn
       {
           current=white;
       }
       else
       {
           current=black;
       }
       
       board.afficher();    // showing the board
  
    } 
     
    while (!black->getPasse()&&!white->getPasse()); //game ends
    return 0;
}
