/*
문제
월드 나라는 모든 도로가 일방통행인 도로이고, 싸이클이 없다. 
그런데 어떤 무수히 많은 사람들이 월드 나라의 지도를 그리기 위해서, 어떤 시작 도시로부터 도착 도시까지 출발을 하여 가능한 모든 경로를 탐색한다고 한다.

이 지도를 그리는 사람들은 사이가 너무 좋아서 지도를 그리는 일을 다 마치고 도착 도시에서 모두 다 만나기로 하였다. 
그렇다고 하였을 때 이들이 만나는 시간은 출발 도시로부터 출발한 후 최소 몇 시간 후에 만날 수 있는가? 
즉, 마지막에 도착하는 사람까지 도착을 하는 시간을 의미한다.

어떤 사람은 이 시간에 만나기 위하여 1분도 쉬지 않고 달려야 한다. 이런 사람들이 지나는 도로의 수를 카운트 하여라.
출발 도시는 들어오는 도로가 0개이고, 도착 도시는 나가는 도로가 0개이다.

입력
첫째 줄에 도시의 개수 n(1 ≤ n ≤ 10,000)이 주어지고 둘째 줄에는 도로의 개수 m(1 ≤ m ≤ 100,000)이 주어진다. 
그리고 셋째 줄부터 m+2줄까지 다음과 같은 도로의 정보가 주어진다. 
처음에는 도로의 출발 도시의 번호가 주어지고 그 다음에는 도착 도시의 번호, 그리고 마지막에는 이 도로를 지나는데 걸리는 시간이 주어진다. 
도로를 지나가는 시간은 10,000보다 작거나 같은 자연수이다.
그리고 m+3째 줄에는 지도를 그리는 사람들이 출발하는 출발 도시와 도착 도시가 주어진다.
모든 도시는 출발 도시로부터 도달이 가능하고, 모든 도시로부터 도착 도시에 도달이 가능하다.

출력
첫째 줄에는 이들이 만나는 시간을, 둘째 줄에는 1분도 쉬지 않고 달려야 하는 도로의 수가 몇 개인지 출력하여라.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m,i,start,end,ans=0;
    cin >>n>>m;
    vector<pair<int,int>> graph[10001];     //가중치가 있는 인접리스트
    vector<pair<int,int>> reverse[10001];   
    vector<bool> visit(10001,false);
    vector<int> pre(n+1,0);
    vector<int> res(n+1,0);
    queue<int> q;
    for(i=0;i<m;i++){
        int s,e,d;
        cin >> s >> e >> d;
        graph[s].push_back({e,d});  //최대 시간을 구하기 위한 vector
        reverse[e].push_back({s,d});    //최대 시간을 만드는 경로를 구하기 위해서 역으로 입력을 넣는 vector
        pre[e]++;
    }
    cin >> start >> end;
    q.push(start);      //여기서는 선행자가 없는 정점이 start밖에 없다.
    while(!q.empty()) {     //위상정렬을 이용해서 최대 시간을 구한다.
        int v = q.front();
        q.pop();
        for(pair<int,int> nextV : graph[v]){
            pre[nextV.first]--;
            if(pre[nextV.first]==0){
                q.push(nextV.first);
            }
            res[nextV.first] = max(res[nextV.first],nextV.second+res[v]);
        }
    }
    
    q.push(end);    
	visit[end] = true;
	while (!q.empty()) {    //뒤에서 부터 위상정렬을 해서 역으로 경로를 구한다.
		int v = q.front(); 
        q.pop();
		for (pair<int,int> nextV : reverse[v]) {    //역으로 가리키는 정점을 반복하도록 한다.
			if (res[v] == res[nextV.first] + nextV.second) {    //이미 구해진 최댓값 vector를 통해서 이전 경로의 값과 현재 경로의 값, 
                                                                //그리고 이전의 최댓값을 더한 값이 같은지 확인한다.(같으면 최대값을 만드는 경로이다.)
				ans++;      //경로를 1증가시켜준다.
				if (!visit[nextV.first]) {  //반복해서 검사하는것을 막기 위해서 방문하지 않은 정점을 반복하도록 한다.
                    visit[nextV.first] = true;     //아직 방문하지 않은 정점을 queue에 넣고, true로 바꾼다.
                    q.push(nextV.first);
                }
			}
		}
	}
    cout <<res[end]<<'\n'<<ans;
}