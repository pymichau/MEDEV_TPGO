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
                break;
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
/*******placerPierre*******/
/*******C'est dans cette fonction qu'il faudrait introduire la verification d'un cas de ko je pense******/
bool Plateau::placerPierre(char abscisse, int ordonnee, bool couleur)
{
    float position(0);
    
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
    position=position*10;//jusqu'ici position était un réel de 1,1 à 9,9.
    //Il faut le passer de 11 à 99 pour pouvoir l'utiliser comme indice du tableau m_listePierre
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

/*******Afficher******/
void Plateau::afficher()
{
    int i(0);
    for (i=0;i++;i<100)
    {
        cout<<"|"<<m_listePierre[i];
        switch (m_size)
        {
            case 5 :
                switch (i)
                {
                    case 15 :
                    case 25 :
                    case 35 :
                    case 45 :
                        cout<<"|"<<endl;
                        //le tableau n'aura pas de separateurs verticaux entre les lignes...
                        i=i+5;
                        //on passe de la case 15 à la case 21
                        break;
                    case 55 :
                        cout<<"|"<<endl;
                        i=100;
                        //On a affiche la derniere case, on met i à 100 pour sortir de la boucle for
                        break;
                }
                break;
            case 9 :
                switch (i)
                {
                    case 19 :
                    case 29 :
                    case 39 :
                    case 49 :
                    case 59 :
                    case 69 :
                    case 79 :
                    case 89 :
                    case 99 :
                        cout<<"|"<<endl;
                        i++;
                        //on passe de la case 19 à la case 21
                        break;
                }
        }
    }
}