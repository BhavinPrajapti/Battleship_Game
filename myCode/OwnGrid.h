#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include "Shot.h"

#include <vector>
#include <map>
#include <algorithm>

using std::map;
using std::vector;

/**
 * @class OwnGrid
 * @brief Represent player's own grid in the game
 *
 * this class is the board with ship from main player's prospective
 * It contains all the data of the board i.e ship location, opponent
 *  shot location
 *
 */
class OwnGrid
{
	 /**
	 * @brief Private. It is row position in the board
	 */
	int rows;

	/**
	* @brief Private. It is column position in the board
    */
	int columns;

	/**
	 * @brief Private. It contains all ships.
		 */
	vector<Ship> ships;

	/**
	 * @brief Private. Map of ship quantity vs ship length
		 */
	map<int,int> shipMap;

	/**
	 * @brief Private. double char board array of main player.
		 */
	char** board;

	/**
	 * @brief Private. It contains shots from opponent.
		*/
	set<GridPosition> shotAt;

public:

	/**
		 * @fn  OwnGrid(int, int)
	 * @brief parameterise constructor. It receives row and column as parameters
	 *
	 * @param rows
	 * @param columns
	 */
	OwnGrid ( int rows, int columns);

	/**
		 * @fn int getRows()const
	 * @brief getter for the row position value.
	 *
	 * @return rows
	 */
	int getRows() const;

	/**
		 * @fn int getColumns()const
	 * @brief getter for the column position value.
	 *
	 * @return columns
	 */
	int getColumns() const;

	/**
		 * @fn bool placeShip(const Ship&)
	 * @brief places ship on the grid
	 *
	 * this member function checking all condition before placing any ship.
	 * checks ship is not intersecting with any other ship.
	 * checks length and number of ship are correct or not.
	 *
	 * @param ship
	 * @return true if ship placement successfull
	 */
	bool placeShip (const Ship& ship);

	/**
		 * @fn const vector<Ship> getShip()const
	 * @brief getter for the vector of ship
	 *
	 * @return ship
	 */
	const vector<Ship> getShip() const;

	/**
		 * @fn char getBoard**()
	 * @brief getter for the board
	 *
	 * @return board
	 */
	char** getBoard();

	/**
		 * @fn Shot::Impact takeBlow(const Shot&)
	 * @brief insert position of shot to the shot container. Also verify if shot
	 * is hitting the ship or not. and update the board accordingly.
	 * also it is verifying whether ship is sunked or not.
	 *
	 * @param shot
	 * @return shot impact
	 */
	Shot::Impact takeBlow(const Shot& shot);

	/**
		 * @fn const set<GridPosition> getShotAt()const
	 * @brief getter for the shot container
	 *
	 * @return shot GridPosition value
	 */
	const set<GridPosition> getShotAt() const;

	/**
		 * @fn  ~OwnGrid()
	 * @brief Destructor of OwnGrid Class
	 *
	 */
	virtual ~OwnGrid();

};

#endif /* OWNGRID_H_ */
