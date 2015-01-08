/* 
 * File:   Groupe.cpp
 * Author: eleve
 * 
 * Created on 1 décembre 2014, 12:00
 */

#include "include.h"

using namespace std;

//vector<Groupe*> m_GroupeBlancAncien = NULL;
//vector<Groupe*> m_GroupeNoirAncien = NULL;
//vector<Groupe*> m_GroupeBlancNouveau = NULL;
//vector<Groupe*> m_groupeNoirNouveau = NULL;
    
int n=0;

Groupe::Groupe(Pierre* _pierre, Plateau* _plateau, Joueur* _joueur) {
    m_idGroupe = n;
    n++;
    ajoutPierre(_pierre);
    m_joueur = _joueur;
    if (_pierre->getCouleur())
    {
       m_groupeNoirNouveau.push_back(this); 
    }
    else m_groupeBlancNouveau.push_back(this);
    m_plateau = _plateau;
}

Groupe::Groupe(const Groupe& orig) {
}

Groupe::~Groupe(){
    m_joueur->setPrise(true);
    for (int i=0; i<m_listePierre.size(); i++)
    {
        m_plateau->retirerPierre(m_listePierre[i]);
        m_joueur->capturePierre();
    }
}

vector<Pierre*> Groupe::getListePierre(){
    return m_listePierre;
}

vector<float> Groupe::getPositionLibertes(){
    return m_positionLibertes;
}

void Groupe::ajoutPierre(Pierre* _pierre){
    m_listePierre.push_back(_pierre);
    for (int z = 0 ; z < m_positionLibertes.size(); z++)
    //for (vector<float>::iterator z = m_positionLibertes.begin() ; z != m_positionLibertes.end(); z++) // boucle permettant d'éliminer la liberté du groupe occupée par la pierre nouvellement posée
    {
        if (m_positionLibertes[z]==_pierre->getPosition())
        {
            m_positionLibertes.erase(m_positionLibertes.begin()+z);
            break;
        }
    }
    for (int i=0; i<m_groupeBlancAncien.size(); i++)
    {
        for (int j=0; j<m_groupeBlancAncien[i]->getListePierre().size();j++) //On parcourt toutes les pierres blanches
        {
            if (!(m_groupeBlancAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()-1))&&!(floor(_pierre->getPosition())==1)) //Si la pierre ne se situe pas à un bord et que sa gauche n'est pas occupée par une pierre blanche
            {
                for (int a=0; a<m_groupeNoirAncien.size(); a++)
                {
                    for (int b=0; b<m_groupeNoirAncien[a]->getListePierre().size();b++) //On parcourt toutes les pierres noires
                    {
                        if (!(m_groupeNoirAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()-1))) //Si que sa gauche n'est pas occupée par une pierre noire
                        {
                            m_positionLibertes.push_back(_pierre->getPosition()-1); // On ajoute la gauche de la pierre posée à la liste de liberté
                        }
                    }
                }
            }
            if (!(m_groupeBlancAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()+1))&&!(floor(_pierre->getPosition())==9)) //Si la pierre ne se situe pas à un bord et que sa droite n'est pas occupée par une pierre blanche
            {
                for (int a=0; a<m_groupeNoirAncien.size(); a++)
                {
                    for (int b=0; b<m_groupeNoirAncien[a]->getListePierre().size();b++) //On parcourt toutes les pierres noires
                    {
                        if (!(m_groupeNoirAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()+1))) //Si sa droite n'est pas occupée par une pierre noire
                        {
                            m_positionLibertes.push_back(_pierre->getPosition()+1); // On ajoute la gauche de la pierre posée à la liste de liberté
                        }
                    }
                }
            }
        }  
    }
    for (int i=0; i<m_groupeNoirAncien.size(); i++)
    {
        for (int j=0; j<m_groupeNoirAncien[i]->getListePierre().size();j++) //On parcourt toutes les pierres noires
        {
            if (!(m_groupeNoirAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()-0.1)||(int (_pierre->getPosition()*10)%10==1.0))) //Si la pierre ne se situe pas à un bord et que sa gauche n'est pas occupée par une pierre noire
            
            {
                for (int a=0; a<m_groupeBlancAncien.size(); a++)
                {
                    for (int b=0; b<m_groupeBlancAncien[a]->getListePierre().size();b++) //On parcourt toutes les pierres blanches
                    {
                        if (!(m_groupeBlancAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()-0.1))) //Si sa gauche n'est pas occupée par une pierre blanche
                        {
                            m_positionLibertes.push_back(_pierre->getPosition()-0.1); // On ajoute la gauche de la pierre posée à la liste de liberté
                        }
                    }
                }
            }
            if (!(m_groupeNoirAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()+0.1))&&!((int (_pierre->getPosition()*10)%10==9))) //Si la pierre ne se situe pas à un bord et que sa droite n'est pas occupée par une pierre noire
            {
                for (int a=0; a<m_groupeBlancAncien.size(); a++)
                {
                    for (int b=0; b<m_groupeBlancAncien[a]->getListePierre().size();b++) //On parcourt toutes les pierres blanches
                    {
                        if (!(m_groupeBlancAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()+0.1))) //Si sa droite n'est pas occupée par une pierre blanche
                        {
                            m_positionLibertes.push_back(_pierre->getPosition()+0.1); // On ajoute la droite de la pierre posée à la liste de liberté
                        }
                    }
                }
            }
        }  
    }
}

