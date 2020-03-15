/*
문제
2차원 평면상에 N(3 ≤ N ≤ 10,000)개의 점으로 이루어진 다각형이 있다. 이 다각형의 면적을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 다음 N개의 줄에는 다각형을 이루는 순서대로 N개의 점의 x, y좌표가 주어진다. 좌표값은 절댓값이 100,000을 넘지 않는 정수이다.

출력
첫째 줄에 면적을 출력한다. 면적을 출력할 때에는 소수점 아래 둘째 자리에서 반올림하여 첫째 자리까지 출력한다.
*/
#include<cstdio>
#include<vector>
#include<cmath>
#define x first     //pair의 first와 second를 줄여서 쓰기 위해서 선언함
#define y second
using namespace std;
vector<pair<long long,long long>> vec;  //다각형의 점들을 저장하는 vector

long long abs(long long x) { return x < 0 ? -x : x; }   //절대값을 반환해주는 함수

//CCW알고리즘을 이용해서 삼각형의 넓이를 구한다.
long long ccw(pair<long long,long long> a,pair<long long,long long> b,pair<long long,long long> c) {
    long long tmp = a.x*b.y + b.x*c.y + c.x*a.y;
    tmp = tmp - a.y*b.x - b.y*c.x - c.y*a.x; 
    return tmp;    
}

int main() {
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        long long x1,y1;
        scanf("%lld %lld",&x1,&y1);
        vec.push_back({x1,y1});
    }
    long long res=0;
    for(i=0;i<n-1;i++){ //다각형을 삼각형으로 나누어서 그 삼각형들의 합을 더하도록 하는 반복문
                        //다각형을 이루는 순서대로 입력이 들어왔으므로 가능하다.
        res += ccw(vec[0],vec[i],vec[i+1]);
    }
    printf("%.1lf",abs(res/2.0));           
}