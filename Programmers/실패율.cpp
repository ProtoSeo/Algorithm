#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
bool cmp(const pair<double,int> &a, const pair<double,int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    int total = stages.size();
    vector<pair<double,int> > result;
    vector<int> answer, save(502,0);
    for(int s : stages) save[s]++;
    for(int i=1;i<=N;i++){
        if(total > 0){
            result.push_back({(double)save[i]/total,i});    
            total -= save[i];
        }else{
            result.push_back({0,i});
        }
    }
    sort(result.begin(),result.end(),cmp);
    for(int i=0;i<result.size();i++){
        answer.push_back(result[i].second);
    }
    return answer;
}

/*
#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
bool cmp(const pair<double,int> &a, const pair<double,int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    int num = 1,total = stages.size();
    vector<pair<double,int> > result;
    sort(stages.begin(),stages.end());
    for(int i=0;i<stages.size();){
        if(num<stages[i]){
            result.push_back({0,num});
            num++;     
        }else if(num == stages[i]){
            int j = i+1;
            for(;j<stages.size();j++){
                if((num != stages[j])) break;
            }
            result.push_back({(double)(j-i)/total,num});
            num++;
            total -= (j-i);
            i=j;
        }
        if(total==0){
            for(int j=num;j<=N;j++){
                result.push_back({0,j});
            }
            break;
        }
        if(num>N){
            break;
        }
    }
    sort(result.begin(),result.end(),cmp);
    vector<int> answer;
    for(int i=0;i<result.size();i++){
        answer.push_back(result[i].second);
    }
    return answer;
}
*/