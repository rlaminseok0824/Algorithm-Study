#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class HS {
	int slocation;
	int blocation;
	int time;
	int count;
	queue<int> qq;
	int array[100001];
public:
	void get_location();
	void branch();
	vector<int> make_number(int a);
	void start();
};

void HS::get_location() {
	int n, m;
	cin >> n >> m;
	slocation = n;
	blocation = m;
	qq.push(m);
	array[m - 1] = 1;
}

vector<int> HS::make_number(int a) {
	int temp;
	vector<int> numbers;

	if (a % 2 == 0) {
		temp = a / 2;
		if (slocation / 2 - 1 < temp && blocation + 2 > temp) {
			if (array[temp - 1] >= time || array[temp - 1] == 0) {
				numbers.push_back(temp);
				array[temp - 1] = time;
			}
		}
	}

	temp = a - 1;
	if (slocation / 2 - 1 < temp && blocation + 2 > temp) {
		if (array[temp - 1] >= time || array[temp - 1] == 0) {
			numbers.push_back(temp);
			array[temp - 1] = time;
		}
	}

	temp = a + 1;
	if (slocation / 2 - 1 < temp && blocation + 2 > temp) {
		if (array[temp - 1] >= time || array[temp - 1] == 0) {
			numbers.push_back(temp);
			array[temp - 1] = time;
		}
	}

	return numbers;
}

void HS::branch() {
	while (count == 0) {
		time += 1;
		int tcount = 0;
		int size = qq.size();
		for (int i = 0; i < size; i++) {
			int a = qq.front();
			qq.pop();
			vector<int> ttemp = make_number(a);
			for (int j = 0; j < ttemp.size(); j++) {
				if (ttemp[j] == slocation) {
					tcount += 1;
				}
				else {
					qq.push(ttemp[j]);
				}
			}
		}
		count = tcount;
	}
}

void HS::start() {
	get_location();
	branch();

	cout << time << endl << count;
}

int main() {
	HS hide_and_seek;
	hide_and_seek.start();
}