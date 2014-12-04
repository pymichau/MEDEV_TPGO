/* 
 * File:   Plateau.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 16:53
 */

#include <Pierre.cpp>
#include <Joueur.cpp>

#include <vector>
#include <cstdlib>
using namespace std;

#ifndef PLATEAU_H
#define	PLATEAU_H

class Plateau {
public:
    Plateau();
    Plateau(const Plateau& orig);
    virtual ~Plateau();
    bool verifierKo();
    void afficher();
    int getSize();
    char getSizeLettre();
    bool placerPierre(char abscisse, int ordonnee, bool couleur);
    void retirerPierre(Pierre &pierre);
    // se substitue potentiellement à actualiser. ou est appelée par elle. 
    //doit incrémenter le compteur de pièces prises.
    int actualiser (float position );
    //à completer avec la classe groupe pour savoir la chaine d'appel qui appelle actualiser. 
    //J'ai mis int pour renvoyer le nombre de pièces prises. potentiellement pas utile.
private:
    int m_size;
    std::vector<char> m_listePierre;//liste des pierres
    

};

#endif	/* PLATEAU_H */

