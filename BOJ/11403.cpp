/*
백준 11403번 : 경로 찾기
https://www.acmicpc.net/problem/11403
*/
#include<iostream>
#include<queue>
using namespace std;
int visited[101][101];
vector<int> graph[101];
queue<int> q;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,i,j;
    cin >> n;
    //인접 행렬을 입력받으면서, 인접리스트를 만든다.
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            int tmp;
            cin >>tmp;
            if(tmp==1){ 
                graph[i].push_back(j);
            }
        }
    }
    for(i=1;i<=n;i++){  //모든 점에서 한번씩 BFS를 통해서 연결된 점을 찾는다.
        if(graph[i].size()!=0){
            for(int v : graph[i])q.push(v);     //인접리스트에 저장되어있는 모든 정점을 queue에 저장한다.
            while(!q.empty()){  //BFS알고리즘 구현
                int v = q.front();
                visited[i][v]=1;
                q.pop();
                for(int nextV : graph[v]){
                    if(visited[i][nextV]==0){   //방문했는지를 확인하는 배열을 이용해서 방문하지 않은 지점만 방문하도록 한다.
                        q.push(nextV);
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++){      //방문배열을 출력한다.
        for(j=1;j<=n;j++){
            cout << visited[i][j]<<' ';
        }
        cout<<'\n';
    }
}