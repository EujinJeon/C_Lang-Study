#pragma once
#include<iostream>
#include<conio.h>


enum KEY {
	KEY_UP = 72, KEY_DOWN = 80, KEY_ESC = 27, KEY_DEL = 83, KEY_ENTER = 13
}; //���������� Ư��Ű���� �Է¿� ���� ����

inline KEY GetKey() // Ű���� �ݹ� ����Լ�

{
	int nKey = _getch(); //_getch()�� ���ؼ� Ű���� �Է��� �޽��ϴ�.
	if (nKey == 0 || nKey == 224) { // �Է��� Ư��Ű�� ��쿡�� �۵�
		return (KEY)_getch();
	}
	return (KEY)nKey; // ������ ���·� Ű���� �Է°� ��ȯ
}

