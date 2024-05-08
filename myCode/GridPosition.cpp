#include "GridPosition.h"

GridPosition::GridPosition(char row, int column) : row(row), column(column){}

GridPosition::GridPosition(string position)
{
	row=position[0];
	column=std::stoi(position.substr(1));
}

bool GridPosition::isValid() const
{
	if ( (row >= 'A' && column <= 'Z') && (column >= 1) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

char GridPosition::getRow() const
{
	return row;
}

int GridPosition::getColumn() const
{
	return column;
}

bool GridPosition::operator == (const GridPosition& other) const
{
	if ( row == other.row && column == other.column)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GridPosition::operator <(const GridPosition &other) const
{
	if( row < other.row || ( row == other.row && column < other.column) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

GridPosition::operator string() const
{
	return string(row + to_string(column));
}

GridPosition::~GridPosition()
{
}
