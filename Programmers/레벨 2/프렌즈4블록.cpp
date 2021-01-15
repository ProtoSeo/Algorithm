#include <string>
#include <vector>

using namespace std;
int dx[3] = {1,0,1},dy[3]={0,1,1};
vector<string> friendblock(vector<string> board){
    vector<string> result(board.begin(),board.end());
    for(int i=0;i<board.size()-1;i++){
        for(int j=0;j<board[i].size()-1;j++){
            if(board[i][j]!='0'){
                bool chk = true;
                for(int k=0;k<3;k++){
                    if(board[i][j]!=board[i+dy[k]][j+dx[k]]){
                        chk = false;
                        break;
                    }
                    
                }
                if(chk){
                    result[i][j]='0';
                    for(int k=0;k<3;k++){
                        result[i+dy[k]][j+dx[k]] = '0';
                    } 
                }
            }
        }
    }
    for(int i=0;i<board[0].size();i++){
        for(int j=board.size()-1;j>=0;j--){
            if(result[j][i]=='0'){
                for(int k=j-1;k>=0;k--){
                    if(result[k][i]!='0'){
                        result[j][i] = result[k][i];
                        result[k][i]='0';
                        break;
                    }
                }
            }
        }
    }
    return result;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<string> tmp;
    while(board != (tmp = friendblock(board))){
        board = tmp;
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]=='0') answer++;
        }
    }
    return answer;
}