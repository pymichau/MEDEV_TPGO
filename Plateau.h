/* 
 * File:   Plateau.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 16:53
 */


#ifndef PLATEAU_H
#define	PLATEAU_H

class Plateau {
public:
    Plateau();
    Plateau(const Plateau& orig);
    virtual ~Plateau();
    //bool verifierKo(); cette fonctionalité sera finalement faite par placerPierre
    void afficher();
    int getSize();
    char getSizeLettre();
    Pierre* placerPierre(char abscisse, int ordonnee, bool couleur);
    void retirerPierre(Pierre* pierre);
    int actualiser (float position );
    //à completer avec la classe groupe pour savoir la chaine d'appel qui appelle actualiser. 
    //J'ai mis int pour renvoyer le nombre de pièces prises. potentiellement pas utile.
private:
    int m_size;
    std::vector<char> m_listePierre;//liste des pierres
    std::vector<char> m_listePierreProvisoire;
    std::vector<char> m_listePierrePrecedent;
    std::vector<char> m_listePierrePrecedentPrecedent;
    //ces 3 listes de pierres sont utilisées pour vérifier les situations de ko
    

};

#endif	/* PLATEAU_H */

