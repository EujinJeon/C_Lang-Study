#include "Class.h"

bool s_name(const PhoneNumber& a, const PhoneNumber& b) {
    return a.name < b.name; //a�� ������� name < b�� ������� name�� ��, ������ ��ȯ 
}// �̸� ������ �����ϱ� ���� �Լ�
bool s_phonenum(const PhoneNumber& a, const PhoneNumber& b) {
    return a.phonenum < b.phonenum; //a�� ������� phonenum < b�� ������� phonenum�� ��, ������ ��ȯ
}// ��ȭ��ȣ ������ �����ϱ� ���� �Լ�
bool s_email(const PhoneNumber& a, const PhoneNumber& b) {
    return a.email < b.email; //a�� ������� email < b�� ������� email�� ��, ������ ��ȯ
}// �̸��� ������ �����ϱ� ���� �Լ�
bool s_birth(const PhoneNumber& a, const PhoneNumber& b) {
    return a.birth < b.birth; // a�� ������� birth < b�� ������� birth�� ��, ������ ��ȯ  
}// ������� ������ �����ϱ� ���� �Լ