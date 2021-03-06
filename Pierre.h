/* 
 * File:   Pierre.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 12:02
 */

#ifndef PIERRE_H
#define	PIERRE_H
//#include "Plateau.h"

class Pierre {
public:
    Pierre(bool couleur, char abscisse, int ordonnee); //true pour blanc, false pour noir
    Pierre(const Pierre& orig);
    virtual ~Pierre();
    
    /********METHODES******/
    float getPosition();
    bool getCouleur();
    
private:
    /********ATTRIBUTS*******/
    float m_position;
    bool m_couleur;

};

#endif	/* PIERRE_H */

