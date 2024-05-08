#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"
#include <iostream>

#include<memory> //required for shared pointer

using std::cout;
using std::endl;

class ConsoleView
{
	Board *board;
	std::shared_ptr<Board> board_s_ptr;

public:

	ConsoleView(Board* board);
	void print();
	void printPtr();
	~ConsoleView();

	ConsoleView(std::shared_ptr<Board> board_s_ptr);
	std::shared_ptr<Board>& getBoardSPtr();
	char modifyOwnGrid(int row,int col);
	char modifyOppGrid(int row,int col);

};

#endif /* CONSOLEVIEW_H_ */
