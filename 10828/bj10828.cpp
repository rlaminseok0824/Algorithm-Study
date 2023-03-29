#include <iostream>
using namespace std;

class Stack {
	int* p;
	int listsize;
public:
	Stack(int n) {
		listsize = n;
		p = new int[n];
	}
	void push(int a);
	void pop();
	void size();
	void empty();
	void top();
	void get();
	~Stack();
};

void Stack::push(int a) {
	if (listsize != 0) {
		for (int i = 0; i < listsize; i++) {
			p[i + 1] = p[i];
		}
	}
		
	p[0] = a;
	listsize += 1;
}

void Stack::pop() {
	if (listsize == 0) {
		cout << -1 << endl;
	}
	else {
		cout << p[0] << endl;
		for (int i = 0; i < listsize; i++) {
			p[i] = p[i + 1];
		}
		listsize -= 1;
	}
}

void Stack::size() {
	cout << listsize << endl;
}

void Stack::empty() {
	if (listsize == 0) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}

void Stack::top() {
	if (listsize == 0) {
		cout << -1 << endl;
	}
	else {
		cout << p[0] << endl;
	}
}

void Stack::get() {

}

Stack::~Stack() {
	delete[] p;
}

int main() {
	Stack s(0);

	s.push(1);
	s.push(2);
	s.top();
	s.size();
	s.empty();
	s.pop();
	s.pop();
	s.pop();
	s.size();
	s.empty();
	s.pop();
	s.push(3);
	s.empty();
	s.top();
}