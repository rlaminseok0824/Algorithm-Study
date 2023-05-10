#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,minDis,ans,map[50][50],dis[100][100];
queue<int> cal;
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
vector<vector<int> > ncr;

int mai(){
    cin >> n >> m;
    //입력 받으면서house chkicken에 위치 저장
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j]==1){
                house.push_back(make_pair(i,j));
            }
            if(map[i][j]==2){
                chicken.push_back(make_pair(i, j));
            }
        }
    }



    //어디서 어디까지 거리를 구하고 dis에 저장
    for(int i=0;i<house.size();i++){
        for(int j=0;j<chicken.size();j++){
            dis[i][j] = abs(house[i].first-chicken[j].first) + abs(house[i].second-chicken[j].second);
        }
    }
    // for(int i=0;i<50;i++){
    //     for(int j=0;j<50;j++){
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }












    //dis배열에 dis[집][치킨] dis[집][치킨+1] 이랑 비교 치킨집을 
    for(int i=0;i<chicken.size()-1;i++){ //그래서 -1함
        minDis=0;
        for(int j=0;j<house.size();j++){
            
            if(dis[j][i]<=dis[j][i+1]){
                minDis += dis[j][i];
            }else minDis+=dis[j][i+1];
            cout << minDis<<' ';
        }
        cout << endl;
        if(ans==0){//갱신되는 minDis에서 가장 작은거 구함
            ans=minDis;
        }
        if(ans>minDis){
            ans=minDis;
        }
    }
    cout << ans;

    return 0;
}
