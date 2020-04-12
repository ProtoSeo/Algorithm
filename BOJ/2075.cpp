/*
백준 2075번 : N번째 큰 수
https://www.acmicpc.net/problem/2075
*/
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);  
    int i,tmp,n;
    cin >> n;
    //메모리 조건이 작으므로 모든 수를 입력받아서 배열로 저장하기는 힘들다고 생각했다.
    //우리가 찾아야하는 n번째 숫자만큼 우선순위 큐를 만들어서 해결하려 하였다.
    for(i=1;i<=n;i++){      //초반의 n개를 우선순위 큐에 담는다.
        cin >>tmp;
        pq.push(tmp);
    }
    //그 뒤의 수들을 받으면서는 우선순위의 top의 크기보다 작으면 입력받지 않고, top의 크기보다 크다면 입력을 받는다.
    for(;i<=n*n;i++){   
        cin >>tmp;
        if(pq.top()<tmp){
            pq.pop();
            pq.push(tmp);
        }
    }
    cout << pq.top();
}

