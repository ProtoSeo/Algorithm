#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int i=1;i<=s.size()/2;i++){
        string tmp = "";
        int cnt = 0;
        for(int j=0;j<s.size();){
            if(j+i<s.size()&& s.substr(j,i) == s.substr(j+i,i)){
                cnt++;
                j+=i;
            }else{
                if(cnt ==0){
                    tmp+= s.substr(j,i);
                }else{
                    tmp += to_string(cnt+1) + s.substr(j,i);    
                }
                cnt=0;
                j+=i;
            }
        }
        if(answer>tmp.size()) answer = tmp.size();
    }
    return answer;
}