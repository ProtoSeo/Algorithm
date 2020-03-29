/*
문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 
둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.
*/
#include<iostream>
#include<queue>
using namespace std;
bool visited[1001];
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<int> res[1001];
    queue<int> q;
    int i,n,m;
    cin >> n>>m;
    for(i=0;i<m;i++){   //인접 리스트 생성
        int s,e;
        cin >>s>>e;
        res[s].push_back(e);
        res[e].push_back(s);
    }
    int ans=0;
    for(i=1;i<=n;i++){
        if(!visited[i]){
            q.push(i);
            while(!q.empty()){  //BFS를 통해서 연결된 요소들을 한번에 처리한다.
                int v = q.front();
                q.pop();
                for(int nextV:res[v]){
                    if(!visited[nextV]){
                        visited[nextV]=true;
                        q.push(nextV);
                    }
                }
            }
            ans++;  //BFS를 통해서 요소를 다 연결했으므로 1을 증가시켜준다.
        }
    }
    cout<<ans;
}