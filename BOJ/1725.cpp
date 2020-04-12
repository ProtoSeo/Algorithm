/*
백준 1725번 : 히스토그램
https://www.acmicpc.net/problem/1725
*/
#include<iostream>
#define MAX(a,b) ((a>b)?(a):(b))
#define MIN(a,b) ((a<b)?(a):(b))
using namespace std;
int ary[100001];
//처음 풀었을때 사각형이 입력 전체를 덮는 것을 생각하지 못해서 틀렸다.
int divide(int left,int right){
    // 기저조건 : 하나밖에 없는경우
    if(left==right) return ary[left];
    int mid = (left+right)/2;   //반으로 나눠서 문제를 해결하기 위한 변수
    //ret 분할한 문제를 해결한다.
    int ret = MAX(divide(left,mid),divide(mid+1,right));
    // 부분문제 3: 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
    int lo = mid,hi = mid+1;
    //[mid,mid+1]만 포함하는 너비 2인 사각형을 고려한다.
    int height = MIN(ary[lo],ary[hi]);
    ret = MAX(ret,height*2);
    //사각형이 입력 전체를 덮을 때까지 확장해 나간다.
    while(left < lo || hi<right){
        if(hi<right&&(lo==left||ary[lo-1]<ary[hi+1])){
            ++hi;
            height = min(height,ary[hi]);
        }else{
            --lo;
            height = min(height,ary[lo]);
        }
        //확장한 후 사각형의 넓이
        ret = MAX(ret,height * (hi - lo +1));
    }
    return ret;
}   
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,i;
    cin >>n;
    for(i=1;i<=n;i++) cin >> ary[i];
    cout << divide(1,n);
}