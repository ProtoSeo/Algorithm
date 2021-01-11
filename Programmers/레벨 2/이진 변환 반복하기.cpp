#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(s!="1"){
        answer[0]++;
        int tmp = 0;
        string result = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') answer[1]++;
            else tmp ++;
        }
        while(tmp != 0){
            result+=to_string(tmp%2);
            tmp/=2;
        }
        reverse(result.begin(),result.end());
        s= result;
    }
    return answer;
}