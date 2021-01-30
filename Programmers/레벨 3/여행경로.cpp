#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<string>> t_copy;
vector<vector<string>> candidate;
void DFS(int n,vector<string> vec,vector<bool> visited){
    if(vec.size()==n+1){
        candidate.push_back(vec);
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]&&vec.back()==t_copy[i][0]){
            vec.push_back(t_copy[i][1]);
            visited[i] = true;
            DFS(n,vec,visited);
            visited[i] = false;
            vec.pop_back();
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    t_copy = tickets;
    
    for(int i=0;i<tickets.size();i++){
        if(tickets[i][0]=="ICN"){
            vector<bool> visited(tickets.size(),0);
            visited[i]= true;
            DFS(tickets.size(),tickets[i],visited);
        }
    }
    sort(candidate.begin(),candidate.end());
    
    return candidate[0];
}