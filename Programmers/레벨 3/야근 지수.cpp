#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer=0;
    priority_queue<int,vector<int>,less<int>> pq(works.begin(),works.end());
    while(n--){
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp-1);
    }
    if(pq.top()<=0) return 0;
    while(!pq.empty()){
        int top = pq.top();
        pq.pop();
        answer += top*top;
    }
    return answer;
}