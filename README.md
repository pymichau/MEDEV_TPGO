MEDEV_TPGO
==========

TP de MEDEV sur le go

consignes pour git :
va dans le dossier contenant le projet netbeans (cd .. pour remonter à la racide, puis cd nomdudossier pour aller jusqu'au dossier
git init pour créer un fichier git là ou tu es
git remote add nomDuProjet https://github.com/pymichau/MEDEV_TPGO.git
pour te connecter au fichier distant

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
actualiser()
verifierKo()
afficher()