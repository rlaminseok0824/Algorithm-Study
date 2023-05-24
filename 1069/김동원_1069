#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>//이거 vscode에선 돌아가는데 백준 문제 낼땐 안돌아가서 여기서 3시간 씀 이거 하나 안써서
using namespace std;
double x,y,d,t,ps,aTime,bTime,bDis,cT,dTime,jump;//a걷기 b점프+걷기 c점프+걷기 d점프점프 ps대각선길이
vector<double> v;
int cnt;
int main(){
    cin >> x >> y >> d >> t;
    ps = sqrt(pow(x,2)+pow(y,2));
    aTime = ps;
    v.push_back(aTime);
    while(true){
        cnt++;
        jump = cnt * d;//점프 * 개수
        if(jump > ps){ //계속점프하다가 대각선 길이를 넘으면 나가기
            break;
        }
    }
    if(d>ps){
        cT = cnt * t; //대각선 넘는것중에 가장 가까움
        cT += jump - ps;//거기서 걸어오기
        v.push_back(cT);
        if(cnt==1){//한번 점프했는데 거리 넘어버리면 안됨 왜냐하면 삼각형은 변이 두개니까
            dTime=(cnt) * t;//넘지 않게 간다음
            dTime += t;//바로 점프해버리기
            v.push_back(dTime);    
        }else{//여러번 점프해서 거리를 넘었으니까 상관없음
            dTime = cnt*t;
            v.push_back(dTime);    
        }
        
        
    }else{
        bTime = (cnt-1) * t; //대각선에서 가장 가깝지만 넘지 않음
        bTime += ps - (jump - d);//대각선이 더 크니까 대각선길이 - 점프한거리-한번 점프할 수 있는 거리
        v.push_back(bTime);
        cT = cnt * t; //대각선 넘는것중에 가장 가까움
        cT += jump - ps;//거기서 걸어오기
        v.push_back(cT);
        if(cnt==1){//한번 점프했는데 거리 넘어버리면 안됨 왜냐하면 삼각형은 변이 두개니까
            dTime=(cnt) * t;//넘지 않게 간다음
            dTime += t;//바로 점프해버리기
            v.push_back(dTime);    
        }else{//여러번 점프해서 거리를 넘었으니까 상관없음
            dTime = cnt*t;
            v.push_back(dTime);    
        }
    }
    double minn = *min_element(v.begin(), v.end()); //min이라는 함수가 iostream에 있다고 해서 바꿈
    cout.precision(16);
    cout << minn;
    return 0;
}
