
#include "part3tests.h"
#include "Board.h"

void assert3True(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 */
void part3tests ()
{

	Board board(10,10);

	//Test takeBlow(const Shot& shot) in OwnGrid

	//Placing 3 ships
	board.getOwnGrid().placeShip(Ship(GridPosition("B2"),GridPosition("B4")));
	board.getOwnGrid().placeShip(Ship(GridPosition("D4"),GridPosition("G4")));
	board.getOwnGrid().placeShip(Ship(GridPosition("F6"),GridPosition("F9")));

	assert3True(board.getOwnGrid().takeBlow(Shot(GridPosition("B2")))
			==Shot::HIT,"HIT was not consider");

	assert3True(board.getOwnGrid().takeBlow(Shot(GridPosition("E6")))
			==Shot::NONE,"NONE was not consider");

	assert3True(board.getOwnGrid().takeBlow(Shot(GridPosition("F8")))
			==Shot::HIT,"HIT was not consider");

	assert3True(board.getOwnGrid().takeBlow(Shot(GridPosition("F10")))
			==Shot::NONE,"NONE was not consider");

	assert3True(board.getOwnGrid().takeBlow(Shot(GridPosition("B5")))
			==Shot::NONE,"NONE was not consider");

	assert3True(board.getOwnGrid().takeBlow(Shot(GridPosition("B4")))
			==Shot::HIT,"HIT was not consider");

	assert3True(board.getOwnGrid().takeBlow(Shot(GridPosition("B3")))
			==Shot::SUNKEN,"SUNKEN was not consider");


	//Test SunkenShips

	board.getOpponentGrid().shotResult(Shot(GridPosition("D3")), Shot::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition("D5")), Shot::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition("A1")), Shot::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition("B1")), Shot::NONE);
	board.getOpponentGrid().shotResult(Shot(GridPosition("A2")), Shot::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition("D7")), Shot::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition("D6")), Shot::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition("D2")), Shot::NONE);
	board.getOpponentGrid().shotResult(Shot(GridPosition("D4")), Shot::SUNKEN);
	board.getOpponentGrid().shotResult(Shot(GridPosition("B2")), Shot::NONE);
	board.getOpponentGrid().shotResult(Shot(GridPosition("E2")), Shot::NONE);
	board.getOpponentGrid().shotResult(Shot(GridPosition("E10")), Shot::NONE);

	vector<Ship> v= board.getOpponentGrid().getSunkenShips();

	assert3True(v[0].occupiedArea() == set<GridPosition>{GridPosition{"D3"},
		GridPosition{"D4"}, GridPosition{"D5"}, GridPosition{"D6"},
		GridPosition{"D7"}}, " The Ship (D3-D7) was NOT in SunkenShips");

	assert3True(v[0].getBow()== GridPosition("D3"),
			"SunkenShip's (D3-D7) Bow was Incorrect");

	assert3True(v[0].getStern()== GridPosition("D7"),
			"SunkenShip's (D3-D7) Stern was Incorrect");

}



