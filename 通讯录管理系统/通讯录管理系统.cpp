//封装函数显示界面	void showMenu
//在main函数中调用
#include <iostream>
#include <string>
#define MAX	1000
using namespace std;

//联系人结构体
struct Person
{
	//名字
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;

};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保存联系人的数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};

//添加联系人
void addPerson(Addressbooks * abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别" << endl;
		cout << "1——男" << endl;
		cout << "2——女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入的是1或2，可以退出循环
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入错误，重新输入" << endl;
		}
		
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		
		system("pause"); //请按任意键继续
		system("cls");	//清屏
	}
}

//显示联系人
void showPerson(Addressbooks * abs)
{
	//如果为0提示为空
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名" << abs->personArray[i].m_Name << endl;
			cout << "性别" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << endl;
			cout << "年龄" << abs->personArray[i].m_Age << endl;
			cout << "电话" << abs->personArray[i].m_Phone << endl;
			cout << "地址" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause"); //请按任意键继续
	system("cls");	//清屏
}

void showMenu()
{
	cout << "*****  1、添加联系人" << endl;
	cout << "*****  2、显示联系人" << endl;
	cout << "*****  3、删除联系人" << endl;
	cout << "*****  4、查找联系人" << endl;
	cout << "*****  5、修改联系人" << endl;
	cout << "*****  6、清空联系人" << endl;
	cout << "*****  0、推出通讯录" << endl;
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录当前人员个数
	abs.m_Size = 0;

	int select = 0;	//用户输入的变量
	
	//输入非0都会重新回到菜单
	while (true)
	{
		showMenu();	//菜单调用
		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			addPerson(&abs);//利用地址传递，可以修饰形参
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
			break;
		case 4://4、查找联系人
			break;
		case 5://5、修改联系人
			break;
		case 6://6、清空联系人
			break;
		case 0://0、推出通讯录
			cout << "欢迎下次使用" << endl;
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