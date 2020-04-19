/*
백준 1996번 : 지뢰 찾기
https://www.acmicpc.net/problem/1996
*/
#include<iostream>
#include<vector>
using namespace std;
char map[1010][1010];
int res[1001][1001],dx[8]={-1,0,1,1,1,0,-1,-1},dy[8]={-1,-1,-1,0,1,1,1,0};
struct boom{
    int x,y,bomb;
    boom(int a,int b,int c){y=a,x=b,bomb=c;}
};
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<boom> v;     //지뢰를 저장하는 vector
    int i,j,n;
    cin >> n;
    //입력을 받는 반복문
    for(i=1;i<=n;i++){  
        string tmp;
        cin >> tmp;
        for(j=1;j<=n;j++){
            map[i][j] = tmp[j-1];
            if('1'<=map[i][j]&&map[i][j]<='9'){     //.이 아닌경우는 지뢰의 개수를 저장하는 것이므로 이를 vector에 저장한다.
                v.push_back(boom(i,j,map[i][j]-'0'));
                res[i][j]=-1;
            }
        }
    }
    for(boom b : v){    //지뢰의 개수만큼 반복한다.
        int y = b.y,x = b.x, bomb = b.bomb;
        for(i=0;i<8;i++){   //그리고 지뢰의 위치에서 8방향의 위치에 개수를 저장한다.
            int yy = y+ dy[i];
            int xx = x+ dx[i];
            if(yy>=1&&xx>=1&&yy<=n&&xx<=n&&res[yy][xx]!=-1){    //배열의 범위를 벗어나지 않고, 지뢰가 없는 위치에만 지뢰의 개수를 증가시킨다.
                res[yy][xx]+=bomb;
            }
        }
    }
    //정답출력
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(res[i][j]==-1) cout << '*';
            else if(res[i][j]>=10) cout <<'M';
            else cout << res[i][j];
        }
        cout <<'\n';
    }
}