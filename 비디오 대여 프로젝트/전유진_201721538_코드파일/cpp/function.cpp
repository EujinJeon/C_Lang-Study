#include "project.h"
using namespace std;

Customer::Customer(string r_name, string r_phonenum, string r_birth, string r_video) { //�� Ŭ���� ������ ����
	name = r_name; //�̸� ���� �ʱ�ȭ
	phonenum = r_phonenum; //��ȭ��ȣ ���� �ʱ�ȭ
	birth = r_birth; //������� ���� �ʱ�ȭ
	video_rent = r_video; //�뿩���� ���� ���� �ʱ�ȭ
}

Video::Video(string r_video_name, int r_rental_yn) { //���� Ŭ���� ������ ����
	video_name = r_video_name; //���� ���� ���� �ʱ�ȭ
	rental_yn = r_rental_yn; //���� �뿩 ���� ���� �ʱ�ȭ
}


//Vector �ڷ� ��� ����
void Customer::print_custom_info() {
	cout << name; //�̸� ���
	cout.width(15); //�ʵ��� 15
	cout << phonenum;//��ȭ��ȣ ���
	cout.width(15); //�ʵ��� 15
	cout << birth; // ������� ���
	cout.width(15); //�ʵ��� 15
	cout << video_rent; // �뿩���� ���� ���(������ empty���)
}

//�˻����
void searched(vector<Customer>& c_data, vector<Video>& v_data) { //���� �˻� ����Լ�
	system("cls"); //ȭ�� Ŭ����

	if (c_data.size() == 0) {
		cout << "�������Ͱ� �ϳ��� �������� �ʽ��ϴ�.";
		Sleep(200);
		customer_add(c_data);
	} //�� ���� ���� ����� 0�̸� �� �߰� �Լ� ȣ��

	else if (v_data.size() == 0) {
		cout << "���� �����Ͱ� �ϳ��� �������� �ʽ��ϴ�.";
		Sleep(200);
		video_add(v_data);
	} //���� ���� ����� 0�̸� ���� �԰� �Լ� ȣ��

	string searching; //�˻��� ���� �Է��� ����
	int torn = 0; // ã�Ҵ��� ��ã�Ҵ��� �����ϴ� ����
	int keycode = 0, loopnum = 0; //Ű���尪 ������, ���ѹݺ��� Ż�� ����

	while (1) {
		system("cls");
		cout << "�˻��Ͻ� ������ �Է��Ͻÿ�.";
		cin >> searching; //�˻��� ���� �Է�
		torn = searching_customer(c_data, searching); //�� ���� �˻��Լ� ȣ��
		if (torn != 1) { //�� ���� �˻��Լ����� �� ã���� ��...
			torn = searching_video(v_data, searching); //���� �˻��Լ� ȣ��
		}
		system("cls");
		if (torn != 1) {//���� �˻��Լ������� �� ã���� ��...
			cout << "�˻��Ͻ� ������ ã�� �� �����ϴ�."<<endl;
		}
		cout << "��� �˻��Ͻ� �Ÿ� ENTER, �����ǰŸ� ESC�� �����ÿ�.";
		keycode = GetKey(); //����ڿ��� Ű���尪�� �Է¹޴� �Լ�
		switch (keycode)
		{
		case 13: //����ڰ� ENTER�� ������ ��
			continue;
			break;
		case 27: //����ڰ� ESC�� ������ ��
			loopnum = 1;
			break;
		}
		if (loopnum == 1) break;
	}
}

//�� �˻����
int searching_customer(vector<Customer>& c_data, string searched) {
	int keycode = 0, tmp = 0;
	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) {
		if (searched.compare(i->name) == 0) { //����ڰ� �Է��� ����� �������� ������ �����ϸ�
			i->print_custom_info(); //ã�� �����͸� ����մϴ�.
			tmp = 1; //�Լ� ����� ��ȯ�� ���� ����
			cout << "\nENTER�� ������ â�� �����ϴ�.";
			keycode = GetKey();
			if(keycode == 13) break; //����ڰ� ENTER�� ������ �� �˻��Լ� ����
		}

		else continue;
	}
	return tmp; //tmp���� ��ȯ
}

