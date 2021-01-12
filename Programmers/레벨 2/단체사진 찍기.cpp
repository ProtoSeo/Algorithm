#include <string>
#include <vector>
#include <cmath>
using namespace std;
string word;
int cnt;
vector<string> data_copy;
vector<bool> visited_copy;
void dfs(string s){
    if(s.size()==8){
        bool chk = true;
        for(string str : data_copy){
            int t1 = s.find(str[0]);
            int t2 = s.find(str[2]);
            int t3 = str[4]-'0';
            if(str[3]=='='){
                chk = (abs(t1-t2)-1 == t3);
            }else if(str[3]=='<'){
                chk = (abs(t1-t2)-1 < t3);
            }else if(str[3]=='>'){
                chk = (abs(t1-t2)-1 > t3);
            }
            if(!chk) break;
        }
        if(chk) cnt++;
        return ;
    }
    for(int i=0;i<8;i++){
        if(visited_copy[i]){
            visited_copy[i] = false;
            dfs(s + word[i]);
            visited_copy[i] = true;
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    vector<bool> visited(8,1);
    
    cnt = 0;
    word = "ACFJMNRT";
    data_copy = data;
    visited_copy = visited;
    
    dfs("");
    return cnt;
}