#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp = 1,cnt=1;
    string s = "";
    for(;tmp<n;cnt++){
        tmp *=3;
    }
    
    while(cnt--){
        int tri = (int)pow(3,cnt);
        for(int i = 2;i>=0;i--){
            if(n >= i*tri){
                s += to_string(i);
                n -= i*tri;
                break;
            }
        }
    }
    if(s[0]=='0') s = s.substr(1);
    for(int i=0;i<s.size();i++){
        int num = (s[i]-'0');
        answer += num*(int)pow(3,i);
    }
    return answer;
    
}