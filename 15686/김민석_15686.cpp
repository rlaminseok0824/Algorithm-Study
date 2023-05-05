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
	//2. ġŲ�� M�� ������ �����ٸ�
	if (depth == M) {
		int total = 0;
		//house�� ���� ġŲ���Ÿ��� ����ϰ� �� �ּҰ����� ���ؼ� total�� �־��ش�.
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
		//�� total ���̶� res ���� ���Ͽ� �������ش�.
		res = min(res, total);
	}

	//�ʱ⿡ �ð��ʰ� ���� Ǯ��
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

	//1. chicken�� M�������� �����Ѵ�.
	for (int i = idx; i < chicken.size(); i++) {
		currChicken[depth] = i;
		dfs(depth + 1, i + 1);
	}
}

int main() {
	//����� �ð� ���̱� ���� �ʱ⼳��
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	//�Է��� �޴´�.
	cin >> N >> M;
	//�Է°��� array�� ������ ������ �ʿ��� ���� ��ǥ�����̹Ƿ� array�� �������� �ʰ� vector�� push_back �ϴ� �������� ����
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
	
	//�⺻�� �ð� �ʰ� ���� ���� Ǯ��
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

	//dfs ����
	dfs(0, 0);
	cout << res;
	return 0;
}