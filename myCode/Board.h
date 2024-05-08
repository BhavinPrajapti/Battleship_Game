#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * @class Board
 * @brief it contains all the data of the game. main class.
 * it replaces the physical papers
 *
 */
class Board
{
	/**
	 * @brief Private. it's board of the main player.
		 */
	OwnGrid ownGrid;

	/**
	 * @brief Private. It's board of the opponent.
		 */
	OpponentGrid opponentGrid;

public:

	/**
		 * @fn  Board(int, int)
	 * @brief Parameterise constructor. It receives row and column as parameters
	 *
	 * @param rows
	 * @param columns
	 */
	Board(int rows, int columns);

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
		 * @fn OwnGrid getOwnGrid&()
	 * @brief getter for main player data.
	 *
	 * @return OwnGrid
	 */
	OwnGrid& getOwnGrid();

	/**
		 * @fn OpponentGrid getOppentGrid&()
	 * @brief getter for opponent player data
	 *
	 * @return OpponentGrid
	 */
	OpponentGrid& getOpponentGrid();

	/**
		 * @fn  ~Board()
	 * @brief destructor of Board Class
	 *
	 */
	~Board();

};

#endif /* BOARD_H_ */
