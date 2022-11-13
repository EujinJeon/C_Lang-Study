#include "project.h"
using namespace std;

Customer::Customer(string r_name, string r_phonenum, string r_birth, string r_video) { //고객 클래스 생성자 구현
	name = r_name; //이름 변수 초기화
	phonenum = r_phonenum; //전화번호 변수 초기화
	birth = r_birth; //생년월일 변수 초기화
	video_rent = r_video; //대여중인 비디오 변수 초기화
}

Video::Video(string r_video_name, int r_rental_yn) { //비디오 클래스 생성자 구현
	video_name = r_video_name; //비디오 제목 변수 초기화
	rental_yn = r_rental_yn; //비디오 대여 여부 변수 초기화
}


//Vector 자료 출력 형식
void Customer::print_custom_info() {
	cout << name; //이름 출력
	cout.width(15); //필드폭 15
	cout << phonenum;//전화번호 출력
	cout.width(15); //필드폭 15
	cout << birth; // 생년월일 출력
	cout.width(15); //필드폭 15
	cout << video_rent; // 대여중인 비디오 출력(없으면 empty출력)
}

//검색기능
void searched(vector<Customer>& c_data, vector<Video>& v_data) { //통합 검색 기능함수
	system("cls"); //화면 클리어

	if (c_data.size() == 0) {
		cout << "고객데이터가 하나도 존재하지 않습니다.";
		Sleep(200);
		customer_add(c_data);
	} //고객 정보 벡터 사이즈가 0이면 고객 추가 함수 호출

	else if (v_data.size() == 0) {
		cout << "비디오 데이터가 하나도 존재하지 않습니다.";
		Sleep(200);
		video_add(v_data);
	} //비디오 벡터 사이즈가 0이면 비디오 입고 함수 호출

	string searching; //검색할 내용 입력할 변수
	int torn = 0; // 찾았는지 못찾았는지 구분하는 변수
	int keycode = 0, loopnum = 0; //키보드값 변수와, 무한반복문 탈출 변수

	while (1) {
		system("cls");
		cout << "검색하실 내용을 입력하시오.";
		cin >> searching; //검색할 내용 입력
		torn = searching_customer(c_data, searching); //고객 정보 검색함수 호출
		if (torn != 1) { //고객 정보 검색함수에어 못 찾았을 때...
			torn = searching_video(v_data, searching); //비디오 검색함수 호출
		}
		system("cls");
		if (torn != 1) {//비디오 검색함수에서도 못 찾았을 때...
			cout << "검색하신 내용을 찾을 수 없습니다."<<endl;
		}
		cout << "계속 검색하실 거면 ENTER, 나가실거면 ESC를 누르시오.";
		keycode = GetKey(); //사용자에게 키보드값을 입력받는 함수
		switch (keycode)
		{
		case 13: //사용자가 ENTER를 눌렀을 때
			continue;
			break;
		case 27: //사용자가 ESC를 눌렀을 때
			loopnum = 1;
			break;
		}
		if (loopnum == 1) break;
	}
}

//고객 검색기능
int searching_customer(vector<Customer>& c_data, string searched) {
	int keycode = 0, tmp = 0;
	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) {
		if (searched.compare(i->name) == 0) { //사용자가 입력한 내용과 데이터의 내용이 동일하면
			i->print_custom_info(); //찾은 데이터를 출력합니다.
			tmp = 1; //함수 종료시 반환할 값을 변경
			cout << "\nENTER를 누르면 창을 나갑니다.";
			keycode = GetKey();
			if(keycode == 13) break; //사용자가 ENTER를 누르면 고객 검색함수 종료
		}

		else continue;
	}
	return tmp; //tmp값을 반환
}

//비디오 검색 기능
int searching_video(vector<Video>& v_data, string searched) {
	int tmp = 0, keycode = 0;
	for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) {
		if (searched.compare(i->video_name) == 0) { //사용자가 입력한 내용과 데이터의 내용이 동일하면
			cout << i->video_name; //찾은 데이터를 출력합니다.
			if (i->rental_yn == 0) { //rental_yn == 0이면
				cout << "  대여가능" <<endl; //대여가능으로 출력
			}
			else {
				cout << "  대여중" << endl; //대여중으로 출력
			}
			tmp = 1; //함수 종료시 반환할 값을 변경
			cout << "\nENTER를 누르면 창을 나갑니다.";
			keycode = GetKey();
			if (keycode == 13) break; //사용자가 ENTER를 누르면 고객 검색함수 종료
			break;
		}

		else continue;
	}
	return tmp; //tmp값 반환
}

