#include "userTree.h"
#include"Node.h"
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
Node* userTree::RightRotate(Node* a)//a指向平衡因子2的点，运行完成后返回新平衡点
{
	Node* r = a->left;         
	a->left = r->right;                   
	r->right = a;
	return r;
}
Node* userTree::LeftRotate(Node* a)//左旋同理
{
	Node* r = a->right;
	a->right = r->left;
	r->left = a;
	return r;
}
Node* userTree::LR_Rotate(Node* a)//拆分为先左旋再右旋，注意a的位置，右旋的a是平衡因子为2的点,运行完成后返回新平衡点
{
	a->left = LeftRotate(a->left);
	return RightRotate(a);
}
Node* userTree::RL_Rotate(Node* a)//右左旋同理
{
	a->right = RightRotate(a->right);
	return LeftRotate(a);
}
void userTree::insert(string name, string password)
{
	//判断用户名是否重复
	int found = 0;
	Node* ptr = myRoot;
	while (ptr != 0 && !found)
	{
		if (name > ptr->userName)
			ptr = ptr->right;
		else if (name < ptr->userName)
			ptr = ptr->left;
		else
			found = 1;
	}
	if (found)
	{
		cout << "创建用户失败：该用户名已注册" << endl;
		return;
	}
	//调用内部函数递归插入
	insertAux(name, password, myRoot);
}
void userTree::insertAux(string name, string password, Node*& a)
{
	if (a == 0)
		a = new Node(name, password);
	else if (name > a->userName)
	{
		insertAux(name, password, a->right);
		if (depth(a->right) - depth(a->left) > 1)//平衡状态下新增右节点，右高减左高肯定大于等于0   //旋转至平衡
		{
			if (name > a->right->userName)       //右右情况，左旋
				a = LeftRotate(a);
			if (name < a->right->userName)       //右左情况，右左旋
				a = RL_Rotate(a);
		}
	}
	else
	{
		insertAux(name, password, a->left);
		if (depth(a->left) - depth(a->right) > 1)
		{
			if (name < a->left->userName)            //左左，右旋
				a = RightRotate(a);
			if (name > a->left->userName)            //左右，左右旋
				a = LR_Rotate(a);
		}
	}
}
int userTree::depth(Node* a)//递归求深度
{
	if (a == 0)
		return 0;
	return max(depth(a->left), depth(a->right)) + 1;
}
void userTree::Delete(string name)
{
	int found = 0;
	Node* ptr = myRoot;
	while (ptr != 0 && !found)
	{
		if (name > ptr->userName)
			ptr = ptr->right;
		else if (name < ptr->userName)
			ptr = ptr->left;
		else
			found = 1;
	}
	if (!found)
	{
		cout << "删除用户失败：该用户名未注册" << endl;
		return;
	}
	//调用内部函数递归删除
	DeleteAux(name, myRoot);
}
void userTree::DeleteAux(string name, Node*& a)
{
	if (a == 0)
		return;
	else if (name > a->userName)  //调平
	{
		DeleteAux(name, a->right);
		if (depth(a->left) - depth(a->right) > 1)
		{
			if (a->left->right && a->left->left)   //删除过程中的特殊情况，详见PPT
				a = RightRotate(a);
			else if (a->left->right)            //左右，双旋
				a = LR_Rotate(a);
			else                                //左左，右旋
				a = RightRotate(a);
		}
	}
	else if (name < a->userName)   //调平
	{
		DeleteAux(name, a->left);
		if (depth(a->right) - depth(a->left) > 1)
		{
			if (a->right->right && a->right->left)   //删除过程中的特殊情况，详见PPT
				a = LeftRotate(a);
			else if (a->right->left)            //右左，双旋
				a = RL_Rotate(a);
			else                                //右右，左旋
				a = LeftRotate(a);
		}
	}
	else     //删除
	{
		if (a->left && a->right)   //有两个孩子
		{
			a->userName = FindMin(a->right)->userName;
			a->userPassword = FindMin(a->right)->userPassword;
			DeleteAux(name, a->right);
		}
		else                       //只有一个孩子或者没有孩子
		{
			Node* t = a;
			if (a->left == 0)
				a = a->right;
			else if (a->right == 0)
				a = a->left;
			delete t;
		}
	}
}
Node* userTree::FindMin(Node* a)//删除中查找直接后继
{
	if (a == 0)
		return 0;
	else
	{
		if (a->left == 0)
			return a;
		else
			return FindMin(a->left);
	}
}
void userTree::graphAux(int n, Node* root)
{
	if (root != 0)
	{
		graphAux(n + 8, root->right);
		cout << setw(n) << " " << root->userName << endl;
		graphAux(n + 8, root->left);
	}
}
void userTree::graph()
{
	graphAux( 0, myRoot);
}

Node* userTree::search(string name)
{
	Node* locptr = myRoot;
	while (locptr != 0)
	{
		if (name > locptr->userName)
			locptr = locptr->right;
		else if (name < locptr->userName)
			locptr = locptr->left;
		else
			return locptr;
	}
	return 0;
}
void outtxt(Node* a, ostream& output)  //输出数据
{
	if (a == 0)
		return;
	output << a->userName << " " << a->userPassword << endl;
	outtxt(a->left, output);
	outtxt(a->right, output);
}
ostream& operator <<(ostream& stream, userTree a)  //输出文件，将用户保存到txt中 
{
	outtxt(a.myRoot, stream);
	return stream;
}
void userTree::showAux(Node* a) 
{
	if (a == NULL) return;
	cout << "                   *  " << a->userName << "   " << a->userPassword << endl;
	showAux(a->left);
	showAux(a->right);
}
void userTree::show()
{
	showAux(myRoot);
}