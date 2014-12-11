/* 
 * File:   Plateau.cpp
 * Author: eleve
 * 
 * Created on 1 décembre 2014, 16:53
 */

#include "Plateau.h"
#include "Groupe.h"
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
                m_listePierre.resize(55,'+');//on met un + dans les intersections vides, un X dans les cases avec une pierre noire et un O dans les cases avec une pierre blanche
                m_listePierreProvisoire.resize(55,'+');
                m_listePierrePrecedent.resize(55,'+');
                m_listePierrePrecedentPrecedent.resize(55,'+');
                break;
            case 9 :
                exit=true;
                m_listePierre.resize(99,'+');
                m_listePierreProvisoire.resize(99,'+');
                m_listePierrePrecedent.resize(99,'+');
                m_listePierrePrecedentPrecedent.resize(99,'+');
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
            return 'F';
            break;
        case 9 :
            return 'J';
            break;
    }
}
/*******placerPierre*******/
/*******C'est dans cette fonction qu'il faudrait introduire la verification d'un cas de ko je pense******/
Pierre* Plateau::placerPierre(char abscisse, int ordonnee, bool couleur)
{
    float position(0);
    Pierre* pointeurPierre(NULL);
    Groupe* pointeurGroupe;
    
    position=ordonnee*0.1;
    switch (abscisse)
    {
        case 'J' :
        case 'j' :            
                position++;
        case 'I':
        case 'i':
                position++;
        case 'h' :   
        case 'H':
                position++;
        case 'G':
        case 'g' :
                position++;
        case 'F':
        case 'f' :
                position++;
        case 'E':
        case 'e' :
                position++;
        case 'D':
        case 'd' :
                position++;
        case 'C':
        case 'c' :
                position++;
                //cout<<"test"<<endl;
        case 'B':
        case 'b' :
                position++;
        case 'A':
        case 'a' :
                break;
                //j=9, i=8, ... b=1, a=0
    }
    position=position*10;//jusqu'ici position était un réel de 0,0 à 9,9.
    //Il faut le passer de 11 à 99 pour pouvoir l'utiliser comme indice du tableau m_listePierre
    switch (m_listePierre[position])
    {
        case 'X' :
        case 'O' :
            cout<<"La case choisie n'est pas vide"<<endl;
            return pointeurPierre;
            break;
        case '+' :
            switch (couleur)
            {
                case true :
                    m_listePierreProvisoire[position]='X'; //on remplie le plateau
                    pointeurPierre=new Pierre(couleur, abscisse, ordonnee);
                    break;
                case false :
                    m_listePierreProvisoire[position]='O';
                    pointeurPierre=new Pierre(couleur, abscisse, ordonnee);
                    break;
                //On a créé une nouvelle pierre dans un plateau provisoire. 
                //Il faut modifier ce plateau en conséquence pour predre/retirer des groupes pour pouvoir tester le ko
            }
            //new Groupe (pointeurPierre, this);
            //finalement on crée le groupe ailleurs
            /*********vérification d'un cas de ko*********/
            if (m_listePierreProvisoire==m_listePierrePrecedent || m_listePierreProvisoire==m_listePierrePrecedentPrecedent)
            {
                cout<<"Coup invalide, vous engendrez un ko (plateau identique a un etat precedent)";
                m_listePierreProvisoire=m_listePierre;
                return NULL;
            }
            else
            {
                m_listePierrePrecedentPrecedent=m_listePierrePrecedent;
                m_listePierrePrecedent=m_listePierre;
                m_listePierre=m_listePierreProvisoire;
                return pointeurPierre;
            }
            break;
    }
}

/*******Afficher******/
void Plateau::afficher()
{
    int i(0);
    while (i<100)
    {
        //cout<<"and there";
        if (i==0)
        {
            switch (m_size)
            {
                    case 5 :
                        cout<<"  A    B    C    D    E    F"<<endl<<"0 ";
                        break;
                    case 9 :
                        cout<<"  A    B    C    D    E    F    G    H    I    J"<<endl<<"0 ";
                        break;
            }


        }
        cout<<m_listePierre[i];
        switch (m_size)
        {
            case 5 :
                switch (i)
                {
                    case 5 :
                    case 15 :
                    case 25 :
                    case 35 :
                    case 45 :
                        cout<<endl;
                        //on arrive au bout du plateau, on passe à la ligne suivante
                        cout<<"  |    |    |    |    |    |"<<endl<<((i-5)/10)+1<<" ";
                        i=i+4;
                        //on passe de la case 5 à la case 9 (qui ne sera pas affichée)
                        //puis à la fin de la boucle à la 10 (qui sera affichée)
                        break;
                    case 55 :
                        cout<<endl;
                        i=100;
                        //On a affiche la derniere case, on met i à 100 pour sortir de la boucle for
                        break;
                    default :
                        cout<<"----";
                        /*On place les pierres entre les cases, on devrait donc obtenir qqch du genre :
                           A----B----C----D----E----F
                         0 O----X----O----+----O----+
                           |    |    |    |    |    |
                         1 X----+----+----O----X----O
                           |    |    |    |    |    |
                         2 X----+----+----O----X----+
                           |    |    |    |    |    |
                         3 X----+----+----O----X----X
                           |    |    |    |    |    |
                         4 X----+----+----O----X----+
                           |    |    |    |    |    |
                         5 X----+----+----O----X----X*/
                }
                break;
            case 9 :
                switch (i)
                {
                    case 9 :
                    case 19 :
                    case 29 :
                    case 39 :
                    case 49 :
                    case 59 :
                    case 69 :
                    case 79 :
                    case 89 :
                        cout<<endl;
                        cout<<"  |    |    |    |    |    |    |    |    |    |"<<endl;
                        cout<<(i+1)/10<<" ";
                        //i++;
                        //on passe de la case 19 à la case 21
                        //EDIT : en fait un tableau de 9x9 cases possède 10x10 intersections
                        //Donc plus besoin de sauter des lignes
                        break;
                    case 99 :
                        cout<<endl;
                        break;
                    default :
                        cout<<"----";
                        break;
                }
        }
        i++;
    }
}

/*void Plateau::retirerPierre(Pierre& pierre)
{
    float position(0);
    position=pierre.getPosition()*10;//On récupère la position pour retrouver la case sur le plateau
}*/