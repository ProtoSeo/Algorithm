#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0,find = 0,idx = 0,size = name.size();
    vector<int> v;
    vector<bool> added(name.size(),false);
    for(int i=0;i<name.size();i++){
        int tmp = min(name[i]-'A',1+('Z'-name[i]));
        v.push_back(tmp);
        if(tmp > 0){
            find++;
        }
    }
    while(find>0){
        if(v[idx] > 0) {
            answer += v[idx];
            v[idx] = 0;
            find--;
        }
        int left = (idx + size-1)%size;
        int right = (idx+1)%size;
        for(int i=left;i!=idx;){
            if(v[i]>0) break;
            left = (left+size-1)%size;
            i = (i+size-1)%size;
        }
        for(int i=right;i!=idx;){
            if(v[i]>0) break;
            right = (right+1)%size;
            i = (i+1)%size;
        }

        answer+=min(right-idx,(size-left)+idx);
        idx = (abs(right-idx)<abs(left-idx))?right:left;
    }

    return answer;
}