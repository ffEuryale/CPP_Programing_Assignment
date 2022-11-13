#include "game.h"

//보드 생성
void ticTacToe::printBoard()
{
	system("cls");
	//보드를 만들 때 행렬을 이용하므로 y축 먼저, x축은 나중에 선언
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << "|" << _board[x][y];
		}
		cout << endl;
	}
}

//이기는 모든 경우의 수 지정
bool ticTacToe::isWinPlayer()
{
	/*
	* 아래와 같은 경우 O의 승리
	* O|O|O
	* O|X|X
	* X|O|X
	*/
	for (int i = 0; i < 3; i++)
	{
		if (_board[i][0] != ' ' &&
			_board[i][0] == _board[i][1] &&
			_board[i][1] == _board[i][2])
		{
			return true;
		}
	}

	/*
	* 아래와 같은 경우 O의 승리
	* O|O|X
	* O|X|O
	* O|X|X
	*/
	for (int i = 0; i < 3; i++)
	{
		if (_board[0][i] != ' ' &&
			_board[0][i] == _board[1][i] &&
			_board[1][i] == _board[2][i])
		{
			return true;
		}
	}

	/*
	* 아래와 같은 경우 O의 승리
	* O|O|X
	* X|O|X
	* O|X|O
	*/
	if (_board[0][0] != ' ' &&
		_board[0][0] == _board[1][1] &&
		_board[1][1] == _board[2][2])
		return true;

	/*
	* 아래와 같은 경우 O의 승리
	* X|O|O
	* X|O|X
	* O|X|O
	*/
	if (_board[0][2] != ' ' &&
		_board[0][2] == _board[1][1] &&
		_board[1][1] == _board[2][0])
		return true;

	//위의 경우에 해당하지 않을 경우 항상 false 상태
	return false;
}

int main()
{
	//ticTacToe 클래스를 game 변수로 선언
	ticTacToe game;

	while (true)
	{
		system("cls");
		cout << "O 또는 X를 선택 해 주세요." << endl;
		cout << "O = 0, X= 1" << endl;
		cout << "입력 :";
		cin >> game._turn;
		//_turn 변수에 입력값이 0이나 1일 경우 while문을 빠져나감
		if (game._turn == 0 || game._turn == 1) break;
		//_turn 변수에 입력값이 0이나 1이 아닐 경우 다시 반복
		else cout << "잘못 입력하셨습니다. 다시 입력 해 주세요." << endl;
	}

	//총 9턴 진행
	for (int i = 0; i < 9; i++)
	{
		game.printBoard();

		//턴이 0일 경우 O의 차례, 1일 경우 X의 차례
		if (game._turn == 0) cout << "O의 차례입니다." << endl;
		else if (game._turn == 1) cout << "X의 차례입니다." << endl;

		//x와 y 좌표 순차적으로 입력
		cout << "X 좌표를 입력 해 주세요.  입력 :";
		cin >> game._locaX;
		cout << "Y 좌표를 입력 해 주세요.  입력 :";
		cin >> game._locaY;

		//이미 입력 되어있는 좌표의 경우 재입력 요청
		if (_board[game._locaX][game._locaY] != ' ')
		{
			cout << "이미 입력 되어 있습니다." << endl;
			i--; //이미 입력 된 좌표의 경우 카운트가 되어선 안되므로 1회 차감
			system("cls");
		}
		//이미 입력 된 좌표가 아닌 경우 게임의 진행
		else
		{
			//O의 턴일 경우 입력한 좌표에 O 삽입
			if (game._turn == 0)
			{
				_board[game._locaX][game._locaY] = 'O';
				game._turn = 1;

				game.printBoard();
				//O가 이겼을 모든 경우의 수에 충족할 경우 O 출력 및 종료 
				if (game.isWinPlayer() == true)
				{
					cout << "O" << endl;
					break;
				}
			}
			//O의 턴이 아닌 경우, X의 턴이므로 입력한 좌표에 X 삽입
			else
			{
				_board[game._locaX][game._locaY] = 'X';
				game._turn = 0;

				game.printBoard();
				//X가 이겼을 모든 경우의 수에 충족할 경우 X 출력 및 종료 
				if (game.isWinPlayer() == true)
				{
					cout << "X" << endl;
					break;
				}
			}
		}
	}

	cout << "\0" << endl;

	return 0;
}