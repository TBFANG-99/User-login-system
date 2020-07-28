#pragma once
#include"Node.h"
#include"userTree.h"
class menu
{
public:
	userTree Tree;
	menu();             //构造函数
	void mainmenu();    //主菜单 
	void load(int n = 0);        //登陆 n为连续输错密码次数，默认为0
	void regist();      //注册 
	bool tooEasy(string password);//判断密码是否过于简单
	void Change(Node* a); //修改密码 
	void Delete(Node* a); //删除用户 
	void close();       //将用户数据保存到userData.txt中
	bool rightPassword(string a, string b);//虚位密码
	void show2();//查看所有用户界面 
	void Delete2(string a);//删除指定用户
};


