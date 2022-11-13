#include "Class.h"

PhoneNumber temp;

PhoneNumber::PhoneNumber(string r_name, string r_phone, string r_email, string r_place, int r_birth) {
    name = r_name;
    phonenum = r_phone;
    email = r_email;
    place = r_place;
    birth = r_birth;
}; //Ŭ���� ���·� ������ ����Ǹ� �ʱ�ȭ�ϴ� Ŭ���� ��� �Լ�

//Vector �ڷ� ��� ����
void PhoneNumber::print_info() {
    cout << name; //�̸� ���
    cout.width(15); //�ʵ��� 15
    cout << phonenum;//��ȭ��ȣ ���
    cout.width(20); //�ʵ��� 20
    cout << email; // �̸��� ���
    cout.width(15); //�ʵ��� 10
    cout << place; // ��°� ���
    cout.width(15); //�ʵ��� 10
    cout << birth; // ������� ���
}

int print_sortm(); //function.cpp�� �ִ� sorted �Լ��� ���� �޴� ����Լ�

//��ȭ��ȣ �߰�
void add(vector<PhoneNumber>& data) {
    system("cls"); // ������ �ִ� ���� �ʱ�ȭ(ȭ���ʱ�ȭ)

    while (1) {
        cout << "��ȭ��ȣ �Է����� :  xxx-xxxx-xxxx" << "   ������� �Է� �� :19870421" << endl;
        cout << "�̸�(����), ��ȭ��ȣ, �̸���, ��°�, ���� ������ �Է��ϼ���." << endl;
        cout << "�Է� : ";
        cin >> temp.name >> temp.phonenum >> temp.email >> temp.place >> temp.birth; // ����ڿ��� �߰��� �ڷ��� ������ �Է¹޽��ϴ�.
        data.push_back(temp); // �Էµ� �ڷḦ Vector ������ data�� �߰�.
        cout << "��ȭ��ȣ�� �� �߰��ϽǰŸ� ����, �����ϽǷ��� ESC�� �����ּ���.";
        int getk = GetKey(); // GetKey �Լ��� Ű���� ���� �Է¹޴´�.
        if (getk == 27) { // Ű���� �Է°��� ESC�� ��
            break; // �Լ��� �����ϰ� ���θ޴��� �Ѿ.
        }
        else if (getk == 13) { //Ű���� �Է°��� ENTER�� ��
            system("cls"); //���� ȭ�� �ʱ�ȭ�մϴ�.
            continue; // add�Լ� ��� �����մϴ�.
        }
    }
}

//����
void modified(vector<PhoneNumber>& data) {
    system("cls");
    int num = 1, order = 0;
    if (data.size() == 0) { //vector�� ����� ������ ���� 0�� ��,
        cout << "������ ��ȭ��ȣ�� �����ϴ�." << endl;
        cout << "��ȭ��ȣ�� �߰��մϴ�...." << endl;
        Sleep(3000); //3�������� ���� �Ӵϴ�.
        add(data); //add �Լ��� ȣ���մϴ�.
    }

    cout << "� �����͸� ���� �Ͻðڽ��ϱ�?" <<endl;
    for (vector<PhoneNumber>::iterator i = data.begin(); i != data.end(); i++) {
        cout << "  ";
        i->print_info(); cout << endl;
    }//iterator�� Ȱ���� �ݺ����� ���ؼ� ���Ϳ� ����� �ڷḦ ����մϴ�.

    int x = 0, y = 1;
    gotoxy(x, y);
    cout << ">";
    while (1) {
        int dkey = GetKey();
        switch (dkey) {
        case 72: //�Էµ� Ű���尡 �� ����Ű�� ���
            if (y > 1) { // 0���� ���� �̵��� �� ������ �����ִ� �����Դϴ�.
                gotoxy(x, y); //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
                cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�.
                gotoxy(x, --y); //�ܼ�ȭ�鿡�� ���� ��ĭ�̵��մϴ�.
                cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
            }
            break;
        case 80: //�Էµ� Ű���尡 �Ʒ� ����Ű�� ���
            if (y < data.size()) { // data.size ������ �Ʒ��� �̵��� �� ������ �����ִ� �����Դϴ�.
                gotoxy(x, y); //gotoxy �Լ��� �ܼ�ȭ�� x,y�� �̵��մϴ�.
                cout << " "; //������ �����ϴ� > Ŀ���� ����ϴ�.
                gotoxy(x, ++y); //�ܼ�ȭ�鿡�� �Ʒ��� ��ĭ�̵��մϴ�.
                cout << ">"; //�̵��� ��ġ�� > �� �Է��մϴ�.
            }
            break;
        case 13: // Ű���� �Է°��� ENTER�� ��
            order = y-1; //order ������ y-1 ���� �Է��մϴ�.
            break; // switch ~case�� ����

        case 27: // Ű���� �Է°��� ESC�� ��
            return; //�Լ��� �����ϰ� ���θ޴��� �Ѿ�ϴ�.
        }
        if (order != 0) break;// order���� 0�� �ƴϸ� �ݺ��� ����
    }
    gotoxy(0, data.size() + 1); // Ŀ���� ������ ���ܼ� ���� ��� �����̶� �� ��ġ���� �̵��մϴ�.
    cout << "�̸� :"; cin >> data[order].name; //������ �ڷ��� �̸� ����
    cout << "��ȭ��ȣ :"; cin >> data[order].phonenum; //������ �ڷ��� ��ȭ��ȣ ����
    cout << "�̸��� :"; cin >> data[order].email; //������ �ڷ��� �̸��� ����
    cout << "��°� :"; cin >> data[order].place; //������ �ڷ��� ��� �� ����
    cout << "������� :"; cin >> data[order].birth; //������ �ڷ��� ������� ����
}


