#include <string>
#include <vector>
#include <iostream>
using namespace std;
string conversion(string s){
    for(int i=0;i<s.size();i++){
        if('A'<=s[i]&&s[i]<='Z') s[i] = s[i] + ('a'-'A');
    }
    return s;
}
int isCache(vector<string> cache, string city){
    bool isCached = false;
    int idx=0;
    for(;idx<cache.size();idx++){
        if(city == cache[idx]) {
            isCached = true;
            break;
        }
    }
    if(isCached){
        return idx;
    }else{
        return -1;
    }
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0,cnt=0;
    vector<string> cache;
    for(int i=0;i<cities.size();i++){
        string city = conversion(cities[i]);
        int cacheIdx = isCache(cache,city);
        if(cacheIdx>=0){
            if(!cache.empty()&&cacheSize==cache.size()) {
                cache.erase(cache.begin()+cacheIdx);
            }
            answer += 1;
        }else{
            if(!cache.empty()&&cacheSize==cache.size()) {
                cache.erase(cache.begin());
            }
            answer += 5;
        }
        if(cacheSize>cache.size()) cache.push_back(city);
    }
    return answer;
}