#include <iostream>
#include <math.h>

using namespace std;
//설명은 생략한다

int hmtx[101][2] = {0,};
int cmtx[14][2] = { 0, };
int bt[14][101] = { 0, };
int wid, maxnum, temp;
int hnum = 0, cnum = 0, minlen = -1;

int backt(int npos, int remain) {
	if (remain == 0) {
		int tempsum = 0;
		for (int i = 0; i < hnum; i++) {
			tempsum += bt[1][i];
		}
		if (minlen == -1 || minlen > tempsum)
			minlen = tempsum;
		return 0;
	}
	else if (remain - cnum + npos > 0 || npos >= cnum)
		return 0;
	else {
		backt(npos + 1, remain);
		if (remain == maxnum) {
			for (int i = 0; i < hnum; i++) {
				bt[remain][i] = abs(hmtx[i][0] - cmtx[npos][0]) + abs(hmtx[i][1] - cmtx[npos][1]);
			}
		}
		else {
			for (int i = 0; i < hnum; i++) {
				int temp_len = abs(hmtx[i][0] - cmtx[npos][0]) + abs(hmtx[i][1] - cmtx[npos][1]);
				if (bt[remain + 1][i] > temp_len)
					bt[remain][i] = temp_len;
				else
					bt[remain][i] = bt[remain + 1][i];
			}
		}
		backt(npos + 1, remain-1);
	}
	return 0;
}

int main() {
	
	cin >> wid >> maxnum;
	for (int i = 0; i < wid; i++) {
		for (int j = 0; j < wid; j++) {
			cin >> temp;
			if (temp == 1) {
				hmtx[hnum][0] = i;
				hmtx[hnum][1] = j;
				hnum++;
			}
			else if (temp == 2) {
				cmtx[cnum][0] = i;
				cmtx[cnum][1] = j;
				cnum++;
			}
		}
	}
	backt(0, maxnum);

	cout << minlen;

	return 0;
}
