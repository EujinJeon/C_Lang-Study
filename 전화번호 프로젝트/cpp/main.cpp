#include "Class.h"
using namespace std;

int print_mainm(); //main.cpp main 함수에서 메인메뉴 출력 함수

int main()
{
	vector<PhoneNumber>p_data; //PhoneNumber Class데이터 타입 형태로 Vector p_data 선언

	// 프로그램 실행시 자동으로 추가될 데이터
	p_data.push_back(PhoneNumber("eujin", "010-7769-2466", "evil@gmail.com", "incheon", 19980308));
	p_data.push_back(PhoneNumber("jayce", "010-7349-1236", "adfd@gmail.com", "chuncheon", 19990311));
	p_data.push_back(PhoneNumber("jieun", "010-3465-4567", "qwer@gmail.com", "jeonju", 19970315));
	p_data.push_back(PhoneNumber("hyeonsoo", "010-2463-6789", "zxcv@gmail.com", "kangneung", 19920805));
	p_data.push_back(PhoneNumber("eunji", "010-0384-4623", "tyui@gmail.com", "seajong", 19940516));
	p_data.push_back(PhoneNumber("sangho", "010-0248-3124", "jkll@gmail.com", "kangnam", 19980429));
	p_data.push_back(PhoneNumber("jaehoon", "010-5636-2745", "cvbn@gmail.com", "kangseo", 19930226));
	p_data.push_back(PhoneNumber("heejin", "010-3411-1342", "dfgh@gmail.com", "seongbuk", 19960308));
	p_data.push_back(PhoneNumber("minji", "010-3240-7609", "iopu@gmail.com", "donghae", 19921218));
	p_data.push_back(PhoneNumber("sujin", "010-3076-1977", "cond@gmail.com", "samcheok", 19921218));
	p_data.push_back(PhoneNumber("sangwook", "010-2376-4537", "dlwlrma@gmail.com", "busan", 19921218));
	p_data.push_back(PhoneNumber("wonyoung", "010-1256-0967", "dkdldb@gmail.com", "daegu", 19921218));

	while (1) {
		int job = print_mainm(); //print_mainm() 함수를 호출하고 반환된 값을 입력받는다.
		switch (job) {
		case 1: 
			add(p_data); //p_data를 입력값으로 하는 add함수
			system("cls");
			break; //반환받은 값이 1일 때, 전화번호 추가 기능인 add 함수를 호출합니다.
		case 2:
			modified(p_data); //p_data를 입력값으로 하는 modified함수
			system("cls");
			break; //반환받은 값이 2일 때, 전화번호 수정 기능인 modified 함수를 호출합니다.
		case 3:
			deleted(p_data); //p_data를 입력값으로 하는 deleted함수
			system("cls");
			break; //반환받은 값이 1일 때, 전화번호 삭제 기능인 deleted 함수를 호출합니다.
		case 4:
			search(p_data); //p_data를 입력값으로 하는 search함수
			system("cls");
			break; //반환받은 값이 1일 때, 전화번호 검색 기능인 search 함수를 호출합니다.
		case 5:
			sorted(p_data); //p_data를 입력값으로 하는 sorted함수
			system("cls");
			break; //반환받은 값이 1일 때, 전화번호 정렬 기능인 sorted 함수를 호출합니다.
		case 0:
			cout << "프로그램을 종료합니다." << endl;
			Sleep(3000);
			system("cls");
			return 0; //반환받은 값이 0일 때, 프로그램을 종료합니다.
		}
	}
	
	system("pause");
}

int print_mainm() {
	int x = 0, y = 0; // gotoxy 함수에 입력될 좌표 변수
	///////// 메인 메뉴 출력 ////////
	cout << "> 전화번호 추가" << endl;
	cout << "  전화번호 수정" << endl;
	cout << "  전화번호 삭제" << endl;
	cout << "  전화번호 검색" << endl;
	cout << "  전화번호 정렬" << endl;

	while (1) {
		int mkey = GetKey(); //GetKey 함수를 통해서 어떤 키보드 버튼을 눌렀는지 입력받습니다.
		switch (mkey) { //switch ~case문으로 입력된 키보드값에 맞는 작업을 합니다.
		case 72://입력된 키보드가 윗 방향키일 경우
			if (y > 0) { // 0보다 위로 이동할 수 없도록 막아주는 역할입니다.
				gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 있던 > 커서를 지웁니다.
				gotoxy(x, --y); //콘솔화면에서 위로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 80: //입력된 키보드가 아래 방향키일 경우
			if (y < 4) { //4보다 밑으로 이동할 수 없도록 막아주는 역할입니다.
				gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 있던 > 커서를 지웁니다.
				gotoxy(x, ++y); //콘솔화면에서 아래로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 27: //입력된 키보드가 ESC일 경우
			return 0; //0값을 반환합니다.
		case 13: //입력된 키보드가 ENTER일 경우
			return y + 1; //y좌표값에 1더한 값으로 반환합니다.
		}
	}
}