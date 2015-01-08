#include <gtest/gtest.h>
#include "MEDEV_TPGO/include.h"

TEST(TestGroupe, TestConstructeur) {
    _joueur = new Joueur(true); // création d'un joueur Noir
    Plateau goban();
    _pierreUne = new Pierre(true, 'A', 1);
    _groupe = new Groupe (_pierreUne, &goban, _joueur);
    ASSERT_EQ([1.2, 2.1], _groupe->m_positionLibertes); //vérifie la fonction ajoutPierre
    EXPECT_EQ(true, _groupe->verifierNbLiberte()); // vérifie la méthode
    _pierreDeux = new Pierre (true, 'A', 2);
    _groupeDeux = new Groupe (_pierreDeux, &goban, joueur); // vérifie ajoutPierre
    EXPECT_EQ([1.3, 2.2], _groupeDeux->m_positionLibertes); //vérifie la fonction ajoutPierre
    _groupeDeux->fusion();
    EXPECT_EQ(3, _groupeDeux->m_positionLibertes.size());
}