//고객 추가
void customer_add(vector<Customer>& c_data) {
	system("cls");
	int keycode = 0, loopnum = 0;
	Customer temp;
	while (1) {
		cout << "이름 전화번로 생년월일 순으로 입력하시오."<<endl;
		cin >> temp.name >> temp.phonenum >> temp.birth; //이름, 전화번호, 생년월일 입력합니다.
		if (atoi(temp.name.c_str()) == 0 && atoi(temp.phonenum.c_str()) > 0 && atoi(temp.birth.c_str()) > 0)
		{ //각 항목이 잘 입력되었을 경우...
			if (c_data.size() != 0) { //고객 정보 벡터 사이즈가 0이 아닐 경우
				for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) { //iterator를 활용한 반복문
					if (i->name == temp.name || i->birth == temp.birth || i->phonenum == temp.phonenum) { //입력한 내용과 동일한 내용이 있으면
						cout << "동일한 데이터가 발견되었습니다." << endl;
						cout << "3초후 메인메뉴로 넘어갑니다.";
						Sleep(300);
						return;//함수 종료
					}
				}
			}
			c_data.push_back(temp); //고객 정보 벡터에 추가
			cout << "고객을 더 추가하시겠습니까? ENTER : 계속추가, ESC : 종료";
			keycode = GetKey();
			switch (keycode)
			{
			case 13: //사용자가 ENTER를 누르면 계속추가
				continue;
				break;
			case 27: //사용자가 ESC를 누르면 함수종료
				system("cls");
				loopnum = 1;
				break;
			}
			if (loopnum == 1) break;
		}
		else { //사용자가 잘 못 입력했을 경우
			cin.clear(); //입력버퍼 초기화
			cout << "잘 못 입력하셨습니다.";
			cout << "\n3초후에 다시 입력하시오.";
			Sleep(300);
		}
	}

}

// 비디오 입고
void video_add(vector<Video>& v_data) {
	system("cls");
	int keycode = 0, loopnum = 0;
	Video temp;
	while (1) {
		cout << "비디오 이름을 입력하시오." << endl;
		cin >> temp.video_name; //비디오 제목을 입력합니다.
		if (atoi(temp.video_name.c_str()) == 0) { //비디오 제목을 잘 입력했을 경우...
			if (v_data.size() != 0) { //비디오 벡터 사이즈가 0이 아니면..
				for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) { //iterator를 활용한 반복문
					if (i->video_name == temp.video_name) { //입력한 내용과 기존의 데이터가 일치할 때
						cout << "동일한 데이터가 발견되었습니다." << endl;
						cout << "3초후 메인메뉴로 넘어갑니다.";
						Sleep(300);
						return; //함수 종료
					}
				}
			}
			temp.rental_yn = 0; //대여여부 대여가능으로 설정
			v_data.push_back(temp); //비디오 벡터에 데이터 추가
			cout << "비디오를 더 입고하시겠습니까? ENTER : 계속추가, ESC : 종료";
			keycode = GetKey();
			switch (keycode)
			{
			case 13: //사용자가 ENTER를 누르면 계속추가
				continue;
				break;
			case 27: //사용자가 ESC를 누르면 함수종료
				system("cls");
				loopnum = 1;
				break;
			}
			if (loopnum == 1) break;
		}

		else { //사용자가 잘 못 입력했을 경우
			cin.clear(); //입력버퍼 초기화
			cout << "잘 못 입력하셨습니다.";
			cout << "\n3초후에 다시 입력하시오.";
			Sleep(300);
		}
	}
}

