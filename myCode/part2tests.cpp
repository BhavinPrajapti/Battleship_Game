
#include "part2tests.h"

void assert2True(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 */
void part2tests ()
{

	//Test Blocked area
	assert2True(Ship(GridPosition("D1"),GridPosition("G1")).blockedArea() ==
		set<GridPosition>{GridPosition{"D1"}, GridPosition{"E1"},
		GridPosition{"F1"}, GridPosition{"G1"}, GridPosition{"D2"},
		GridPosition{"E2"}, GridPosition{"F2"}, GridPosition{"G2"},
		GridPosition{"H1"}, GridPosition{"H2"},
        GridPosition{"C1"}, GridPosition{"C2"}},
		"Blocked area is not correct");

	//Test PlaceShip
	Board board(10,10);

	assert2True(board.getOwnGrid().placeShip(Ship(GridPosition("D1"),
			GridPosition("D5"))),
			"Ship(length 5) is valid but not inserted");

	assert2True(!board.getOwnGrid().placeShip(Ship(GridPosition("G1"),
			GridPosition("G5"))),
			"can place two ships with length 5");

	assert2True(!board.getOwnGrid().placeShip(Ship(GridPosition('A',2),
			GridPosition("C2"))),
			"can place ship that is touching with other ship");

	assert2True(!board.getOwnGrid().placeShip(Ship(GridPosition('A',4),
			GridPosition('C',6))), "Can place non-straight ship");

	assert2True(!board.getOwnGrid().placeShip(Ship(GridPosition('G',1),
			GridPosition('H',4))),
			"Can place non-horizontal and non-vertical ship");

	assert2True(board.getOwnGrid().placeShip(Ship(GridPosition('J',8),
			GridPosition('J',10))),
			"Can not place ship at edges of the grid");



}






