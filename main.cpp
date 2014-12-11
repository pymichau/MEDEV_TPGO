/* 
 * File:   main.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 10:05
 */

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
    char answer;
    
    current = black; //black ones begin
    
    do  //game main cycle
    {
       current.jouer(board); // play
       
       cout<<"Passe?  (Y/N)"<<endl; //passe or not
       cin<<answer;
       if (answer=='Y') 
       {
           current.passer()
       };
       
        
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
