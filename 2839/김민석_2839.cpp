#include<iostream>
using namespace std;

int N;  //입력 받는 변수
int dp[5001];  //최대 입력값까지의 array 미리 선언

int main() {
	cin >> N;  //입력 받고

	dp[0] = 1;  //거꾸로 0에서 N까지 갈 수 있는지 확인할거임
	for (int i = 0; i <= N; i++) {  //시간복잡도 : N
		if (dp[i] == 0) continue;  //만약에 빈 array면 그냥 지나감
		if (i + 5 > 5000) break;   //array index error 방지
		else if (dp[N])  //만약 N에 값이 들어갔다면 그것이 최소값이기 때문에 출력 후 종료
		{
			cout << dp[N] -1;
			return 0;
		}

		if (!dp[i + 3])    //값이 이미 써져있다면 그것이 최소값이기 때문에 지나치고 아니라면
		{
			dp[i + 3] = dp[i] + 1;  //현재 값에 + 1
		}
		if (!dp[i + 5]) 
		{
			dp[i + 5] = dp[i] + 1;
		}
	}

	if (dp[N])   //for문 다 돌고 다시 한 번 확인해서 -1인지 N인지 결정
		cout << dp[N] -1;
	else
		cout << -1;
	return 0;
}