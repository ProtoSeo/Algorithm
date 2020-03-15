/*
문제
2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자. 
한 선분의 끝 점이 다른 선분이나 끝 점 위에 있으면 교차하는 경우이다.

L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.

입력
첫째 줄에 L1의 양 끝 점 x1, y1, x2, y2가, 둘째 줄에 L2의 양 끝 점 x3, y3, x4, y4가 주어진다.

출력
L1과 L2가 교차하면 1, 아니면 0을 출력한다.
*/
#include<iostream>
#define ll long long
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
bool intersection(pair<ll,ll> A,pair<ll,ll> B,pair<ll,ll> C,pair<ll,ll> D){
    int AB = ccw(A,B,C) * ccw(A,B,D);
    int CD = ccw(C,D,A) * ccw(C,D,B);
    if(AB==0&&CD==0){   //여기가 17386과 차이점. AB값과 CD값이 둘다 0인 경우는 두 선분이 일직선으로 겹쳐있는 경우이다.
        //서로의 pair에서 작은값이 왼쪽으로가고, 큰값이 오른쪽으로 가게 하기위해서(뒤집힘을 막기 위해서)swap한다.
        if(A>B)swap(A,B);   
        if(C>D)swap(C,D);
        return C <= B&&A <= D;  // A-B C-D 가 아닌 경우를 찾는것 즉 A-C-B-D이런 경우에만 겹치는 것이므로 이때를 1로 출력한다.
    }
    return AB <=0 && CD <= 0 ;
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