#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int x, y, dist, time, tempnum;
	double t[4] = {0,};
	double min;

	cin >> x >> y >> dist >> time;

	t[0] = sqrt(x * x + y * y);
	
	tempnum = static_cast<int>(t[0]) / dist;

	t[1] = t[0] - tempnum * dist + tempnum * time;
	t[2] = (tempnum + 1) * dist - t[0] + (tempnum + 1) * time;

	if (tempnum < 1) tempnum = 1;
	t[3] = (tempnum + 1) * time;

	min = t[0];
	for (int i = 1; i < 4; i++) {
		if (min > t[i]) min = t[i];
	}
	cout << fixed;
	cout.precision(13);
	cout << min;

	return 0;
}
