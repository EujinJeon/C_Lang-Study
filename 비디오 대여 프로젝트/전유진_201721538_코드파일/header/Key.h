#ifndef Key_h
#define Key_h
#include<iostream>
#include<conio.h>


enum KEY {
	KEY_UP = 72, KEY_DOWN = 80, KEY_ESC = 27, KEY_DEL = 83, KEY_ENTER = 13,
	KEY_1 = 49, KEY_2 = 50, KEY_3 = 51, KEY_4 = 52
}; //열거형으로 특수키보드 입력에 대한 정의

inline KEY GetKey() // 키보드 콜백 기능함수
{
	int nKey = _getch(); //_getch()를 통해서 키보드 입력을 받습니다.
	if (nKey == 0 || nKey == 224) { // 입력이 특수키일 경우에만 작동
		return (KEY)_getch();
	}
	return (KEY)nKey; // 열거형 형태로 키보드 입력값 반환
}
#endif // !Key_h