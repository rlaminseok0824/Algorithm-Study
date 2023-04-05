#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
    int num = 0, maxnum = 0;
    cin >> num;
    int numlist[1001];
    int dp[1001];
    memset(numlist, 0, sizeof(numlist));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < num; i++) {
        cin >> numlist[i];
        dp[i] = 1;
    }
    for (int i = 1; i < num; i++) {
        for (int j = 0; j < i; j++) {
            if (numlist[j] > numlist[i] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        if (dp[i] > maxnum)
            maxnum = dp[i];
    }
    cout << maxnum;
}