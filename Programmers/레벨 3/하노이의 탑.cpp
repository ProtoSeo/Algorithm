#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void hanoi(int n ,int x,int y){
    if(n>1) hanoi(n-1,x,6-x-y);
    answer.push_back({x,y});
    if(n>1) hanoi(n-1,6-x-y,y);
}
vector<vector<int>> solution(int n) {
    hanoi(n,1,3);
    return answer;
}