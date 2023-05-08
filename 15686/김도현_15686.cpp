#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Chicken {
public:
	int N;
	int M;
	int distance;
	int one_distance;
	int c_d = 1000000;
	vector<vector<int>> map;
	vector<vector<int>> cmap = { {},{} };
	void start();
	void get_NM();
	void get_map();
	void get_cmap();
	int get_distance(vector<int> c);
	void pick(int n, vector<int>& picked, int m);
};

void Chicken::start() {
	get_NM();
	get_map();
	get_cmap();
	int n = cmap[0].size();
	int m = M;
	vector<int> combination;
	pick(n, combination, m);

	cout << c_d;
}

void Chicken::get_NM() {
	int n, m;
	cin >> n >> m;
	N = n;
	M = m;
}

void Chicken::get_map() {
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			temp.push_back(num);
		}
		map.push_back(temp);
	}
}

void Chicken::get_cmap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 2) {
				cmap[0].push_back(i);
				cmap[1].push_back(j);
			}
		}
	}
}

int Chicken::get_distance(vector<int> c) {
	distance = 0;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			if (map[i][j] == 1) {
				for (int k = 0; k < c.size(); k++) {
					int num = abs(i - cmap[0][c[k]]) + abs(j - cmap[1][c[k]]);
					if (k == 0) {
						one_distance = num;
					}
					else {
						if (one_distance > num) {
							one_distance = num;
						}
					}
				}
				distance += one_distance;
			}

		}
	}

	return distance;
}

void Chicken::pick(int n, vector<int>& picked, int m) {
	if (m == 0) {
		if (c_d > get_distance(picked)) {
			c_d = get_distance(picked);
		}
		return;
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int j = smallest; j < n; ++j) {
		picked.push_back(j);
		pick(n, picked, m - 1);
		picked.pop_back();
	}
}

int main() {
	Chicken c;
	c.start();
}