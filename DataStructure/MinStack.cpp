#include <memory>
#include <iostream>

// ?????
class MinStackElement
{
public:
	int min;
	int data;
};
class MinStack
{
private:
	int mCapacity;
	int top;
	MinStackElement *data;

public:
	MinStack(int capacity);
	~MinStack();
	int min();
	void push(int d);
	int pop();
};

//×îÐ¡Õ»
MinStack::MinStack(int capacity)
	:mCapacity(capacity)
{
	data = new MinStackElement[mCapacity];
	top = -1;
}

MinStack::~MinStack()
{
	delete[]data;
}

int MinStack::min()
{
	if (top == -1) {
		std::cerr << "Stack is empty!" << std::endl;
		exit(1);
	}
	return data[top].min;
}

void MinStack::push(int d)
{
	if (top == mCapacity-1) {
		std::cerr << "out of stack space!" << std::endl;
		exit(1);
	}
	top++;
	MinStackElement* p = &data[top];
	p->data = d;
	p->min = top == 0 ? d : data[top].min = std::min(d, data[top - 1].min);
	return;
}

int MinStack::pop()
{
	if (top == -1) {
		std::cerr << "Stack is empty!" << std::endl;
		exit(1);
	}
	return data[--top].data;
}
