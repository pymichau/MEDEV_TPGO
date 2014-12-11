#include <iostream>
#include "gtest/gtest.h"
using namespace std;
#include "Groupe.h"
#include "Joueur.h"
#include "Plateau.h"

TEST(MyDeathTest, NormalExit) {
  EXPECT_EXIT(main(), ::testing::ExitedWithCode(0), "Success");
}

TEST(MyDeathTest, FastExit) {
  ASSERT_DEATH(main(), "");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}