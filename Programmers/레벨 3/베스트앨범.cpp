#include <string>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;
bool cmp1(pair<string,pair<int,int>> a, pair<string,pair<int,int>> b){
    if(a.first == b.first){
        if(a.second.first == b.second.first){
            return a.second.second< b.second.second;
        }
        return a.second.first > b.second.first;
    }
    return a.first>b.first;
}
bool cmp2(pair<string,int> a, pair<string,int> b){
    return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string,pair<int,int>>> v;

    map<string,int> t;
    for(int i=0;i<genres.size();i++){
        t[genres[i]]+=plays[i];
        v.push_back({genres[i],{plays[i],i}});
    }
    sort(v.begin(),v.end(),cmp1);
    vector<pair<string,int>> save(t.begin(),t.end());
    sort(save.begin(),save.end(),cmp2);

    for(auto s : save){
        int cnt = 0;
        string key = s.first;
        for(auto a:v){
            if(cnt >=2) {
                break;
            }else if(a.first == key){
                answer.push_back(a.second.second);
                cnt++;
            }
        }
    }
    return answer;
}