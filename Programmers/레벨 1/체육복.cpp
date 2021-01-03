#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> total(n,1);
    for(int i=0;i<reserve.size();i++){
        total[reserve[i]-1]++;    
    }
    for(int i=0;i<lost.size();i++){
        total[lost[i]-1]--;    
    }
    for(int i=0;i<n;i++){
        if(i-1>=0 &&total[i]==2 && total[i-1]==0){
            total[i]=1;
            total[i-1]=1;
        }
        if(i+1<n &&total[i]==2 && total[i+1]==0){
            total[i]=1;
            total[i+1]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(total[i]>=1) answer++;
    }
    return answer;
}