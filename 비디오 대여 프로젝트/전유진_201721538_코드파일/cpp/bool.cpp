#include "project.h"

bool sc_name(const Customer& a, const Customer& b) {
    return a.name < b.name; //a의 멤버변수 name < b의 멤버변수 name의 참, 거짓값 반환 
}// 이름 순으로 정렬하기 위한 함수
bool sc_birth(const Customer& a, const Customer& b) {
    return a.birth < b.birth; //a의 멤버변수 phonenum < b의 멤버변수 phonenum의 참, 거짓값 반환
}// 전화번호 순으로 정렬하기 위한 함수
bool sv_name(const Video& a, const Video& b) {
    return a.video_name < b.video_name; //a의 멤버변수 video_name < b의 멤버변수 video_name 의 참, 거짓값 반환
}// 비디오 이름 순으로 정렬하기 위한 함수