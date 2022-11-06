//��װ������ʾ����	void showMenu
//��main�����е���
#include <iostream>
#include <string>
#define MAX	1000
using namespace std;

//��ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;

};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б�����ϵ�˵�����
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};

//�����ϵ��
void addPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1������" << endl;
		cout << "2����Ů" << endl;
		int sex = 0;
		while (true)
		{
			//����������1��2�������˳�ѭ��
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "���������������" << endl;
		}
		
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		
		system("pause"); //�밴���������
		system("cls");	//����
	}
}

//��ʾ��ϵ��
void showPerson(Addressbooks * abs)
{
	//���Ϊ0��ʾΪ��
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����:" << abs->personArray[i].m_Name << endl;
			cout << "�Ա�:" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << endl;
			cout << "����:" << abs->personArray[i].m_Age << endl;
			cout << "�绰:" << abs->personArray[i].m_Phone << endl;
			cout << "��ַ:" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause"); //�밴���������
	system("cls");	//����
}

//�����ϵ���Ƿ���
int isExist(Addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�ҵ��ˣ�����������������е��±���
		}
	}
	return -1;
}

//ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//���ɾ�������飬���������������ǰ�ƶ������ǵ�����Ա����-1
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�밴���������
	system("cls");	//����
}

//������ϵ��
void selectPerson(Addressbooks *abs)
{
	cout << "������Ҫ���ҵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << endl;
		cout << "���䣺" << (abs->personArray[ret].m_Age == 1 ? "��":"Ů") << endl;
		cout << "�Ա�" << abs->personArray[ret].m_Sex << endl;
		cout << "�绰��" << abs->personArray[ret].m_Phone << endl;
		cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�밴���������
	system("cls");	//����
}

//�޸���ϵ��
void fixPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1������" << endl;
		cout << "2����Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�밴���������
	system("cls");	//����
}

void cleanPerson(Addressbooks* abs)
{
	cout << "�Ƿ�ȷ��Ҫ���,���ȷ�������� 1" << endl;
	int ret = 0;
	cin >> ret;
	if (ret == 1)
	{
		//����ǰ��¼����ϵ��������Ϊ0
		abs->m_Size = 0;
		cout << "�����" << endl;
	}
	system("pause"); //�밴���������
	system("cls");	//����
}

void showMenu()
{
	cout << "*****  1�������ϵ��" << endl;
	cout << "*****  2����ʾ��ϵ��" << endl;
	cout << "*****  3��ɾ����ϵ��" << endl;
	cout << "*****  4��������ϵ��" << endl;
	cout << "*****  5���޸���ϵ��" << endl;
	cout << "*****  6�������ϵ��" << endl;
	cout << "*****  0���Ƴ�ͨѶ¼" << endl;
}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼��ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;	//�û�����ı���
	
	//�����0�������»ص��˵�
	while (true)
	{
		showMenu();	//�˵�����
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addPerson(&abs);//���õ�ַ���ݣ����������β�
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://4��������ϵ��
			selectPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			fixPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���Ƴ�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}