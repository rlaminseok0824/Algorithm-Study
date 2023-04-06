#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int dp[1001];

int main() {
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        arr[i] = k;
    }
    dp[0]= 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1; 
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp, dp + n);
    return 0;
}