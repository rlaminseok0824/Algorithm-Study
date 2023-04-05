#include <iostream>

using namespace std;

int main()
{
    int weight;
    cin >> weight;

    int num_5 = weight / 5; //일단 5키로 봉투로 꽉 채우고
    int num_3 = (weight - num_5*5)/3; //남은 무게를 3키로로 채움
    while (num_5 >= 0) {
        if (num_5 * 5 + num_3 * 3 == weight) { //만약 설탕봉지들의 무게가 총 설탕 무게보다 작으면 5키로짜리 하나 빼고 3키로짜리 2개넣음
            cout << num_5 + num_3;
            break;
        }
        else if (num_5 * 5 + num_3 * 3 < weight) {
            num_5--;
            num_3 += 2;
        }
    }
    if (num_5 < 0) { //안되면 -1
        cout << -1;
    }


    return 0;
}