//���� �˻� ���
int searching_video(vector<Video>& v_data, string searched) {
	int tmp = 0, keycode = 0;
	for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) {
		if (searched.compare(i->video_name) == 0) { //����ڰ� �Է��� ����� �������� ������ �����ϸ�
			cout << i->video_name; //ã�� �����͸� ����մϴ�.
			if (i->rental_yn == 0) { //rental_yn == 0�̸�
				cout << "  �뿩����" <<endl; //�뿩�������� ���
			}
			else {
				cout << "  �뿩��" << endl; //�뿩������ ���
			}
			tmp = 1; //�Լ� ����� ��ȯ�� ���� ����
			cout << "\nENTER�� ������ â�� �����ϴ�.";
			keycode = GetKey();
			if (keycode == 13) break; //����ڰ� ENTER�� ������ �� �˻��Լ� ����
			break;
		}

		else continue;
	}
	return tmp; //tmp�� ��ȯ
}

//�� �߰�
void customer_add(vector<Customer>& c_data) {
	system("cls");
	int keycode = 0, loopnum = 0;
	Customer temp;
	while (1) {
		cout << "�̸� ��ȭ���� ������� ������ �Է��Ͻÿ�."<<endl;
		cin >> temp.name >> temp.phonenum >> temp.birth; //�̸�, ��ȭ��ȣ, ������� �Է��մϴ�.
		if (atoi(temp.name.c_str()) == 0 && atoi(temp.phonenum.c_str()) > 0 && atoi(temp.birth.c_str()) > 0)
		{ //�� �׸��� �� �ԷµǾ��� ���...
			if (c_data.size() != 0) { //�� ���� ���� ����� 0�� �ƴ� ���
				for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) { //iterator�� Ȱ���� �ݺ���
					if (i->name == temp.name || i->birth == temp.birth || i->phonenum == temp.phonenum) { //�Է��� ����� ������ ������ ������
						cout << "������ �����Ͱ� �߰ߵǾ����ϴ�." << endl;
						cout << "3���� ���θ޴��� �Ѿ�ϴ�.";
						Sleep(300);
						return;//�Լ� ����
					}
				}
			}
			c_data.push_back(temp); //�� ���� ���Ϳ� �߰�
			cout << "���� �� �߰��Ͻðڽ��ϱ�? ENTER : ����߰�, ESC : ����";
			keycode = GetKey();
			switch (keycode)
			{
			case 13: //����ڰ� ENTER�� ������ ����߰�
				continue;
				break;
			case 27: //����ڰ� ESC�� ������ �Լ�����
				system("cls");
				loopnum = 1;
				break;
			}
			if (loopnum == 1) break;
		}
		else { //����ڰ� �� �� �Է����� ���
			cin.clear(); //�Է¹��� �ʱ�ȭ
			cout << "�� �� �Է��ϼ̽��ϴ�.";
			cout << "\n3���Ŀ� �ٽ� �Է��Ͻÿ�.";
			Sleep(300);
		}
	}

}

