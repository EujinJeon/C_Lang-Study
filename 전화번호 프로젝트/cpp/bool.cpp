#include "Class.h"

bool s_name(const PhoneNumber& a, const PhoneNumber& b) {
    return a.name < b.name; //a의 멤버변수 name < b의 멤버변수 name의 참, 거짓값 반환 
}// 이름 순으로 정렬하기 위한 함수
bool s_phonenum(const PhoneNumber& a, const PhoneNumber& b) {
    return a.phonenum < b.phonenum; //a의 멤버변수 phonenum < b의 멤버변수 phonenum의 참, 거짓값 반환
}// 전화번호 순으로 정렬하기 위한 함수
bool s_email(const PhoneNumber& a, const PhoneNumber& b) {
    return a.email < b.email; //a의 멤버변수 email < b의 멤버변수 email의 참, 거짓값 반환
}// 이메일 순으로 정렬하기 위한 함수
bool s_birth(const PhoneNumber& a, const PhoneNumber& b) {
    return a.birth < b.birth; // a의 멤버변수 birth < b의 멤버변수 birth의 참, 거짓값 반환  
}// 생년월일 순으로 정렬하기 위한 함수