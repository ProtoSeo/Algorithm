/*
백준 14716번 : 현수막
https://www.acmicpc.net/problem/14716
*/
#include<iostream>
#include<queue>
using namespace std;
//8가지 방향의 변화량 배열 dx dy를 만든다.
int ary[251][251],dy[8]={-1,-1,-1,0,1,1,1,0},dx[8]={-1,0,1,1,1,0,-1,-1}, n,m;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int i,j,cnt=0;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {  //입력을 받는다.
        for (j = 1; j <= m; j++){
            cin >> ary[i][j];
        }
    }
    queue<pair<int,int>> q;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (ary[i][j] == 1) {   //해당점이 1일때 부터 단어의 시작이므로 이 점부터 BFS를 통해서 단어를 찾는다.
				cnt++;
                q.push({i,j});
                ary[i][j] = 0;      //그리고 현수막의 배열 자체를 방문 배열로 만들어서 확인한다.
                while(!q.empty()){  //BFS 알고리즘
                    int x = q.front().second;
                    int y = q.front().first;
                    q.pop();
                    for(int k=0;k<8;k++){
                        int xx = x + dx[k];
                        int yy = y + dy[k];
                        if(xx<=m&&yy<=n&&xx>=1&&yy>=1){ //범위 검사
                            if(ary[yy][xx]==1){     //연결되어있다면 시작한 단어의 일부 일것이다.
                                ary[yy][xx]=0;      //방문했음을 알기 위해 0으로 만들고 queue에 담는다.
                                q.push({yy,xx});
                            }
                        }
                    }    
                }
			}
		}
	}
	cout << cnt;
}