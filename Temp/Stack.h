#pragma once
#include <string>

using namespace std;


class Stack { //constructor
private:
	struct Mitem
	{
		string name;
		char arrname;
		Mitem* lastItem;
	};

	Mitem* stackPt;

public:
	void Push(string name,int arrname);
	void Pop();
	void ReadItem(Mitem);
	void PrintStack();

	Stack();
	~Stack();


};