#include<iostream>
#include <queue> //queue 사용하기 위하여
#include<algorithm>  //min 함수 사용 위하여
using namespace std;

#define MAXSIZE (int)1e5 + 1 //MAXSIZE 정의함 : 100001

int roads[MAXSIZE]; //array를 AMXSIZE 크기만큼 선언함
int N, K; //입력 받을 변수
queue<int> q; //BFS를 위한 queue 선언
int result = 99999999; //min값 갱신을 위하여 result를 최댓값으로 초기화
int result_cnt = 0; //cnt 계산

int main() {
	//입출력 시간 줄이기 위한 초기설정
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	//입력값 받음
	cin >> N >> K;
	//초기 시작 지점을 1로 초기화
	roads[N] = 1;

	//bfs 시작
	q.push(N);
	while (!q.empty()) {
		//queue에서 제일 처음값을 꺼냄
		int curr = q.front();
		int currVal = roads[curr];
		q.pop();

		//만약, 현재값이 목표값인 K라면,
		if (curr == K) {
			//만약 result==currVal이면, 가장 빠른 시간의 방법의 수가 더 있다는 뜻이므로
			if (result == currVal) {
				result_cnt++; //cnt를 ++하고
			}
			else { //아니라면
				result = min(result, currVal); //result 를 새로 갱신하고
				result_cnt = 1; //cnt를 1로 초기화한다.
			}
			continue; //continue하여 아래 구문 없이 통과
		}
		//앞으로 3가지 케이스에 관하여
		// 1. 수빈이가 -1 지점으로 갈 때
		// 먼저, roads[curr - 1] == 0이면 초기값이 안 들어가있으니 예외 처리
		// 둘째로, roads[curr - 1]이 더 크다면 굳이 들어갈 필요가 없으므로 통과
		if (roads[curr - 1] == 0 || roads[curr - 1] > currVal) {
			//마지막으로 curr -1은 0보다는 커야하므로 예외 처리
			if (curr - 1 >= 0) {
				roads[curr - 1] = currVal + 1; //시간초를 현재 + 1로 저장
				q.push(curr - 1); //queue에 넣은 값 저장
			}
		}
		//2. 수빈이가 + 1 지점으로 갈때
		if (roads[curr + 1] == 0 || roads[curr + 1] > currVal) {
			if (curr + 1 <= K) {
				roads[curr + 1] = currVal + 1;
				q.push(curr + 1);
			}
		}
		//3. 수빈이가 *2 지점으로 순간이동 할 때
		if (curr * 2 < MAXSIZE && (roads[curr * 2] == 0 || roads[curr * 2] > currVal)) {
			roads[curr * 2] = currVal + 1;
			q.push(curr * 2);
		}
	}

	//마지막으로 출력해준다.. endl 대신에 시간을 더 줄이기 위하여 '\n' 사용
	std::cout << result -1  << '\n' << result_cnt;

	return 0;
}