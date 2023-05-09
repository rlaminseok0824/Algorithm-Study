#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main() {
	int slocation;
	int blocation;
	int time = 0;
	int count = 0;
	int tcount = 0;
	queue<int> qq;
	int array[100002] = { 0, };


	cin >> slocation >> blocation;
	qq.push(blocation);
	array[blocation] = 1;

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

				temp = a - 1;
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

				temp = a + 1;
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
			count = tcount;
		}
		cout << time << endl << count;
	}
}