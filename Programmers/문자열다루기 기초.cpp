#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size()==4||s.size()==6){
        for(int i=0;i<s.size();i++){
            if(!(48<=s[i]&&s[i]<=57)){
                answer = false;
                break;
            }
        }
    }else{
        answer = false;
    }
    return answer;
}