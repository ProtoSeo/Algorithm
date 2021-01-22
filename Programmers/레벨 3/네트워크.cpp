#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,1);
    for(int i=0;i<n;i++){
        queue<int> q;
        if(visited[i]){
            answer++;
            q.push(i);
            visited[i] = false;
            while(!q.empty()){
                int t = q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(visited[j]&&computers[t][j]==1){
                        q.push(j);
                        visited[j] = false;
                    }
                }
            }
        }
    }
    return answer;
}