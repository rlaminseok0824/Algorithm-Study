#include<iostream>
#include<queue>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<pair<int,int>> roads[1001]; // first : weight , second : dest
pair<int, int> dest;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq; //pq pair<int,int>의 역순
int visited[1001];
int list[1001];

void bfs(int start, int end) {
	//처음 최소값 갱신을 위하여 초기값 int_max로 초기화
	for (int i = 1; i <= n; i++) {
		visited[i] = 2147483647;
	}

	//시작점 pq에 push
	pq.push({ 0,start });

	while (!pq.empty()) {
		int weight = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		//다익스트라 중요 조건 && end값 만나면 continue
		if (visited[curr] < weight || curr == end)
			continue;

		for (auto a : roads[curr]) {
			int weight_next = a.first + weight;
			int next = a.second;
			//최소값 만나면 갱신해줌
			if (visited[next] > weight_next) {
				visited[next] = weight_next;
				pq.push({ weight_next,next });
				//next는 어느 곳에서 왔는지 갱신해줌 이를 통해 기록이 남음
				list[next] = curr;
			}
		}
	}
}


int main() {
	//초기 설정
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//입력값을 받음
	cin >> n;
	cin >> m;
	int t1, t2, t3;
	for (int i = 1; i <= m; i++) {
		cin >> t1 >> t2 >> t3;
		roads[t1].push_back(make_pair(t3, t2));
	}
	cin >> dest.first >> dest.second;
	
	//다익스트라 실행
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
