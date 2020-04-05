/*
문제
2048 게임은 4×4 크기의 보드에서 혼자 즐기는 재미있는 게임이다. 이 링크를 누르면 게임을 해볼 수 있다.

이 게임에서 한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것이다.
이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다. 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다. 
(실제 게임에서는 이동을 한 번 할 때마다 블록이 추가되지만, 이 문제에서 블록이 추가되는 경우는 없다)


이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다. 보드의 크기와 보드판의 블록 상태가 주어졌을 때, 
최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N (1 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에는 게임판의 초기 상태가 주어진다.
0은 빈 칸을 나타내며, 이외의 값은 모두 블록을 나타낸다. 블록에 쓰여 있는 수는 2보다 크거나 같고, 1024보다 작거나 같은 2의 제곱꼴이다. 
블록은 적어도 하나 주어진다.

출력
최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n,ans;

vector<vector<int>> gravity(int cmd,vector<vector<int>> ary){
    //0의 개수를 센다음에 그 다음 만난 수에 0개수만큼 이동하도록 한다.
    if(cmd==0){ //위로 이동
        for(int j=1;j<=n;j++){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(ary[i][j]==0) cnt++;
                else{
                    int temp = ary[i][j];
                    ary[i][j]=0;
                    ary[i-cnt][j]=temp;
                }
            }
        }
    }
    else if(cmd==1){ //아래로 이동
         for(int j=1;j<=n;j++){
            int cnt=0;            
            for(int i=n;i>=1;i--){
                if(ary[i][j]==0) cnt++;
                else{
                    int temp = ary[i][j];
                    ary[i][j]=0;
                    ary[i+cnt][j]=temp;
                }
            }
        }
    }
    else if(cmd==2){ //왼쪽으로 이동
        for(int i=1;i<=n;i++){
            int cnt=0;  
            for(int j=1;j<=n;j++){
                if(ary[i][j]==0) cnt++;
                else{
                    int temp = ary[i][j];
                    ary[i][j]=0;
                    ary[i][j-cnt]=temp;
                }
            }
        }
    }
    else if(cmd==3){ //오른쪽으로 이동
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=n;j>=1;j--){
                if(ary[i][j]==0) cnt++;
                else{
                    int temp = ary[i][j];
                    ary[i][j]=0;
                    ary[i][j+cnt]=temp;
                }
            }
        }
    }
    return ary;
}
vector<vector<int>> solve(int cmd,vector<vector<int>> ary){
    if(cmd==0){ //위로 이동
        for(int i=2;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ary[i][j]==ary[i-1][j]){
                    ary[i-1][j]*=2;
                    ary[i][j]=0;
                }
            }
        }
    }
    else if(cmd==1){ //아래로 이동
        for(int i=n;i>1;i--){
            for(int j=1;j<=n;j++){
                if(ary[i][j]==ary[i-1][j]){
                    ary[i][j]*=2;
                    ary[i-1][j]=0;
                }
            }
        }
    }
    else if(cmd==2){ //왼쪽으로 이동
        for(int j=2;j<=n;j++){
            for(int i=1;i<=n;i++){
                if(ary[i][j]==ary[i][j-1]){
                    ary[i][j-1]*=2;
                    ary[i][j]=0;
                }
            }
        }
    }
    else if(cmd==3){ //오른쪽으로 이동
        for(int j=n;j>1;j--){
            for(int i=1;i<=n;i++){
                if(ary[i][j]==ary[i][j-1]){
                    ary[i][j]*=2;
                    ary[i][j-1]=0;
                }
            }
        }
    }
    //위에 조건문들을 통해서 합치기만 했으므로 다시 중력을 줘서 정리를 한다.
    return gravity(cmd,ary);    
}
void dfs(int cnt,vector<vector<int>> ary){
    if(cnt==5){     //기저 조건(5번 이상 움직일수 없다.)
        for(int i=1;i<=n;i++){  //2중 반복문을 통해서 최댓값을 찾아서 저장한다.
            for(int j=1;j<=n;j++) ans = max(ans,ary[i][j]); 
        }
    }
    else{
        for(int i=0;i<4;i++){   //0~3까지 반복
            //gravity를 먼저해서 2칸이상 멀리 떨어진 경우의 오류를 방지
            dfs(cnt+1,solve(i,gravity(i,ary)));
        }
    }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<vector<int> > ary(21, vector<int>(21, 0));
    int i,j;
    cin >>n;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin >> ary[i][j];   //입력
    dfs(0,ary); //dfs를 통해서 완전탐색 실행
    cout<<ans;
}