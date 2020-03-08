/*
문제
N명의 학생들을 키 순서대로 줄을 세우려고 한다. 각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 
마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 그나마도 모든 학생들을 다 비교해 본 것이 아니고, 
일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

입력
첫째 줄에 N(1≤N≤32,000), M(1≤M≤100,000)이 주어진다. M은 키를 비교한 회수이다. 
다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

학생들의 번호는 1번부터 N번이다.

출력
첫째 줄부터 앞에서부터 줄을 세운 결과를 출력한다. 답이 여러 가지인 경우에는 아무거나 출력한다.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;    //n = 정점의 수, m = 경로의 수
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    cin >> n>> m;
    vector<int> predecessor(n+1);   //위상정렬을 하기 위해서 선행자를 미리 저장해놓는 vector
    vector<int> graph[32001];
    for(i=0;i<m;i++){   // 정점의 위치를 입력받아서 단방향성 인접리스트를 생성한다.
        int a,b;
        cin >> a>>b;
        graph[a].push_back(b);  
        predecessor[b]++;
    }
    
    for(i=1;i<n+1;i++){ //위상정렬을 위해서 선행자가 0인 정점을 우선순위 큐에 담는다.
        if(predecessor[i] == 0){
            q.push(i);
        }    
    }
    while(!q.empty()){     //위상정렬
        int v = q.front();
        cout << v << ' ';
        q.pop();    
        for (int nextV : graph[v]) {       //그리고 해당 정점에서 연결이 되어있는 다른 정점이 있는지 확인하는 반복문
            predecessor[nextV]--; 
            if (predecessor[nextV] == 0) { 
                q.push(nextV);
            }
        }
    }
}