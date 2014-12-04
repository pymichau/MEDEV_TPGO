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
            case 'J' :
                m_position++;
            case'I':
                m_position++;
            case 'H':
                m_position++;
            case 'G':
                m_position++;
            case 'F':
                m_position++;
            case 'E':
                m_position++;
            case 'D':
                m_position++;
            case 'C':
                m_position++;
            case 'B':
                m_position++;
            case 'A':
                break;
    }               
}

Pierre::Pierre(const Pierre& orig) {
}

Pierre::~Pierre() 
{
}

float Pierre::getPosition()
{
    return m_position;
}

bool Pierre::getCouleur()
{
    return m_couleur;
}