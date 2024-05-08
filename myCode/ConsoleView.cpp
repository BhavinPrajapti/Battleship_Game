
//	#include "Board.h"
//	#include <iostream>
//
//	#include<memory> //required for shared pointer
//
//	using std::cout;
//	using std::endl;
//
//	class ConsoleView
//	{
//		Board *board;
//		std::shared_ptr<Board> board_s_ptr;
//
//	public:
//
//		ConsoleView(Board* board);
//		void print();
//		void printPtr();
//		~ConsoleView();
//
//		ConsoleView(std::shared_ptr<Board> board_s_ptr);
//		std::shared_ptr<Board>& getBoardSPtr();
//		char modifyOwnGrid(int row,int col);
//		char modifyOppGrid(int row,int col);
//
//	};

#include "ConsoleView.h"
#include<iostream>

ConsoleView::ConsoleView(Board *board)
{
	this->board=board;
}

void ConsoleView::print()
{
	//print column number(first line)
	for(int boardCount=1; boardCount<=2; boardCount++)
	{
		cout<<"   ";
		for(int y=1 ; y <= board->getColumns() ; y++)
		{
			if( (y/10) == 0)
			{
				cout<<"  ";
			}
			else
			{
				cout<<y/10<<" ";
			}
		}
	}
	cout<<endl;

	//print column number(second line)
	for(int boardCount=1; boardCount<=2; boardCount++)
	{
		cout<<"   ";
		for(int y=1 ; y <= board->getColumns() ; y++)
		{
			cout<<y%10<<" ";
		}
	}
	cout<<endl;

	//print row number and grid contains
	for( int x=0 ; x < board->getRows() ; x++)
	{
		cout<<" "<<char('A'+x)<<" ";

	for ( int y=0; y < board->getColumns() ; y++)
	{
		cout<<board->getOwnGrid().getBoard()[x][y]<<" ";
	}
	    cout<<" "<<char('A'+x)<<" ";


	    for ( int y=0; y < board->getColumns() ; y++)
		{
			cout<<board->getOpponentGrid().getBoard()[x][y]<<" ";
		}
	    cout << endl;
	}
}

ConsoleView::ConsoleView(std::shared_ptr<Board> board_s_ptr)
{
	this->board_s_ptr=board_s_ptr;
}

std::shared_ptr<Board>& ConsoleView::getBoardSPtr()
{
	return board_s_ptr;
}

ConsoleView::~ConsoleView()
{
}

char ConsoleView::modifyOwnGrid(int row, int col)
{
	OwnGrid& og=getBoardSPtr()->getOwnGrid();
	GridPosition g(char(row+65),col);

	for(auto ship : og.getShip()) {
		if(ship.occupiedArea().count(g)>0) {
			if(og.getShotAt().count(g)>0) {
				return 'O';
			}
			return'#';
		}}if(og.getShotAt().count(g)>0) {
			return '^';
	}
	return '~';
}

char ConsoleView::modifyOppGrid(int row, int col)
{
    OpponentGrid& opponentgrid = getBoardSPtr()->getOpponentGrid();

    GridPosition gridRef(char(row+65), col);

    for (const Ship& ship : opponentgrid.getSunkenShips())
    {
        if (ship.occupiedArea().count(gridRef) > 0)
        {
        	return '#'; //! Ship Hit and Sunk.
        }
    }

	auto shotsAt = opponentgrid.getShotsAt();

	auto shotsHit = shotsAt.find(gridRef);

    if (shotsHit != shotsAt.end())
    {
        if (shotsHit->second == Shot::Impact::HIT)
        {
            //! Not sunk but hit
            return '0';
        }
        else if(shotsHit->second == Shot::Impact::NONE)
        {
            //! Missed Shot
            return '^';
        }
    }

    return '~'; //! Empty sea
}

void ConsoleView::printPtr()
{
	//print column number(first line)
	for(int boardCount=1; boardCount<=2; boardCount++)
	{
		cout<<"   ";
		for(int y=1 ; y <= board_s_ptr->getColumns() ; y++)
		{
			if( (y/10) == 0)
			{
				cout<<"  ";
			}
			else
			{
				cout<<y/10<<" ";
			}
		}
	}
	cout<<endl;

	//print column number(second line)
	for(int boardCount=1; boardCount<=2; boardCount++)
	{
		cout<<"   ";
		for(int y=1 ; y <= board_s_ptr->getColumns() ; y++)
		{
			cout<<y%10<<" ";
		}
	}
	cout<<endl;
//	//print row number and grid contains
	for( int x=0 ; x < board_s_ptr->getRows() ; x++)
	{
		cout<<" "<<char('A'+x)<<" ";
		for ( int y=1; y < board_s_ptr->getColumns()+1 ; y++) {
			cout<<modifyOwnGrid(x,y)<<" ";
		}

		cout<<" "<<char('A'+x)<<" ";
				for ( int y=1; y < board_s_ptr->getColumns()+1 ; y++) {
					cout<<modifyOppGrid(x,y)<<" ";
				}

		cout<<endl;
	}}
