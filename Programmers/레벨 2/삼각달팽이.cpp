#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[1002][1002];
int dx[3] = {0,1,-1},dy[3] = {1,0,-1};
vector<int> solution(int n) {
    vector<int> answer;
    int cnt = 0, x=1, y=1, now=1;
    for(int i=n;i>0;i--){
        
        for(int j=0;j<i;j++){
            arr[y][x]=now++;
            if(j==i-1) cnt = (cnt + 1)%3;
            x += dx[cnt];
            y += dy[cnt];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}