// ���� �԰�
void video_add(vector<Video>& v_data) {
	system("cls");
	int keycode = 0, loopnum = 0;
	Video temp;
	while (1) {
		cout << "���� �̸��� �Է��Ͻÿ�." << endl;
		cin >> temp.video_name; //���� ������ �Է��մϴ�.
		if (atoi(temp.video_name.c_str()) == 0) { //���� ������ �� �Է����� ���...
			if (v_data.size() != 0) { //���� ���� ����� 0�� �ƴϸ�..
				for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) { //iterator�� Ȱ���� �ݺ���
					if (i->video_name == temp.video_name) { //�Է��� ����� ������ �����Ͱ� ��ġ�� ��
						cout << "������ �����Ͱ� �߰ߵǾ����ϴ�." << endl;
						cout << "3���� ���θ޴��� �Ѿ�ϴ�.";
						Sleep(300);
						return; //�Լ� ����
					}
				}
			}
			temp.rental_yn = 0; //�뿩���� �뿩�������� ����
			v_data.push_back(temp); //���� ���Ϳ� ������ �߰�
			cout << "������ �� �԰��Ͻðڽ��ϱ�? ENTER : ����߰�, ESC : ����";
			keycode = GetKey();
			switch (keycode)
			{
			case 13: //����ڰ� ENTER�� ������ ����߰�
				continue;
				break;
			case 27: //����ڰ� ESC�� ������ �Լ�����
				system("cls");
				loopnum = 1;
				break;
			}
			if (loopnum == 1) break;
		}

		else { //����ڰ� �� �� �Է����� ���
			cin.clear(); //�Է¹��� �ʱ�ȭ
			cout << "�� �� �Է��ϼ̽��ϴ�.";
			cout << "\n3���Ŀ� �ٽ� �Է��Ͻÿ�.";
			Sleep(300);
		}
	}
}

// ���� �뿩
void video_rental(vector<Video>& v_data, vector<Customer>& c_data) {
	system("cls");
	if (v_data.size() == 0) { //���� ���� ����� 0�� ���
		cout << "�����ϰ� �ִ� ������ �����ϴ�." << endl;
		cout << "3�� �� ���� �԰�� �Ѿ�ϴ�...";
		Sleep(300);
		video_add(v_data); //���� �԰� �Լ� ȣ��
	}

	else if (c_data.size() == 0) { //�� ���� ���� ����� 0�� ���
		cout <<"�����ϰ� �ִ� �� ������ �����ϴ�.";
		cout << "3�� �� �� �߰��� �Ѿ�ϴ�...";
		Sleep(300);
		customer_add(c_data); //�� ���� �߰� �Լ� ȣ��
	}

	int x = 0, y = 0;
	int keycode = 0, choice = 0, choice2 = 0, loop = 0;
	string temp;
	for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) {
		if (i->rental_yn == 0) { //rental_yn�� 0�� ��� �뿩���� ���
			cout << "  ";
			cout << i->video_name << "  �뿩����" << endl;
		}
		else { //rental_yn�� 0�� �ƴ� ��� �뿩�� ���
			cout << "  ";
			cout << i->video_name << "  �뿩��" << endl;
		}
	}
	cout << "�뿩�ϰ� ���� ������ �����Ͻÿ�. ����Ű ��, �Ʒ�, ENTER�� Ȱ���ϼ���. ";
	gotoxy(x, y);
	cout << ">";
	while (1) {
		keycode = GetKey(); //����ڿ��� Ű���尪�� �Է¹޴� �Լ�
		switch (keycode)
		{
		case 72: //�Էµ� Ű���尡 �� ����Ű�� ���
			if (y > 0) { //Ŀ���� 0���� ���� ��ġ�� �̵����Ѱ� �����ݴϴ�.
				gotoxy(x, y); //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
				cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�.
				gotoxy(x, --y); //�ܼ�ȭ�鿡�� ���� ��ĭ�̵��մϴ�.
				cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
			}
			break;
		case 80: //�Էµ� Ű���尡 �Ʒ� ����Ű�� ���
			if (y < v_data.size()-1) { // c_data.size -1 ������ �Ʒ��� �̵��� �� ������ �����ִ� �����Դϴ�.
				gotoxy(x, y); //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
				cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�.
				gotoxy(x, ++y); //�ܼ�ȭ�鿡�� ���� ��ĭ�̵��մϴ�.
				cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
			}
			break;
		case 13:
			if (v_data[y].rental_yn == 1) { //������ ������ �뿩���� ���..
				gotoxy(0, v_data.size() + 1);
				cout << "�̹� �뿩�� �����Դϴ�."<<endl;
				cout << "3���Ŀ� �����մϴ�...";
				Sleep(300);
				return; //�Լ� ����
			}
			choice = y;
			loop += 1; //���ѹݺ����� Ż���ϱ� ���� 1�Է�
			v_data[choice].rental_yn = 1; //������ ���� �뿩������ ����
			system("cls");
			break;
		}
		if (loop != 0)break;
	}

	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) { //iterator�� ����� �ݺ���
		cout << "  ";
		i->print_custom_info(); cout << endl; //�� ���� ���
	}
	x = 0, y = 0;
	gotoxy(x, y);
	cout << ">";
	while (1) {
		keycode = GetKey(); //����ڿ��� Ű���尪�� �Է¹޴� �Լ�
		switch (keycode)
		{
		case 72: //�Էµ� Ű���尡 �� ����Ű�� ���
			if (y > 0) { // 0���� ���� �̵��� �� ������ �����ִ� �����Դϴ�.
				gotoxy(x, y);  //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
				cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�.
				gotoxy(x, --y); //�ܼ�ȭ�鿡�� ���� ��ĭ�̵��մϴ�.
				cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
			}
			break;
		case 80: //�Էµ� Ű���尡 �Ʒ� ����Ű�� ���
			if (y < v_data.size() - 1) { // v_data.size -1 ������ �Ʒ��� �̵��� �� ������ �����ִ� �����Դϴ�.
				gotoxy(x, y); //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
				cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�
				gotoxy(x, ++y); //�ܼ�ȭ�鿡�� ���� ��ĭ�̵��մϴ�.
				cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
			}
			break;
		case 13:
			if (c_data[choice2].video_rent != "empty") { //�뿩�� ������ ���� ���
				gotoxy(0, c_data.size() + 1); //�������ٷ� �̵��մϴ�.
				cout << "�̹� ������ �뿩�� ���Դϴ�." <<endl;
				cout << "3���Ŀ� �����մϴ�...";
				Sleep(300);
				return; //�Լ� ����
			}
			choice2 = y; //choice������ y���� �Է��մϴ�.
			c_data[choice2].video_rent = v_data[choice].video_name; //�� �뿩 ���� ������ �Է�
			gotoxy(0, c_data.size()+1); //�������ٷ� �̵�
			cout << "�뿩�� �Ϸ��߽��ϴ�.";
			Sleep(300);
			system("cls");
			return; //�Լ� ����
		}
	}
	choice = 0, choice2 = 0;
	x = 0, y = 0;
}

