#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	Node* left = 0;
	Node* right = 0;
	string userName;
	string userPassword;
	Node() :right(0), left(0){};
	Node(string a, string b) :userName(a), userPassword(b), right(0), left(0){};
};

