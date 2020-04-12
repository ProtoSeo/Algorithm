/*
백준 11003번 : 최솟값 찾기
https://www.acmicpc.net/problem/11003
*/
#include<iostream>
#include<queue>
using namespace std;
int n,l,i,val[5000001];
//var와 index를 같이 저장하기 위해서 pair를 사용하는 우선순위 큐를 사용하였다.
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);    
    cin >> n>>l;
    for(i=1;i<=n;i++) cin >> val[i];    //var에 값을 저장

    //처음에는 이 반복문에, 분할정복을 이용해서 l범위의 최소값을 구하는 함수를 이용해서 문제를 해결하려고 했다.(예상 O(log n)) - > TLE 
    for(i=1;i<=n;i++){
        int tmp = (i-l+1<=0)? 1:i-l+1;
        //만약 우선순위 큐가 비어있지 않고 윈도우의 최소범위보다 큰 범위를 가지는 값이 있다면 pop을 통해서 비워준다
        while(!pq.empty()&&pq.top().second<tmp) {
            pq.pop();   
        }
        pq.push({val[i],i});
        cout << pq.top().first<<' ';
    }
}