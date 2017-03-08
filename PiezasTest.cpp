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

TEST(PiezasTest, dropPieceInvalidNegativeColumn){
  Piezas p;
  ASSERT_TRUE(p.dropPiece(-1) == Invalid);
}

TEST(PiezasTest, dropPieceInvalidTooHighColumn){
  Piezas p;
  ASSERT_TRUE(p.dropPiece(BOARD_COLS) == Invalid);
}

Test(PiezasTest, dropPieceColumnFull){
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(0);
  ASSERT_TRUE(p.dropPiece(0) == Blank);
}

TEST(PiezasTest, dropPieceValid){
  Piezas p;
  ASSERT_TRUE(p.dropPiece(0) == X);
}

TEST(PiezasTest, dropPieceValidToggleTurn){
  Piezas p;
  p.dropPiece(0)
  ASSERT_TRUE(p.dropPiece(0) == O);
}

TEST(PiezasTest, dropPieceInValidToggleTurn){
  Piezas p;
  p.dropPiece(10)
  ASSERT_TRUE(p.dropPiece(0) == O);
}

Test(PiezasTest, dropPieceColumnFullToggleTurn){
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(0);
  ASSERT_TRUE(p.dropPiece(1) == X);
}

Test(PiezasTest, pieceAtBlank){
  Piezas p;
  ASSERT_TRUE(p.pieceAt(0,0) == Blank);
}

Test(PiezasTest, pieceAtX){
  Piezas p;
  p.dropPiece(0);
  ASSERT_TRUE(p.pieceAt(0,0) == X);
}

Test(PiezasTest, pieceAtInvalidRowTooHigh){
  Piezas p;
  ASSERT_TRUE(p.pieceAt(BOARD_ROWS,0) == Invalid);
}

Test(PiezasTest, pieceAtInvalidColTooHigh){
  Piezas p;
  ASSERT_TRUE(p.pieceAt(0,BOARD_COLS) == Invalid);
}

Test(PiezasTest, pieceAtInvalidRowNegative{
  Piezas p;
  ASSERT_TRUE(p.pieceAt(-1,0) == Invalid);
}

Test(PiezasTest, pieceAtInvalidColNegative){
  Piezas p;
  ASSERT_TRUE(p.pieceAt(0,-1) == Invalid);
}

Test(PiezasTest, pieceAtInvalidBothNegative){
  Piezas p;
  ASSERT_TRUE(p.pieceAt(-1, -1) == Invalid);
}

Test(PiezasTest, pieceAtInvalidBothTooHigh){
  Piezas p;
  ASSERT_TRUE(p.pieceAt(BOARD_ROWS,BOARD_COLS) == Invalid);
}

Test(PiezasTest, pieceAtInvalidRowTooHighColNegative){
  Piezas p;
  ASSERT_TRUE(p.pieceAt(BOARD_ROWS, -1) == Invalid);
}

Test(PiezasTest, pieceAtInvalidRowNegativeColTooHigh){
  Piezas p;
  ASSERT_TRUE(p.pieceAt(-1,BOARD_COLS) == Invalid);
}

Test(PiezasTest, gameStateBoardNotFull){
  Piezas p;
  ASSERT_TRUE(p.gameState() == Invalid);
}

Test(PiezasTest, gameStateBoardFullTie){
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
  p.dropPiece(2);
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
  ASSERT_TRUE(p.gameState() == Blank);
}

Test(PiezasTest, gameStateBoardFullXWinsVerticallyLeftThree){
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
  ASSERT_TRUE(p.gameState() == X);
}
