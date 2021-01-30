#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;
int dist[20001];
vector<pair<int,int> > adj[20001];

void dijkstra(int start){
    priority_queue<pair<int,int> > q;  
    q.push({0,start});     
    dist[start]=0;     
    
    while(!q.empty()){
        int cost=-q.top().first;     
        int here=q.top().second;     
        q.pop();
        
        for(int i=0; i<adj[here].size(); i++){
            int next=adj[here][i].first;
            int nextcost=adj[here][i].second;
            
            if(dist[next] > dist[here] + nextcost){    
                dist[next]=dist[here]+nextcost;
                q.push({-dist[next],next});
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    fill(dist,dist+n+1,INF); 
    for(auto v : edge){
        adj[v[0]].push_back({v[1],1});
        adj[v[1]].push_back({v[0],1});
    }
    dijkstra(1);
    int max = -1;
    for(int i=1;i<=n;i++){
        if(max <dist[i]) max = dist[i];
    }
    for(int i=1;i<=n;i++){
        if(max == dist[i]) answer++;
    }
    return answer;
}