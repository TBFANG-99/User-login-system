#pragma once
#include<iostream>
#include "Node.h"
using namespace std;
class userTree
{
private:
	Node* myRoot;
	void insertAux(string name, string password, Node*& a); //对内插入新用户数据，递归用,a用引用
	void DeleteAux(string name, Node*& a);//递归用
	Node* FindMin(Node* a);//删除用
	void graphAux(int n, Node* root);
public:
	Node* RightRotate(Node* a);//右旋,返回新平衡节点
	Node* LeftRotate(Node* a);//左旋，返回新平衡节点
	Node* LR_Rotate(Node* a);//左右旋
	Node* RL_Rotate(Node* a);//右左旋
	void insert(string name, string password);//对外插入新用户数据，判断是否重复用户名
	int depth(Node* a);//节点所在深度，叶子为1，向上递增，用于计算平衡因子
	void Delete(string name);
	void graph();
	userTree() :myRoot(0) {};
	Node* search(string name);
	friend ostream& operator << (ostream& stream, userTree a);  //输出文件 
	friend void outtxt(Node* a, ostream& output);
	void showAux(Node* a); 
	void show();
};