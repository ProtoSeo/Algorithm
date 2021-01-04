#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "", tri = "";
    while(n>0){
        tri += to_string(n%3);
        n/=3;
    }
    for(int i=0;i<tri.size();i++){
        if(tri[i]=='0'){
            if(i == tri.size()-1) break;
            for(int j =i+1;j<tri.size();j++){
                if(tri[j]=='0') {
                    tri[j]='2';
                }else{
                    tri[j] -= 1;
                    break;
                }
            }
            answer += "4";
        }else{
            answer += tri[i];
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}