#include <iostream>
using namespace std;

int main() {
	int kg;
	cin >> kg;

	int f_q, f_r, t_q, t_r;
	f_q = kg / 5; // 5kg ���� ����
	f_r = kg % 5; // 5kg ������ �� ��� kg


	for (int i = f_q; i > -1; i--) {
		t_q = f_r / 3; // ���� ������ 3kg ���� ����
		t_r = f_r % 3; // 3kg ������ �� ��� kg

		if (t_r == 0) { // ���� ������ ����
			i = 0;
		}
		else { // ���� ��� ���� ���࿡ ���� ������ 5kg �ø��� 5kg ���� ���� ����
			f_r += 5;
			f_q -= 1;
		}
	}

	int sum;
	if (t_r != 0) { // �Ұ����ϸ� -1 ���
		sum = -1;
	}
	else { // �����ϸ� �� ���� �� ���
		sum = f_q + t_q;
	}

	cout << sum;
}