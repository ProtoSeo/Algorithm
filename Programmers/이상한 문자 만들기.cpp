#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    for(int i=0;i<s.size();++i){
        char tmp = s[i];
        if(tmp==' '){
            idx = 0;
            answer.push_back(tmp);
            continue;
        }
        if(idx%2 == 0){
            if('a'<=tmp &&tmp<='z')tmp -= ('a'-'A');
        }else{
            if('A'<=tmp &&tmp<='Z')tmp += ('a'-'A');
        }
        idx++;
        answer.push_back(tmp);
    }
    return answer;
}