//����
void deleted(vector<PhoneNumber>& data) {
    system("cls");
    int num = 1, order = 0;
    if (data.size() == 0) {
        cout << "������ ��ȭ��ȣ�� �����ϴ�." << endl;
        cout << "��ȭ��ȣ�� �߰��մϴ�...." << endl;
        Sleep(3000);
        add(data);
    } // ���Ϳ� ����� �ڷᰡ ������ �߰� �Լ� ȣ��

    for (vector<PhoneNumber>::iterator i = data.begin(); i != data.end(); i++) {
        cout << "  ";
        i->print_info(); cout << endl;
    } //iterator�� ���ؼ� ���Ϳ� ����� �ڷḦ ���

    cout << "� �����͸� ���� �Ͻðڽ��ϱ�?";
    int x = 0, y = 0;
    gotoxy(x,y);
    cout << ">";
    while (1) {
        int dkey = GetKey(); //Ű���� ��, �Ʒ� �������� ������ �����ϰ� ���� �ڷ� ����
        switch (dkey) {
        case 72:
            if (y > 0) {
                gotoxy(x, y);
                cout << " ";
                gotoxy(x, --y);
                cout << ">";
            }
            break;
        case 80:
            if (y < data.size()-1) {
                gotoxy(x, y);
                cout << " ";
                gotoxy(x, ++y);
                cout << ">";
            }
            break;
        case 13: //����ڰ� ���͸� ������ ��
            order = y; // �ܼ�ȭ�� y��ǥ���� order������ �ֽ��ϴ�.
            data.erase(data.begin() + order); //data ù��° �ڷῡ�� order��° ��ŭ �ڿ��ִ� �ڷḦ �����մϴ�.
            return; //�����ϰ� �Լ��� �����մϴ�.

        case 27 : //����ڰ� ESC�� ������ ��
            return; //�Լ��� �����ϰ� ���θ޴��� �Ѿ�ϴ�.
        }
    }
}

