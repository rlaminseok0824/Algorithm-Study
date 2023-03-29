//https://www.acmicpc.net/problem/17413

/*
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string inputStr,result;
	getline(cin, inputStr);
	stack<char> reverse;
	int index = 0, findOtherIndex;
	for (int i = 0; i < inputStr.size();i++) {
		if (inputStr[i] == '<') {
			if (!reverse.empty()) {
				while (!reverse.empty()) {
					result.push_back(reverse.top());
					reverse.pop();
				}
			}

			index = i;
			findOtherIndex = inputStr.find('>', index);
			i += (findOtherIndex - index);
			for (int j = index;j <= findOtherIndex;j++)
				result.push_back(inputStr[j]);
		}
		else if (inputStr[i] == ' ') {
			while (!reverse.empty()) {
				result.push_back(reverse.top());
				reverse.pop();
			}
			result.push_back(' ');
		}
		else {
			reverse.push(inputStr[i]);
		}
	}

	while (!reverse.empty()) {
		result.push_back(reverse.top());
		reverse.pop();
	}
	cout << result << '\n';
	return 0;
}
*/