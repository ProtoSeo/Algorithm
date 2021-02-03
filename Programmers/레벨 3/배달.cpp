#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
int dist[51];
int adj[51][51];
void dijkstra(int start,int N){
    priority_queue<pair<int,int> > q;  
    q.push({0,start});     
    dist[start]=0;     
    
    while(!q.empty()){
        int cost=-q.top().first;     
        int here=q.top().second;     
        q.pop();
        
        for(int i=0; i<=N; i++){
            if(adj[here][i]!=INF){
                int next=i;
                int nextcost=adj[here][i];
            
                if(dist[next] > dist[here] + nextcost){    
                    dist[next]=dist[here]+nextcost;
                    q.push({-dist[next],next});
                }    
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    fill(dist,dist+N+1,INF);
    fill(&adj[0][0], &adj[50][51],INF);
    for(auto v : road){
        if(adj[v[0]][v[1]]>v[2]){
            adj[v[0]][v[1]] = v[2];
            adj[v[1]][v[0]] = v[2];
        }
    }
    dijkstra(1,N);
    for(int i=1;i<=N;i++){
        if(dist[i]<=K) answer++;
    }
    return answer;
}