//�˻�
void search(vector<PhoneNumber>& data) {
    system("cls");
    if (data.size() == 0) {
        cout << "������ ��ȭ��ȣ�� �����ϴ�." << endl;
        cout << "��ȭ��ȣ�� �߰��մϴ�...." << endl;
        Sleep(3000);
        add(data);
    }

    string searching; //����ڿ��� �˻��� ������ �Է¹��� ���ڿ� ����
    int nfind = 0, skey = 0; //nfind�� ã�Ҵ��� ��ã�Ҵ��� �����ϱ� ���� ����
    cout << "�̸�(����), ��ȭ��ȣ, �̸����� �ϳ� �Է��ϼ���.";
    cin >> searching; //����ڿ��� �Է¹޴� �Լ�
    for (int i = 0; i < data.size(); i++) { //������ ������ŭ �ݺ��ϴ� �ݺ���
        if (searching.compare(data[i].name) == 0) { //searching�� �Էµ� ����� ���Ϳ� ����� �̸��� ���� ���
            data[i].print_info(); // �˻��� ������ ����մϴ�.
            cout << endl;
            ++nfind; // �ڷḦ ã�Ҵٴ� ǥ�ø� ���ݴϴ�.
            cout << "���͸� ������ ����ȭ������ �Ѿ�ϴ�.";
            skey = GetKey(); 
            if(skey == 13)break; //����ڰ� ENTER�� ������ �˻� �Լ��� �����ϰ� ���� �޴��� �Ѿ�ϴ�.
            
        } 
        else if (searching.compare(data[i].email)==0) { //searching�� �Էµ� ����� ���Ϳ� ����� �̸��� ���� ���
            data[i].print_info();
            cout << endl;
            ++nfind;
            cout << "���͸� ������ ����ȭ������ �Ѿ�ϴ�.";
            skey = GetKey();
            if (skey == 13)break;
        }
        else if (searching.compare(data[i].phonenum)==0) { //searching�� �Էµ� ����� ���Ϳ� ����� ��ȭ��ȣ�� ���� ���
            data[i].print_info();
            cout << endl;
            ++nfind;
            cout << "���͸� ������ ����ȭ������ �Ѿ�ϴ�.";
            skey = GetKey();
            if (skey == 13)break;
        }
    }
    if (nfind == 0) { //����ڰ� �Է��� �ڷḦ ã�� ������ ��
        cout << "�˻��Ͻ� ��ȭ��ȣ�� �������� �ʽ��ϴ�."<<endl;
        cout << "3���Ŀ� ���θ޴��� ���ư��ϴ�..."; // ã�� ���޴ٴ� ������ ����ݴϴ�.
        Sleep(3000); //3�ʵ��� ���α׷� ����
    }
}

//����
void sorted(vector<PhoneNumber>& data) {
    system("cls");
    if (data.size() == 0) {
        cout << "������ ��ȭ��ȣ�� �����ϴ�." << endl;
        cout << "��ȭ��ȣ�� �߰��մϴ�...." << endl;
        Sleep(3000);
        add(data);
    }
    int order = print_sortm(); //�������� ��� �޴��� ����Լ��� ȣ���մϴ�.
    switch (order) //switch~case������ print_sortm���� ������ ��ɿ� �´� �������� �Ѿ�ϴ�.
    {
    case 1: // �̸������� ������ �������� ��
        sort(data.begin(), data.end(), s_name); //sort�Լ��� ���ؼ� �̸������� ����
        break;
    case 2: // ��ȭ��ȣ������ ������ �������� ��
        sort(data.begin(), data.end(), s_phonenum); //sort�Լ��� ���ؼ� ��ȭ��ȣ������ ����
        break;
    case 3: // �̸��ϼ����� ������ �������� ��
        sort(data.begin(), data.end(), s_email); //sort�Լ��� ���ؼ� �̸��ϼ����� ����
        break;
    case 4: // ������� ������ ������ �������� ��
        sort(data.begin(), data.end(), s_birth); //sort�Լ��� ���ؼ� ������ϼ����� ����
        break;
    case 5: // ����ڰ� ESC�� ������ ��
        return; //�Լ��� �����ϰ� ���θ޴��� ���ư��ϴ�.
    }

    for (vector<PhoneNumber>::iterator i = data.begin(); i != data.end(); i++) {
        i->print_info();
        cout << endl;
    } //���ĵ� ������� �ݺ������� ����մϴ�.
    cout << "���͸� ������ ���� �޴��� �Ѿ�ϴ�.";
    int rekey = GetKey(); //����ڿ��� Ű���尪�� �Է¹޴´�.
    if (rekey == 13) { //ENTER�� ������ ��
        return; //�Լ��� �����ϰ� ���θ޴��� �Ѿ�ϴ�.
    }
}

int print_sortm() {
    int x = 0, y = 0;
    cout << "> �̸������� ����" << endl;
    cout << "  ��ȭ��ȣ������ ����" << endl;
    cout << "  �̸��ϼ����� ����" << endl;
    cout << "  ������ϼ����� ����" << endl;
    while (1) {
        int gkey = GetKey();
        switch (gkey) {
        case 72:
            if (y > 0) {
                gotoxy(x, y);
                cout << " ";
                gotoxy(x, --y);
                cout << ">";
            }
            break;
        case 80:
            if (y < 3) {
                gotoxy(x, y);
                cout << " ";
                gotoxy(x, ++y);
                cout << ">";
            }
            break;

        case 27:
            return 5;

        case 13:
            return y + 1;
        }
    }

}