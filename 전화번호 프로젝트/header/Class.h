#ifndef Class_h
#define Class_h

#include <iostream>
#include <algorithm> //sort 활용을 위한 헤더파일
#include <vector> //벡터 헤더파일
#include <string> // string.compare 사용을 위해서 추가
#include "Move.h" //  메인메뉴와 정렬 메뉴를 따로 구현
#include "Key.h" // 콘솔 키보드 콜백 함수 구현
using namespace std;

class PhoneNumber {
public:
	friend int main(); //멤버 변수가 private로 선언해서 멤버변수에 접근권한 main함수에 부여
	PhoneNumber(string r_name = "empty", string r_phone = "empty", string r_email = "empty", string r_place = "empty", int r_birth=0); // 클래스 타입 변수 생성 및 초기화;
	void print_info(); // 자료를 출력하는 함수
	friend bool s_name(const PhoneNumber& a, const PhoneNumber& b);
	friend bool s_phonenum(const PhoneNumber& a, const PhoneNumber& b);
	friend bool s_email(const PhoneNumber& a, const PhoneNumber& b);
	friend bool s_birth(const PhoneNumber& a, const PhoneNumber& b);
	friend void add(vector<PhoneNumber> &data);
	friend void modified(vector<PhoneNumber>& data);
	friend void deleted(vector<PhoneNumber>& data);
	friend void search(vector<PhoneNumber>& data);
	friend void sorted(vector<PhoneNumber>& data);

private:
	string name; // 이름을 입력받을 변수
	string phonenum; // 전화번호를 입력받을 변수
	string email; // 이메일을 입력받을 변수
	string place; // 사는곳을 입력받을 변수
	int birth; // 생년월일을 입력받을 변수
};


/// 기능함수 선언 ///
void add(vector<PhoneNumber>& data); // 전화번호 추가 기능 함수 선언
void modified(vector<PhoneNumber>& data); // 전화번호 수정 기능 함수 선언
void deleted(vector<PhoneNumber>& data); // 전화번호 삭제 기능 함수 선언
void search(vector<PhoneNumber>& data); // 전화번호 검색 기능 함수 선언
void sorted(vector<PhoneNumber>& data); // 전화번호 정렬 기능 함수 선언
/////////////////////

////////정렬함수//////////

bool s_name(const PhoneNumber& a, const PhoneNumber& b); //이름 순으로 정렬함수 선언.
bool s_phonenum(const PhoneNumber& a, const PhoneNumber& b); //전화번호 순으로 정렬함수 선언
bool s_email(const PhoneNumber& a, const PhoneNumber& b); //이메일 순으로 정렬함수 선언
bool s_birth(const PhoneNumber& a, const PhoneNumber& b); //생년월일 순으로 정렬함수 선언

////////////////////////////
#endif // !Class_h