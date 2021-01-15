#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<string>> r_copy;
vector<string> save;
void permutation(int num,vector<int> idx, int lmt){
    if(lmt==idx.size()){
        set<string> s;
        for(int j=0;j<r_copy.size();j++){
            string tmp = "";
            for(int i :idx){
                tmp += r_copy[j][i]+" ";
            }
            s.insert(tmp);
        }
        if(s.size()==r_copy.size()){
            string tmp = "";
            for(int i: idx) tmp += to_string(i);
            save.push_back(tmp);
        }
        return;
    }
    for(int i=num;i<r_copy[0].size();i++){
        idx.push_back(i);
        permutation(i+1,idx,lmt);
        idx.pop_back();
    }
}
int solution(vector<vector<string>> relation) {
    r_copy = relation;
    for(int i=1;i<=relation[0].size();i++){
        vector<int> idx;
        permutation(0,idx,i);
    }
    for(int i=0;i<save.size();i++){
        for(int j=i+1;j<save.size();j++){
            if(includes(save[j].begin(),save[j].end(),save[i].begin(),save[i].end())){
                save.erase(save.begin()+j);
                j--;
            }
        }
    }
    return save.size();
}