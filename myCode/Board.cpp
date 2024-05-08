
//#include "OwnGrid.h"
//#include "OpponentGrid.h"
//
//class Board
//{
//
//	OwnGrid ownGrid;
//
//	OpponentGrid opponentGrid;
//
//public:
//
//	Board(int rows, int columns);
//
//	int getRows() const;
//
//	int getColumns() const;
//
//	OwnGrid& getOwnGrid();
//
//	OpponentGrid& getOpponentGrid();
//
//	~Board();
//
//};

#include "Board.h"

Board::Board(int rows, int columns) : ownGrid(OwnGrid(rows,columns)) ,
opponentGrid(OpponentGrid(rows,columns)) {}

int Board::getRows() const
{
	return ownGrid.getRows();
}

int Board::getColumns() const
{
	return ownGrid.getColumns();
}

OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}

Board::~Board()
{
}
