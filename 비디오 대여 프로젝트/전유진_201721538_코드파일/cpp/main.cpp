#define _CRT_SECURE_NO_WARNINGS
#include "project.h"
using namespace std;

int mainm(); //메인메뉴 출력 함수

int main()
{	
	vector<Customer> customer_data; //고객 정보 벡터
	vector<Video> video_data; //비디오 벡터
	Customer tmp;
	Video tmp2;
	FILE* loading = NULL; //고객 정보 데이터 파일 입력을 위한 선언
	FILE* loading2 = NULL; //비디오 데이터 파일 입력을 위한 선언
	loading = fopen("c_data.txt", "r"); //고객 정보를 담은 데이터를 읽습니다.
	if (loading != NULL) { //파일이 만약 존재할 경우.
		char buffer[2048];
		while (!feof(loading)) { //데이터 파일이 끝날 때까지
			fgets(buffer, sizeof(buffer), loading);

			char* ptr = strtok(buffer, "\t"); //버퍼에 저장된 내용을 \t이 입력된 기준으로 끊습니다.
			tmp.name = ptr; //이름에 저장
			ptr = strtok(NULL, "\t");
			tmp.phonenum = ptr; //전화번호 에 저장
			ptr = strtok(NULL, "\t");
			tmp.birth = ptr; //생년월일에 저장
			ptr = strtok(NULL, "\n"); //\n가 입력된곳까지 자릅니다.
			tmp.video_rent = ptr; //대여한 비디오에 저장

			customer_data.push_back(tmp); //고객 정보 벡터에 저장합니다.
		}
		fclose(loading); //읽기모드로 불러온 파일을 종료합니다.
	}

	loading2 = fopen("v_data.txt", "r"); //비디오 데이터 파일을 읽기모드로 불러옵니다.
	if (loading2 != NULL) { //비디오 데이터 파일이 있을경우
		char buffer2[2048];
		while (!feof(loading2)) { //비디오 데이터 파일이 끝날 때까지
			fgets(buffer2, sizeof(buffer2), loading2);
			char* ptr = strtok(buffer2, "\t"); //버퍼에 저장된 내용을 \t이 입력된 기준으로 끊습니다.
			tmp2.video_name = ptr; //비디오 제목으로 입력
			ptr = strtok(NULL, "\n"); //\n가 입력된곳까지 자릅니다.
			tmp2.rental_yn= atoi(ptr); //문자에서 정수형 변수로 변환
			video_data.push_back(tmp2); //비디오 벡터에 저장합니다.
		}

		fclose(loading2); //읽기모드로 불러온 파일을 종료합니다.
	}

	while (1) {

		int choice = mainm();

		switch (choice)
		{
		case 0:
			customer_add(customer_data); //고객 정보 추가 함수 호출
			break;
		case 1:
			video_add(video_data); //비디오 입고 함수 호출
			break;
		case 2:
			video_rental(video_data, customer_data); //비디오 대여 함수 호출
			break;
		case 3:
			video_nrental(video_data, customer_data); //비디오 반납 함수 호출
			break;
		case 4:
			customer_delete(customer_data); //고객 정보 삭제함수 호출
			break;
		case 5:
			searched(customer_data, video_data); //검색함수 호출
			break;
		case 6:
			video_print(video_data); //비디오 내역 출력 함수 호출
			break;
		case 7:
			customer_print(customer_data); //고객 정보 출력함수 호출
			break;
		case 8:
			ofstream c_dataout("c_data.txt"); //고객 데이터파일은 c_data.txt 파일을 생성하고 저아합니다.
			for (int i = 0; i < customer_data.size(); i++) {
				if (i == customer_data.size() - 1) { //마지막 데이터를 \n없이 입력
					c_dataout << customer_data[i].name << "\t" << customer_data[i].phonenum << "\t" << customer_data[i].birth << "\t" << customer_data[i].video_rent;
				}
				else {
					c_dataout << customer_data[i].name << "\t" << customer_data[i].phonenum << "\t" << customer_data[i].birth << "\t" << customer_data[i].video_rent << endl;
				}
			}
			ofstream v_dataout("v_data.txt"); //비디오 데이터 파일은 v_data.txt 파일을 생성하고 저아합니다.
			for (int i = 0; i < video_data.size(); i++) {
				if (i == video_data.size() - 1) { //마지막 데이터를 \n없이 입력
					v_dataout << video_data[i].video_name << "\t" << video_data[i].rental_yn;
				}
				else {
					v_dataout << video_data[i].video_name << "\t" << video_data[i].rental_yn << endl;
				}
			}
			return 0;
		}
	}
	system("pause");	
}

int mainm() {
	system("cls");
	int x = 0, y = 0;
	cout << "> 1. 고객 정보 추가" << endl;
	cout << "  2. 비디오 입고" << endl;
	cout << "  3. 비디오 대여" << endl;
	cout << "  4. 비디오 반납" << endl;
	cout << "  5. 고객 정보 삭제" << endl;
	cout << "  6. 검색" << endl;
	cout << "  7. 비디오 출력" << endl;
	cout << "  8. 고객 정보 출력" << endl;
	cout << "  9. 저장하고 종료하기";

	while (1) {
		while (1) {
			int keycode = GetKey(); //사용자에게 키보드 값을 입력받는 함수
			switch (keycode)
			{
			case 72: //사용자가 위방향키를 눌렸을 경우
				if (y > 0) { // 0보다 위로 이동할 수 없도록 막아주는 역할입니다.
					gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다.
					cout << " "; //기존에 존재하는 > 커서를 지웁니다.
					gotoxy(x, --y); //콘솔화면에서 위로 한칸이동합니다.
					cout << ">"; //이동된 위치에 > 를 입력합니다.
				}
				break;

			case 80: //입력된 키보드가 아래 방향키일 경우
				if (y < 8) { // 8보다 아래로 이동할 수 없도록 막아주는 역할입니다.
					gotoxy(x, y); //gotoxy 함수로 콘솔화면 x,y로 이동합니다
					cout << " "; //기존에 존재하는 > 커서를 지웁니다.
					gotoxy(x, ++y); //콘솔화면에서 아래로 한칸이동합니다.
					cout << ">"; //이동된 위치에 > 를 입력합니다.
				}
				break;
			case 13: //사용자가 ENTER를 눌렀을 때...
				return y; //y값 리턴
				break;
			}
		}
	}
}