#pragma once
#include <iostream>

using namespace std;

//������ �ʱ� �� ����
char _board[3][3] = { {' ',' ',' '},{' ',' ',' '} ,{' ',' ',' '} };

class ticTacToe
{
public:
	void printBoard();
	bool isWinPlayer();

	int _locaX; //X �� ��ġ�� �Է��ϱ� ���� ����
	int _locaY; //Y �� ��ġ�� �Է��ϱ� ���� ����
	int _turn; //O, X�� ���� ī��Ʈ �ϱ� ���� ����

};
