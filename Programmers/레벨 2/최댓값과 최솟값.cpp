#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    int min = 1e9,max=-1e9;
    string tmp = "";
    s+=' ';
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            int now = stoi(tmp);
            if(min>now) min = now;
            if(max<now) max = now;
            tmp ="";
            continue;
        }
        tmp+=s[i];
    }
    return to_string(min)+" "+to_string(max);
}