#ifndef Class_h
#define Class_h

#include <iostream>
#include <algorithm> //sort Ȱ���� ���� �������
#include <vector> //���� �������
#include <string> // string.compare ����� ���ؼ� �߰�
#include "Move.h" //  ���θ޴��� ���� �޴��� ���� ����
#include "Key.h" // �ܼ� Ű���� �ݹ� �Լ� ����
using namespace std;

class PhoneNumber {
public:
	friend int main(); //��� ������ private�� �����ؼ� ��������� ���ٱ��� main�Լ��� �ο�
	PhoneNumber(string r_name = "empty", string r_phone = "empty", string r_email = "empty", string r_place = "empty", int r_birth=0); // Ŭ���� Ÿ�� ���� ���� �� �ʱ�ȭ;
	void print_info(); // �ڷḦ ����ϴ� �Լ�
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
	string name; // �̸��� �Է¹��� ����
	string phonenum; // ��ȭ��ȣ�� �Է¹��� ����
	string email; // �̸����� �Է¹��� ����
	string place; // ��°��� �Է¹��� ����
	int birth; // ��������� �Է¹��� ����
};


/// ����Լ� ���� ///
void add(vector<PhoneNumber>& data); // ��ȭ��ȣ �߰� ��� �Լ� ����
void modified(vector<PhoneNumber>& data); // ��ȭ��ȣ ���� ��� �Լ� ����
void deleted(vector<PhoneNumber>& data); // ��ȭ��ȣ ���� ��� �Լ� ����
void search(vector<PhoneNumber>& data); // ��ȭ��ȣ �˻� ��� �Լ� ����
void sorted(vector<PhoneNumber>& data); // ��ȭ��ȣ ���� ��� �Լ� ����
/////////////////////

////////�����Լ�//////////

bool s_name(const PhoneNumber& a, const PhoneNumber& b); //�̸� ������ �����Լ� ����.
bool s_phonenum(const PhoneNumber& a, const PhoneNumber& b); //��ȭ��ȣ ������ �����Լ� ����
bool s_email(const PhoneNumber& a, const PhoneNumber& b); //�̸��� ������ �����Լ� ����
bool s_birth(const PhoneNumber& a, const PhoneNumber& b); //������� ������ �����Լ� ����

////////////////////////////
#endif // !Class_h