/*
백준 14868번 : 문명
https://www.acmicpc.net/problem/14868
*/
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int map[2001][2001],ary[100001],dx[4]={0,1,0,-1},dy[4]= {1,0,-1,0};
//union find 알고리즘
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
struct Loc{
    int x,y,civ,cnt;
    Loc(int a,int b,int c,int d){y=a,x=b,civ=c,cnt=d;}
};
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i,j,n,k;
    queue<Loc> q;
    memset(ary,-1,sizeof(ary));     //union find알고리즘을 위해서 배열 초기화
    cin >> n >> k;
    for(i=1;i<=k;i++){  //문명이 시작하는 위치를 받고 BFS알고리즘을 위해서 queue에 저장한다.
        int x,y;
        cin >> x >> y;
        map[y][x] = i;
        q.push(Loc(y,x,i,0));
    }
    //처음에 문명이 붙어있는 경우를 초기화 해주기 위한 2중반복문
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(map[i][j]!=0){   //문명인 경우의 조건문
                for(int l=0;l<4;l++){   //4방향으로 탐색
                    int yy = i + dy[l];
                    int xx = j + dx[l];
                    if(xx>=1&&yy>=1&&yy<=n&&xx<=n&&map[i+dy[l]][j+dx[l]]!=0){   //배열의 범위를 벗어나지 않고 문명이라면
                        merge(map[i][j],map[i+dy[l]][j+dx[l]]);     //해당 문명과 붙어있는 명문을 union한다.
                    }
                }
            }
        }
    }

    while(!q.empty()){  //BFS알고리즘
        Loc loc = q.front();
        q.pop();
        int x = loc.x,y=loc.y,civ=loc.civ,cnt=loc.cnt;
        if(-(ary[find(1)])==k){    //1번문명이 모든 문명과 연결이 되어있는지 확인
            cout << cnt <<'\n';   //만약 모든 문명과 연결이 되어있다면 현재 cnt를 출력하고 종료
            return 0;
        }
        for(i=0;i<4;i++){   
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx>=1&&yy>=1&&xx<=n&&yy<=n){     //현재 문명에서 4가지 방향으로 문명 전파
                if(map[yy][xx]!=0&&find(civ)!=find(map[yy][xx])){   //0칸 차이로 다른 문명과 만난경우(퍼지면서 붙은 경우)
                    merge(civ,map[yy][xx]); //문명끼리 union
                }else if(map[yy][xx]==0){   //아직 문명과 만나지 않은경우
                    for(j=0;j<4;j++){   //미리 한칸을 더 가지를 뻗어서 생각한다.
                        int xxx = xx + dx[j];   
                        int yyy = yy + dy[j];
                        if(xxx>=1&&yyy>=1&&xxx<=n&&yyy<=n){
                            //한칸 차이로 다른 문명과 만난경우(왜냐하면 다음번 한칸 차이의 문명이 커지는 순간 만날 것이기 때문에 미리 union)
                            //한칸 차이의 경우 상대 문명이 커지더라도 위의 if문으로 문명을 union 하는 조건을 만족시킬수 없다.(문제의 문명이 합쳐지는 조건을 보자.)
                            if(map[yyy][xxx]!=0&&find(civ)!=find(map[yyy][xxx])){   
                                merge(civ,map[yyy][xxx]);
                            }
                        }
                    }
                    //그 다음 문명의 번호를 배열에 저장하고(방문 배열 역할) queue에 저장
                    map[yy][xx]=civ;    
                    q.push(Loc(yy,xx,civ,cnt+1));
                }
            }
        }
        //이렇게 한 뒤에 만약 1번 문명의 disjoint set의 크기가 문명의 개수와 같다면
        if(-(ary[find(1)])==k){
            cout << cnt+1<<'\n';    //미리 한칸을 예측해서 증가 되었으므로 cnt에 1을 더해서 답을 출력한다.
            return 0;
        }
    }
}