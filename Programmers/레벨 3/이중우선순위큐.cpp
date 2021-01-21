#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer={0,0};
    set<int> q;
    for(string s : operations){
        if(s[0]=='I'){
            q.insert(stoi(s.substr(2)));
        }else {
            if(q.empty()) {
                continue;
            }
            if(s[2]=='1'){
                int tmp = *q.rbegin();
                q.erase(tmp);
            }else{
                int tmp = *q.begin();
                q.erase(tmp);
            }
        }
    }
    if(!q.empty()) answer = {*q.rbegin(),*q.begin()};
    return answer;
}