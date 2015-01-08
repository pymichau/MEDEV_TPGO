/* 
 * File:   Joueur.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 15:17
 */

#ifndef JOUEUR_H
#define	JOUEUR_H
#include "include.h"

class Joueur {
public:
    /******Constructeurs/destructeurs*****/
    Joueur(bool couleur);
    Joueur(const Joueur& orig);
    virtual ~Joueur();
    
    /******methodes*******/
    
    Pierre* jouer(Plateau &goban); //j'ai toujours foiré mes pointeurs, verifier ici s'il y a un bug
    void passer();
    bool getPasse(); // au début de chaque tour, le plateau check si les joueurs ont passé, s'ils ont passé tous les deux l'un après l'autre, les deux passe sont à true et c'est la fin de la partie
    void capturePierre();
    void setPrise(bool prise);
    bool getPrise();
    
private:
    bool m_couleur;
    int m_nbPierreCapture;
    bool m_passe;
    bool m_prise; //indique si le joueur a pris une pierre à ce tour

};

#endif	/* JOUEUR_H */

