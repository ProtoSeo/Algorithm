/*
백준 11286번 : 절댓값 힙
https://www.acmicpc.net/problem/11286
*/
#include<iostream>
#define ABS(a) ((a<0)? -(a):(a))
#include<queue>
using namespace std;
//특수한 경우 우선순위 큐에서 사용되는 비교함수 구현
struct cmp{
    bool operator()(int a,int b){
        if(ABS(a)==ABS(b)){    //먼저 같은 절댓값을 가진 경우
            return a>b; //작은 값이 먼저 출력되도록 한다.
        }else { //절대값이 다른경우 절대값이 작은 경우가 먼저 출력되도록 한다.
            return ABS(a)>ABS(b);
        }        
    }
};
priority_queue<int,vector<int>,cmp> pq;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,i,tmp;
    cin >>n;
    while(n--){
        cin >>tmp;
        if(tmp==0){
            if(pq.empty()){
                cout << 0<<'\n';
                continue;
            }
            cout << pq.top()<<'\n';
            pq.pop();
        }else{
            pq.push(tmp);
        }
    }
}