/*
 * File:   Joueur.cpp
 * Author: eleve
 *
 * Created on 1 décembre 2014, 15:18
 */

#include "Joueur.h"
#include "Plateau.h"

#include <iostream>
#include <cstdlib>
using namespace std

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

void Joueur::jouer(Plateau& goban)
{
    char abscisse('z');
    int ordonnee(0);
    bool fincoup(false);
    m_passe=false;// on repasse le compteur de passe à false
    
    while (fincoup==false)
    {
    while (ordonnee>9 || ordonnee=<1) // pour empêcher la saisie de donnees incorrectes
    {
    std::cout<<"Sur quelle ligne souhaitez-vous poser votre pierre ?"<<std::endl;
    std::cout<<"(indiquez un chiffre de 0 à "<<goban.getSize()<<")"<<std::endl;
    std::cin>>ordonnee;
    }

    while (abscisse!='A' || abscisse!='B' || abscisse!='C' || abscisse!='D' || abscisse!='E' || abscisse!='F' || abscisse!='G' || abscisse!='H' || abscisse!='I' || abscisse!='J' )
    {//la condition serait plus propre si je trouvais le moyen de dire abscisse "n'appartiens pas à l'ensemble"
    std::cout<<std::endl<<"Sur quelle colonne souhaitez-vous poser votre pierre ?"<<std::endl;
    std::cout<<"(indiquez une lettre de A à "<<goban.getSizeLettre()<<")"<<std::endl;
    std::cin<<abscisse;

    if (goban.getSize==5)//si l'utilisateur tape une lettre de G à J et que le tableau est de 5*5, la saisie est incorrecte, cette boucle permet d'en tenir compte
    {
        if (abscisse!='A' || abscisse!='B' || abscisse!='C' || abscisse!='D' || abscisse!='E' || abscisse!='F')
        {
           abscisse='z';
        }
    }
    }
    // tester ici si le coup est valide
    //On transmet les données au plateau pour placer la pierre
    fincoup=goban.placerPierre(abscisse, ordonnee, m_couleur);
    //Si le coup est valide, goban renvoie true, sinon il renvoie false et on recommence la boucle
    }
}

void Joueur::passer()
{
    m_passe=true;
}

bool Joueur::getPasse()
{
    return m_passe;
}