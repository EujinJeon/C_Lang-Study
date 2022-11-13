#ifndef project_h
#define project_h


#include <iostream>
#include <cstdio> //C���� ����� Ȱ���� ���� �������
#include <fstream> //��������� Ȱ���� ���� �������
#include <algorithm> //sort Ȱ���� ���� �������
#include <vector> //���� �������
#include <string> // string.compare ����� ���ؼ� �߰�
#include "Move.h" //  ���θ޴��� ���� �޴��� ���� ����
#include "Key.h" // �ܼ� Ű���� �ݹ� �Լ� ����
using namespace std;

// ������ Ŭ����
class Customer {
public:
	Customer(string r_name = "empty", string r_phonenum = "empty", string r_birth = "empty", string r_video = "empty"); // Customer Ŭ���� ������
	void print_custom_info(); // �ڷḦ ����ϴ� �Լ�
	string name; // �̸��� �Է¹��� ����
	string phonenum; // ��ȭ��ȣ�� �Է¹��� ����
	string birth; // ��������� �Է¹��� ����
	string video_rent; //���� �뿩�� ����
};

// ���� Ŭ����
class Video {
public :
	Video(string r_video_name = "empty", int r_rental_yn = 0); // Video Ŭ���� ������
	string video_name; // ���� �̸�
	int rental_yn; //���� �뿩 ����
};


/// ����Լ� ���� ///
void searched(vector<Customer>& c_data, vector<Video>& v_data); //���հ˻�
int searching_customer(vector<Customer>& c_data, string searched); //�� �˻� ���
int searching_video(vector<Video>& v_data, string searched); //���� �˻� ���
void customer_add(vector<Customer> &c_data); //�� �߰�
void video_add(vector<Video>& v_data); // ���� �԰�
void video_rental(vector<Video>& v_data, vector<Customer>& c_data); // ���� �뿩
void customer_delete(vector<Customer>& c_data); //�� ������ ����
void customer_print(vector<Customer>& c_data); //�� ���� ���
void video_print(vector<Video>& v_data); //���� ��� ���
void video_nrental(vector<Video>& v_data, vector<Customer>& c_data); //���� �ݳ�
/////////////////////

// ���� �Լ�
bool sc_name(const Customer& a, const Customer& b); // �̸� ������ �����ϱ� ���� �Լ�
bool sc_birth(const Customer& a, const Customer& b); // ������� ������ �����ϱ� ���� �Լ�
bool sv_name(const Video& a, const Video& b); //���� �̸� ������ �����ϱ� ���� �Լ�
#endif // !project_h