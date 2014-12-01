/* 
 * File:   Plateau.cpp
 * Author: eleve
 * 
 * Created on 1 décembre 2014, 16:53
 */

#include "Plateau.h"
#include "Joueur.h"
#include "Pierre.h"

#include <iostream>
#include <cstdlib>
using namespace std;

Plateau::Plateau() 
{
    bool exit(false);
    while (exit==false)
    {
        cout<<"Choisissez la taille du plateau de jeu : soit 5 cases de cote, soit 9 cases de cote."<<endl;
        cin>>m_size;
        switch (m_size)
        {
            case 5 :
                exit=true;
                m_listePierre.resize(55,'.');//on met un point dans les cases vides, un X dans les cases avec une pierre noire et un O dans les cases avec une pierre blanche
                break
            case 9 :
                exit=true;
                m_listePierre.resize(99,'.');
                break;
            default :
                cout<<"Saisie incorrecte. Entrez le nombre de case de coté du plateau avec les touches du pave numerique."<<endl;
                exit=false;
                break;
        }
    }
}

Plateau::Plateau(const Plateau& orig) {
}

Plateau::~Plateau() {
}

int Plateau::getSize()
{
    return m_size;
}
char Plateau::getSizeLettre()
{
    switch (m_size)
    {
        case 5 :
            return 'e';
            break;
        case 9 :
            return 'i';
            break;
    }
}

bool Plateau::placerPierre(char abscisse, int ordonnee, bool couleur)
{
    int position(0);
    
    position=ordonnee*0.1;
    switch (abscisse)
    {
            case'i':
                position++;
            case 'h':
                position++;
            case 'g':
                position++;
            case 'f':
                position++;
            case 'e':
                position++;
            case 'd':
                position++;
            case 'c':
                position++;
            case 'b':
                position++;
            case 'a':
                position++;
                break;
    }
    switch (m_listePierre[position])
    {
        case 'X' :
        case 'O' :
            cout<<"La case choisie n'est pas vide"<<endl;
            return false;
            break;
        case '.' :
            return true;
            switch (couleur)
            {
                case true :
                    m_listePierre[position]='X';
                    break;
                case false :
                    m_listePierre[position]='O';
                    break;
            }
            break;
    }
}