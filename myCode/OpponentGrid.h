#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"
#include "Shot.h"

#include <vector>
#include <map>

using std::vector;
using std::map;

/**
 * @class OpponentGrid
 * @brief Represent Opponent player's grid in the game
 * this class is the Opponent board from main player's prospective
 * main player know the ship location based on shots that given
 */
class OpponentGrid
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
	 * @brief Private. It contains all suken ships.
		 */
	vector<Ship> sukenShips;

	/**
	 * @brief Private. double char board array of opponent.
		 */
	char** board;

	/**
	 * @brief Private. map that contains shots of the main player & it's result
		 */
	map<GridPosition,Shot::Impact> shots;

public:

	/**
		 * @fn  OpponentGrid(int, int)
	 * @brief parameterise constructor. It receives row and column as parameters
	 *
	 * @param rows
	 * @param columns
	 */
	OpponentGrid(int rows, int columns);

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
		 * @fn char getBoard**()
	 * @brief getter for the board
	 *
	 * @return board
	 */
	char** getBoard();

	/**
		 * @fn const vector<Ship> getSunkenShips()const
	 * @brief getter for the sunkenships
	 *
	 * @return sunkenships
	 */
	const vector<Ship> getSunkenShips() const;

	/**
		 * @fn void shotResult(const Shot&, Shot::Impact)
	 * @brief shows result of the shot from main player prospectives
	 *
	 * It receives data of the shots and its impact
	 *
	 * @param shot
	 * @param impact
	 */
	void shotResult(const Shot& shot, Shot::Impact impact);

	/**
		 * @fn const map<GridPosition,Shot::Impact> getShotsAt&()const
	 * @brief getter for the shots positions  and it's impact
	 *
	 * @return shots
	 */
	const map<GridPosition,Shot::Impact>& getShotsAt() const;

	/**
		 * @fn  ~OpponentGrid()
	 * @brief Destructor of OpponentGrid Class
	 *
	 */
	virtual ~OpponentGrid();

};

#endif /* OPPONENTGRID_H_ */
