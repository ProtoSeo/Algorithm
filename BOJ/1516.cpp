/*
문제
숌 회사에서 이번에 새로운 전략 시뮬레이션 게임 세준 크래프트를 개발하기로 하였다. 
핵심적인 부분은 개발이 끝난 상태고, 종족별 균형과 전체 게임 시간 등을 조절하는 부분만 남아 있었다.

게임 플레이에 들어가는 시간은 상황에 따라 다를 수 있기 때문에, 모든 건물을 짓는데 걸리는 최소의 시간을 이용하여 근사하기로 하였다. 
물론, 어떤 건물을 짓기 위해서 다른 건물을 먼저 지어야 할 수도 있기 때문에 문제가 단순하지만은 않을 수도 있다. 
예를 들면 스타크래프트에서 벙커를 짓기 위해서는 배럭을 먼저 지어야 하기 때문에, 배럭을 먼저 지은 뒤 벙커를 지어야 한다. 
여러 개의 건물을 동시에 지을 수 있다.

편의상 자원은 무한히 많이 가지고 있고, 건물을 짓는 명령을 내리기까지는 시간이 걸리지 않는다고 가정하자.

입력
첫째 줄에 건물의 종류 수 N(1 ≤ N ≤ 500)이 주어진다. 
다음 N개의 줄에는 각 건물을 짓는데 걸리는 시간과 그 건물을 짓기 위해 먼저 지어져야 하는 건물들의 번호가 주어진다. 
건물의 번호는 1부터 N까지로 하고, 각 줄은 -1로 끝난다고 하자. 각 건물을 짓는데 걸리는 시간은 100,000보다 작거나 같은 자연수이다.

출력
N개의 각 건물이 완성되기까지 걸리는 최소 시간을 출력한다.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,i;
    cin >>n;
    vector<int> graph[501];
    vector<int> pre(n+1,0);
    vector<int> time(n+1);
    vector<int> res(n+1);
    queue<int> q;
    for(i=1;i<n+1;i++){     //입력을 받는 반복문
        int tmp;
        cin >> time[i]>>tmp;
        while(tmp!=-1){
            graph[tmp].push_back(i);
            pre[i]++;
            cin >>tmp;
        }
    }
    for(i=1;i<n+1;i++){     //선행자가 없는 정점을 queue에 담는다.
        if(pre[i]==0){
            q.push(i);
            res[i]=time[i]; //선행자가 없는 정점에서는 입력받은 시간이 최소 시간이다.
        }
    }
    while(!q.empty()){  //위상정렬
        int v = q.front();
        q.pop();
        for(int nextV : graph[v]){  
            pre[nextV]--;
            if(pre[nextV]==0){
                q.push(nextV);
            }
            res[nextV] = max(res[nextV],time[nextV]+res[v]);    //v를 거치는 nextV중 최대시간을 구하도록 한다.
        }
    }
    for(i=1;i<n+1;i++){
        cout << res[i]<<'\n';
    }
}