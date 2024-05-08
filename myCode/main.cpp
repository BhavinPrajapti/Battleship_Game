#include "GridPosition.h"
#include "Ship.h"
#include "OwnGrid.h"
#include "OpponentGrid.h"
#include "Board.h"
#include "ConsoleView.h"
#include "Shot.h"
#include "part1tests.h"
#include "part3tests.h"
#include "part2tests.h"
#include "gamePlayDemo.h"
#include<memory>

int main ()
{
	part1tests();
	part2tests();
	part3tests();
	gamePlayDemo();

	cout<<"Creating and printing 10x10 empty Board"<<endl;
	Ship ship1(GridPosition("A1"),GridPosition("C1"));
	Ship ship2(GridPosition("F3"),GridPosition("F7"));

	std::shared_ptr<Board> board= std::make_shared<Board>(10,10);

	ConsoleView console(board);

	console.getBoardSPtr()->getOwnGrid().placeShip(ship1);
	console.getBoardSPtr()->getOwnGrid().placeShip(ship2);

	//OwnGrid& owngrid=console.getBoardSPtr()->getOwnGrid()
	//owngrid.placeShip(ship1);

	//console.getBoardSPtr()->getOwnGrid().takeBlow(GridPosition("A1"));

	console.getBoardSPtr()->getOwnGrid().takeBlow(GridPosition("A1"));
	console.getBoardSPtr()->getOwnGrid().takeBlow(GridPosition("A2"));
	console.getBoardSPtr()->getOwnGrid().takeBlow(GridPosition("B1"));
	console.getBoardSPtr()->getOwnGrid().takeBlow(GridPosition("C1"));
	console.getBoardSPtr()->getOwnGrid().takeBlow(GridPosition("F2"));
	console.getBoardSPtr()->getOwnGrid().takeBlow(GridPosition("F3"));



	//console.getBoardSPtr()->getOpponentGrid().shotResult(GridPosition("C1"), Shot::HIT);

	console.getBoardSPtr()->getOpponentGrid().shotResult(GridPosition("C1"), Shot::NONE);
	console.getBoardSPtr()->getOpponentGrid().shotResult(GridPosition("D1"), Shot::HIT);
	console.getBoardSPtr()->getOpponentGrid().shotResult(GridPosition("E1"), Shot::NONE);
	console.getBoardSPtr()->getOpponentGrid().shotResult(GridPosition("D3"), Shot::HIT);
	console.getBoardSPtr()->getOpponentGrid().shotResult(GridPosition("D4"), Shot::NONE);
	console.getBoardSPtr()->getOpponentGrid().shotResult(GridPosition("D2"), Shot::SUNKEN);
	console.getBoardSPtr()->getOpponentGrid().shotResult(GridPosition("B6"), Shot::HIT);
	console.getBoardSPtr()->getOpponentGrid().shotResult(GridPosition("C6"), Shot::HIT);



	console.printPtr();


	vector<Ship> sunkenships= console.getBoardSPtr()-> getOpponentGrid().getSunkenShips();

	cout<<"\nSunken Ship Bow is: "<<string(sunkenships[0].getBow())<<endl;
	cout<<"Sunken Ship Stern is: "<<string(sunkenships[0].getStern())<<endl;

	std::string str="bhavin";
	//cout<<str.length();	//string length here is 6
	//bool empty=str.empty();  //if empty then return true
	//str.clear(); //void for clearing
	//str.append(" prajapati");
	//cout<<str;	//bhavin prajapati
	//cout<<str.at(0);	//b - return charactrt
	//str.insert(0,"@"); 	//@bhavin
	//cout<<str;
	//cout<<str.find('a');	//3
	//cout<<str.size();
	//str.erase(2,2);		//start erasing from 2 and 1 is no of element you want to erase
//	cout<<str;	//bhin
	string b=str.substr(3);	//substring create new string based on specify starting ending point
	cout<<b;	//vin
	string time="11:50";
	string h=time.substr(0,time.find(':'));
	string min=time.substr(time.find(':')+1);
	cout<<h<<min;

	//string s1="abcdefg";
	//char buf[20];
	//s1.copy(buf,10);
	//cout<<buf[0];
	//s1.push_back('s');
	//s1.pop_back();
	string s1="bhavin";
	replace(s1.begin(),s1.end(),'a','@');
	//int num=count_if(s1.begin(),s1.end(),[](char c) {return (c>='b');});
	cout<<s1;
	cout<<endl;

	string alpha="-bhbk";

	bool is=std::all_of(alpha.begin(),alpha.end(), [](char c) {return (std::isalpha(c));}  );
	cout<<is;
	return 0;

}
