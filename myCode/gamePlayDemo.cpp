#include "gamePlayDemo.h"
#include<vector>

void gamePlayDemo()
{

	// defining two ships

	Ship ship1(GridPosition("A1"),GridPosition("C1"));
	Ship ship2(GridPosition("F3"),GridPosition("F7"));

	cout<<"Creating and printing 10x10 empty Board"<<endl;

	// defining board with numbers of row and column value
	Board board(10,10);

	// defining cosoleview
	ConsoleView console(&board);

	//print board on console
	console.print();

	cout<<"\nPlacing 2 Ships (A1-C1) & (F3-F7) in the Board, "
			"and print the Board"<<endl;

	//placing the ships
	board.getOwnGrid().placeShip(ship1);
	board.getOwnGrid().placeShip(ship2);
	console.print();

	cout<<"\nShowing takeblow at A1, A2, B1, C1, F2, F3 GridPositions"<<endl;

	//Implementing TakeBlow Method
	board.getOwnGrid().takeBlow(GridPosition("A1"));
	board.getOwnGrid().takeBlow(GridPosition("A2"));
	board.getOwnGrid().takeBlow(GridPosition("B1"));
	board.getOwnGrid().takeBlow(GridPosition("C1"));
	board.getOwnGrid().takeBlow(GridPosition("F2"));
	board.getOwnGrid().takeBlow(GridPosition("F3"));

	console.print();

	cout<<"\nshowing shotResult of OpponentGrid"<<endl;

	//Implementing shotResult Method
	board.getOpponentGrid().shotResult(GridPosition("C1"), Shot::NONE);
	board.getOpponentGrid().shotResult(GridPosition("D1"), Shot::HIT);
	board.getOpponentGrid().shotResult(GridPosition("E1"), Shot::NONE);
	board.getOpponentGrid().shotResult(GridPosition("D3"), Shot::HIT);
	board.getOpponentGrid().shotResult(GridPosition("D4"), Shot::NONE);
	board.getOpponentGrid().shotResult(GridPosition("D2"), Shot::SUNKEN);
	board.getOpponentGrid().shotResult(GridPosition("B6"), Shot::HIT);
	board.getOpponentGrid().shotResult(GridPosition("C6"), Shot::HIT);

	console.print();

	cout<<"\nit is observed that Ship(D1-D3) is sunked"<<endl;

	cout<<"\nPrinting sunken ship's bow stern"<<endl;

	vector<Ship> sunkenships= board.getOpponentGrid().getSunkenShips();

	cout<<"\nSunken Ship Bow is: "<<string(sunkenships[0].getBow())<<endl;
	cout<<"Sunken Ship Stern is: "<<string(sunkenships[0].getStern())<<endl;

}

//#include "part2tests.h"
//
//void assert2True(bool condition, string failedMessage) {
//    if (!condition) {
//        cout << failedMessage << endl;
//    }
//}
//
///**
// */
//void part2tests ()
//{
//
//	//Test Blocked area
//	assert2True(Ship(GridPosition("D1"),GridPosition("G1")).blockedArea() ==
//		set<GridPosition>{GridPosition{"D1"}, GridPosition{"E1"},
//		GridPosition{"F1"}, GridPosition{"G1"}, GridPosition{"D2"},
//		GridPosition{"E2"}, GridPosition{"F2"}, GridPosition{"G2"},
//		GridPosition{"H1"}, GridPosition{"H2"},
//        GridPosition{"C1"}, GridPosition{"C2"}},
//		"Blocked area is not correct");
