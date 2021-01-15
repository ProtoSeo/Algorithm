/**
 * 백준 1915번 : 가장 큰 정사각형
 * https://www.acmicpc.net/problem/1915
*/
#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
using namespace std;

int board[1001][1001];
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m,answer=0;
    cin >> n>> m;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        for(int j=0;j<tmp.size();j++){
            board[i][j] = tmp[j]-'0';
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(board[i-1][j-1]>0&&board[i][j-1]>0&&board[i-1][j]>0&&board[i][j]>0){
                if(board[i-1][j-1]==board[i-1][j]&&board[i-1][j]==board[i][j-1]){
                    board[i][j]=board[i-1][j-1]+1;
                }else{
                    board[i][j] = MIN(board[i][j-1],MIN(board[i-1][j],board[i-1][j-1]))+1;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(answer<board[i][j]) answer = board[i][j];
        }
    }
    cout << answer*answer;
}