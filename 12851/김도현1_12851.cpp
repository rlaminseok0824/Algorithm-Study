#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class HS {
public:
	int slocation;
	int blocation;
	int time = 0;
	int count = 0;
	int tcount = 0;
	queue<int> qq;
	int array[100002] = { 0, };
	void get_location();
	void put_number(int a);
	void hide_seek();
};

void HS::get_location() {
	cin >> slocation >> blocation;
	qq.push(blocation);
	array[blocation] = 1;
}

void HS::put_number(int temp) {
	if (slocation / 2 <= temp && blocation + 2 > temp && 0 <= temp && temp <= 100000) {
		if (array[temp] >= time || array[temp] == 0) {
			array[temp] = time;
			if (temp == slocation) {
				tcount += 1;
			}
			else {
				qq.push(temp);
			}
		}
	}
}

void HS::hide_seek() {
	get_location();
	if (slocation >= blocation) {
		int num = slocation - blocation;
		cout << num << endl << 1;
	}
	else {
		while (count == 0) {
			time += 1;
			int size = qq.size();
			for (int i = 0; i < size; i++) {
				int a = qq.front();
				qq.pop();
				int temp;
				if (a % 2 == 0) {
					temp = a / 2;
					put_number(temp);
				}

				temp = a - 1;
				put_number(temp);

				temp = a + 1;
				put_number(temp);
			}
			count = tcount;
		}
		cout << time << endl << count;
	}
}

int main() {
	HS hs;
	hs.hide_seek();
}