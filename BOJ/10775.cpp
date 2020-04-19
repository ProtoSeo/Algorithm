/*
백준 10775번 : 공항
https://www.acmicpc.net/problem/10775
*/
#include<iostream>
#include<string.h>
using namespace std;
int ary[100001];
//union find 알고리즘
int find(int n) {
	if (ary[n] < 0) return n;
	return ary[n] = find(ary[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	ary[a] += ary[b];
	ary[b] = a;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i,g,p,ans=0;
    cin >> g >>p;
    memset(ary,-1,sizeof(ary));     //disjoint set을 사용하기 위해서 -1로 초기화
    for(i=0;i<p;i++){
        int t;
        cin >> t;   //입력받은 항공기의 번호
        int dock = find(t);     //도킹(union)이 가능한지를 find를 통해서 연결할수 있는지 확인
        if(dock!=0){    //0과 도킹이 되어있지 않은경우
            merge(dock-1,dock); //그 숫자보다 1작은 수와 union한다.
            ans ++; //그리고 무사히 도킹이 완료되었으므로 정답의 개수를 1 증가시킨다.
        }else{  //0과 도킹이 되어있는경우
            break;
        }
    }
    cout << ans;
}