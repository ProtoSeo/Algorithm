#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0;i<s.size();i++){
        char tmp = s[i];
        if('A'<=s[i]&&s[i]<='Z'){
            tmp += n;
            if('A'>tmp||tmp>'Z'){
                tmp = tmp - 'Z' + 'A'-1;
            }
        }else if('a'<=s[i]&&s[i]<='z'){
            tmp += n;
            if('a'>tmp||tmp>'z'){
                tmp = tmp - 'z' + 'a'-1;
            }
        }   
        answer += tmp;
    }
    return answer;
}
