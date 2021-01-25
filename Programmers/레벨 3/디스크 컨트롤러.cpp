#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Disk{
    int s;
    int r;
    Disk(int a,int b){
        r = a;s = b;
    }
};
bool operator<(Disk a, Disk b){
    return a.r > b.r;
}
int solution(vector<vector<int>> jobs) {
    int answer = 0,now=0,cnt=0;
    priority_queue<Disk> pq;
    sort(jobs.begin(),jobs.end());
    
    while(cnt<jobs.size()||!pq.empty()){
        if(cnt < jobs.size() && jobs[cnt][0] <= now) {
            while(cnt < jobs.size() && jobs[cnt][0] <= now) {
                pq.push(Disk(jobs[cnt][1],jobs[cnt][0]));
                cnt++;
            }
            continue;
        }
        if(!pq.empty()) {
            now += pq.top().r;
            answer += (now - pq.top().s); 
            pq.pop();
        }
        else {
            now = jobs[cnt][0];
        } 
    }
    return (answer/jobs.size());
}