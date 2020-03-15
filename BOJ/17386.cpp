/*
문제
2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자.

L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.

입력
첫째 줄에 L1의 양 끝 점 x1, y1, x2, y2가, 둘째 줄에 L2의 양 끝 점 x3, y3, x4, y4가 주어진다. 세 점이 일직선 위에 있는 경우는 없다.

출력
L1과 L2가 교차하면 1, 아니면 0을 출력한다.
*/
#include<iostream>
#define ll long long    //long long 형을 줄여서 사용하기 위한 선언
#define x first
#define y second
using namespace std;
pair<ll,ll> loc[4];

int ccw(pair<ll,ll> a,pair<ll,ll> b , pair<ll,ll> c){
    long long tmp = a.x*b.y + b.x*c.y + c.x*a.y;
    tmp = tmp - a.y*b.x - b.y*c.x - c.y*a.x; 
    if(tmp >0){    //반시계
        return 1;
    }else if(tmp<0){    //시계
        return -1;
    }else{  //일직선
        return 0;
    }
}
bool intersection(pair<ll,ll> A,pair<ll,ll> B,pair<ll,ll> C,pair<ll,ll> D){ //해당 문제에서는 AB선분과 CD선분이 겹치지 않는다고 가정하였다.
    int AB = ccw(A,B,C) * ccw(A,B,D);   //AB선분에서 C,D점이 십자 모양으로 형성되어있는지 확인
    int CD = ccw(C,D,A) * ccw(C,D,B);   //CD선분에서 A,B점이 십자 모양으로 형성되어있는지 확인
    return AB <=0 && CD <= 0 ;  //둘다 십자모양이면 겹쳐있다고 볼수있다.
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    for(int i=0;i<4;i++){
        ll xi,yi;
        cin >> xi>>yi;
        loc[i] = {xi,yi};
    }
    cout<<intersection(loc[0],loc[1],loc[2],loc[3]);
}