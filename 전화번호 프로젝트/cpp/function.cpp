#include "Class.h"

PhoneNumber temp;

PhoneNumber::PhoneNumber(string r_name, string r_phone, string r_email, string r_place, int r_birth) {
    name = r_name;
    phonenum = r_phone;
    email = r_email;
    place = r_place;
    birth = r_birth;
}; //클래스 형태로 변수가 선언되면 초기화하는 클래스 멤버 함수

//Vector 자료 출력 형식
void PhoneNumber::print_info() {
    cout << name; //이름 출력
    cout.width(15); //필드폭 15
    cout << phonenum;//전화번호 출력
    cout.width(20); //필드폭 20
    cout << email; // 이메일 출력
    cout.width(15); //필드폭 10
    cout << place; // 사는곳 출력
    cout.width(15); //필드폭 10
    cout << birth; // 생년월일 출력
}

int print_sortm(); //function.cpp에 있는 sorted 함수의 선택 메뉴 출력함수

//전화번호 추가
void add(vector<PhoneNumber>& data) {
    system("cls"); // 이전에 있던 내용 초기화(화면초기화)

    while (1) {
        cout << "전화번호 입력형식 :  xxx-xxxx-xxxx" << "   생년월일 입력 예 :19870421" << endl;
        cout << "이름(영어), 전화번호, 이메일, 사는곳, 생일 순으로 입력하세요." << endl;
        cout << "입력 : ";
        cin >> temp.name >> temp.phonenum >> temp.email >> temp.place >> temp.birth; // 사용자에게 추가할 자료의 내용을 입력받습니다.
        data.push_back(temp); // 입력된 자료를 Vector 형태의 data에 추가.
        cout << "전화번호를 더 추가하실거면 엔터, 종료하실려면 ESC를 눌러주세요.";
        int getk = GetKey(); // GetKey 함수로 키보드 값을 입력받는다.
        if (getk == 27) { // 키보드 입력값이 ESC일 때
            break; // 함수를 종료하고 메인메뉴로 넘어감.
        }
        else if (getk == 13) { //키보드 입력값이 ENTER일 때
            system("cls"); //이전 화면 초기화합니다.
            continue; // add함수 계속 진행합니다.
        }
    }
}

//수정
void modified(vector<PhoneNumber>& data) {
    system("cls");
    int num = 1, order = 0;
    if (data.size() == 0) { //vector에 저장되 데이터 수가 0일 때,
        cout << "수정할 전화번호가 없습니다." << endl;
        cout << "전화번호를 추가합니다...." << endl;
        Sleep(3000); //3초정도의 텀을 둡니다.
        add(data); //add 함수를 호출합니다.
    }

    cout << "어떤 데이터를 수정 하시겠습니까?" <<endl;
    for (vector<PhoneNumber>::iterator i = data.begin(); i != data.end(); i++) {
        cout << "  ";
        i->print_info(); cout << endl;
    }//iterator를 활용한 반복문을 통해서 벡터에 저장된 자료를 출력합니다.

    int x = 0, y = 1;
    gotoxy(x, y);
    cout << ">";
    while (1) {
        int dkey = GetKey();
        switch (dkey) {
        case 72: //입력된 키보드가 윗 방향키일 경우
            if (y > 1) { // 0보다 위로 이동할 수 없도록 막아주는 역할입니다.
                gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
                cout << " "; //기존에 존재하는 > 커서를 지웁니다.
                gotoxy(x, --y); //콘솔화면에서 위로 한칸이동합니다.
                cout << ">"; //이동된 위치에 > 를 입력합니다.
            }
            break;
        case 80: //입력된 키보드가 아래 방향키일 경우
            if (y < data.size()) { // data.size 값보다 아래로 이동할 수 없도록 막아주는 역할입니다.
                gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
                cout << " "; //기존에 존재하는 > 커서를 지웁니다.
                gotoxy(x, ++y); //콘솔화면에서 아래로 한칸이동합니다.
                cout << ">"; //이동된 위치에 > 를 입력합니다.
            }
            break;
        case 13: // 키보드 입력값이 ENTER일 때
            order = y-1; //order 변수에 y-1 값을 입력합니다.
            break; // switch ~case문 종료

        case 27: // 키보드 입력값이 ESC일 때
            return; //함수를 종료하고 메인메뉴로 넘어갑니다.
        }
        if (order != 0) break;// order값이 0이 아니면 반복문 종료
    }
    gotoxy(0, data.size() + 1); // 커서를 밑으로 옯겨서 기존 출력 내용이랑 안 겹치도록 이동합니다.
    cout << "이름 :"; cin >> data[order].name; //선택한 자료의 이름 수정
    cout << "전화번호 :"; cin >> data[order].phonenum; //선택한 자료의 전화번호 수정
    cout << "이메일 :"; cin >> data[order].email; //선택한 자료의 이메일 수정
    cout << "사는곳 :"; cin >> data[order].place; //선택한 자료의 사는 곳 수정
    cout << "생년월일 :"; cin >> data[order].birth; //선택한 자료의 생년월일 수정
}


