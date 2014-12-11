/* 
 * File:   main.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:05
 */
#include "GoogleTest"
#include <cstdlib>
#include "Plateau.h"
#include "Groupe.h"
#include "Joueur.h"
#include "Pierre.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Plateau* board = new Plateau;
    Joueur black = new Joueur;
    Joueur white = new Joueur;
    Joueur current = new Joueur;
    Pierre* tempPierre = new Pierre
    int i;
    bool verif;
    
    
    char answer;
    
    current = black; //black ones begin
    
    do  //game main cycle
    {
      
       
       cout<<"Passe?  (Y/N)"<<endl; //passe or not
       cin<<answer;
       if (answer=='Y') 
       {
           current.passer()
       };
       
       do {
       tempPierre = current.jouer(board); // play
       Groupe* tempGroup  = new Groupe(tempPierre);
       
       
       tempGroup.presenceLiberteOppose(tempPierre);
       for (i = tempGroup.begin; i!= tempGroup.end; i++)
       {
           verif=verifierNbLiberte(tempGroup.i);
           if (verif==false)
               (~tempGroup.i);
       }
       
       tempGroup->fusion();
       
          }
       
       while (!current.getPierre()&&!tempGroup.verifierNbLiberte);
       
       if (current==black) //switching the turn
       {
           current=white
       }  
       else
       {
           current=black
       };
       
       board->afficher();    // showing the board
  
    } 
     
    while (!black.getPasse()&&!white.getPasse()); //game ends
    return 0;
}
