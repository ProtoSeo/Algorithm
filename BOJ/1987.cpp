/*
문제
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 
보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 
새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 
즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 
말이 지나는 칸은 좌측 상단의 칸도 포함된다.

입력
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1<=R,C<=20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

출력
첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.
*/
#include <iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
using namespace std;
int res=1,n,m,dx[4] ={0,1,0,-1},dy[4]={1,0,-1,0};
bool chk[30],visit[22][22];
char map[22][22] ;
int dfs(int x,int y,int cnt){   //DFS알고리즘
    for(int i=0;i<4;i++){   //dx,dy배열에 저장되어있는 방향을 통해서 이동을 할 수 있는지 반복문을 통해서 확인함
        //방향에 x값을 더한값을 통해서 xx, yy 변수에 저장한다.
        int xx = x + dx[i];     
        int yy = y + dy[i];      
        if(xx>=0&&yy>=0&&xx<m&&yy<n&&!visit[yy][xx]&&!chk[(map[yy][xx]-'A')]){  //map을 벗어나는지 검사하고, visit과 chk도 함께 검사한다.
            visit[yy][xx] =true;   
            chk[(map[yy][xx]-'A')] = true;
            res = max(dfs(xx,yy,cnt+1),res);    //res에 dfs를 통해서 반환된 최댓값을 저장한다.
            visit[yy][xx] =false;
            chk[(map[yy][xx]-'A')] = false;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n>>m;
    for(int i=0;i<n;i++) cin >> map[i]; //배열을 입력받는다.
    chk[(map[0][0]-'A')] = true;//처음에 말이 존재하는 칸의 알파벳에 해당하는 chk배열의 칸은 true로 변경한다.
    visit[0][0] = true;     //그리고 좌표상으로 왔던곳인지를 표시하는 visit배열에 true를 표시한다.(해당 배열을 필요없어도 될거같음)
    dfs(0,0,1); //그리고 dfs를 실행한다.
    cout <<res;
}