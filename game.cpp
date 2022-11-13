#include "game.h"

//���� ����
void ticTacToe::printBoard()
{
	system("cls");
	//���带 ���� �� ����� �̿��ϹǷ� y�� ����, x���� ���߿� ����
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << "|" << _board[x][y];
		}
		cout << endl;
	}
}

//�̱�� ��� ����� �� ����
bool ticTacToe::isWinPlayer()
{
	/*
	* �Ʒ��� ���� ��� O�� �¸�
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
	* �Ʒ��� ���� ��� O�� �¸�
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
	* �Ʒ��� ���� ��� O�� �¸�
	* O|O|X
	* X|O|X
	* O|X|O
	*/
	if (_board[0][0] != ' ' &&
		_board[0][0] == _board[1][1] &&
		_board[1][1] == _board[2][2])
		return true;

	/*
	* �Ʒ��� ���� ��� O�� �¸�
	* X|O|O
	* X|O|X
	* O|X|O
	*/
	if (_board[0][2] != ' ' &&
		_board[0][2] == _board[1][1] &&
		_board[1][1] == _board[2][0])
		return true;

	//���� ��쿡 �ش����� ���� ��� �׻� false ����
	return false;
}

int main()
{
	//ticTacToe Ŭ������ game ������ ����
	ticTacToe game;

	while (true)
	{
		system("cls");
		cout << "O �Ǵ� X�� ���� �� �ּ���." << endl;
		cout << "O = 0, X= 1" << endl;
		cout << "�Է� :";
		cin >> game._turn;
		//_turn ������ �Է°��� 0�̳� 1�� ��� while���� ��������
		if (game._turn == 0 || game._turn == 1) break;
		//_turn ������ �Է°��� 0�̳� 1�� �ƴ� ��� �ٽ� �ݺ�
		else cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է� �� �ּ���." << endl;
	}

	//�� 9�� ����
	for (int i = 0; i < 9; i++)
	{
		game.printBoard();

		//���� 0�� ��� O�� ����, 1�� ��� X�� ����
		if (game._turn == 0) cout << "O�� �����Դϴ�." << endl;
		else if (game._turn == 1) cout << "X�� �����Դϴ�." << endl;

		//x�� y ��ǥ ���������� �Է�
		cout << "X ��ǥ�� �Է� �� �ּ���.  �Է� :";
		cin >> game._locaX;
		cout << "Y ��ǥ�� �Է� �� �ּ���.  �Է� :";
		cin >> game._locaY;

		//�̹� �Է� �Ǿ��ִ� ��ǥ�� ��� ���Է� ��û
		if (_board[game._locaX][game._locaY] != ' ')
		{
			cout << "�̹� �Է� �Ǿ� �ֽ��ϴ�." << endl;
			i--; //�̹� �Է� �� ��ǥ�� ��� ī��Ʈ�� �Ǿ �ȵǹǷ� 1ȸ ����
			system("cls");
		}
		//�̹� �Է� �� ��ǥ�� �ƴ� ��� ������ ����
		else
		{
			//O�� ���� ��� �Է��� ��ǥ�� O ����
			if (game._turn == 0)
			{
				_board[game._locaX][game._locaY] = 'O';
				game._turn = 1;

				game.printBoard();
				//O�� �̰��� ��� ����� ���� ������ ��� O ��� �� ���� 
				if (game.isWinPlayer() == true)
				{
					cout << "O" << endl;
					break;
				}
			}
			//O�� ���� �ƴ� ���, X�� ���̹Ƿ� �Է��� ��ǥ�� X ����
			else
			{
				_board[game._locaX][game._locaY] = 'X';
				game._turn = 0;

				game.printBoard();
				//X�� �̰��� ��� ����� ���� ������ ��� X ��� �� ���� 
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