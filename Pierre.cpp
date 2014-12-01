/* 
 * File:   Pierre.cpp
 * Author: eleve
 * 
 * Created on 1 décembre 2014, 12:02
 */

#include "Pierre.h"

Pierre::Pierre(bool couleur, char abscisse, int ordonnee) 
{/*penser a bien construire l'input de la position*/
    m_couleur=couleur;
    m_position=ordonnee*0.1;
    switch (abscisse)
    {
            case'i':
                m_position++;
            case 'h':
                m_position++;
            case 'g':
                m_position++;
            case 'f':
                m_position++;
            case 'e':
                m_position++;
            case 'd':
                m_position++;
            case 'c':
                m_position++;
            case 'b':
                m_position++;
            case 'a':
                m_position++;
                break;
    }               
}

Pierre::Pierre(const Pierre& orig) {
}

Pierre::~Pierre() {
}

float Pierre::getPosition()
{
    return m_position;
}

bool Pierre::getCouleur()
{
    return m_couleur;
}