vector<Groupe*> Groupe::presenceLiberteOppose(Pierre* _pierre)
{
    vector<Groupe*> resultat ;
    if (m_couleurGroupe=true)
    {
        for (int i=0; i<m_groupeBlancAncien.size(); i++)
        {
            for (int j=0; j<m_groupeBlancAncien[i]->getListePierre().size();j++) //On parcourt toutes les pierres blanches
            {
                if (m_groupeBlancAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()-1)) //Si la gauche de la pierre est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeBlancAncien[i]);
                }
                if (m_groupeBlancAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()+1)) //Si la droite est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeBlancAncien[i]);
                }
            }  
        }
        for (int a=0; a<m_groupeBlancAncien.size(); a++)
        {
            for (int b=0; b<m_groupeBlancAncien[a]->getListePierre().size();b++) //On parcourt toutes les pierres blanches
            {
                if (!(m_groupeBlancAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()-0.1))) //Si le haut est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeBlancAncien[a]);
                }
                if (!(m_groupeBlancAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()+0.1))) //Si le bas est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeBlancAncien[a]);
                }
            }
        }
    }
    if (m_couleurGroupe=false)
    {
        for (int i=0; i<m_groupeNoirAncien.size(); i++)
        {
            for (int j=0; j<m_groupeNoirAncien[i]->getListePierre().size();j++) //On parcourt toutes les pierres blanches
            {
                if (m_groupeNoirAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()-1)) //Si la gauche de la pierre est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeNoirAncien[i]); 
                }
                if (m_groupeNoirAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()+1)) //Si la droite de la pierre est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeNoirAncien[i]);
                }
            }  
        }
        for (int a=0; a<m_groupeNoirAncien.size(); a++)
        {
            for (int b=0; b<m_groupeNoirAncien[a]->getListePierre().size();b++) //On parcourt toutes les pierres noires
            {
                if (!(m_groupeNoirAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()-0.1))) //Si le haut est occupée par une pierre noire
                {
                    resultat.push_back(m_groupeNoirAncien[a]);
                }
                if (!(m_groupeNoirAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()+0.1))) //Si le bas est occupée par une pierre noire
                {
                    resultat.push_back(m_groupeNoirAncien[a]);
                }
            }
        }
    }
    return resultat;
}

bool Groupe::verifierNbLiberte()
{
    if (this->getPositionLibertes().size()==0)
        return false;
    else return true;
}

vector<Groupe*> Groupe::presenceLiberteCouleurPierre(Pierre* _pierre)
{
    vector<Groupe*> resultat ;
    if (m_couleurGroupe=false)
    {
        for (int i=0; i<m_groupeBlancAncien.size(); i++)
        {
            for (int j=0; j<m_groupeBlancAncien[i]->getListePierre().size();j++) //On parcourt toutes les pierres blanches
            {
                if (m_groupeBlancAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()-1)) //Si la gauche de la pierre est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeBlancAncien[i]);
                }
                if (m_groupeBlancAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()+1)) //Si la droite est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeBlancAncien[i]);
                }
            }  
        }
        for (int a=0; a<m_groupeBlancAncien.size(); a++)
        {
            for (int b=0; b<m_groupeBlancAncien[a]->getListePierre().size();b++) //On parcourt toutes les pierres blanches
            {
                if (!(m_groupeBlancAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()-0.1))) //Si le haut est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeBlancAncien[a]);
                }
                if (!(m_groupeBlancAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()+0.1))) //Si le bas est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeBlancAncien[a]);
                }
            }
        }
    }
    if (m_couleurGroupe=true)
    {
        for (int i=0; i<m_groupeNoirAncien.size(); i++)
        {
            for (int j=0; j<m_groupeNoirAncien[i]->getListePierre().size();j++) //On parcourt toutes les pierres blanches
            {
                if (m_groupeNoirAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()-1)) //Si la gauche de la pierre est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeNoirAncien[i]); 
                }
                if (m_groupeNoirAncien[i]->getListePierre()[j]->getPosition()==(_pierre->getPosition()+1)) //Si la droite de la pierre est occupée par une pierre blanche
                {
                    resultat.push_back(m_groupeNoirAncien[i]);
                }
            }  
        }
        for (int a=0; a<m_groupeNoirAncien.size(); a++)
        {
            for (int b=0; b<m_groupeNoirAncien[a]->getListePierre().size();b++) //On parcourt toutes les pierres noires
            {
                if (!(m_groupeNoirAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()-0.1))) //Si le haut est occupée par une pierre noire
                {
                    resultat.push_back(m_groupeNoirAncien[a]);
                }
                if (!(m_groupeNoirAncien[a]->getListePierre()[b]->getPosition()==(_pierre->getPosition()+0.1))) //Si le bas est occupée par une pierre noire
                {
                    resultat.push_back(m_groupeNoirAncien[a]);
                }
            }
        }
    }
    return resultat;
}

vector<Groupe*> Groupe::presenceLiberteCouleurPierre(Groupe* _groupe){
    vector<Groupe*> resultat;
    for(int i=0; i<_groupe->getListePierre().size(); i++)
    {
        vector<Groupe*> resultatInter = presenceLiberteCouleurPierre(_groupe->getListePierre()[i]);
        for (int j=0; j<resultatInter.size(); j++)
        {
            if (!(&*resultatInter[j]==&*_groupe))
            {
                resultat.push_back(resultatInter[j]);
            }
        }
    }
    return resultat;
}

void Groupe::fusion(){
    vector<Groupe*> resultatInter;
    resultatInter = presenceLiberteCouleurPierre(this);
    for (int i=0; i<resultatInter.size(); i++)
    {
        for(int j=0; j<resultatInter[i]->getListePierre().size(); j++)
        {
            ajoutPierre(resultatInter[i]->getListePierre()[j]);
        }
    }
}
