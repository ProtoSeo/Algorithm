/*
문제
N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.

어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 
이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.

각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.

이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. 
N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.

입력
첫째 줄에 N(1 <= N <= 1,000), M(1 <= M <= 10,000), X가 공백으로 구분되어 입력된다. 
두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다.

모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.

출력
첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.
*/
#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000000
using namespace std;
int graph[1001][1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,res=0,i,j,k;
    cin >> n>>m>>x;
    for(i=1;i<=n;i++){     //입력을 받을 graph배열을 초기화 해준다.
        for(j=1;j<=n;j++){
            if(i==j)
                graph[i][j] =0;
            else
                graph[i][j] = INF;
        }
    }
    for(i=0;i<m;i++){   // 방향에 대해서 입력을 받고 가중치를 저장한다.
        int s,e,w;
        cin >>s>>e>>w;
        graph[s][e]=w;
    }
    // 플로이드 와샬 알고리즘
    for(i=1;i<=n;i++){  //경유지 
        for(j=1;j<=n;j++){  //시작지점
            for(k=1;k<=n;k++){  //도착지점
                if(graph[j][k] > graph[j][i]+graph[i][k]){  
                    graph[j][k] = graph[j][i]+graph[i][k];
                }
            }
        }
    }
    for(i=1;i<=n;i++){  //x를 거쳤다가 와야하므로 반복문을 통해서 해당 값이 최대인값을 찾는다.
        res = max(res,graph[i][x]+graph[x][i]);
    }
    cout<<res;
}