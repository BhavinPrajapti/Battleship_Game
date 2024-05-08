#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>

using std::string;
using std::stoi;
using std::to_string;

/**
 * @class GridPosition
 * @brief Represents a position on grid.
 * This defines a grid position by specifying a row and column.
 * This is widely used class in the project for positions of ships and shots
 *
 */
class GridPosition
{

	 /**
	  * @brief Private. It is row position in the board
		 */
	char row;

	/**
	 * @brief Private. It is column position in the board
		 */
	int column;

public:

	/**
		 * @fn  GridPosition(char, int)
	 * @brief parameterise constructor. It receives row and column as parameters
	 *
	 * @param row
	 * @param column
	 */
	GridPosition(char row, int column);

	/**
		 * @fn  GridPosition(string)
	 * @brief parameterise constructor. It receives string as a parameter.
	 * Received parameter is spited in row and column.
	 *
	 * @param position
	 */
	GridPosition(string position);

	/**
		 * @fn bool isValid()const
	 * @brief checks if the grid position is valid.
	 *
	 * @return True for the valid grid position, otherwise False.
	 */
	bool isValid() const;

	/**
		 * @fn char getRow()const
	 * @brief getter for the row position value.
	 *
	 * @return row
	 */
	char getRow() const;

	/**
		 * @fn int getColumn()const
	 * @brief getter for the column position value.
	 *
	 * @return column
	 */
	int getColumn() const;

	/**
		 * @fn bool operator ==(const GridPosition&)const
	 * @brief overloaded == operator for class GridPosition objects.
	 *
	 * @param other
	 * @return True if both objects are equal, otherwise False.
	 */
	bool operator== (const GridPosition& other) const;

	/**
		 * @fn bool operator <(const GridPosition&)const
	 * @brief overloaded < operator for class GridPosition objects.
	 * for arranging instances inside container
	 * for identifying bow and stern of the ship
	 * for comparing GridPositions
	 *
	 * @param other
	 * @return True if this object is less than other object, otherwise False.
	 */
	bool operator< (const GridPosition& other) const;

	/**
		 * @fn  operator std::__cxx11::basic_string<char,std::char_traits<char>,
		 * std::allocator<char>>()const
	 * @brief Operator String
	 *
	 * @return string of (row+column)
	 */
	operator string() const;

	/**
		 * @fn  ~GridPosition()
	 * @brief Destructor of GridPosition class
	 *
	 */
	~GridPosition();

};

#endif /* GRIDPOSITION_H_ */
