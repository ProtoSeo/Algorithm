/*
문제
지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!

미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.

지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동한다. 

불은 각 지점에서 네 방향으로 확산된다. 

지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다. 

지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

입력
입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.

다음 입력으로 R줄동안 각각의 미로 행이 주어진다.

 각각의 문자들은 다음을 뜻한다.

#: 벽
.: 지나갈 수 있는 공간
J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
F: 불이난 공간
J는 입력에서 하나만 주어진다.

출력
지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는경우 IMPOSSIBLE 을 출력한다.

지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다. 
*/
#include<iostream>
#include<queue>
using namespace std;
char a[1001][1001]; //저장
int n,m,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct Loc{
    int x;
    int y;
    int day=0;
    Loc(int a,int b){
        y = a;
        x = b;
    }
    Loc(int a,int b,int d){
        y = a;
        x = b;
        day = d;    
    }
};
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i,j,t=0;
    queue<Loc> q,f;
    cin >>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j]=='J') q.push(Loc(i,j,0));
            if(a[i][j]=='F') f.push(Loc(i,j));
        }
    }
    int countDay = 0;
    while(!q.empty()){  //BFS알고리즘
        Loc loc = q.front();
        q.pop();
        int y = loc.y;
        int x = loc.x;
        int day = loc.day;
        if(a[y][x]=='F') continue;  //불에 만났으면 continue;
        for(i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(yy==0||xx==0||yy>n||xx>m){   //밖으로 나가서 종료하는 경우
                cout << day+1;  
                return 0;
            }
            if(yy<=n&&xx<=m&&yy>0&&xx>0&&a[yy][xx]=='.'){   //.이어서 이동할수 있는경우
                a[yy][xx] = 'J';
                q.push(Loc(yy,xx,day+1));
            }
        }
        if(countDay==day){  //불이 계속 퍼지는 것을 막기위해서 현재 날이 같은날에만 불이 퍼지도록 한다.
            countDay++;
            int fireSize = f.size();    //현재 담겨져 있는 불들만 번지도록 한다.
            while(fireSize--){
            Loc temp = f.front();
                f.pop();
                for(i=0;i<4;i++){
                    int yy = temp.y + dy[i];
                    int xx = temp.x + dx[i];
                    if(yy<=n&&xx<=m&&yy>0&&xx>0&&a[yy][xx]!='#'&&a[yy][xx]!='F'){   //벽과 불이 아닌경우
                        a[yy][xx] = 'F';
                        f.push(Loc(yy,xx));
                    }
                }       
            }
        }
    }
    cout<<"IMPOSSIBLE"; //탈출에 실패한경우
}