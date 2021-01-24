#include <string>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

struct Edge{
    int s;
    int e;
    int w;
    Edge(int a,int b,int c){
        s = a;e = b;w = c;
    }
};
bool operator<(Edge a, Edge b){
    return a.w > b.w;
}
int ary[101];

int find(int n) {
	if (ary[n] < 0) return n;
	return ary[n] = find(ary[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	ary[a] += ary[b];
	ary[b] = a;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    memset(ary,-1,sizeof(ary));
    priority_queue<Edge> pq;
    for(auto c : costs){
        Edge e = Edge(c[0],c[1],c[2]);
        pq.push(e);
    }
    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        if(find(e.s)!=find(e.e)){
            answer += e.w;
            merge(e.s,e.e);
        }
    }
    return answer;
}