#include "project.h"

bool sc_name(const Customer& a, const Customer& b) {
    return a.name < b.name; //a�� ������� name < b�� ������� name�� ��, ������ ��ȯ 
}// �̸� ������ �����ϱ� ���� �Լ�
bool sc_birth(const Customer& a, const Customer& b) {
    return a.birth < b.birth; //a�� ������� phonenum < b�� ������� phonenum�� ��, ������ ��ȯ
}// ��ȭ��ȣ ������ �����ϱ� ���� �Լ�
bool sv_name(const Video& a, const Video& b) {
    return a.video_name < b.video_name; //a�� ������� video_name < b�� ������� video_name �� ��, ������ ��ȯ
}// ���� �̸� ������ �����ϱ� ���� �Լ