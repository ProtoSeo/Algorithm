/*
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 
최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
*/
#include<iostream>
#include<queue>
#include<string.h>
#include<cmath>

using namespace std;
struct Loc {
	int x;
	int y;
    int dest;
	Loc(int a, int b,int c) {
		x = a;
		y = b;
        dest = c;
	}
};
queue<Loc> q;
//d 배열을 통해서 위치를 저장하면서 동시에 벽을 부수고 온건지 아닌건지를 표시까지 하도록 함
int n, m, a[1001][1001], d[1001][1001][2],dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
bool chk[1001][1001][2];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int i, j;
    memset(d,-1,sizeof(d));
	cin >> n >> m;
	for (i = 1; i <= n; i++) {  //입력을 받아서 a배열에 저장해준다.
		char ch[1001];
		cin >> ch + 1;
		for (j = 1; j <= m; j++) a[i][j] = ch[j] - 48;
	}
	q.push(Loc(1, 1,0));
	d[1][1][0] = 1;    //최단 경로의 수를 저장해주는 배열 초기화
    chk[1][1][0] = true;    //처음 1,1에서 벽을 부수지 않은 칸에 이동했으므로 true
	while (!q.empty()) {    //BFS 알고리즘
		Loc tmp = q.front();
		q.pop();
		int x = tmp.x;
		int y = tmp.y;
		for (i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
            if (xx <= m && yy <= n && xx >= 1 && yy >= 1) {
                int dest = tmp.dest;            
                if(a[yy][xx]==0){   //다음칸이 벽이 없는 경우
                    if(dest==0&&!chk[yy][xx][dest]){    //그리고 다음칸에 이동할수 있는 경우(chk배열로 확인)
                        d[yy][xx][dest] = d[y][x][dest] + 1;
                        q.push(Loc(xx,yy,dest));
                    }
                    else if(dest==1&&!chk[yy][xx][dest]){
                        d[yy][xx][dest] = d[y][x][dest] + 1;                        
                        q.push(Loc(xx,yy,dest));
                    }
                    chk[yy][xx][dest]=true; //다음칸 chk배열은 true로 방문표시를 한다.
                }
                else if(a[yy][xx]==1){  //다음칸이 벽이 있는경우
                    if(dest==0&&!chk[yy][xx][dest]){    //dest가 0이고, 다음칸에 이동할수 있는 경우(chk배열로 확인)
                        dest++;     //dest를 증가시키고 이를 다음 위치와 함께 q에 넣는다.
                        q.push(Loc(xx,yy,dest));
                        d[yy][xx][dest] = d[y][x][dest-1] + 1;                        
                    }
                    chk[yy][xx][dest]=true; //다음칸 chk배열은 true로 방문표시를 한다.
                }
            }
		}
	}
	if (d[n][m][0] == -1&&d[n][m][1] == -1) cout << -1; //마지막칸에 벽을 부순경우, 안부수고 간 경우 둘다 -1인 경우에는 -1 출력
	else {
        if(d[n][m][0]==-1) d[n][m][0] = 987654321;  //-1인 경우 최솟값 비교를 위해서 큰 값을 집어넣어준다.
        if(d[n][m][1]==-1) d[n][m][1] = 987654321;
        cout<< min(d[n][m][1],d[n][m][0]);
    }
}