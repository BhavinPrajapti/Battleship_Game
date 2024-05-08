#ifndef SHIP_H_
#define SHIP_H_
#include "GridPosition.h"
#include <set>

using std::set;

/**
 * @class Ship
 * @brief Represent ship on a grid with bow and stern position
 *
 */
class Ship
{
	/**
	 * @brief Private. It is bow position of the Ship
		 */
	GridPosition bow;

	/**
		 * @brief Private. It is stern position of the Ship
			 */
	GridPosition stern;

public:

	/**
		 * @fn  Ship(const GridPosition&, const GridPosition&)
	 * @brief parameterise constructor. It receives bow and stern as parameters
	 *
	 * @param bow
	 * @param stern
	 */
	Ship( const GridPosition& bow, const GridPosition& stern);

	/**
		 * @fn bool isValid()const
	 * @brief checks if ship is valid or not
	 *
	 * checks ship length (between 2 to 5) and ship should be vertical or
	 * horizontal, not diagonal
	 *
	 * @return True for the valid ship, otherwise false
	 */
	bool isValid() const;

	/**
		 * @fn int length()const
	 * @brief getter for length of the ship
	 *
	 * @return length of the ship
	 */
	int length() const;

	/**
		 * @fn GridPosition getBow()const
	 * @brief getter for bow position value.
	 *
	 * @return bow position
	 */
	GridPosition getBow() const;

	/**
		 * @fn GridPosition getStern()const
	 * @brief getter for stern position value.
	 *
	 * @return stern position
	 */
	GridPosition getStern() const;

	/**
		 * @fn const set<GridPosition> occupiedArea()const
	 * @brief container of the occupied area of the ship
	 *
	 * @return set of GridPosition represents occupied area
	 */
	const set<GridPosition> occupiedArea() const;

	/**
		 * @fn const set<GridPosition> blockedArea()const
	 * @brief container of the blocked area of the ship
	 *
	 * @return set of GridPosition represents blocked area
	 */
	const set<GridPosition> blockedArea() const;

	/**
		 * @fn  ~Ship()
	 * @brief Destructor of Ship class
	 *
	 */
	~Ship();

};

#endif /* SHIP_H_ */
