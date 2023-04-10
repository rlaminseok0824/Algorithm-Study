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
		// �������� �Է°��� �޴� ����
		dp[i] = 1; //dp�� ���� �ʱ�ȭ�Ѵ�.(default�� ������ 1�̴�.)
		for (int j = 0; j < i; j++) { //���� i�� ���� �������� �� ���������� ��ȸ�Ѵ�.
			if (list[j] > list[i]) { //���� j�� ��ȸ�ϸ鼭 i�� ������ �� ū ���� ���� ���, �ű��� dp ������ �������ش�.
				dp[i] = max(dp[i], dp[j] + 1);  //dp�� ��ȸ�ϸ鼭 max�� ������ �� ū ������ �������ش�.
			}
		}
	}

	int result = 0;   //dp�� �� �� �ִ밪�� ���Ѵ�.
	for (int i = 0; i < N; i++) {
		result = max(result, dp[i]);
	}
	cout << result;
	return 0;
}