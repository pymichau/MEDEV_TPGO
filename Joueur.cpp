/*
 * File:   Joueur.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 15:18
 */

#include "Joueur.h"
//#include "Plateau.h"

#include <iostream>
#include <cstdlib>
using namespace std;

Joueur::Joueur(bool couleur) 
{
    m_couleur=couleur;
    m_nbPierreCapture=0;
    m_passe=false;
}

Joueur::Joueur(const Joueur& orig) {
}

Joueur::~Joueur() {
}

Pierre* Joueur::jouer(Plateau& goban)
{
    char abscisse('z');
    int ordonnee(0);
    Pierre* fincoup(NULL);
    m_passe=false;// on repasse le compteur de passe à false
    
    while (fincoup==NULL)
    {
        while (abscisse!='A' || abscisse!='B' || abscisse!='C' || abscisse!='D' || abscisse!='E' || abscisse!='F' || abscisse!='G' || abscisse!='H' || abscisse!='I' || abscisse!='J'..
                .. abscisse!='a' || abscisse!='b' || abscisse!='c' || abscisse!='d' || abscisse!='e' || abscisse!='f' || abscisse!='g' || abscisse!='h' || abscisse!='i' || abscisse!='j')
            {//la condition serait plus propre si je trouvais le moyen de dire abscisse "n'appartiens pas à l'ensemble"
                std::cout<<std::endl<<"Sur quelle colonne souhaitez-vous poser votre pierre ?"<<std::endl;
                std::cout<<"(indiquez une lettre de A à "<<goban.getSizeLettre()<<")"<<std::endl;
                std::cin<<abscisse;

                if (goban.getSize==5)//si l'utilisateur tape une lettre de G à J et que le tableau est de 5*5, la saisie est incorrecte, cette boucle permet d'en tenir compte
                   {
                        if (abscisse!='A' || abscisse!='B' || abscisse!='C' || abscisse!='D' || abscisse!='E' || abscisse!='F'..
                            ..|| abscisse!='a' || abscisse!='b' || abscisse!='c' || abscisse!='d' || abscisse!='e' || abscisse!='f')
                            {
                                abscisse='z';
                            }
                    }
            }
        while (ordonnee>9 || ordonnee=<1) // pour empêcher la saisie de donnees incorrectes
            {
                std::cout<<"Sur quelle ligne souhaitez-vous poser votre pierre ?"<<std::endl;
                std::cout<<"(indiquez un chiffre de 0 à "<<goban.getSize()<<")"<<std::endl;
                std::cin>>ordonnee;
            }

    // tester ici si le coup est valide -> test effectué dans la classe plateau
    //On transmet les données au plateau pour placer la pierre
    fincoup=goban->placerPierre(abscisse, ordonnee, m_couleur);
    //Si le coup est valide, goban renvoie un pointeur sur une pierre, sinon il renvoie NULL et on recommence la boucle
    }
    return fincoup;
}

void Joueur::passer()
{
    m_passe=true;
    ofstream fichier("HistoriquePartie.txt", ios::app);
                if (fichier)
                {
                    if (m_couleur==true)
                    {
                        fichier<<"Blanc "<<;
                    }
                    else
                    {
                        fichier<<"Noir ";
                    }
                    fichier<<"passe."<<endl;
                }
}

bool Joueur::getPasse()
{
    return m_passe;
}

void Joueur::setPrise(bool prise)
{
    m_prise=prise;
}

bool Joueur::getPrise()
{
    return m_prise;
}
void Joueur::capturePierre()
{
    m_nbPierreCapture=m_nbPierreCapture+1;
}