/*
문제
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

입력
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 
다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 
이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 
최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

출력
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
//유니온 파인드 알고리즘 구현부분
int ary[10001];
int find(int n){
    if(ary[n]<0) return n;
    return ary[n]=find(ary[n]);
}
void merge(int a,int b){
    a= find(a);
    b= find(b);
    if(a==b) return;
    ary[a] += ary[b];
	ary[b] = a;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<pair<int,pair<int,int>>> edge;
    memset(ary,-1,sizeof(ary));
    int n,m,i,ans=0;
    cin>>n>>m;
    for(i=0;i<m;i++){   //edge를 입력받아서 저장한다.
        int s,e,v;
        cin >> s>> e>> v;
        edge.push_back({v,{s,e}});
    }
    //크루스칼 알고리즘을 위해서 간선의 비용을 기준으로 오름차순으로 정렬한다.
    sort(edge.begin(),edge.end());
    for(auto e : edge){
        int x =e.second.first;
        int y = e.second.second;
        //최소 스패닝 트리에 속해져 있지 않다면 union한 다음, 간선의 비용을 최소 스패닝 트리의 비용에 추가한다.
        if(find(x)!=find(y)){   
            merge(x,y);
            ans+=e.first;
        }
    }
    cout<<ans;
}