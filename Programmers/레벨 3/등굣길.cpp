#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cache[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(auto v: puddles){
        cache[v[0]][v[1]] = -1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cache[j][i]==-1) cache[j][i]=0;
            else if(i==1&&j==1) cache[j][i] = 1;
            else cache[j][i] = (cache[j][i-1] + cache[j-1][i])%1000000007;
        }
    }

    return answer = cache[m][n];
}