//���� �ݳ�
void video_nrental(vector<Video>& v_data, vector<Customer>& c_data) { 
	system("cls");
	if (v_data.size() == 0) { //���� ���� ����� 0�ϰ��
		cout << "�����ϰ� �ִ� ������ �����ϴ�.";
		cout << "\n 3���� ���� �԰�� �Ѿ�ϴ�.";
		Sleep(300);
		video_add(v_data); //���� �԰� �Լ� ȣ��
	}

	else if (c_data.size() == 0) { //�� ���� ���� ����� 0�� ���
		cout << endl << "�����ϰ� �ִ� �� ������ �����ϴ�.";
		cout << "\n 3���� �� �߰��� �Ѿ�ϴ�.";
		Sleep(300);
		customer_add(c_data); //�� ���� �߰� �Լ� ȣ��
	}

	int x = 0, y = 0;
	int keycode = 0, choose = 0;
	string temp;
	gotoxy(x, y);
	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) { //iterator�� ����� �ݺ���
		cout << "  ";
		i->print_custom_info(); //�� ���� ���
		cout << endl;
	}
	cout << "�ݳ��� ���� �����Ͻÿ�.(���� : ENTER)";
	gotoxy(x, y);
	cout << ">";
	while (1) {
		keycode = GetKey(); //����ڿ��� Ű���尪�� �Է¹޴� ����
		switch (keycode)
		{
		case 72: //�Էµ� Ű���尡 �� ����Ű�� ���
			if (y > 0) { // 0���� ���� �̵��� �� ������ �����ִ� �����Դϴ�.
				gotoxy(x, y); //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
				cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�.
				gotoxy(x, --y); //�ܼ�ȭ�鿡�� ���� ��ĭ�̵��մϴ�.
				cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
			}
			break;
		case 80: //�Էµ� Ű���尡 �Ʒ� ����Ű�� ���
			if (y < c_data.size()-1) { // c_data.size - 1������ �Ʒ��� �̵��� �� ������ �����ִ� �����Դϴ�.
				gotoxy(x, y); //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
				cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�.
				gotoxy(x, ++y); //�ܼ�ȭ�鿡�� �Ʒ��� ��ĭ�̵��մϴ�.
				cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
			}
			break;
		case 13: // Ű���� �Է°��� ENTER�� ��
			if (c_data[y].video_rent == "empty") { //���� �뿩���� ������ �������
				cout << "�� ���� �뿩���� ������ �����ϴ�." << endl;
				cout << "3���Ŀ� ����˴ϴ�...";
				Sleep(300);
				return; //�Լ� ����
			}
			c_data[y].video_rent = "empty"; //�� ���� �뿩 ������ ���ϴ�.
			temp = c_data[y].video_rent; //���� ���Ϳ��� �뿩 ���θ� �����ϱ� ���� �ӽ�����
			choose += 1;// �ݺ��� Ż���� ���� ����
			break; // switch ~case�� ����

		case 27: // Ű���� �Է°��� ESC�� ��
			return; //�Լ��� �����ϰ� ���θ޴��� �Ѿ�ϴ�.
		}
		if (choose != 0) break;// choose���� 0�� �ƴϸ� �ݺ��� ����
	}

	for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) {
		if (temp == i->video_name) { //�Է°��� ���������Ϳ� �����Ұ��
			i->rental_yn = 0; //�뿩���� �뿩�������� �����մϴ�.
		}
	}

}

