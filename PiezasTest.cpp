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

TEST(PiezasTest, resetClearsBoard){
	Piezas p;
	p.dropPiece(0);
	p.reset();
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

TEST(PiezasTest, dropPieceColumnFull){
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
	p.dropPiece(0);
	ASSERT_TRUE(p.dropPiece(0) == O);
}

TEST(PiezasTest, dropPieceInValidToggleTurn){
	Piezas p;
	p.dropPiece(10);
	ASSERT_TRUE(p.dropPiece(0) == O);
}

TEST(PiezasTest, dropPieceColumnFullToggleTurn){
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(0);
	p.dropPiece(0);
	p.dropPiece(0);
	ASSERT_TRUE(p.dropPiece(1) == X);
}

TEST(PiezasTest, pieceAtBlank){
	Piezas p;
	ASSERT_TRUE(p.pieceAt(0,0) == Blank);
}

TEST(PiezasTest, pieceAtX){
	Piezas p;
	p.dropPiece(0);
	ASSERT_TRUE(p.pieceAt(0,0) == X);
}

TEST(PiezasTest, pieceAtInvalidRowTooHigh){
	Piezas p;
	ASSERT_TRUE(p.pieceAt(BOARD_ROWS,0) == Invalid);
}

TEST(PiezasTest, pieceAtInvalidColTooHigh){
	Piezas p;
	ASSERT_TRUE(p.pieceAt(0,BOARD_COLS) == Invalid);
}

TEST(PiezasTest, pieceAtInvalidRowNegative){
	Piezas p;
	ASSERT_TRUE(p.pieceAt(-1,0) == Invalid);
}

TEST(PiezasTest, pieceAtInvalidColNegative){
	Piezas p;
	ASSERT_TRUE(p.pieceAt(0,-1) == Invalid);
}

TEST(PiezasTest, pieceAtInvalidBothNegative){
	Piezas p;
	ASSERT_TRUE(p.pieceAt(-1, -1) == Invalid);
}

TEST(PiezasTest, pieceAtInvalidBothTooHigh){
	Piezas p;
	ASSERT_TRUE(p.pieceAt(BOARD_ROWS,BOARD_COLS) == Invalid);
}

TEST(PiezasTest, pieceAtInvalidRowTooHighColNegative){
	Piezas p;
	ASSERT_TRUE(p.pieceAt(BOARD_ROWS, -1) == Invalid);
}

TEST(PiezasTest, pieceAtInvalidRowNegativeColTooHigh){
	Piezas p;
	ASSERT_TRUE(p.pieceAt(-1,BOARD_COLS) == Invalid);
}

TEST(PiezasTest, gameStateBoardNotFull){
	Piezas p;
	ASSERT_TRUE(p.gameState() == Invalid);
}

TEST(PiezasTest, severalPiecesDroppedNotFull){
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(1);
	p.dropPiece(3);
	p.dropPiece(0);
	ASSERT_TRUE(p.gameState() == Invalid);
}

TEST(PiezasTest, gameStateBoardFullTie){
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

TEST(PiezasTest, gameStateBoardFullXWinsVerticallyLeftThree){
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

TEST(PiezasTest, gameStateBoardFullXWinsHorizontalBottomFour){
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(0);
	p.dropPiece(1);
	p.dropPiece(1);
	p.dropPiece(2);
	p.dropPiece(0);
	p.dropPiece(3);
	p.dropPiece(2);
	p.dropPiece(3);
	p.dropPiece(1);
	p.dropPiece(2);
	p.dropPiece(3);
	ASSERT_TRUE(p.gameState() == X);
}

TEST(PiezasTest, gameStateBoardFullOWinsHorizontalTopFour){
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(1);
	p.dropPiece(2);
	p.dropPiece(1);
	p.dropPiece(2);
	p.dropPiece(1);
	p.dropPiece(3);
	p.dropPiece(2);
	p.dropPiece(0);
	p.dropPiece(0);
	p.dropPiece(3);
	p.dropPiece(3);
	ASSERT_TRUE(p.gameState() == O);
}

TEST(PiezasTest, gameStateBoardFullTieOMaxVertical){
	Piezas p;
	p.dropPiece(0);
	p.dropPiece(1);
	p.dropPiece(2);
	p.dropPiece(1);
	p.dropPiece(3);
	p.dropPiece(1);
	p.dropPiece(0);
	p.dropPiece(0);
	p.dropPiece(2);
	p.dropPiece(3);
	p.dropPiece(2);
	p.dropPiece(3);
	ASSERT_TRUE(p.gameState() == Blank);
}
