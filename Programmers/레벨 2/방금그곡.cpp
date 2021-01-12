#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

struct music{
    int time = 0;
    int idx = 0;
    string name="";
    string play = "";
};

bool cmp (music a, music b){
    if(a.time == b.time) return a.idx>b.idx;
    return a.time>b.time;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}
string conversion(string s){
    char prev = s[0];
    s+=" ";
    string result = "";
    for(int i=1;i<s.size();i++){
        if(s[i]=='#') {
            result +=(prev +7);
            i++;
            if(i<s.size()) prev = s[i];
        }else{
            result += prev;
            prev = s[i];
        }
    }
    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)",cm=conversion(m);
    vector<music> v;
    for(int i=0;i<musicinfos.size();i++){
        music m;
        string s = musicinfos[i];
        vector<string> spt = split(s,',');
        string tmp = conversion(spt[3]);

        m.name = spt[2];
        m.time = ((stoi(s.substr(6,2))-stoi(s.substr(0,2)))*60 + 
                      stoi(s.substr(9,2))-stoi(s.substr(3,2)));
        
        for(int j=0;j<m.time;j++){
            m.play += tmp[j%tmp.size()];
        }
        if(m.play.find(cm)==string::npos){
            continue;
        }else{
            v.push_back(m);
        }
    }
    sort(v.begin(),v.end(),cmp);
    
    return v.size()==0?answer:v[0].name;
}