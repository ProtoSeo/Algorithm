/*
문제
KOI 준비를 위해 회의를 개최하려 한다. 주최측에서는 회의에 참석하는 사람의 수와 참석자들 사이의 관계를 따져 하나 이상의 위원회를 구성하려고 한다. 
위원회를 구성하는 방식은 다음과 같다.

서로 알고 있는 사람은 반드시 같은 위원회에 속해야 한다.
효율적인 회의 진행을 위해 위원회의 수는 최대가 되어야 한다.
이런 방식으로 위원회를 구성한 후에 각 위원회의 대표를 한 명씩 뽑아야 한다. 각 위원회의 대표만이 회의 시간 중 발언권을 가지며, 
따라서 회의 참석자들이 자신의 의견을 말하기 위해서는 자신이 속한 위원회의 대표에게 자신의 의견을 전달해야 한다. 
그런데 각 참석자는 자신이 알고 있는 사람에게만 의견을 전달할 수 있어 대표에게 의견을 전달하기 위해서는 때로 여러 사람을 거쳐야 한다. 
대표에게 의견을 전달하는 경로가 여러 개 있을 경우에는 가장 적은 사람을 거치는 경로로 의견을 전달하며 
이때 거치는 사람의 수를 참석자의 의사전달시간이라고 한다.

위원회에서 모든 참석자들의 의사전달시간 중 최댓값이 최소가 되도록 대표를 정하는 프로그램을 작성하시오.

예를 들어 1번, 2번, 3번 세 사람으로 구성되어 있는 위원회에서 1번과 2번, 2번과 3번이 서로 알고 있다고 하자. 
1번이 대표가 되면 3번이 대표인 1번에게 의견을 전달하기 위해서 2번을 거쳐야만 한다. 
반대로 3번이 대표가 되어도 1번이 대표인 3번에게 의견을 전달하려면 2번을 거쳐야만 한다. 
하지만 2번이 대표가 되면 1번과 3번 둘 다 아무도 거치지 않고 대표에게 직접 의견을 전달 할 수 있다. 
따라서 이와 같은 경우 2번이 대표가 되어야 한다.

입력
첫째 중에 회의에 참석하는 사람의 수 N이 주어진다. 참석자들은 1부터 N까지의 자연수로 표현되며 회의에 참석하는 인원은 100 이하이다. 
둘째 줄에는 서로 알고 있는 관계의 수 M이 주어진다. 이어 M개의 각 줄에는 서로 아는 사이인 참석자를 나타내는 두개의 자연수가 주어진다.

출력
첫째 줄에는 구성되는 위원회의 수 K를 출력한다. 다음 K줄에는 각 위원회의 대표 번호를 작은 수부터 차례로 한 줄에 하나씩 출력한다. 한 위원회의 대표가 될 수 있는 사람이 둘 이상일 경우 그중 한 명만 출력하면 된다.
*/
#include <iostream>
#include <vector>
#include <set>
#include<string.h>
#define INF 20000001
using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,k;
    int graph[101][101];
    vector<int> disjoint[101];
    set<int> res;
    memset(ary,-1,sizeof(ary));
    cin >> n>>m;
    for(i=1;i<n+1;i++){     // 인접행렬 초기화 부분
        for(j=1;j<n+1;j++){
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=INF;
        }
    }
    for(i=0;i<m;i++){
        int s,e;
        cin >> s>> e;   
        merge(s,e); //위원회를 구성해야하므로 union을 서로 해준다.
        graph[s][e]=graph[e][s] = 1;   //양방향으로 인접행렬을 만든다.
    }
    //플로이드 와셜 알고리즘으로 최단거리를 찾는다.
    for(i=1;i<=n;i++){  //경유지
        for(j=1;j<=n;j++){  //시작지점
            for(k=1;k<=n;k++){  //종료지점
                if(graph[j][k]>graph[j][i]+graph[i][k]){
                    graph[j][k] = graph[j][i]+graph[i][k];
                }
            }
        }
    }
    for(i=1;i<=n;i++){  
        for(j=1;j<=n;j++){
            if(graph[i][j]==INF) graph[i][j]=0; //연결이 되어있지 않은, 즉 INF인 부분을 0으로 초기화 해준다.
        }
    }
    for(i=1;i<=n;i++)  {    //그리고 disjoint라는 리스트 배열을 통해서 root가 배열의 인덱스로 하고, root에 연결된 자식들을 저장한다.
        disjoint[find(i)].push_back(i); //(이렇게 하면 그룹별로 vector를 만들수 있다.)
    }
    for(i=1;i<=n;i++){  //n만큼 반복문을 돌린뒤
        if(!disjoint[i].empty()){   // 해당 값이 root인지를 disjoint배열을 통해서 확인한다.
            int tmp = 20000000;
            int save = 0;
            for(int v : disjoint[i]){   //그리고 해당 배열의 리스트에 저장되어있는 값을 하나씩 꺼내서,
                int max=-1; 
                for(j=1;j<=n;j++){  // 모든 정점을 확인해서 의사전달시간이 가장 큰 값을 max에 저장한다.
                    if(max<graph[v][j]){    
                        max = graph[v][j];
                    }
                }
                if(max<tmp){    //그리고 v정점에서 최대 의사전달 시간이 해당 그룹에서 작은지 확인한다. 
                    tmp = max;  // 작으면 해당 값을 tmp에 저장하고, save에 해당 정점을 저장한다.
                    save = v;   
                }   
            }
            res.insert(save);   //그리고 결과값을 set에 저장한다.(작은값부터 출력해야하는데 정렬을 하지 않기위해 set을 사용)
        }
    }
    cout<<res.size()<<'\n'; //set의 크기가 위원회의 개수이다.
    for(auto it=res.begin();it!=res.end();++it){    //그리고 auto키워드를 이용해서 iterator를 통해서 하나씩 값을 출력해준다.
        cout<<*it<<'\n';
    }
}