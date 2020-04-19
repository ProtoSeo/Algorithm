/*
백준 7562번 : 나이트의 이동
https://www.acmicpc.net/problem/7562
*/
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct Loc {
	int x,y;
	Loc(int a, int b) {y = a,x=b;}
};
int dx[8] = { 2,1,-1,-2,-2,-1,1,2 }, dy[8] = { 1,2,2,1,-1,-2,-2,-1 },ary[301][301];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
    cin >> t;
    while(t--){
        int n,nx,ny,fx,fy;
        queue<Loc> q;
        memset(ary,-1,sizeof(ary));
        cin >> n >> nx >> ny >> fx>> fy;    //현재 나이트의 위치와 목적지 위치를 받는다.
        //현재 위치에서의 출발 값은 방문배열에 저장하고, 위치를 queue에 저장한다
        ary[ny][nx]= 0;
        q.push(Loc(ny,nx));
        while(!q.empty()){  //BFS알고리즘
            int x = q.front().x,y = q.front().y;
            int cnt = ary[y][x];
            if(x==fx&&y==fy){   //현재의 queue에서 꺼낸 값이 목적지 위치와 같다면 cnt를 출력하고 종료
                cout << cnt <<'\n';
                break;
            }
            q.pop();
            for(int i=0;i<8;i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx>=0&&yy>=0&&xx<n&&yy<n&&ary[yy][xx]==-1){  //배열의 범위를 벗어나지 않고, 한번도 방문하지 않은 지역이라면 queue에 저장한다.
                    ary[yy][xx]= cnt +1;
                    q.push(Loc(yy,xx));
                }
            }
        }
    }
}