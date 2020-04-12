/*
백준 1707번 : 이분 그래프
https://www.acmicpc.net/problem/1707
*/
#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){     //테스트 케이스만큼 반복
        int n,m,i,temp;
        bool flag=true;     //이분그래프인지 아닌지를 판별하는 bool형
        cin >> n>>m;
        vector<int> graph[20001];
        vector<char> color(20001,'\0');
        vector<bool> visited(20001,false);
        queue<int> q;
        for(i=0;i<m;i++){   //인접리스트 생성
            int a,b;
            cin >> a >>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(i=1;i<=n;i++){      //모든점을 방문한다고 생각하고 반복문을 돌린다.
            if(color[i]=='\0'){ //하지만 이미 색칠을 했다면, 방문할 필요가 없으므로 색이 없는 점만 방문하도록 한다.
                color[i]='A';   //처음의 색깔을 A색으로 가정한다.
                q.push(i);  
                while(!q.empty()){  //BFS를 하면서 색을 칠한다
                    int v = q.front();
                    char nextColor = (color[v]=='A')? 'B':'A';  //다음 색을 정하는데, 이번 정점의 색의 반대 색으로 칠한다.
                    q.pop();
                    for(int nextV : graph[v]){  //BFS이므로 인접리스트를 통해서 연결된 다음 점들을 탐색하는 반복문이다.
                        if(color[nextV]=='\0'){     //연결된 정점 중 색이 없는 점만 방문하도록 한다.
                            color[nextV]=nextColor;
                            q.push(nextV);
                        }
                    }
                }
            }
        }
        for(int v=1;v<=n;v++){  //모든 정점을 탐색하도록 한다.
            for(int nextV : graph[v]){      //인접리스트를 통해서 현재 정점에 연결된 다른 정점들을 확인한다
                if(color[v]==color[nextV]){ //만약 한 점이라도 색이 같은 점이 있다면 이분 그래프가 아니다.
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) cout <<"YES\n";
        else cout << "NO\n";
    }
}