// 비디오 대여
void video_rental(vector<Video>& v_data, vector<Customer>& c_data) {
	system("cls");
	if (v_data.size() == 0) { //비디오 벡터 사이즈가 0일 경우
		cout << "보유하고 있는 비디오가 없습니다." << endl;
		cout << "3초 후 비디오 입고로 넘어갑니다...";
		Sleep(300);
		video_add(v_data); //비디오 입고 함수 호출
	}

	else if (c_data.size() == 0) { //고객 정보 벡터 사이즈가 0일 경우
		cout <<"보유하고 있는 고객 정보가 없습니다.";
		cout << "3초 후 고객 추가로 넘어갑니다...";
		Sleep(300);
		customer_add(c_data); //고객 정부 추가 함수 호출
	}

	int x = 0, y = 0;
	int keycode = 0, choice = 0, choice2 = 0, loop = 0;
	string temp;
	for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) {
		if (i->rental_yn == 0) { //rental_yn이 0일 경우 대여가능 출력
			cout << "  ";
			cout << i->video_name << "  대여가능" << endl;
		}
		else { //rental_yn이 0이 아닐 경우 대여중 출력
			cout << "  ";
			cout << i->video_name << "  대여중" << endl;
		}
	}
	cout << "대여하고 싶은 비디오를 선택하시오. 방향키 위, 아래, ENTER를 활용하세요. ";
	gotoxy(x, y);
	cout << ">";
	while (1) {
		keycode = GetKey(); //사용자에게 키보드값을 입력받는 함수
		switch (keycode)
		{
		case 72: //입력된 키보드가 윗 방향키일 경우
			if (y > 0) { //커서가 0보다 작은 위치로 이동안한게 막아줍니다.
				gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 존재하는 > 커서를 지웁니다.
				gotoxy(x, --y); //콘솔화면에서 위로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 80: //입력된 키보드가 아래 방향키일 경우
			if (y < v_data.size()-1) { // c_data.size -1 값보다 아래로 이동할 수 없도록 막아주는 역할입니다.
				gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 존재하는 > 커서를 지웁니다.
				gotoxy(x, ++y); //콘솔화면에서 위로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 13:
			if (v_data[y].rental_yn == 1) { //선택한 비디오가 대여중인 경우..
				gotoxy(0, v_data.size() + 1);
				cout << "이미 대여한 비디오입니다."<<endl;
				cout << "3초후에 종료합니다...";
				Sleep(300);
				return; //함수 종료
			}
			choice = y;
			loop += 1; //무한반복문을 탈출하기 위한 1입력
			v_data[choice].rental_yn = 1; //선택한 비디오 대여중으로 변경
			system("cls");
			break;
		}
		if (loop != 0)break;
	}

	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) { //iterator를 사용한 반복문
		cout << "  ";
		i->print_custom_info(); cout << endl; //고객 정보 출력
	}
	x = 0, y = 0;
	gotoxy(x, y);
	cout << ">";
	while (1) {
		keycode = GetKey(); //사용자에게 키보드값을 입력받는 함수
		switch (keycode)
		{
		case 72: //입력된 키보드가 윗 방향키일 경우
			if (y > 0) { // 0보다 위로 이동할 수 없도록 막아주는 역할입니다.
				gotoxy(x, y);  //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 존재하는 > 커서를 지웁니다.
				gotoxy(x, --y); //콘솔화면에서 위로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 80: //입력된 키보드가 아래 방향키일 경우
			if (y < v_data.size() - 1) { // v_data.size -1 값보다 아래로 이동할 수 없도록 막아주는 역할입니다.
				gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 존재하는 > 커서를 지웁니다
				gotoxy(x, ++y); //콘솔화면에서 위로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 13:
			if (c_data[choice2].video_rent != "empty") { //대여한 비디오가 있을 경우
				gotoxy(0, c_data.size() + 1); //마지막줄로 이동합니다.
				cout << "이미 비디오를 대여한 고객입니다." <<endl;
				cout << "3초후에 종료합니다...";
				Sleep(300);
				return; //함수 종료
			}
			choice2 = y; //choice변수에 y값을 입력합니다.
			c_data[choice2].video_rent = v_data[choice].video_name; //고객 대여 비디오 변수에 입력
			gotoxy(0, c_data.size()+1); //마지막줄로 이동
			cout << "대여를 완료했습니다.";
			Sleep(300);
			system("cls");
			return; //함수 종료
		}
	}
	choice = 0, choice2 = 0;
	x = 0, y = 0;
}

//비디오 반납
void video_nrental(vector<Video>& v_data, vector<Customer>& c_data) { 
	system("cls");
	if (v_data.size() == 0) { //비디오 벡터 사이즈가 0일경우
		cout << "보유하고 있는 비디오가 없습니다.";
		cout << "\n 3초후 비디오 입고로 넘어갑니다.";
		Sleep(300);
		video_add(v_data); //비디오 입고 함수 호출
	}

	else if (c_data.size() == 0) { //고객 정보 벡터 사이즈가 0일 경우
		cout << endl << "보유하고 있는 고객 정보가 없습니다.";
		cout << "\n 3초후 고객 추가로 넘어갑니다.";
		Sleep(300);
		customer_add(c_data); //고객 정보 추가 함수 호출
	}

	int x = 0, y = 0;
	int keycode = 0, choose = 0;
	string temp;
	gotoxy(x, y);
	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) { //iterator를 사용한 반복문
		cout << "  ";
		i->print_custom_info(); //고객 정보 출력
		cout << endl;
	}
	cout << "반납할 고객을 선택하시오.(선택 : ENTER)";
	gotoxy(x, y);
	cout << ">";
	while (1) {
		keycode = GetKey(); //사용자에게 키보드값을 입력받는 변수
		switch (keycode)
		{
		case 72: //입력된 키보드가 윗 방향키일 경우
			if (y > 0) { // 0보다 위로 이동할 수 없도록 막아주는 역할입니다.
				gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 존재하는 > 커서를 지웁니다.
				gotoxy(x, --y); //콘솔화면에서 위로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 80: //입력된 키보드가 아래 방향키일 경우
			if (y < c_data.size()-1) { // c_data.size - 1값보다 아래로 이동할 수 없도록 막아주는 역할입니다.
				gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 존재하는 > 커서를 지웁니다.
				gotoxy(x, ++y); //콘솔화면에서 아래로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 13: // 키보드 입력값이 ENTER일 때
			if (c_data[y].video_rent == "empty") { //고객이 대여중인 비디오가 없을경우
				cout << "이 고개은 대여중인 비디오가 없습니다." << endl;
				cout << "3초후에 종료됩니다...";
				Sleep(300);
				return; //함수 종료
			}
			c_data[y].video_rent = "empty"; //고개 비디오 대여 변수를 비웁니다.
			temp = c_data[y].video_rent; //비디오 벡터에서 대여 여부를 변경하기 위한 임시저장
			choose += 1;// 반복문 탈출을 위한 변수
			break; // switch ~case문 종료

		case 27: // 키보드 입력값이 ESC일 때
			return; //함수를 종료하고 메인메뉴로 넘어갑니다.
		}
		if (choose != 0) break;// choose값이 0이 아니면 반복문 종료
	}

	for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) {
		if (temp == i->video_name) { //입력값과 기존데이터와 동일할경우
			i->rental_yn = 0; //대여중을 대여가능으로 변경합니다.
		}
	}

}

//고객 데이터 삭제
void customer_delete(vector<Customer>& c_data) {
	system("cls");
	if (c_data.size() == 0) { //고객 정보 벡터 사이즈가 0일 경우
		cout << "보유하고 있는 비디오가 없습니다.";
		customer_add(c_data); //고객 정보 추가 함수 호출
		return; //함수종료
	}
	int x = 0, y = 0;
	int keycode = 0;
	int choose = 0;
	gotoxy(x, y);
	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) { //iterator를 활용한 반복문
		cout << "  ";
		i->print_custom_info(); //고객 정보를 출력합니다.
		cout << endl;
	}
	cout << "방향키 위, 아래 조절가능, ENTER : 선택, ESC : 종료";
	gotoxy(x, y);
	while (1) {
		keycode = GetKey(); //사용자에게 키보드값을 입력받습니다.
		switch (keycode)
		{
		case 72: //입력된 키보드가 윗 방향키일 경우
			if (y > 0) { // 0보다 위로 이동할 수 없도록 막아주는 역할입니다.
				gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 존재하는 > 커서를 지웁니다.
				gotoxy(x, --y); //콘솔화면에서 위로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 80: //입력된 키보드가 아래 방향키일 경우
			if (y < c_data.size()-1) { // c_data.size - 1 값보다 아래로 이동할 수 없도록 막아주는 역할입니다.
				gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
				cout << " "; //기존에 존재하는 > 커서를 지웁니다.
				gotoxy(x, ++y); //콘솔화면에서 아래로 한칸이동합니다.
				cout << ">"; //이동된 위치에 > 를 입력합니다.
			}
			break;
		case 13: // 키보드 입력값이 ENTER일 때
			choose = y; //choose 변수에 y 값을 입력합니다.
			c_data.erase(c_data.begin() + choose);
			break; // swich~case 문 종료

		case 27: // 키보드 입력값이 ESC일 때
			return; //함수를 종료하고 메인메뉴로 넘어갑니다.
		}
		if (choose != 0) break;// order값이 0이 아니면 반복문 종료
	}
}

//고객 정보 출력
void customer_print(vector<Customer>& c_data) {
	system("cls");
	if (c_data.size() == 0) { // 고객 정보 벡터 사이즈가 0일 경우
		cout << "보유하고 있는 고객 정보가 없습니다.";
		customer_add(c_data); //고객 정보 추가 함수를 호출합니다.
	}
	int keycode = 0;

	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) {
		i->print_custom_info(); cout << endl; //고객 정보를 출력합니다.
	}
	cout << "숫자 1 : 이름순으로 정렬  숫자 2 : 생년월일순으로 정렬  ESC : 메인메뉴";
	while (1) {
		keycode = GetKey(); // 사용자에게 키보드 값을 입력받습니다.
		switch (keycode)
		{
		case 49 : //숫자 1을 입력했을 경우
			system("cls"); //화면 초기화하고
			sort(c_data.begin(), c_data.end(), sc_name); //이름 순으로 정렬합니다.
			for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) {
				i->print_custom_info(); cout << endl; //정렬된 고객 정보를 출력합니다.
			}
			cout << "숫자 1 : 이름순으로 정렬  숫자 2 : 생년월일순으로 정렬  ESC : 메인메뉴";
			break;
		case 50:
			system("cls");
			sort(c_data.begin(), c_data.end(), sc_birth); //생년월일 순으로 정렬합니다.
			for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) {
				i->print_custom_info(); cout << endl; //정렬된 고객 정보를 출력합니다.
			}
			cout << "숫자 1 : 이름순으로 정렬  숫자 2 : 생년월일순으로 정렬  ESC : 메인메뉴";
			break;
		case 27: //사용자가 ESC를 눌렀을 때
			return; //함수를 종료하고 메인메뉴로 넘어갑니다.
		}
	}
}

