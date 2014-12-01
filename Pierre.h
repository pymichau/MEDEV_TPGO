/* 
 * File:   Pierre.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 12:02
 */

#ifndef PIERRE_H
#define	PIERRE_H

class Pierre {
public:
    Pierre(bool couleur, char abscisse, int ordonnee); //false pour blanc, true pour noir
    Pierre(const Pierre& orig);
    virtual ~Pierre();
    
    /********METHODES******/
    getPosition();
    getCouleur();
    
private:
    /********ATTRIBUTS*******/
    float m_position;
    bool m_couleur;

};

#endif	/* PIERRE_H */

