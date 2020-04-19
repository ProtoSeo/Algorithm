/*
백준 2583번 : 영역 구하기
https://www.acmicpc.net/problem/2583
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int m,n,ary[101][101],dx[4] ={1,0,-1,0},dy[4]= {0,1,0,-1};
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i, j, t;
	cin >> n >> m >> t;
	while (t--) {   //입력만큼 구역을 1로 채운다.
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (i = b; i < d; i++) for (j = a; j < c; j++) ary[i][j] = 1;
	}
    queue<pair<int,int>> q;
    vector<int> v;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){       //해당 점이 0일때 그 공간의 영역을 찾는다.
            if(ary[i][j]==0){
                int cnt=0;
                q.push({i,j});
                ary[i][j]=1;    //입력받은 2차원 배열을 방문배열로 생각한다.
                cnt ++;
                while(!q.empty()){  //BFS알고리즘
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int yy = y + dy[k];
                        int xx = x + dx[k];
                        if(yy>=0&&xx>=0&&xx<m&&yy<n){   //범위 확인
                            if(ary[yy][xx]==0){     //연결이 되어있다면
                                ary[yy][xx]=1;      //0으로 만들고 
                                cnt++;              //영토의 범위를 증가시킨다.
                                q.push({yy,xx});
                            }
                        }
                    }
                }
                v.push_back(cnt);   //BFS알고리즘이 끝난뒤 나온 영역의 넓이를 저장하는 vector
            }   
        }
    }
    cout << v.size()<<'\n';
    sort(v.begin(),v.end());    //오름차순으로 정렬해준다.
    for(int vv : v) {
        cout << vv <<' ';
    }
}