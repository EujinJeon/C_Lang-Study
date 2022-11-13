#ifndef project_h
#define project_h


#include <iostream>
#include <cstdio> //C파일 입출력 활용을 위한 헤더파일
#include <fstream> //파일입출력 활용을 위한 헤더파일
#include <algorithm> //sort 활용을 위한 헤더파일
#include <vector> //벡터 헤더파일
#include <string> // string.compare 사용을 위해서 추가
#include "Move.h" //  메인메뉴와 정렬 메뉴를 따로 구현
#include "Key.h" // 콘솔 키보드 콜백 함수 구현
using namespace std;

// 고객정보 클래스
class Customer {
public:
	Customer(string r_name = "empty", string r_phonenum = "empty", string r_birth = "empty", string r_video = "empty"); // Customer 클래스 생성자
	void print_custom_info(); // 자료를 출력하는 함수
	string name; // 이름을 입력받을 변수
	string phonenum; // 전화번호를 입력받을 변수
	string birth; // 생년월일을 입력받을 변수
	string video_rent; //고객이 대여한 비디오
};

// 비디오 클래스
class Video {
public :
	Video(string r_video_name = "empty", int r_rental_yn = 0); // Video 클래스 생성자
	string video_name; // 비디오 이름
	int rental_yn; //비디오 대여 여부
};


/// 기능함수 선언 ///
void searched(vector<Customer>& c_data, vector<Video>& v_data); //통합검색
int searching_customer(vector<Customer>& c_data, string searched); //고객 검색 기능
int searching_video(vector<Video>& v_data, string searched); //비디오 검색 기능
void customer_add(vector<Customer> &c_data); //고객 추가
void video_add(vector<Video>& v_data); // 비디오 입고
void video_rental(vector<Video>& v_data, vector<Customer>& c_data); // 비디오 대여
void customer_delete(vector<Customer>& c_data); //고객 데이터 삭제
void customer_print(vector<Customer>& c_data); //고객 정보 출력
void video_print(vector<Video>& v_data); //비디오 목록 출력
void video_nrental(vector<Video>& v_data, vector<Customer>& c_data); //비디오 반납
/////////////////////

// 정렬 함수
bool sc_name(const Customer& a, const Customer& b); // 이름 순으로 정렬하기 위한 함수
bool sc_birth(const Customer& a, const Customer& b); // 생년월일 순으로 정렬하기 위한 함수
bool sv_name(const Video& a, const Video& b); //비디오 이름 순으로 정렬하기 위한 함수
#endif // !project_h