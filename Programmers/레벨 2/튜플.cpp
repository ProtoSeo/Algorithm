#include <string>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string tmp="";
    map<int,int> m;
    vector<pair<int,int>> v;
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='{'||(s[i]==','&&tmp=="")){
            continue;
        }else if('0'<=s[i]&&s[i]<='9'){
            tmp += s[i];
        }else if(s[i]=='}'||(s[i]==','&&tmp!="")){
            m[stoi(tmp)]++;
            tmp ="";
        }
    }
    for(auto it=m.begin();it!=m.end();++it){
        v.push_back({it->second,it->first});
    }
    sort(v.rbegin(),v.rend());
    for(auto it : v){
        answer.push_back(it.second);
    }
    return answer;
}