//�� ������ ����
void customer_delete(vector<Customer>& c_data) {
	system("cls");
	if (c_data.size() == 0) { //�� ���� ���� ����� 0�� ���
		cout << "�����ϰ� �ִ� ������ �����ϴ�.";
		customer_add(c_data); //�� ���� �߰� �Լ� ȣ��
		return; //�Լ�����
	}
	int x = 0, y = 0;
	int keycode = 0;
	int choose = 0;
	gotoxy(x, y);
	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) { //iterator�� Ȱ���� �ݺ���
		cout << "  ";
		i->print_custom_info(); //�� ������ ����մϴ�.
		cout << endl;
	}
	cout << "����Ű ��, �Ʒ� ��������, ENTER : ����, ESC : ����";
	gotoxy(x, y);
	while (1) {
		keycode = GetKey(); //����ڿ��� Ű���尪�� �Է¹޽��ϴ�.
		switch (keycode)
		{
		case 72: //�Էµ� Ű���尡 �� ����Ű�� ���
			if (y > 0) { // 0���� ���� �̵��� �� ������ �����ִ� �����Դϴ�.
				gotoxy(x, y); //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
				cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�.
				gotoxy(x, --y); //�ܼ�ȭ�鿡�� ���� ��ĭ�̵��մϴ�.
				cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
			}
			break;
		case 80: //�Էµ� Ű���尡 �Ʒ� ����Ű�� ���
			if (y < c_data.size()-1) { // c_data.size - 1 ������ �Ʒ��� �̵��� �� ������ �����ִ� �����Դϴ�.
				gotoxy(x, y); //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
				cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�.
				gotoxy(x, ++y); //�ܼ�ȭ�鿡�� �Ʒ��� ��ĭ�̵��մϴ�.
				cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
			}
			break;
		case 13: // Ű���� �Է°��� ENTER�� ��
			choose = y; //choose ������ y ���� �Է��մϴ�.
			c_data.erase(c_data.begin() + choose);
			break; // swich~case �� ����

		case 27: // Ű���� �Է°��� ESC�� ��
			return; //�Լ��� �����ϰ� ���θ޴��� �Ѿ�ϴ�.
		}
		if (choose != 0) break;// order���� 0�� �ƴϸ� �ݺ��� ����
	}
}

