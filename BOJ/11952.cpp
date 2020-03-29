/*
문제
JOI국은 N개의 도시와 M개의 도로로 이루어져 있다. 모든 도시는 도로로 연결되어 있으며, 각 도로를 통하지 않고는 다른 도시로 갈 수 없다.

이번에 K개의 도시는 좀비에 의해서 점령당했다.

따라서 경곽이는 벙커가 있는 가장 안전한 도시로 피난을 가기로 했다. 
경곽이는 현재 1번 도시에 살고 있으며, 벙커가 있는 가장 안전한 피난처는 N번 도시이다. 
1번 도시와 N번 도시는 아직 좀비에게 점령당하지 않았다.

경곽이는 각 도시를 이동할 때마다 1박을 해야하고, 1박을 할 때 숙박비를 지불해야 한다. 
만약 그 도시가 좀비에게 점령당했다면 숙박이 불가능하다.

좀비에게 점령당한 도시로 부터 S번 이하의 이동으로 이동할 수 있는 모든 도시는 위험한 도시로 정의하며, 
그 이외의 도시는 안전한 도시로 정의할 때, 만약 그 도시가 안전한 도시라면 숙박비가 p원이고, 
만약 그 도시가 위험한 도시라면 숙박비는 q원이다. 

경곽이가 도시 1부터 N으로 이동하는 데 드는 최단 비용을 구하자.

입력
첫 번째 줄에 N, M, K, S가 공백으로 구분되어 입력된다. 각 값은 도시의 수, 길의 수, 
좀비에게 점령당한 도시의 수, 위험한 도시의 범위 를 의미한다. (2 ≦ N ≦ 100000, 1 ≦ M ≦ 200000, 0 ≦ K ≦ N - 2, 0 ≦ S ≦ 100000)
다음 줄에는 숙박비를 나타내는 정수 p, q가 입력된다. (1 ≦ p ＜ q ≦ 100000)
그 다음 줄부터 K줄에 걸쳐서 좀비에게 점령당한 도시가 한 줄에 하나씩 주어진다.
다음 줄부터 M줄에 걸쳐서 각 도시를 연결하는 도로의 정보가 주어진다. 이 도로는 서로 양방향으로 이동 가능하다.
1번 도시에서 N번 도시로 항상 도달 가능하다.

출력
최소 비용을 출력한다.
*/
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int n,m,k,s,p,q;
int info[100001];
bool visit[100001];
vector<int> road[100001];

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i,j;
    queue<pair<int,int>> danger;  //위험한도시 구하기 위한 큐
    cin >> n>>m>>k>>s>>p>>q;
    for(i=1;i<n;i++) info[i]=p;    //모든 도시를 위험하지 않다고 초기화
    for(i=0;i<k;i++){   //좀비에 감염된 도시 저장
        int zombie;
        cin >> zombie;
        info[zombie]=-1;   //좀비에 감염됨을 표시힌디.
        danger.push({zombie,0});   //queue에 담음
        visit[zombie]=true;
    }
    for(i=0;i<m;i++){   //도로 입력
        int start,end;
        cin >> start>>end;
        road[start].push_back(end);
        road[end].push_back(start);
    }
    while(!danger.empty()){ //BFS알고리즘
        pair<int,int> pi=danger.front();    //위험도시 후보를 꺼낸다.
        danger.pop();
        int v = pi.first;
        int trans = pi.second;
        if(trans >= s) continue;    //좀비도시에서 위험도시까지 전이된 수 만큼이 넘어가면 continue
        for(int nextV : road[v]){
            if(visit[nextV]) continue;
            visit[nextV]=true;  //방문을 표시한다.
            info[nextV] =q;     //위험한 도시로 숙박비를 업데이트 해준다
            danger.push({nextV,trans+1});
        }
    }
    info[1]=info[n]=0;  //첫번째 도시와 마지막 도시는 숙박비를 내지 않는다.
    memset(visit,0,sizeof(visit));  //위헤서 위험도시를 확인하기 위한 bfs에서 사용했으므로 초기화 해준다.
    //우선순위큐를 사용해서 숙박비가 싼 점부터 확인하도록 한다.
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,1}); //시작점
    visit[1]=true;
    while(!pq.empty()){
        pair<long long,int> pi =pq.top();
        pq.pop();
        long long money = pi.first;
        int v = pi.second; 
        if(v == n) {    //n에 도착하면 숙박비를 출력하고 종료한다.
            cout << pi.first;
            return 0;
        }
        for(int nextV : road[v]){
            //-1(좀비도시), 이전에 방문한 도시는 continue한다.
            if(info[nextV]==-1||visit[nextV]) continue; 
            visit[nextV] = true;
            pq.push({money+info[nextV],nextV}); //해당 도시의 숙박비를 추가한뒤 우선순위 큐에 저장한다.
        }
    }
}