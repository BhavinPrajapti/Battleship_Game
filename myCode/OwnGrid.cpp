
#include "Ship.h"
#include "Shot.h"

//#include <vector>
//#include <map>
//#include <algorithm>
//
//using std::map;
//using std::vector;
//
//class OwnGrid
//{
//	int rows;
//
//	int columns;
//
//	vector<Ship> ships;
//
//	map<int,int> shipMap;
//
//	char** board;
//
//	set<GridPosition> shotAt;
//
//public:
//
//	OwnGrid ( int rows, int columns);
//
//	int getRows() const;
//
//	int getColumns() const;
//
//	bool placeShip (const Ship& ship);
//
//	const vector<Ship> getShip() const;
//
//	char** getBoard();
//
//	Shot::Impact takeBlow(const Shot& shot);
//
//	const set<GridPosition> getShotAt() const;
//
//	virtual ~OwnGrid();
//
//};

#include "OwnGrid.h"

OwnGrid::OwnGrid(int rows, int columns) : rows(rows), columns(columns)
{
	// first element of map is ship size
	// second element of map is ship quantity
	shipMap = { {5,1} , {4,2} , {3,3} , {2,4}};

	// dyanamic memory allocation for board
	board = new char*[rows+2];
	for( int i=0 ; i< columns+1 ; i++)
	{
		board[i] = new char[columns+1];
	}

	// Initialize the board with '~'
	for( int x=0 ; x<rows ; x++)
	{
		for(int y=0 ; y<columns ; y++)
		{
			board[x][y]= '~';
		}
	}
}
//
//bool is=std::all_of(alpha.begin(),alpha.end(), [](char c) {return (std::isalpha(c));}  );
//cout<<is;

int OwnGrid::getRows() const
{
	return rows;
}

int OwnGrid::getColumns() const
{
	return columns;
}

bool OwnGrid::placeShip(const Ship &ship)
{
	//checks ship validity
	if(ship.isValid())
	{
		//checks availability of entered length ship from shipMap map
		if(shipMap.find(ship.length())->second > 0)
		{
			// checks ship's bow and stern is lying inside the board
			if( ((ship.getBow().getRow()-65)<= rows)
					&& ((ship.getStern().getRow()-65)<=rows)
					&& ((ship.getStern().getColumn()-1)<= columns)
					&& ((ship.getBow().getColumn()-1)<= columns))
			{
				vector<GridPosition> intersection;
				set<GridPosition> existingShipBlockedAra;
				set<GridPosition> shipOccupiedArea;

				// Iterate through existing ships to get their blocked areas
				for( const auto &existingShip : ships)
				{
					existingShipBlockedAra = existingShip.blockedArea();

					shipOccupiedArea = ship.occupiedArea();

					// checks intersection between existing ships blocked area
					// and entered ship occupied area
					set_intersection(existingShipBlockedAra.begin(),
						existingShipBlockedAra.end(),
						shipOccupiedArea.begin(),
						shipOccupiedArea.end(),//intersection.begin());
						std::back_inserter(intersection));
				}
				// if ships are not intersecting then place ship & return true
				if( intersection.empty())
				{
					ships.push_back(ship);
					shipMap.find(ship.length())->second--;

                    // Update the board with the ship positions
					for (auto iterGetOccupiedArea: ship.occupiedArea())
					{
						board[iterGetOccupiedArea.getRow()-65]
							  [iterGetOccupiedArea.getColumn()-1]='#';
					}
					return true;
				}
				else
				{
					// intersection occured
					return false;
				}
				}
				else
				{
					// Ship is out of bounds
					return false;
				}
		}
		else
		{
			// No Ship available of this length
			return false;
		}

	}
	else
	{
		// invalid ship
		return false;
	}
}

const vector<Ship> OwnGrid::getShip() const
{
	return ships;
}

char** OwnGrid::getBoard()
{
	return board;
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	shotAt.insert(shot.getTargetPosition());
	bool tempHit=false;
	bool tempSunken = false;

	vector<GridPosition> intersection;
	set<GridPosition> existingShipsOccupiedArea;

    // Iterate through ships to check for hits and sunken ships
    for(const auto &itr : ships)
    {
    	existingShipsOccupiedArea =itr.occupiedArea();

    	if(existingShipsOccupiedArea.find(shot.getTargetPosition()) !=
    			existingShipsOccupiedArea.end() )
    	{
    		tempHit=true;

    		board[shot.getTargetPosition().getRow()-65]
				  [shot.getTargetPosition().getColumn()-1]='O';

            // Check intersection between ship occupied area and shot positions
    		set_intersection(existingShipsOccupiedArea.begin(),
    				existingShipsOccupiedArea.end(),
					shotAt.begin(),
					shotAt.end(),
					back_inserter(intersection));

    		// storing ship length to a variable
    		int shipLength=itr.length();

    		//storing insersection size to a variable
    		int occupiedAreaVsShotIntersection=intersection.size();

    		// check if insersection size and ship length is same or not
    		// if yes then ship needs to be sunken
    		if(shipLength == occupiedAreaVsShotIntersection)
    		{
    			 tempSunken = true;
    		}
    	}
    	if(tempHit)
    	{
    		break;
    	}
    }

    if(tempSunken)
    {
    	return Shot::Impact::SUNKEN;
    }
    else if(tempHit)
    {
    	return Shot::Impact::HIT;
    }
    else
    {
    	board[shot.getTargetPosition().getRow()-65]
			  [shot.getTargetPosition().getColumn()-1]='^';

    	return Shot::Impact::NONE;
    }
}

const set<GridPosition> OwnGrid::getShotAt() const
{
	return shotAt;
}

OwnGrid::~OwnGrid()
{
	for(int i=0; i<rows; ++i)
	{
		delete[] board[i];
	}
	delete[] board;
}
