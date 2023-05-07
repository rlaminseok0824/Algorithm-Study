#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;
int checkp[100001] = { 0 };

//설명은 생략한다
int main()
{
    int me, bro, num = -1, snum = 0;
    
    queue<pair<int, int>> posq;
    cin >> me >> bro;

    posq.push(pair<int, int>(me, 0));
    while (!posq.empty()) {
        pair<int, int> temp = posq.front();
        posq.pop();
        if (temp.first == bro) {
            if(num == -1)
                num = temp.second;
            if(num != temp.second)
                break;
            snum++;
            
        }
        else {
            if(temp.first + 1 <= 100000)
                if (checkp[temp.first + 1] == 0 || checkp[temp.first + 1] == temp.second) {
                    posq.push(pair<int, int>(temp.first + 1, temp.second + 1));
                    checkp[temp.first + 1] = temp.second;
                }
            if (temp.first - 1 >= 0)
                if (checkp[temp.first - 1] == 0 || checkp[temp.first - 1] == temp.second) {
                    posq.push(pair<int, int>(temp.first - 1, temp.second + 1));
                    checkp[temp.first - 1] = temp.second;
                }
            if (temp.first*2 <= 100000 && temp.first *2 >= 0)
                if (checkp[temp.first*2] == 0 || checkp[temp.first*2] == temp.second) {
                    posq.push(pair<int, int>(temp.first * 2, temp.second + 1));
                    checkp[temp.first*2] = temp.second;
                }
            
        }
    }
    cout << num << endl;
    cout << snum;

    return 0;
}
