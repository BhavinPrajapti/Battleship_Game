
#include "Ship.h"
#include "Shot.h"

#include <vector>
#include <map>

using std::vector;
using std::map;

class OpponentGrid
{
	int rows;
	int columns;
	vector<Ship> sukenShips;
	char** board;
	map<GridPosition,Shot::Impact> shots;

public:

	OpponentGrid(int rows, int columns);
	int getRows() const;
	int getColumns() const;
	char** getBoard();
	const vector<Ship> getSunkenShips() const;
	void shotResult(const Shot& shot, Shot::Impact impact);
	const map<GridPosition,Shot::Impact>& getShotsAt() const;
	virtual ~OpponentGrid();

};

#include "OpponentGrid.h"

OpponentGrid::OpponentGrid(int rows, int columns) : rows(rows), columns(columns)
{
	board = new char*[rows+2];
	for( int i=0 ; i< columns+1 ; i++)
	{
		board[i] = new char[columns+1];
	}
	for( int x=0 ; x<rows ; x++)
	{
		for(int y=0 ; y<columns ; y++)
		{
			board[x][y]= '~';
		}
	}
}

int OpponentGrid::getRows() const
{
	return rows;
}

int OpponentGrid::getColumns() const
{
	return columns;
}

char** OpponentGrid::getBoard()
{
	return board;
}

const vector<Ship> OpponentGrid::getSunkenShips() const
{
	return sukenShips;
}

void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
	shots[shot.getTargetPosition()]=impact;

	if(impact == Shot::Impact::HIT)
	{
		board[shot.getTargetPosition().getRow()-65][shot.getTargetPosition().getColumn()-1]= 'O';
	}
	else if(impact == Shot::Impact::NONE)
	{
		board[shot.getTargetPosition().getRow()-65][shot.getTargetPosition().getColumn()-1]= '^';
	}
	else if(impact == Shot::Impact::SUNKEN)
	{
		set<GridPosition> shukenShipOccupiedarea;

		// defining bow and stern
		GridPosition bow(shot.getTargetPosition());
		GridPosition stern(shot.getTargetPosition());

		int row= shot.getTargetPosition().getRow();
		int column=shot.getTargetPosition().getColumn();

		bool shipHorizontal=false;
		bool shipVertical=false;

		board[row-65][column-1]= '#';
		shukenShipOccupiedarea.insert(GridPosition(row,column));

		//checks if ship is horizontal
		for(int i=-1; i<=1 ; i++)
		{
			if(GridPosition(row+i,column).isValid())
			{
				if (shots[GridPosition(row+i,column)]==Shot::Impact::HIT)
				{
					shipHorizontal=true;
				}
			}
		}

		//checks if ship is vertical
		for(int j=-1; j<=1 ; j++)
		{
			if(GridPosition(row,column+j).isValid())
			{
				if (shots[GridPosition(row,column+j)]==Shot::Impact::HIT)
				{
					shipVertical=true;
				}
			}
		}
		if(shipHorizontal)	// finding whole ship in horizontal direction
		{
			for(int i=-4 ; i<=4 ; i++)
			{
				if(GridPosition(row+i,column).isValid())
				{
					if (shots[GridPosition(row+i,column)]==Shot::Impact::HIT)
					{
						shukenShipOccupiedarea.insert(GridPosition(row+i,column));
						board[row+i-65][column-1]= '#';
					}
				}
			}
		}
		else if(shipVertical) // finding ship in vertical direction
		{
			for(int j=-4 ; j<=4 ; j++)
			{
				if(GridPosition(row,column+j).isValid())
				{
					if (shots[GridPosition(row,column+j)]==Shot::Impact::HIT)
					{
						shukenShipOccupiedarea.insert(GridPosition(row,column+j));
						board[row-65][column+j-1]= '#';
					}
				}
			}
		}
		bow=*shukenShipOccupiedarea.begin(); // storing bow value
		stern=*shukenShipOccupiedarea.rbegin(); // storing stern value

		// inserting the ship in the vector
		sukenShips.push_back(Ship(bow,stern));
	}
}

const map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() const
{
	return shots;
}

OpponentGrid::~OpponentGrid()
{
	for(int i=0; i<rows; ++i)
	{
		delete[] board[i];
	}
	delete[] board;
}
