/*
문제
낚시왕이 상어 낚시를 하는 곳은 크기가 R×C인 격자판으로 나타낼 수 있다. 격자판의 각 칸은 (r, c)로 나타낼 수 있다. 
r은 행, c는 열이고, (R, C)는 아래 그림에서 가장 오른쪽 아래에 있는 칸이다. 칸에는 상어가 최대 한 마리 들어있을 수 있다. 
상어는 크기와 속도를 가지고 있다.



낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다. 다음은 1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다. 
낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.

낚시왕이 오른쪽으로 한 칸 이동한다.
낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
상어가 이동한다.
상어는 입력으로 주어진 속도로 이동하고, 속도의 단위는 칸/초이다. 
상어가 이동하려고 하는 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.

왼쪽 그림의 상태에서 1초가 지나면 오른쪽 상태가 된다. 상어가 보고 있는 방향이 속도의 방향, 왼쪽 아래에 적힌 정수는 속력이다. 
왼쪽 위에 상어를 구분하기 위해 문자를 적었다.



상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.

낚시왕이 상어 낚시를 하는 격자판의 상태가 주어졌을 때, 낚시왕이 잡은 상어 크기의 합을 구해보자.

입력
첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)

둘째 줄부터 M개의 줄에 상어의 정보가 주어진다. 
상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다. 
(r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.

두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.

출력
낚시왕이 잡은 상어 크기의 합을 출력한다.
*/
#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
struct shark{
    int r,c,s,d,z;
    shark(int rr,int cc,int ss,int dd,int zz){r=rr,c=cc,s=ss,d=dd,z=zz;}
};
int row,col,k;   //상어의 방향을 저장하고 있음
int ary[101][101];
vector<shark> sv;
//상어들이 움직임을 구현한 함수
void move(){
    for(int i=0;i<sv.size();i++){
        if(sv[i].d==0) continue;
        else if(sv[i].d==1||sv[i].d==2){    //상하로 이동
            int tmp=sv[i].r;
            for(int j=0;j<sv[i].s;j++){ //속도 만큼 반복
                if(sv[i].d==1){ //위로 이동
                    if(tmp==1&&sv[i].d==1){     //처음에 입력이 이렇게 되어있는경우
                        tmp++;
                        sv[i].d=2;
                        continue;
                    }
                    tmp--;
                    if(tmp==1) sv[i].d=2;  //1을 만나면 방향을 튼다.  
                }else{      //아래로 이동
                    if(tmp==row&&sv[i].d==2){       //처음에 입력이 이렇게 되어있는경우
                        tmp--;
                        sv[i].d=1;
                        continue;
                    }
                    tmp++;
                    if(tmp==row) sv[i].d=1; //row를 만나면 방향을 튼다.
                }
            }
            sv[i].r = tmp;
        }
        else if(sv[i].d==3||sv[i].d==4){    //양옆으로 이동
            int tmp=sv[i].c;
            for(int j=0;j<sv[i].s;j++){     //속도 만큼 반복
                if(sv[i].d==3){ //오른쪽으로 이동
                    if(tmp==col&&sv[i].d==3){
                        tmp--;
                        sv[i].d=4;
                        continue;
                    }
                    tmp++;
                    if(tmp==col) sv[i].d=4;    //col과 만나면 방향을 튼다.
                }else{  //왼쪽으로 이동
                    if(tmp==1&&sv[i].d==4){
                        tmp++;
                        sv[i].d=3;
                        continue;
                    }
                    tmp--;
                    if(tmp==1)sv[i].d=3;   //1을 만나면 방향을 튼다.
                }
            }
            sv[i].c = tmp;
        }
    }
}
//상어를 잡는 함수
int take(int loc){
    for(int i=1;i<=row;i++){
        if(ary[i][loc]!=-1){
            int ret = sv[ary[i][loc]].z;    //해당하는 상어의 번호에 해당하는 크기를 저장한다.
            sv[ary[i][loc]].d= 0; //그리고 해당하는 물고기 번호를 초기화 한다.
            ary[i][loc]=-1;  //해당하는 배열에서 상어의 번호를 없앤다(잡혔으므로)
            return ret;
        }
    }
    return 0;
}
//상어끼리 잡아먹음을 구현하는 함수
void kill(){
    memset(ary,-1,sizeof(ary));     //초기화
    for(int i=0;i<sv.size();i++){
        if(sv[i].d!=0){
            int r = sv[i].r;
            int c = sv[i].c;
            if(ary[r][c]==-1){
                ary[r][c] = i;
            }else{
                if(sv[ary[r][c]].z>sv[i].z){
                    sv[i] = shark(0,0,0,0,0);
                }else{
                    sv[ary[r][c]] = shark(0,0,0,0,0);
                    ary[r][c]=i;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i,ans=0;
    cin >> row>>col>>k;  
    memset(ary,-1,sizeof(ary));
    for(i=0;i<k;i++){   //sv vector에 초기화를 하고있는 반복문
        int r,c,s,d,z;  
        cin >> r>>c>>s>>d>>z;
        ary[r][c]=i;    //상어를 입력받을때 반복문의 인덱스를 통해서 상어의 번호를 지정해준다.
        sv.push_back(shark(r,c,s,d,z));
    }
    //낚시왕이 col까지 한칸씩 움직이면서 물고기를 잡고,물고기가 움직이고 하는 것을 반복문으로 표현
    for(i=1;i<=col;i++){    
        ans+=take(i);
        move();
        kill();
    }
    cout << ans;
}