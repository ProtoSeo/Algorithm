#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<string,int> m;
void permutation(string s,string tmp,int c,int n){
    if(tmp.size()==c){
        sort(tmp.begin(),tmp.end());
        m[tmp]++;
        return;
    }
    for(int i=n;i<s.size();i++){
        permutation(s,tmp+s[i],c,i+1);
    }
}
bool cmp(pair<string,int> a,pair<string,int> b){
    return a.second > b.second;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    sort(orders.begin(),orders.end());
    for(string o: orders){
        for(int c : course){
            permutation(o,"",c,0); 
        }
    }

    for(int c : course){
        vector<pair<string,int>> tmp;
        for(auto it : m){
            if(it.first.size()==c&&it.second>1){
                tmp.push_back({it.first,it.second});
            }
        }
        sort(tmp.begin(),tmp.end(),cmp);
        int max = tmp[0].second;
        for(auto t : tmp){
            if(max==t.second){
                answer.push_back(t.first);
            }else{
                break;
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}