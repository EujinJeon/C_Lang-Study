#include "Move.h"
void gotoxy(int x, int y) {
	COORD Pos; //�ܼ�ȭ���� ��ǥ ���� POS�� ����
	Pos.X = x; //Pos�� �ִ� X��ǥ ������ �ް����� x�� �Է��մϴ�.
	Pos.Y = y; //Pos�� �ִ� Y��ǥ ������ �ް����� y�� �Է��մϴ�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	//�ܼ� ȭ�鿡�� �Էµ� ��ǥ������ �̵��մϴ�.
}