#pragma once
#include <iostream>

using namespace std;

//보드의 초기 값 설정
char _board[3][3] = { {' ',' ',' '},{' ',' ',' '} ,{' ',' ',' '} };

class ticTacToe
{
public:
	void printBoard();
	bool isWinPlayer();

	int _locaX; //X 의 위치를 입력하기 위한 변수
	int _locaY; //Y 의 위치를 입력하기 위한 변수
	int _turn; //O, X의 턴을 카운트 하기 위한 변수

};
