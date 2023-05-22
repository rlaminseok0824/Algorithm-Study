#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	double X, Y, D, T;
	cin >> X >> Y >> D >> T;

	double distance = sqrt(X * X + Y * Y);
	int nearint = distance / D;
	double short_time;

	if (D > T) {
		if (nearint == 0) {
			short_time = min(2 * T, distance);
			short_time = min(T + D - distance, short_time);
		}
		else {
			double neark = nearint * T + distance - D * nearint;
			double fark = (nearint + 1) * T;
			short_time = min(neark, fark);
		}

	}
	else {
		short_time = distance;
	}

	cout.precision(10);
	cout << short_time;
}