/* 
 * File:   Groupe.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 12:00
 */

#ifndef GROUPE_H
#define	GROUPE_H

#include <vector>

class Groupe {
public:
    Groupe();
    Groupe(const Groupe& orig);
    virtual ~Groupe();
    ajoutPierre(float);
    presenceLiberteOppose();
    verifierNbLiberte();
    fusion();
private:
    std::vector<Pierre*> m_listePierre;
    std::vector<float> m_positionLibertes;
    int m_idGroupe;
    bool m_couleurGroupe;
    static std::vector<Groupe*> m_GroupeBlancAncien;
    static std::vector<Groupe*> m_GroupeNoirAncien;
    static std::vector<Groupe*> m_GroupeBlancNouveau;
    static std::vector<Groupe*> m_GroupeNoirNouveau;

};

#endif	/* GROUPE_H */

