/*
문제
상근이는 1층 빌딩에 침입해 매우 중요한 문서를 훔쳐오려고 한다. 
상근이가 가지고 있는 평면도에는 문서의 위치가 모두 나타나 있다. 빌딩의 문은 모두 잠겨있기 때문에, 문을 열려면 열쇠가 필요하다. 
상근이는 일부 열쇠를 이미 가지고 있고, 일부 열쇠는 빌딩의 바닥에 놓여져 있다.

상근이가 훔칠 수 있는 문서의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 수는 100개를 넘지 않는다.

각 테스트 케이스의 첫째 줄에는 지도의 높이와 너비 h와 w (2 ≤ h, w ≤ 100)가 주어진다. 
다음 h개 줄에는 빌딩을 나타내는 w개의 문자가 주어지며, 각 문자는 다음 중 하나이다.

'.'는 빈 공간을 나타낸다.
'*'는 벽을 나타내며, 상근이는 벽을 통과할 수 없다.
'$'는 상근이가 훔쳐야하는 문서이다.
알파벳 대문자는 문을 나타낸다.
알파벳 소문자는 열쇠를 나타내며, 그 문자의 대문자인 모든 문을 열 수 있다.
마지막 줄에는 상근이가 이미 가지고 있는 열쇠가 공백없이 주어진다. 만약, 열쇠를 하나도 가지고 있지 않는 경우에는 "0"이 주어진다.

상근이는 처음에는 빌딩의 밖에 있으며, 빌딩 가장자리의 빈 공간이나 문을 통해 빌딩 안팎을 드나들 수 있다. 
각각의 문에 대해서, 그 문을 열 수 있는 열쇠의 개수는 0개, 1개, 또는 그 이상이고, 각각의 열쇠에 대해서, 
그 열쇠로 열 수 있는 문의 개수도 0개, 1개, 또는 그 이상이다. 열쇠는 여러 번 사용할 수 있다.

출력
각 테스트 케이스 마다, 상근이가 훔칠 수 있는 문서의 최대 개수를 출력한다.
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;
struct Loc{ //좌표를 활용하기 위한 구조체
    int x;
    int y;
    Loc(int a,int b){
        y = a;
        x = b;
    }
};
int n,m,ans,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char map[102][102];
bool visited[102][102];
queue<char> key;
void init(){ memset(visited,0,sizeof(visited));}    //방문을 저장하는 visited배열을 memset을 통해 초기화 해준다.
void unlock(char k){    //입력받은 char형의 대문자를 다 제거하는 반복문이다.
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            if(map[i][j] == (char)k-32) map[i][j]='.';
        }
    }
}

void bfs(){     //BFS알고리즘
    queue<Loc> q;
    q.push(Loc(0,0));
    visited[0][0] = true;
    while(!q.empty()){
        Loc loc = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx = loc.x+dx[i];
            int yy = loc.y+dy[i];
            if(xx>=0&&yy>=0&&xx<=m+1&&yy<=n+1&&!visited[yy][xx]){
                if(map[yy][xx]=='*') continue;
                if('A'<=map[yy][xx]&&map[yy][xx]<='Z') continue;    //문이 그대로 있는경우는 막혀서 지나갈수없다.
                if('a'<=map[yy][xx]&&map[yy][xx]<='z'){ //key를 발견하는 순간
                    init();     //이전까지의 모든 방문 기록을 초기화 한다.
                    unlock(map[yy][xx]);    //그리고 해당 key값을 통해서 해당 대문자 문을 연다.
                    while(!q.empty()) q.pop();  //그리고 지금까지 queue의 값에 저장되어있는 값을 지운다.
                    map[yy][xx]='.';    //그리고 key가 있던 위치를 .으로 바꾼다.
                    visited[yy][xx]=true;   //초기화 된 방문배열을 처음부터 시작한다.
                    q.push(Loc(yy,xx));
                }else if(map[yy][xx]=='$'){ //문서를 발견하는 순간
                    ans++;  //정답의 값을 증가시킨다.
                    map[yy][xx]='.'; //그리고 다시 방문하지 않도록 .으로 바꾼다.
                    visited[yy][xx]=true;
                    q.push(Loc(yy,xx));
                }else if(map[yy][xx]=='.'){ //이동
                    visited[yy][xx]=true;
                    q.push(Loc(yy,xx));
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
        init();
        ans=0;
        int i,j;
        char s[100];
        cin >> n>>m;
        for(i=0;i<=n+1;i++){    //입력을 받을때 한칸 더 크게 받아서 한칸 더 큰 값들을 .으로 채우고 밖에서 BFS를
                                //실행할 수 있도록 한다.(반복문으로 바깥에서 안으로 들어올수 있는 위치를 찾는것보다 구현이 쉽다.)
            for(j=0;j<=m+1;j++){
                if(i==0||j==0||i==n+1||j==m+1) map[i][j]='.';
                else cin >> map[i][j];
            }
        }
        cin >>s;
        for(i=0;i<s[i]!='\0'&&s[i]!='0';i++) unlock(s[i]);  //key가 처음에 입력받는 경우 문을 다 열어놓는다.
        bfs();
        cout <<ans<<'\n';
    }
}