//삭제
void deleted(vector<PhoneNumber>& data) {
    system("cls");
    int num = 1, order = 0;
    if (data.size() == 0) {
        cout << "수정할 전화번호가 없습니다." << endl;
        cout << "전화번호를 추가합니다...." << endl;
        Sleep(3000);
        add(data);
    } // 벡터에 저장된 자료가 없으면 추가 함수 호출

    for (vector<PhoneNumber>::iterator i = data.begin(); i != data.end(); i++) {
        cout << "  ";
        i->print_info(); cout << endl;
    } //iterator를 통해서 벡터에 저장된 자료를 출력

    cout << "어떤 데이터를 삭제 하시겠습니까?";
    int x = 0, y = 0;
    gotoxy(x,y);
    cout << ">";
    while (1) {
        int dkey = GetKey(); //키보드 윗, 아래 방향으로 움지여 삭제하고 싶은 자료 선택
        switch (dkey) {
        case 72:
            if (y > 0) {
                gotoxy(x, y);
                cout << " ";
                gotoxy(x, --y);
                cout << ">";
            }
            break;
        case 80:
            if (y < data.size()-1) {
                gotoxy(x, y);
                cout << " ";
                gotoxy(x, ++y);
                cout << ">";
            }
            break;
        case 13: //사용자가 엔터를 눌렀을 때
            order = y; // 콘솔화면 y좌표값을 order변수에 넣습니다.
            data.erase(data.begin() + order); //data 첫번째 자료에서 order번째 만큼 뒤에있는 자료를 삭제합니다.
            return; //삭제하고 함수를 종료합니다.

        case 27 : //사용자가 ESC를 눌렀을 때
            return; //함수를 종료하고 메인메뉴로 넘어갑니다.
        }
    }
}

