/*
문제
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

출력
첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.
*/
#include<iostream>
#include<vector>
using namespace std;
int n,m;
int main() {
	ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m,i,aIn=0,bIn=0;
    cin >>n>>m;     //각자의 배열의 크기를 입력받는다
    vector<int> a(n);   
    vector<int> b(m);
    vector<int> res(n+m);   //정답의 결과를 저장하는 vector
    //각자의 배열을 입력받는다.
    for(i=0;i<n;i++) cin >> a[i];   
    for(i=0;i<m;i++) cin >> b[i];
    for(i=0;i<n+m && aIn<n && bIn<m;i++){
        //a 와 b 벡터 각각의 인덱스를 이용해서 정렬을 한다.
        if(a[aIn]<b[bIn]){  //크기를 비교해서 작은쪽을 정답 배열에 저장하고 작은쪽의 인덱스를 1 증가시킨다.
            res[i] = a[aIn++];  
        }else {
            res[i] = b[bIn++];
        }
    }
    //그리고 이제 출력을 다하고 만약 한 배열만 다 꺼내고, 다른배열에 남아있다면
    //인덱스를 통해서 확인을 해서 반복문을 통해서 나머지 값들을 저장한다.
    if(aIn<n){  
        for(;i<n+m;i++)
            res[i] = a[aIn++];
    }else if(bIn<m){
        for(;i<m+n; i++)
            res[i] = b[bIn++];
    }
    for(i=0;i<n+m;i++)
        cout<< res[i]<<' ';
}