#include "Move.h"
void gotoxy(int x, int y) {
	COORD Pos; //콘솔화면의 좌표 변수 POS를 선언
	Pos.X = x; //Pos에 있는 X좌표 변수에 메개변수 x를 입력합니다.
	Pos.Y = y; //Pos에 있는 Y좌표 변수에 메개변수 y를 입력합니다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	//콘솔 화면에서 입력된 좌표값으로 이동합니다.
}