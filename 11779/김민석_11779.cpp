#include<iostream>
#include<queue>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<pair<int,int>> roads[1001]; // first : weight , second : dest
pair<int, int> dest;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq; //pq pair<int,int>�� ����
int visited[1001];
int list[1001];

void bfs(int start, int end) {
	//ó�� �ּҰ� ������ ���Ͽ� �ʱⰪ int_max�� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		visited[i] = 2147483647;
	}

	//������ pq�� push
	pq.push({ 0,start });

	while (!pq.empty()) {
		int weight = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		//���ͽ�Ʈ�� �߿� ���� && end�� ������ continue
		if (visited[curr] < weight || curr == end)
			continue;

		for (auto a : roads[curr]) {
			int weight_next = a.first + weight;
			int next = a.second;
			//�ּҰ� ������ ��������
			if (visited[next] > weight_next) {
				visited[next] = weight_next;
				pq.push({ weight_next,next });
				//next�� ��� ������ �Դ��� �������� �̸� ���� ����� ����
				list[next] = curr;
			}
		}
	}
}


int main() {
	//�ʱ� ����
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//�Է°��� ����
	cin >> n;
	cin >> m;
	int t1, t2, t3;
	for (int i = 1; i <= m; i++) {
		cin >> t1 >> t2 >> t3;
		roads[t1].push_back(make_pair(t3, t2));
	}
	cin >> dest.first >> dest.second;
	
	//���ͽ�Ʈ�� ����
	bfs(dest.first, dest.second);
	

	stack<int> st;
	st.push(dest.second);
	int curr = dest.second;
	int cnt = 0;
	while (true) {
		if (curr == dest.first) {
			break;
		}
		st.push(list[curr]);
		curr = list[curr];
		cnt++;
	}

	cout << visited[dest.second] << '\n';
	cout << cnt + 1 << '\n';
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}
