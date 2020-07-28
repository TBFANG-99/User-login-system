#include "menu.h"
#include<iostream>
#include<fstream>
#include"userTree.h"
#include"Node.h"
#include<string>
#include<conio.h>
using namespace std;
menu::menu()
{
	ifstream Fang("userData.txt");
	string tempname;
	string temppassword;
	for (int i = 0; i < 20; i++)
	{
		getline(Fang, tempname, ' ');//一行一个数据，用户名和密码之间用空格分开，遇到空格停止
		getline(Fang, temppassword);//遇到换行停止
		Tree.insert(tempname, temppassword);
	}
}
void menu::mainmenu()  //主菜单
{
	system("cls");              //清空屏幕
	cout << endl << endl << endl << endl;
	cout << "                                      用户登录系统" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *        请选择操作：                                *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                 1.登录                             *" << endl;
	cout << "                   *                 2.注册新用户                       *" << endl;
	cout << "                   *                 3.退出系统并输出用户数据           *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   输入1-3: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "3" || a < "1")
	{
	   	cout << "               	   输入错误！请重新输入1-3: ";
		cin >> a;
	}
	int t = a[0] - '0';
	switch (t)
	{
	case 1:
		load();
		break;
	case 2:
		regist(); 
		break;
	case 3:
		close(); 
		break;
	}
}
bool menu::rightPassword(string a, string b)
{
	string::size_type idx;           //虚位密码
	idx = a.find(b);                 //在a中查找b
	if (idx == string::npos)         //密码错误
		return false;
	else
		return true;
}
void menu::show2()  //查看所有用户界面 
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      所有用户数据" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	Tree.show();
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   请选择操作：" << endl;
	cout << "                   1.返回主菜单" << endl;
	cout << "                   2.退出系统并输出用户数据" << endl;
	cout << "                   输入1-2: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "2" || a < "1")
	{
		cout << "                   输入错误！请重新输入1-2: ";
		cin >> a;
	}
	int t = a[0] - '0';
	switch (t)
	{
	case 1:
		mainmenu();
		break;
	case 2:
		close();
		break;
	}
}
void menu::load(int n)   //登录界面
{
	system("cls");
	string name;
	cout << endl << endl;
	cout << "                      管理员账号：201806062707    密码:fangtianbin" << endl;
	cout << endl;
	cout << "                                      用户登录界面" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *      请输入用户名: ";
	cin >> name;
	cout << "                   *      请输入用户密码: ";
	string password;
	int i = 0;
	char ch;
	while ((ch = _getch()) != 13)//13是回车
	{
		password += ch;
		cout << "*";
	}
	cout << endl;
	Node* ptr = Tree.search(name);
	if (n == 2)
	{
		cout << "                   *      密码错误三次，自动退出系统                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		close();
	}
	else if (ptr == 0)
	{
		cout << "                   *      登录错误：用户名不存在                        *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   1.重新登录" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			load();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (rightPassword(password, ptr->userPassword) && name == "201806062707")//进入管理员界面，管理员账户不可修改密码
	{
		cout << "                   *      登录成功！                                    *" << endl;
		cout << "                   *      尊敬的管理员用户，您好！                      *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.查看所有用户数据" << endl;
		cout << "                   2.删除指定用户" << endl;
		cout << "                   3.返回主菜单" << endl;
		cout << "                   4.退出系统并输出用户数据" << endl;
		cout << "                   输入1-4: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "4" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-4: ";
			cin >> a;
		}
		int t = a[0] - '0';
		string delname;
		string b;
		switch (t)
		{
		case 1:
			show2();
			break;
		case 2:
			cout << "                   输入想删除的用户账号: ";
			cin >> delname;
			Delete2(delname);
			break;
		case 3:
			mainmenu();
			break;
		case 4:
			close();
			break;
		}
	}
	else if (rightPassword(password, ptr->userPassword))
	{
		cout << "                   *      登录成功！                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.修改密码" << endl;
		cout << "                   2.删除用户" << endl;
		cout << "                   3.返回主菜单" << endl;
		cout << "                   4.退出系统并输出用户数据" << endl;
		cout << "                   输入1-4: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "4" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-4: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			Change(Tree.search(name)); 
			break;
		case 2:
			Delete(Tree.search(name));
			break;
		case 3:
			mainmenu(); 
			break;
		case 4:
			close(); 
			break;
		}
	}
	else
	{
		n++;
		cout << "                   *      登录失败：密码错误                            *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.重新登录" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			load(n);
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
}
bool menu::tooEasy(string password)//过于简单的密码
{
	if (password.length() < 4)
		return true;
	if (password == "123456")
		return true;
	if (password == "12345678")
		return true;
	if (password == "123456789")
		return true;
	if (password == "8888")
		return true;
	if (password == "888888")
		return true;
	if (password == "88888888")
		return true;
	return false;
}
void menu::regist()  //注册 
{
	string name, password1, password2;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      新用户注册界面" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *     请输入想要注册的用户名:";
	cin >> name;
	cout << "                   *     请输入密码: ";
	char ch1;
	while ((ch1 = _getch()) != 13)//13是回车
	{
		password1 += ch1;
		cout << "*";
	}
	cout << endl;
	cout << "                   *     请确认密码: ";
	char ch2;
	while ((ch2 = _getch()) != 13)//13是回车
	{
		password2 += ch2;
		cout << "*";
	}
	cout << endl;
	Node* ptr = Tree.search(name);
	if (ptr == 0 && password1 == password2 && !tooEasy(password1))
	{
		Tree.insert(name, password1);
		cout << "                   *     注册成功！                                     *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainmenu();
			break;
		case 2:
			close();
			break;
		}
	}
	else if (ptr != 0) 
	{ 
		cout << "                   *     注册失败：用户名已存在                         *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.重新注册" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			regist();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (password1 != password2) 
	{ 
		cout << "                   *     注册失败：两次密码不一致                       *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.重新注册" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			regist();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (tooEasy(password1))
	{
		cout << "                   *     注册失败：密码过于简单                         *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.重新注册" << endl;
		cout << "                   2.返回主菜单" << endl;
		cout << "                   3.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			regist();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
}
void menu::Change(Node* ptr)                   //修改密码 
{
	string name = ptr->userName;
	string password;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      用户密码修改界面" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *      请输入新密码:";
	char ch;
	while ((ch = _getch()) != 13)//13是回车
	{
		password += ch;
		cout << "*";
	}
	if (!tooEasy(password) && password != ptr->userPassword)
	{
		ptr->userPassword = password;
		cout << "                   *      修改密码成功！                                *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-2:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainmenu();
			break;
		case 2:
			close();
			break;
		}
	}
	else if (tooEasy(password))
	{
		cout << "                   *      密码修改失败：密码过于简单                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.重新修改密码" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			Change(Tree.search(name));
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (password == ptr->userPassword)
	{
		cout << "                   *      修改密码失败：新密码不能与原密码相同          *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.重新修改密码" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			Change(Tree.search(name));
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
}
void menu::Delete2(string a)  //删除指定用户 
{
	Node* ptr = Tree.search(a);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      删除用户界面" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	if (ptr == 0)
	{
		cout << "                   *      删除用户失败：用户不存在                      *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainmenu();
			break;
		case 2:
			close();
			break;
		}
	}
	else
	{
		Tree.Delete(ptr->userName);
		cout << "                   *      删除该用户成功！                              *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   请选择操作：" << endl;
		cout << "                   1.返回主菜单" << endl;
		cout << "                   2.退出系统并输出用户数据" << endl;
		cout << "                   输入1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   输入错误！请重新输入1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainmenu();
			break;
		case 2:
			close();
			break;
		}
	}
}
void menu::Delete(Node* p)  //删除用户 
{
	Tree.Delete(p->userName);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      删除用户界面" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *      删除该用户成功！                              *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   请选择操作：" << endl;
	cout << "                   1.返回主菜单" << endl;
	cout << "                   2.退出系统并输出用户数据" << endl;
	cout << "                   输入1-2: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "2" || a < "1")
	{
		cout << "                   输入错误！请重新输入1-2: ";
		cin >> a;
	}
	int t = a[0] - '0';
	switch (t)
	{
	case 1:
		mainmenu();
		break;
	case 2:
		close();
		break;
	}
}
void menu::close()  //将用户保存到txt中
{
	ofstream FFang("NewuserData.txt");
	FFang << Tree;
	FFang.close();
}