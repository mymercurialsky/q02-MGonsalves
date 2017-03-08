/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, constructorSetsTurnToX){
  Piezas p;
  ASSERT_TRUE(p.dropPiece(0) == X);
}

TEST(PiezasTest, constructorClearsBoard){
  Piezas p;
  bool clear = true;
	for (int i = 0; i < BOARD_ROWS; i++){
		for (int j = 0; j < BOARD_COLS; j++){
			if (p.pieceAt(i, j) != Blank){
				clear = false;
				break;
			}
		}
	}
	ASSERT_TRUE(clear == true);

}
