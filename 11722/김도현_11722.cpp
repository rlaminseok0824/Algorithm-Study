#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int listsize;
	int list[1001];
	int location[1001];

	cin >> listsize;

	for (int i = 0; i < listsize; i++) {
		cin >> list[i];
		int num = list[i];
		location[num] = i;
	}


}