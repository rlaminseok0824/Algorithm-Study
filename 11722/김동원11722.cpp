#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr; //동적 배열을 위해 받을때 귀찮음
int dp[1001];

int main() {
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) { //받기
        cin >> arr[i];
    }
    dp[0]= 1; 
    for (int i = 1; i < n; i++) {//기준
        dp[i] = 1;
        for (int j = 0; j < i; j++) {//피봇
            if (arr[j] > arr[i]) {//기준이 피봇보다 크면
                dp[i] = max(dp[i], dp[j] + 1);//dp배열에 +1
            }
        }
    }
    cout << *max_element(dp, dp + n);
    return 0;
}
