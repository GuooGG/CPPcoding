#pragma once
#include<memory>
#include<iostream>

//最小栈类型
class MinStackElement {
public:
	int min;
	int data;
};
class MinStack
{
private:
	int mCapacity;
	int top;
	MinStackElement* data;
public:
	MinStack(int capacity);
	~MinStack();
	int min();
	void push(int d);
	int pop();
};

