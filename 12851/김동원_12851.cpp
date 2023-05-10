#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int subin,dong,cnt=1,arr[100000001], ans;
queue<int> q;
vector<int> v;
bool flag = false;
int main(){
    cin >> subin >> dong;
    if(subin > dong){
        cout<<subin-dong<<'1';
    }else if(subin+1 == dong){
        cout<<'1'<<'1';
    }else if(subin-1 == dong){
        cout<<'1'<<'1';
    }else if(subin*2 == dong){
        cout<<'1'<<'1';
    }else{
        q.push(subin+1);//수빈이가 일단 한칸 감
        q.push(subin-1);
        q.push(subin*2);
        arr[subin+1]=1;
        arr[subin-1]=1;
        arr[subin*2]=1;
        while(true){
            if(flag == true){
                break;
            }
            cnt++;
            v.clear();
            while(true){
                if(q.empty()){//큐가 비었으면 break
                    break;
                }
                int chk;
                chk = q.front();
                q.pop();
                 if(chk-1>0 && chk-1<100002){//사실 여기서가 문제였는데 -가 v에 -가 나오면 안돼서 0보다 크면 들어가게
                    v.push_back(chk-1);
                }
                if(chk+1>0 && chk+1 < 100002){//나온 숫자 +1ㅌ
                    v.push_back(chk+1);
                }
                if(chk*2>0 && chk*2<100002){
                    v.push_back(chk*2);
                }
            }
            for(int i=0;i<v.size();i++){
                if(v[i] == dong){//상봉
                    for(int j=0;j<v.size();j++){
                        if(v[j]==dong){
                            ans++;
                        }
                    }
                    cout<< cnt << ' ' << ans;
                    flag = true;
                    break;
                }else{//못만났으면
                    if(arr[v[i]]==0){//한번도 안들어왔으니까
                        arr[v[i]] = cnt; //arr에 depth넣음
                        q.push(v[i]); //큐에 넣음
                    }else if(arr[v[i]] > cnt){ //똑같은 depth면 그대로 들어가
                        q.push(v[i]);
                    }
                }
            }
        }
    }
    return 0;
}
