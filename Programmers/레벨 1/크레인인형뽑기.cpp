#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> result;
    int answer = 0;
    for(int i=0;i<moves.size();i++){
        int row = moves[i]-1;
        for(int j=0;j<board.size();j++){
            if(board[j][row] != 0){
                if(result.size()!=0){
                    if(result.top() == board[j][row]){
                        answer += 2;
                        result.pop();
                    }else{
                        result.push(board[j][row]);
                    }  
                }
                else{
                    result.push(board[j][row]);
                }
                board[j][row] = 0;
                break;
            }
        }
    }
    return answer;
}