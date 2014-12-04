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
    while (ordonnee>9 || ordonnee<1) // pour empêcher la saisie de donnees incorrectes
    {
    cout<<"Dans quelle colonne souhaitez-vous poser votre pierre ?"<<endl;
    cout<<"(indiquez un chiffre de 1 à "<<goban.getSize()<<")"<<endl;
    cin>>ordonnee;
    }

    while (abscisse!='a' || abscisse!='b' || abscisse!='c' || abscisse!='d' || abscisse!='e' || abscisse!='f' || abscisse!='g' || abscisse!='h' || abscisse!='i' || )
    {//la condition serait plus propre si je trouvais le moyen de dire abscisse "n'appartiens pas à l'ensemble"
    cout<<endl<<"Dans quelle colonne souhaitez-vous poser votre pierre ?"<<endl;
    cout<<"(indiquez une lettre de A à "<<goban.getSizeLettre()<<")"<<endl;
    cin<<abscisse;

    if (goban.getSize==5)//si l'utilisateur tape une lettre de f à i et que le tableau est de 5*5, la saisie est incorrecte, cette boucle permet d'en tenir compte
    {
        if (abscisse!='a' || abscisse!='b' || abscisse!='c' || abscisse!='d' || abscisse!='e')
        {
           abscisse='z';
        }
    }
    }
    // tester ici si le coup est valide
    //On transmet les données au plateau pour placer la pierre
    fincoup=goban.placerPierre(abscisse, ordonnee, m_couleur);
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