#include<iostream>
using namespace std;

int N;  //�Է� �޴� ����
int dp[5001];  //�ִ� �Է°������� array �̸� ����

int main() {
	cin >> N;  //�Է� �ް�

	dp[0] = 1;  //�Ųٷ� 0���� N���� �� �� �ִ��� Ȯ���Ұ���
	for (int i = 0; i <= N; i++) {  //�ð����⵵ : N
		if (dp[i] == 0) continue;  //���࿡ �� array�� �׳� ������
		if (i + 5 > 5000) break;   //array index error ����
		else if (dp[N])  //���� N�� ���� ���ٸ� �װ��� �ּҰ��̱� ������ ��� �� ����
		{
			cout << dp[N] -1;
			return 0;
		}

		if (!dp[i + 3])    //���� �̹� �����ִٸ� �װ��� �ּҰ��̱� ������ ����ġ�� �ƴ϶��
		{
			dp[i + 3] = dp[i] + 1;  //���� ���� + 1
		}
		if (!dp[i + 5]) 
		{
			dp[i + 5] = dp[i] + 1;
		}
	}

	if (dp[N])   //for�� �� ���� �ٽ� �� �� Ȯ���ؼ� -1���� N���� ����
		cout << dp[N] -1;
	else
		cout << -1;
	return 0;
}