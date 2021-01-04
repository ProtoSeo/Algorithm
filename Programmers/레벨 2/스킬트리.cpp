#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(string s: skill_trees){
        bool ans = true;
        int prev = -1;
        vector<int> v;
        for(int i=0;i<skill.size();i++) v.push_back(s.find(skill[i]));
        
        for(int i=0;i<v.size();i++){
            if(prev<v[i]){
                prev = v[i];
                continue;
            }else{
                if(v[i]<0){
                    for(int j=i+1;j<v.size();j++){
                        if(v[j]<0) continue;
                        ans = false;
                    }
                }else{
                    ans = false;
                }
                break;
            }
        }
        if (ans) answer++;
    }
    return answer;
}