MEDEV_TPGO
==========

Couverture de Test
==================
Le fichier TestGroupe permet de tester les diff�rentes m�thodes de la classe groupe. Cependant, j'ai rencontrer un probl�me avec Git ce qui m'a oblig� � le d�placer dans les sources.
De plus je rencontre un probl�me d'include.


TP de MEDEV sur le go

Commandes git utiles que j'oublie toujours :
git commit -m "commentaire sur ce qui a �t� fait"
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
placerPierre(char abscisse, int ordonnee, bool couleur) la cr�ation des pierres doit se faire au sein du plateau
retirerPierre(Pierre &pierre)

Vid�o tuto pour googleTest : https://www.youtube.com/watch?v=TS2CTf11k1U