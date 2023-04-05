#include <iostream>
using namespace std;

int main() {
	int kg;
	cin >> kg;

	int f_q, f_r, t_q, t_r;
	f_q = kg / 5; // 5kg 봉지 개수
	f_r = kg % 5; // 5kg 봉지로 못 담는 kg


	for (int i = f_q; i > -1; i--) {
		t_q = f_r / 3; // 남은 설탕을 3kg 봉지 개수
		t_r = f_r % 3; // 3kg 봉지로 못 담는 kg

		if (t_r == 0) { // 남지 않으면 종료
			i = 0;
		}
		else { // 남는 경우 다음 시행에 남은 설탕을 5kg 늘리고 5kg 봉지 수를 줄임
			f_r += 5;
			f_q -= 1;
		}
	}

	int sum;
	if (t_r != 0) { // 불가능하면 -1 출력
		sum = -1;
	}
	else { // 가능하면 총 봉지 수 출력
		sum = f_q + t_q;
	}

	cout << sum;
}