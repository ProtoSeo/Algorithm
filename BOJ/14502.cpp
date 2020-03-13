/*
문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 
바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 
연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 

일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 
새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 
2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

빈 칸의 개수는 3개 이상이다.

출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.
*/#include<iostream>
#include<queue>
#include<cmath>
#include<vector>

using namespace std;
struct Loc {    //좌표를 저장하기 위한 구조체
	int x;
	int y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};
queue<Loc> q;
int n,m,map[9][9],dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
vector<int> res;

void bfs(){     //bfs 알고리즘을 구현함. 
    queue<Loc> q;
    bool chk[9][9];
    for(int i=1;i<=n;i++){  //먼저 해당 반복문을 통해서 바이러스부분을 queue에 담는다.(바이러스가 퍼지므로)
        for(int j=1;j<=m;j++){
            if(map[i][j]==2){   //해당 조건문에서 queue에 담음
                q.push(Loc(j,i));
            }
            if(map[i][j]!=0){   //그리고 방문 여부를 chk배열에 담는다.(0만 방문하지 않은 칸)
                chk[i][j] = true;
            }else{
                chk[i][j]=false;
            }
        }
    }
    while(!q.empty()){  //bfs 알고리즘
        Loc tmp = q.front();
        q.pop();
        int x = tmp.x;
        int y = tmp.y;
        for(int i=0;i<4;i++){
            int xx = x +dx[i];
            int yy = y +dy[i];
            if(xx>=1&&yy>=1&&xx<=m&&yy<=n){ //맵의 범위를 넘어가지 않고
                if(!chk[yy][xx]&&map[yy][xx]==0){   //해당 배열이 빈칸이고, 방문하지 않았다면
                    chk[yy][xx]=true;
                    q.push(Loc(xx,yy));
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){  //해당 반복문을 통해서 안전지대를 찾는다 (방문되지 않은칸은 안전지대 일 것이다.)
        for(int j=1;j<=m;j++){
            if(!chk[i][j]) cnt++;
        }
    }
    res.push_back(cnt); //해당 안전지대 값을 vector에 저장
}

void dfs(int len){  //해당 dfs는 벽을 3개 랜덤하게, 브루트포스로 생성하기위해서 사용한다.
    if(len == 3){   //세운 벽의 개수가 3개라면 bfs를 실행한다.
        bfs();
    }else{
        for(int i=1;i<=n;i++){  //해당 반복문을 통해서 0인 곳에 벽을 하나씩 세운다.
            for(int j=1;j<=m;j++){
                if(map[i][j]==0){
                    map[i][j]=1;    //벽을 세우고
                    dfs(len+1);     //dfs로 벽의 개수를 1증가시키고 재귀로 호출한다.
                    map[i][j]=0;    //다시 벽을 되돌림
                }
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >>n>>m;
    for(int i=1;i<=n;i++){  //그래프를 입력받는다.
        for(int j=1;j<=m;j++){
            cin >> map[i][j];
        }
    }
    dfs(0);     //dfs를 벽의 개수가 0인 상태로 호출함.
    int ans=0;
    for(int i:res){ //res vector를 반복하면서 최대값을 찾는다.
        ans = max(ans,i);
    }
    cout <<ans;   
}