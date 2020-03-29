/*
문제
지금 민식이가 계획한 여행은 달이 맨 처음 뜨기 시작할 때 부터, 준비했던 여행길이다. 
하지만, 매번 달이 차오를 때마다 민식이는 어쩔 수 없는 현실의 벽 앞에서 다짐을 포기하고 말았다.

민식이는 매번 자신의 다짐을 말하려고 노력했지만, 말을 하면 아무도 못 알아들을 것만 같아서, 
지레 겁먹고 벙어리가 되어버렸다. 결국 민식이는 모두 잠든 새벽 네시 반쯤 홀로 일어나, 창 밖에 떠있는 달을 보았다.

하루밖에 남지 않았다. 달은 내일이면 다 차오른다. 이번이 마지막기회다. 이걸 놓치면 영영 못간다.

영식이는 민식이가 오늘도 여태것처럼 그냥 잠 들어버려서 못 갈지도 모른다고 생각했다. 
하지만 그러기엔 민식이의 눈에는 저기 뜬 달이 너무나 떨렸다.

민식이는 지금 미로 속에 있다. 미로는 직사각형 모양이고, 여행길을 떠나기 위해 미로를 탈출하려고 한다. 
미로는 다음과 같이 구성되어져있다.

빈 곳 : 언제나 이동할 수 있다. ('.‘로 표시됨)
벽 : 절대 이동할 수 없다. (‘#’)
열쇠 : 언제나 이동할 수 있다. 이 곳에 처음 들어가면 열쇠를 집는다. (a - f)
문 : 대응하는 열쇠가 있을 때만 이동할 수 있다. (A - F)
민식이의 현재 위치 : 빈 곳이고, 민식이가 현재 서 있는 곳이다. (숫자 0)
출구 : 달이 차오르기 때문에, 민식이가 가야하는 곳이다. 이 곳에 오면 미로를 탈출한다. (숫자 1)
달이 차오르는 기회를 놓치지 않기 위해서, 미로를 탈출하려고 한다. 한 번의 움직임은 현재 위치에서 수평이나 수직으로 한 칸 이동하는 것이다.

민식이가 미로를 탈출하는데 걸리는 이동 횟수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 미로의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 50) 둘째 줄부터 N개의 줄에 미로의 모양이 주어진다. 
같은 타입의 열쇠가 여러 개 있을 수 있고, 문도 마찬가지이다. 그리고, 영식이가 열쇠를 숨겨놓는 다면 문에 대응하는 열쇠가 없을 수도 있다. 
0은 한 개, 1은 적어도 한 개 있다. 그리고, 열쇠는 여러 번 사용할 수 있다.

출력
첫째 줄에 민식이가 미로를 탈출하는데 드는 이동 횟수의 최솟값을 출력한다. 만약 민식이가 미로를 탈출 할 수 없으면, -1을 출력한다.
*/
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct Loc{     //위치와 함께 소지하고 있는 key를 저장하는 구조체
    int key,x,y;
    Loc(int k,int a,int b){key = k,y = a,x = b;}
};

queue<Loc> q;
int n,m,idx=0,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int visited[64][51][51];    //63인 이유 : 1<<7
char map[51][51];

void bfs(){
    while(!q.empty()){
        Loc loc = q.front();
        int x = loc.x;
        int y = loc.y;
        int key = loc.key;
        q.pop();
        for(int i=0;i<4;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>0&&yy>0&&xx<=m&&yy<=n){
                if(visited[key][yy][xx]>=0||map[yy][xx]=='#')continue;
                if('A'<=map[yy][xx]&&map[yy][xx]<='F') {    //대문자로 막혀있는경우
                    //현재 소지한 key로 열수있는가?(비트 마스킹으로 확인)(and연산으로 확인한다.)
                    if(key & 1 << (int(map[yy][xx]) - 'A')){    
                        visited[key][yy][xx]=visited[key][y][x]+1;
                        q.push(Loc(key,yy,xx));
                    }
                }
                else if('a'<=map[yy][xx]&&map[yy][xx]<='f') {   //key를 찾은상황
                    //key를 찾았으므로 newKey를 생성해서 현재 key에 or연산을 통해서 추가한다(or이므로 기존에 key가 있었다면 그대로이다.)
                    int newKey = key | (1 << (int(map[yy][xx])-'a'));
                    if(visited[newKey][yy][xx]<0){  //그리고 newkey로 방문했을때 한번도 방문되어있지 않다면 초기화 해주고 queue에 추가한다.
                        visited[newKey][yy][xx] =visited[key][yy][xx]= visited[key][y][x]+1;
                        q.push(Loc(newKey,yy,xx));
                    }
                //1하고 .일때는 지나간다
                }else if(map[yy][xx]=='1'){
                    visited[key][yy][xx]= visited[key][y][x]+1;
                    q.push(Loc(key,yy,xx));
                }else if(map[yy][xx]=='.'){
                    visited[key][yy][xx]= visited[key][y][x]+1;
                    q.push(Loc(key,yy,xx));
                }
            }   
        }
    }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    memset(visited,-1,sizeof(visited));
    int i,j;
    cin >> n>>m;
    vector<pair<int,int>> ans;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> map[i][j];
            if(map[i][j]=='0'){     //0이 초기점 이므로 이를queue에 추가하고, 초기화 해준다.
                q.push(Loc(0,i,j));
                map[i][j]='.';
                visited[0][i][j]=0;
            }
            if(map[i][j]=='1'){ //정답을 확인하기 위해서 1의 위치를 기억한다.
                ans.push_back({i,j});
            }            
        }
    }
    int res = 21000000;
    bfs();
    for(i=0;i<64;i++){  //key값들 마다 1의 위치로 가서 최소값을 확인한다.
        for(pair<int,int> p : ans){
            if(visited[i][p.first][p.second]>0){
                res = min(res,visited[i][p.first][p.second]);
            }
        }
    }
    if(res != 21000000) cout << res;
    else cout << -1;
}