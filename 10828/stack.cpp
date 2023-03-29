https://www.acmicpc.net/problem/10828    stack

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class stack {
private:
	int sizeOfStack;
	vector<int> Stack;
public:
	stack() {
		vector<int> stack;
		sizeOfStack = 0;
	}
	void push(int inputNum);
	int pop();
	int size();
	int empty();
	int top();
};

void stack::push(int inputNum) {
	Stack.push_back(inputNum);
	sizeOfStack++;
}

int stack::pop() {
	if (sizeOfStack == 0)
		return -1;
	else {
		int temp = Stack.back();
		Stack.pop_back();
		sizeOfStack--;
		return temp;
	}
}

int stack::size() {
	return sizeOfStack;
}

int stack::empty() {
	if (sizeOfStack == 0)
		return 1;
	else
		return 0;
}

int stack::top() {
	if (sizeOfStack == 0)
		return -1;
	else
		return Stack.back();
}

int main() {
	int input;
	cin >> input;
	string temp;
	stack s1;
	for (int i = 0; i < input;i++) {
		cin >> temp;
		if (temp == "push") {
			int pushNum;
			cin >> pushNum;
			s1.push(pushNum);
		}
		else if (temp == "pop") {
			cout << s1.pop() << endl;
		}
		else if (temp == "size") {
			cout << s1.size() << endl;
		}
		else if (temp == "empty") {
			cout << s1.empty() << endl;
		}
		else if (temp == "top") {
			cout << s1.top() << endl;
		}
	}
	return 0;
}
