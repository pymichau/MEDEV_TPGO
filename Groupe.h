/* 
 * File:   Groupe.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 12:00
 */

#ifndef GROUPE_H
#define	GROUPE_H

//#include "include.h"
//#include "Joueur.h"

class Groupe {
public:
    Groupe(Pierre*, Plateau*, Joueur*);
    Groupe(const Groupe& orig);
    ~Groupe();
    void ajoutPierre(Pierre*);
    std::vector<Groupe*> presenceLiberteOppose(Pierre*); //renvoie les groupes adajcents de couleur opposé pour une pierre
    std::vector<Groupe*> presenceLiberteCouleurPierre(Pierre*); // renvoie les groupes adjacents de la couleur de la pierre pour une pierre
    std::vector<Groupe*> presenceLiberteCouleurPierre(Groupe*); //renvoie les groupes adjacents de la couleur de la pierre pour un groupe
    bool verifierNbLiberte(); // renvoie false si le groupe n'a plus de liberté
    void fusion();
    std::vector<Pierre*> getListePierre();
    std::vector<float> getPositionLibertes();
    static std::vector<Groupe*> m_groupeBlancAncien;
    static std::vector<Groupe*> m_groupeNoirAncien;
    static std::vector<Groupe*> m_groupeBlancNouveau;
    static std::vector<Groupe*> m_groupeNoirNouveau;
private:
    Plateau* m_plateau;
    Joueur* m_joueur;
    std::vector<Pierre*> m_listePierre;
    std::vector<float> m_positionLibertes;
    int m_idGroupe;
    bool m_couleurGroupe; //1 si Noir, 0 si Blanc


};

#endif	/* GROUPE_H */

