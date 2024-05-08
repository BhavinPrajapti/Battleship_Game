#include "Shot.h"

Shot::Shot(GridPosition targetPosition) : targetPosition(targetPosition){}

GridPosition Shot::getTargetPosition() const
{
	return targetPosition;
}

Shot::~Shot()
{
}
