/*
문제
상근이는 감옥에서 죄수 두 명을 탈옥시켜야 한다. 이 감옥은 1층짜리 건물이고, 상근이는 방금 평면도를 얻었다.

평면도에는 모든 벽과 문이 나타나있고, 탈옥시켜야 하는 죄수의 위치도 나타나 있다. 
감옥은 무인 감옥으로 죄수 두 명이 감옥에 있는 유일한 사람이다.

문은 중앙 제어실에서만 열 수 있다. 상근이는 특별한 기술을 이용해 제어실을 통하지 않고 문을 열려고 한다. 
하지만, 문을 열려면 시간이 매우 많이 걸린다. 두 죄수를 탈옥시키기 위해서 열어야 하는 문의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 수는 100개를 넘지 않는다.

첫째 줄에는 평면도의 높이 h와 너비 w가 주어진다. (2 ≤ h, w ≤ 100) 다음 h개 줄에는 감옥의 평면도 정보가 주어지며, 
빈 공간은 '.', 지나갈 수 없는 벽은 '*', 문은 '#', 죄수의 위치는 '$'이다.

상근이는 감옥 밖을 자유롭게 이동할 수 있고, 평면도에 표시된 죄수의 수는 항상 두 명이다. 
각 죄수와 감옥의 바깥을 연결하는 경로가 항상 존재하는 경우만 입력으로 주어진다.

출력
각 테스트 케이스마다 두 죄수를 탈옥시키기 위해서 열어야 하는 문의 최솟값을 출력한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<string.h>
using namespace std;
char map[102][102];
int n,m,door[3][102][102],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct Loc{     //좌표를 위한 구조체
    int x;
    int y;
    Loc(int yy,int xx){
        y = yy;
        x = xx;
    }
};
void bfs(int index,Loc loc){    // 0 - 1 BFS 알고리즘
    deque<Loc> q;   //최단거리를 구하기 위해서 deque를 사용한다.
    q.push_back(loc);
    door[index][loc.y][loc.x]=0;    //초기 시작점 값을 0으로 초기화 해준다
    while(!q.empty()){  
        Loc l = q.front();
        q.pop_front();
        int x = l.x;
        int y = l.y;
        int openDoor = door[index][y][x];
        for(int i=0;i<4;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(yy<=n+1&&xx<=m+1&&yy>=0&&x>=0){
                //이미 방문했었거나, 벽으로 막혀있는 경우는 continue
                if(door[index][yy][xx]>=0||map[yy][xx]=='*') continue;
                //.이거나 $거나 \0(외곽부분) 인 경우 이동해도 문을 열지 않으므로 값이 증가하지 않는다.
                else if(map[yy][xx]=='.'||map[yy][xx]=='$'||map[yy][xx]=='\0'){
                    door[index][yy][xx]=openDoor;
                    //문을 열지 않아서 값이 증가하지 않으므로 deque의 앞부분에 삽입한다.
                    q.push_front(Loc(yy,xx));
                }
                else if(map[yy][xx]=='#'){  //#인경우 문을 여는경우이므로 값을 1 증가시킨다.
                    door[index][yy][xx]=openDoor+1;
                    //값이 1 증가했으므로 deque의 뒷부분에 삽입한다.
                    q.push_back(Loc(yy,xx));
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        //재사용 해야하므로 초기화
        memset(map,0,sizeof(map));
        memset(door,-1,sizeof(door));
        vector<Loc> start;
        int i,j;
        cin >> n>>m;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin >> map[i][j];
                if(map[i][j]=='$') start.push_back(Loc(i,j));
            }
        }
        start.push_back(Loc(0,0));
        for(i=0;i<3;i++) bfs(i,start[i]);
        int res = 100000000;
        for(i=0;i<=n+1;i++){
            for(j=0;j<=m+1;j++){
                if(map[i][j]=='*') continue;
                int temp = door[0][i][j]+door[1][i][j]+door[2][i][j];
                //문을 열었을때는 한번만 열면 계속 열린상태를 유지할수 있다.
                //그런데 3번다 문을 여는 것으로 구했으므로 나중에 2를 빼준다.
                if(map[i][j]=='#') temp -=2;
                res = min(temp,res);
            }
        }
        cout << res <<'\n';
    }
}