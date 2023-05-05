#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
int res = 99999999;
int currChicken[100];

void dfs(int depth,int idx) {
	//2. 치킨집 M개 선정이 끝났다면
	if (depth == M) {
		int total = 0;
		//house들 마다 치킨집거리를 계산하고 그 최소값만을 더해서 total로 넣어준다.
		for (int i = 0; i < house.size(); i++) {
			int homeX = house[i].first;
			int homeY = house[i].second;
			int temp = 99999999;

			for (int j = 0; j < M; j++) {
				int chiDist = (abs(homeX - chicken[currChicken[j]].first) + abs(homeY - chicken[currChicken[j]].second));
				temp = min(temp, chiDist);
			}

			total += temp;
		}
		//총 total 값이랑 res 값을 비교하여 갱신해준다.
		res = min(res, total);
	}

	//초기에 시간초과 떴던 풀이
	/*
	if (depth == house.size()) {
		res = min(res, temp);
		return;
	}

	for (int i = 0; i < chicken.size(); i++) {
		for (int j = cdx; j < house.size(); j++) {
			if (curr <= M) {
				if (visited[i] == 0 && curr == M) {
					continue;
				}
				if (visited[i] == 0) {
					curr++;
				}
				visited[i]++;
				temp += distances[i][j];	
				dfs(depth + 1, temp,j + 1);
				temp -= distances[i][j];
				visited[i]--;
				if (visited[i] == 0) {
					curr--;
				}
			}
		}
	}*/

	//1. chicken집 M개까지를 선택한다.
	for (int i = idx; i < chicken.size(); i++) {
		currChicken[depth] = i;
		dfs(depth + 1, i + 1);
	}
}

int main() {
	//입출력 시간 줄이기 위한 초기설정
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	//입력을 받는다.
	cin >> N >> M;
	//입력값은 array로 받지만 실제로 필요한 것은 좌표값만이므로 array로 저장하지 않고 vector에 push_back 하는 형식으로 저장
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			if (temp == 2) {
				chicken.push_back(make_pair(i, j));
			}
			else if (temp == 1) {
				house.push_back(make_pair(i, j));
			}
		}
	}
	
	//기본에 시간 초과 떴던 문제 풀이
	/*for (auto home : house) {
		for (int i = 0; i < chicken.size();i++) {
			distances[i].push_back(abs(home.first - chicken[i].first) + abs(home.second - chicken[i].second));
		}
	}*/

	/*for (int i = 0; i < 5; i++) {
		for (auto a : distances[i]) {
			cout << a << " ";
		}
		cout << endl;
	}
	cout << "-----------" << endl;*/

	//dfs 시작
	dfs(0, 0);
	cout << res;
	return 0;
}