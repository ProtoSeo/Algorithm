#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    vector<int> cache;
    for(int i=0;i<land.size();i++){
        if(i==0){
            cache = land[i];
        }else{
            vector<int> prev = cache;
            cache[0] = land[i][0]+ max(prev[1],max(prev[2],prev[3]));
            cache[1] = land[i][1]+ max(prev[0],max(prev[2],prev[3]));
            cache[2] = land[i][2]+ max(prev[0],max(prev[1],prev[3]));
            cache[3] = land[i][3]+ max(prev[0],max(prev[1],prev[2]));     
        }
    }
    return max(max(cache[0],cache[1]),max(cache[2],cache[3]));
    //return *max_element(cache.begin(),cache.end());
}
