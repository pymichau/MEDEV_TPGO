MEDEV_TPGO
==========

TP de MEDEV sur le go

Commandes git utiles que j'oublie toujours :
git commit -m "commentaire sur ce qui a été fait"
git push -u [nomDuProjet] [Branche dans laquelle on fait le push]

=======================
classe : Groupe
m_listePierres
m_positionLibertes
m_idGroupe
m_couleurGroupe
ajoutPierre()
presenceLiberteOppose()
verifierNbLiberte()

classe : Pierre
m_position
m_couleur

classe : Joueur
m_couleur
m_nbPierreCapture
m_passe (bool)
passer()
jouer()

classe : Plateau
m_listePierre
m_size
actualiser() <= N'est-ce pas placerPierre() ?
verifierKo()
afficher()
getSize()
getSizeLettre()
placerPierre(char abscisse, int ordonnee, bool couleur) la création des pierres doit se faire au sein du plateau
retirerPierre(Pierre &pierre)