//�� ���� ���
void customer_print(vector<Customer>& c_data) {
	system("cls");
	if (c_data.size() == 0) { // �� ���� ���� ����� 0�� ���
		cout << "�����ϰ� �ִ� �� ������ �����ϴ�.";
		customer_add(c_data); //�� ���� �߰� �Լ��� ȣ���մϴ�.
	}
	int keycode = 0;

	for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) {
		i->print_custom_info(); cout << endl; //�� ������ ����մϴ�.
	}
	cout << "���� 1 : �̸������� ����  ���� 2 : ������ϼ����� ����  ESC : ���θ޴�";
	while (1) {
		keycode = GetKey(); // ����ڿ��� Ű���� ���� �Է¹޽��ϴ�.
		switch (keycode)
		{
		case 49 : //���� 1�� �Է����� ���
			system("cls"); //ȭ�� �ʱ�ȭ�ϰ�
			sort(c_data.begin(), c_data.end(), sc_name); //�̸� ������ �����մϴ�.
			for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) {
				i->print_custom_info(); cout << endl; //���ĵ� �� ������ ����մϴ�.
			}
			cout << "���� 1 : �̸������� ����  ���� 2 : ������ϼ����� ����  ESC : ���θ޴�";
			break;
		case 50:
			system("cls");
			sort(c_data.begin(), c_data.end(), sc_birth); //������� ������ �����մϴ�.
			for (vector<Customer>::iterator i = c_data.begin(); i != c_data.end(); i++) {
				i->print_custom_info(); cout << endl; //���ĵ� �� ������ ����մϴ�.
			}
			cout << "���� 1 : �̸������� ����  ���� 2 : ������ϼ����� ����  ESC : ���θ޴�";
			break;
		case 27: //����ڰ� ESC�� ������ ��
			return; //�Լ��� �����ϰ� ���θ޴��� �Ѿ�ϴ�.
		}
	}
}

//���� ��� ���
void video_print(vector<Video>& v_data) {
	system("cls");
	if (v_data.size() == 0) { //���� ���� ����� 0�� ���
		cout << "�����ϰ� �ִ� ������ �����ϴ�.";
		video_add(v_data); //���� �԰� �Լ� ȣ��
	}

	int keycode = 0;
	for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) { //iterator�� Ȱ���� �ݺ���
		if (i->rental_yn == 0) { //�뿩������ ������ ���
			cout << i->video_name << "  �뿩����" << endl; //����մϴ�.
		}
	}
	cout << "���� 1 : �̸������� ����  ESC : ���θ޴�";
	while (1) {
		keycode = GetKey();
		switch (keycode)
		{
		case 49: //����ڰ� ����1�� ������ ���
			system("cls"); //ȭ�� �ʱ�ȭ�մϴ�.
			sort(v_data.begin(), v_data.end(), sv_name); //���� ���� ������ �����մϴ�
			for (vector<Video>::iterator i = v_data.begin(); i != v_data.end(); i++) {
				if (i->rental_yn == 0) { //�뿩������ ������ ����մϴ�.
					cout << i->video_name << "  �뿩����" <<endl;
				}
			}
			cout << "���� 1 : �̸������� ����  ESC : ���θ޴�";
			break;
		case 27: //����ڰ� ESC�� ������ ��
			return; //�Լ��� �����ϰ� ���θ޴��� �Ѿ�ϴ�.
		}
	}
}