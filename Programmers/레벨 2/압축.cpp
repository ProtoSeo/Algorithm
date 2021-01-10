#include <string>
#include <vector>
#include <map>
#include<iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    int idx = 1;
    map<string,int> m;
    for(char c = 'A';c<='Z';c++){
        string tmp(1,c);
        m[tmp] = idx++;
    }
    
    for(int i=0;i<msg.size();){
        string tmp = "";
        tmp += msg[i];
        int result = m[tmp],j = i+1;
        for(;j<msg.size();j++){
            tmp += msg[j];
            if(m.find(tmp)==m.end()){ //find x
                m[tmp] = idx++;
                break;
            }else{
                result = m[tmp];
            }
        }
        i = j;
        answer.push_back(result);
    }
    return answer;
}