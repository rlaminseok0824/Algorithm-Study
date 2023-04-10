#include<iostream>
#include<algorithm>
using namespace std;

int N;
int list[1001];
int dp[1001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i]; 
		// 위에까지 입력값을 받는 내용
		dp[i] = 1; //dp의 값을 초기화한다.(default은 무조건 1이다.)
		for (int j = 0; j < i; j++) { //현재 i의 값을 기준으로 그 이전까지를 순회한다.
			if (list[j] > list[i]) { //만약 j를 순회하면서 i의 값보다 더 큰 값을 만날 경우, 거기의 dp 값으로 갱신해준다.
				dp[i] = max(dp[i], dp[j] + 1);  //dp를 순회하면서 max의 값으로 더 큰 값으로 갱신해준다.
			}
		}
	}

	int result = 0;   //dp의 값 중 최대값을 취한다.
	for (int i = 0; i < N; i++) {
		result = max(result, dp[i]);
	}
	cout << result;
	return 0;
}