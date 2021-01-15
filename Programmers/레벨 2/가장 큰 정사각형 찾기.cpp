#include <iostream>
#include<vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for(int i=1;i<board.size();i++){
        for(int j=1;j<board[i].size();j++){
            if(board[i-1][j-1]>0&&board[i][j-1]>0&&board[i-1][j]>0&&board[i][j]>0){
                if(board[i-1][j-1]==board[i-1][j]&&board[i-1][j]==board[i][j-1]){
                    board[i][j]=board[i-1][j-1]+1;
                }else{
                    board[i][j] = MIN(board[i][j-1],MIN(board[i-1][j],board[i-1][j-1]))+1;
                }

            }
        }
    }

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(answer<board[i][j]) answer = board[i][j];
        }
    }
    return answer*answer;
}