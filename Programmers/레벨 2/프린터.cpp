#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq(priorities.begin(),priorities.end());
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
    }
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        if(p.first == pq.top()){
            answer++; 
            if(p.second == location) return answer;
            
            pq.pop();
        }else{
            q.push(p);
        }
    }
    return answer;
}