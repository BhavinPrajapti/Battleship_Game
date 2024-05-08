#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * @class Shot
 * @brief Contains all the data of the shots. It has ENUM for the shot results.
 *
 */
class Shot
{
	/**
	 * @brief Private. It is the Position of the shot.
		 */
	GridPosition targetPosition;

public:
	/**
		 * @fn  Shot(GridPosition)
	 * @brief Parameterise constructor. It receives position of the shot.
	 *
	 * @param targetPosition
	 */
	Shot(GridPosition targetPosition);

	/**
		 * @fn GridPosition getTargetPosition()const
	 * @brief getter for the shot GridPosition
	 *
	 * @return position of the shot
	 */
	GridPosition getTargetPosition() const;

	/**
		 * @enum Impact
	 * @brief contains result of the shot
	 *
	 */
	enum Impact
	{
		NONE, HIT, SUNKEN
	};

	/**
		 * @fn  ~Shot()
	 * @brief Destructor of the Shot class
	 *
	 */
	~Shot();

};


#endif /* SHOT_H_ */