//검색
void search(vector<PhoneNumber>& data) {
    system("cls");
    if (data.size() == 0) {
        cout << "수정할 전화번호가 없습니다." << endl;
        cout << "전화번호를 추가합니다...." << endl;
        Sleep(3000);
        add(data);
    }

    string searching; //사용자에게 검색할 내용을 입력받을 문자열 변수
    int nfind = 0, skey = 0; //nfind는 찾았는지 못찾았는지 구분하기 위한 변수
    cout << "이름(영어), 전화번호, 이메일중 하나 입력하세요.";
    cin >> searching; //사용자에게 입력받는 함수
    for (int i = 0; i < data.size(); i++) { //데이터 개수만큼 반복하는 반복문
        if (searching.compare(data[i].name) == 0) { //searching에 입력된 내용과 벡터에 저장된 이름과 같은 경우
            data[i].print_info(); // 검색된 내용을 출력합니다.
            cout << endl;
            ++nfind; // 자료를 찾았다는 표시를 해줍니다.
            cout << "엔터를 누르면 메인화면으로 넘어갑니다.";
            skey = GetKey(); 
            if(skey == 13)break; //사용자가 ENTER를 누르면 검색 함수를 종료하고 메인 메뉴로 넘어갑니다.
            
        } 
        else if (searching.compare(data[i].email)==0) { //searching에 입력된 내용과 벡터에 저장된 이름과 같은 경우
            data[i].print_info();
            cout << endl;
            ++nfind;
            cout << "엔터를 누르면 메인화면으로 넘어갑니다.";
            skey = GetKey();
            if (skey == 13)break;
        }
        else if (searching.compare(data[i].phonenum)==0) { //searching에 입력된 내용과 벡터에 저장된 전화번호와 같은 경우
            data[i].print_info();
            cout << endl;
            ++nfind;
            cout << "엔터를 누르면 메인화면으로 넘어갑니다.";
            skey = GetKey();
            if (skey == 13)break;
        }
    }
    if (nfind == 0) { //사용자가 입력한 자료를 찾지 못했을 때
        cout << "검색하신 전화번호는 존재하지 않습니다."<<endl;
        cout << "3초후에 메인메뉴로 돌아갑니다..."; // 찾지 못햇다는 문구를 띄워줍니다.
        Sleep(3000); //3초동안 프로그램 중지
    }
}

//정렬
void sorted(vector<PhoneNumber>& data) {
    system("cls");
    if (data.size() == 0) {
        cout << "수정할 전화번호가 없습니다." << endl;
        cout << "전화번호를 추가합니다...." << endl;
        Sleep(3000);
        add(data);
    }
    int order = print_sortm(); //세부정렬 기능 메뉴를 출력함수를 호출합니다.
    switch (order) //switch~case문에서 print_sortm에서 선택한 기능에 맞는 조건으로 넘어갑니다.
    {
    case 1: // 이름순으로 정렬을 선택했을 때
        sort(data.begin(), data.end(), s_name); //sort함수를 통해서 이름순으로 정렬
        break;
    case 2: // 전화번호순으로 정렬을 선택했을 때
        sort(data.begin(), data.end(), s_phonenum); //sort함수를 통해서 전화번호순으로 정렬
        break;
    case 3: // 이메일순으로 정렬을 선택했을 때
        sort(data.begin(), data.end(), s_email); //sort함수를 통해서 이메일순으로 정렬
        break;
    case 4: // 생년월일 순으로 정렬을 선택했을 때
        sort(data.begin(), data.end(), s_birth); //sort함수를 통해서 생년월일순으로 정렬
        break;
    case 5: // 사용자가 ESC를 눌렀을 때
        return; //함수를 종료하고 메인메뉴로 돌아갑니다.
    }

    for (vector<PhoneNumber>::iterator i = data.begin(); i != data.end(); i++) {
        i->print_info();
        cout << endl;
    } //정렬된 결과값을 반복문으로 출력합니다.
    cout << "엔터를 누르면 메인 메뉴로 넘어갑니다.";
    int rekey = GetKey(); //사용자에게 키보드값을 입력받는다.
    if (rekey == 13) { //ENTER를 눌렀을 때
        return; //함수를 종료하고 메인메뉴로 넘어갑니다.
    }
}

int print_sortm() {
    int x = 0, y = 0;
    cout << "> 이름순으로 정렬" << endl;
    cout << "  전화번호순으로 정렬" << endl;
    cout << "  이메일순으로 정렬" << endl;
    cout << "  생년월일순으로 정렬" << endl;
    while (1) {
        int gkey = GetKey();
        switch (gkey) {
        case 72:
            if (y > 0) {
                gotoxy(x, y);
                cout << " ";
                gotoxy(x, --y);
                cout << ">";
            }
            break;
        case 80:
            if (y < 3) {
                gotoxy(x, y);
                cout << " ";
                gotoxy(x, ++y);
                cout << ">";
            }
            break;

        case 27:
            return 5;

        case 13:
            return y + 1;
        }
    }

}