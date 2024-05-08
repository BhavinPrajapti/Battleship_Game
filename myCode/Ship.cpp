#include "Ship.h"

Ship::Ship(const GridPosition &bow, const GridPosition &stern) : bow(bow),
		stern(stern){}

bool Ship::isValid() const
{
	if( bow.isValid() == true && stern.isValid() == true)
	{
		if( (bow.getRow() == stern.getRow() ||
				bow.getColumn() == stern.getColumn())
				&& (this->length()>=2 && this->length()<=5))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int Ship::length() const
{
	return abs( (bow.getColumn() - stern.getColumn()) +
			(bow.getRow() - stern.getRow())) + 1;
}

GridPosition Ship::getBow() const
{
	return bow;
}

GridPosition Ship::getStern() const
{
	return stern;
}

const set<GridPosition> Ship::occupiedArea() const
{
	set<GridPosition> tempOccupiedArea;
	if(bow.getRow()==stern.getRow()) // ship is horizontal
	{
		for(int i=0; i<length();++i)
		{
			if(stern.getColumn()<bow.getColumn())
			{
				tempOccupiedArea.insert(GridPosition(bow.getRow(),
						stern.getColumn()+i));
			}
			else
			{
				tempOccupiedArea.insert(GridPosition(bow.getRow(),
						bow.getColumn()+i));
			}
		}
	}
	else if(bow.getColumn()==stern.getColumn()) // ship is vertical
		{
			for(int i=0; i<length();++i)
			{
				if(stern.getRow()<bow.getRow())
				{
					tempOccupiedArea.insert(GridPosition(stern.getRow()+i,
							bow.getColumn()));
				}
				else
				{
					tempOccupiedArea.insert(GridPosition(bow.getRow()+i,
							bow.getColumn()));
				}
			}
		}
	return tempOccupiedArea;
}

const set<GridPosition> Ship::blockedArea() const
{
	set<GridPosition> tempBlockedArea;
	for( auto itr_occupied_area : occupiedArea() )
	{
		char newRow = itr_occupied_area.getRow();
		int newCol = itr_occupied_area.getColumn();

		if( itr_occupied_area.isValid() == 1 )
		{
			for ( int i=-1; i<=1 ; ++i)
			{
				for( int j=-1; j<=1 ; ++j)
				{
					char neighborRow = newRow + i;
					int neighborCol = newCol + j;

					if( GridPosition(neighborRow,neighborCol).isValid()==1)
					{
						tempBlockedArea.insert(GridPosition
								(neighborRow,neighborCol));
					}
				}
			}
		}
	}
	return tempBlockedArea;
}

Ship::~Ship()
{
}

//#include "Shot.h"
//
//Shot::Shot(GridPosition targetPosition) : targetPosition(targetPosition){}
//
//GridPosition Shot::getTargetPosition() const
//{
//	return targetPosition;
//}