//비디오 목록 출력
void video_print(vector<Video>& v_data) {
	system("cls");
	if (v_data.size() == 0) { //비디오 벡터 사이즈가 0일 경우
		cout << "보유하고 있는 비디오가 없습니다.";
		video_add(v_data); //비디오 입고 함수 호출
	}

	int keycode = 0;
	for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) { //iterator를 활용한 반복문
		if (i->rental_yn == 0) { //대여가능한 비디오일 경우
			cout << i->video_name << "  대여가능" << endl; //출력합니다.
		}
	}
	cout << "숫자 1 : 이름순으로 정렬  ESC : 메인메뉴";
	while (1) {
		keycode = GetKey();
		switch (keycode)
		{
		case 49: //사용자가 숫자1을 눌렀을 경우
			system("cls"); //화면 초기화합니다.
			sort(v_data.begin(), v_data.end(), sv_name); //비디오 제목 순으로 정렬합니다
			for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) {
				if (i->rental_yn == 0) { //대여가능한 비디오만 출력합니다.
					cout << i->video_name << "  대여가능" <<endl;
				}
			}
			cout << "숫자 1 : 이름순으로 정렬  ESC : 메인메뉴";
			break;
		case 27: //사용자가 ESC를 눌렀을 때
			return; //함수를 종료하고 메인메뉴로 넘어갑니다.
		}
	}
}