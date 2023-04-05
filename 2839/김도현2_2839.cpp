#include <iostream>
using namespace std;

int main() {
	int kg;
	cin >> kg;

	int f_q, f_r, t_q, t_r;
	f_q = kg / 5; // 5kg 봉지 개수
	f_r = kg % 5; // 5kg 봉지로 못 담는 kg
	
	if (kg == 7 || kg == 4) {
		cout << -1;
		return 0;
	}
	else if (f_r == 1) {
		f_q -= 1;
		t_q = 2;
	}
	else if (f_r == 2) {
		f_q -= 2;
		t_q = 4;
	}
	else if (f_r == 3) {
		t_q = 1;
	}
	else if (f_r == 4) {
		f_q -= 1;
		t_q = 3;
	}
	else {
		t_q = 0;
	}

	int sum = f_q + t_q;
	cout << sum;
}