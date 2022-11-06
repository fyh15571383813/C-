//封装函数显示界面	void showMenu
//在main函数中调用
#include <iostream>
using namespace std;

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
	int select = 0;	//用户输入的变量
	
	//输入非0都会重新回到菜单
	while (true)
	{
		showMenu();	//菜单调用
		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			break;
		case 2://2、显示联系人
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